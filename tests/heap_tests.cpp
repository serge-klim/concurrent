#define BOOST_TEST_MODULE HeapTests
#include <boost/test/unit_test.hpp>
#include "concurrent/heap.hpp"
#include <memory>
#include <functional>
#include <iterator>
#include <type_traits>
#include <set>
#include <atomic>
#include <boost/iterator/indirect_iterator.hpp>


template<typename T>
void custom_delete(T* ptr) { delete ptr; }

template<typename T>
struct CustomDelete
{
	void operator()(T* ptr) { delete ptr; }
};


void compile_time_delete_deducer_tests()
{
	static_assert(concurrent::detail::parameter::deducer::IsDeleter<std::default_delete<int>, int>::value, "can't deduce  std::default_delete<int>  as deleter");
	static_assert(concurrent::detail::parameter::deducer::IsDeleter<CustomDelete<int>, int>::value, "can't deduce  CustomDelete<int> as deleter");
	static_assert(concurrent::detail::parameter::deducer::IsDeleter<void(int*), int>::value, "can't deduce void(int*) as deleter");
	auto deleter = [](int*) {};
	static_assert(concurrent::detail::parameter::deducer::IsDeleter<decltype(deleter), int>::value, "can't deduce lamda void(int*) as deleter");
	auto f = &custom_delete<int>;
	static_assert(concurrent::detail::parameter::deducer::IsDeleter<decltype(f), int>::value, "can't deduce pointer to void(int*) as deleter");


	static_assert(!concurrent::detail::parameter::deducer::IsDeleter<std::default_delete<unsigned int>, int>::value, "cstd::default_delete<unsigned int> is not supposed to be deduced as a deleter for int");
	static_assert(!concurrent::detail::parameter::deducer::IsDeleter<std::allocator<int>, int>::value, "std::allocator<int> is not supposed to be deduced as a deleter for int");
	static_assert(!concurrent::detail::parameter::deducer::IsDeleter<std::hash<int>, int>::value, "std::hash<int> is not supposed to be deduced as a deleter for int");
	static_assert(!concurrent::detail::parameter::deducer::IsDeleter<std::equal_to<int>, int>::value, "std::equal_to<int> is not supposed to be deduced as a deleter for int");
}


void compile_time_deducers_tests()
{
	static_assert(concurrent::detail::parameter::deducer::IsAllocator<std::allocator<int>, int>::value, "can't deduce std::allocator<int>");
	static_assert(!concurrent::detail::parameter::deducer::IsAllocator<int, int>::value, "error: concurrent::detail::parameter::deducer::IsAllocator<int, int>");
	static_assert(!concurrent::detail::parameter::deducer::IsAllocator<std::allocator<float>, int>::value, "std::allocator<float> is not supposed to be much int");
	static_assert(!concurrent::detail::parameter::deducer::IsAllocator<std::vector<int>, int>::value, "std::vector<int> can't be used as allocator for int");
	static_assert(!concurrent::detail::parameter::deducer::IsAllocator<std::hash<int>, int>::value, "std::hash<int> is not supposed to be deduced as a allocator for int");
	static_assert(!concurrent::detail::parameter::deducer::IsAllocator<std::equal_to<int>, int>::value, "std::equal_to<int> is not supposed to be deduced as a allocator for int");


	static_assert(concurrent::detail::parameter::deducer::IsHasher<std::hash<int>, int>::value, "can't deduce hasher for int");
	static_assert(!concurrent::detail::parameter::deducer::IsHasher<int, int>::value, "int is not hasher for int");
	static_assert(!concurrent::detail::parameter::deducer::IsHasher<std::vector<int>, int>::value, "std::vector<int> can't be used as hasher for int");
	static_assert(!concurrent::detail::parameter::deducer::IsHasher<std::allocator<int>, int>::value, "std::allocator<int> is not supposed to be deduced as a hasher for int");
	static_assert(!concurrent::detail::parameter::deducer::IsHasher<std::allocator<int>, int*>::value, "std::allocator<int> is not supposed to be deduced as a hasher for int*");
	static_assert(!concurrent::detail::parameter::deducer::IsHasher<std::equal_to<int>, int>::value, "std::equal_to<int> is not supposed to be deduced as a hasher for int");

	compile_time_delete_deducer_tests();
}


void compile_time_heap_tests()
{
	using Heap = concurrent::Heap<int>;
	static_assert(std::is_same<Heap::allocator_type, std::allocator<int>>::value , "invalid default allocator");
	static_assert(std::is_same<Heap::hasher, std::hash<int*>>::value, "invalid default hasher");
}

struct Fixture
{
	Fixture() 
	{
		compile_time_deducers_tests();
		compile_time_heap_tests();
	}
};

BOOST_FIXTURE_TEST_SUITE(HeapTestSuite, Fixture)

BOOST_AUTO_TEST_CASE(IntHeap)
{
	using Heap = concurrent::Heap<int, std::hash<int>>;
	std::allocator<int> alloc;
	Heap heap{ alloc };
	static_assert(sizeof(heap) == sizeof(concurrent::Heap<int>), "std allocator, hash and compare shouldn't increase heap object size");
	heap.emplace(1);
	BOOST_CHECK_EQUAL(heap.bucket_size(), 31);
}


BOOST_AUTO_TEST_CASE(HeapCustomEmptyTypeDeleterTest)
{
	using Heap = concurrent::Heap<int, std::hash<int>, CustomDelete<int>>;
	static_assert(sizeof(Heap) == sizeof(concurrent::Heap<int>), "empty type deleter as well as std allocator hash and compare shouldn't increase heap object size");
	static_assert(std::is_same<Heap::deleter_type, CustomDelete<int>>::value, "deleter_type expected to be CustomDelete");
	std::allocator<int> alloc;
	CustomDelete<int> deleter;
	Heap heap{ alloc, deleter };
	Heap heap1{ alloc, CustomDelete<int>{} };
	static_assert(std::is_same<typename std::decay<decltype(heap.get_deleter())>::type, CustomDelete<int>>::value, "deleter_type expected to be CustomDelete");
}

BOOST_AUTO_TEST_CASE(HeapFunctionDeleterTest)
{
	using deleter_type = void (*)(int*);
	using Heap = concurrent::Heap<int, std::hash<int>, deleter_type>;
	static_assert(std::is_same<Heap::deleter_type, deleter_type>::value, "deleter_type expected to void (*)(int*)");
	static_assert(sizeof(Heap) > sizeof(concurrent::Heap<int>), "function pointer deleter expect to increase Heap size");
	deleter_type ptr = [](int*) {};
	Heap heap{ std::allocator<int>{}, ptr };
	static_assert(std::is_same<typename std::decay<decltype(heap.get_deleter())>::type, deleter_type>::value, "deleter_type expected to be deleter_type aka void (*)(int*)");
	BOOST_CHECK_EQUAL(heap.get_deleter(), ptr);
	{
		auto heap = concurrent::Heap<int, std::hash<int>, void(*)(int*)>{ &custom_delete<int> };
		static_assert(std::is_same<typename std::decay<decltype(heap.get_deleter())>::type, deleter_type>::value, "deleter_type expected to be deleter_type aka void (*)(int*)");
		BOOST_CHECK_EQUAL(heap.get_deleter(), &custom_delete<int>);
	}

}

BOOST_AUTO_TEST_CASE(HeapRValueRef)
{
	using Heap = concurrent::Heap<int, std::hash<int>, concurrent::BucketSize<50>, CustomDelete<int>>;
	////	using Heap = concurrent::Heap<int, std::hash<int>, void(int*)>;
	CustomDelete<int> deleter;
	Heap heap{ std::allocator<int>{}, deleter/*CustomDelete<int>{}*/ };
	BOOST_CHECK_EQUAL(heap.bucket_size(), 53);
}

BOOST_AUTO_TEST_CASE(HeapIteratorTest)
{
	using Heap = concurrent::Heap<int, std::hash<int>>;
	std::allocator<int> alloc;
	Heap heap{ alloc };
	auto const& cheap = heap;
	static_assert(sizeof(heap) == sizeof(concurrent::Heap<void>), "std allocato hash and compare shouldn't increase heap object size");
	BOOST_CHECK_EQUAL(std::distance(heap.begin(), heap.end()), 0);
	BOOST_CHECK_EQUAL(std::distance(cheap.begin(), cheap.end()), 0);
	BOOST_CHECK_EQUAL(std::distance(cheap.cbegin(), cheap.cend()), 0);
	BOOST_CHECK_EQUAL(std::distance(begin(heap), end(heap)), 0);
	BOOST_CHECK_EQUAL(std::distance(begin(cheap), end(cheap)), 0);
	BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), 0);
	{
		auto p1 = heap.emplace(1);
		BOOST_CHECK_EQUAL(std::distance(heap.begin(), heap.end()), 1);
		BOOST_CHECK_EQUAL(std::distance(cheap.cbegin(), cheap.cend()), 1);
		BOOST_CHECK_EQUAL(std::distance(begin(heap), end(heap)), 1);
		BOOST_CHECK_EQUAL(std::distance(begin(cheap), end(cheap)), 1);
		BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), 1);
		auto p2 = heap.emplace(2);
		BOOST_CHECK_EQUAL(std::distance(heap.begin(), heap.end()), 2);
		BOOST_CHECK_EQUAL(std::distance(cheap.cbegin(), cheap.cend()), 2);
		BOOST_CHECK_EQUAL(std::distance(begin(heap), end(heap)), 2);
		BOOST_CHECK_EQUAL(std::distance(begin(cheap), end(cheap)), 2);
		BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), 2);
		auto p3 = heap.emplace(3);
		auto p4 = heap.emplace(4);
		auto p5 = heap.emplace(5);
		BOOST_CHECK_EQUAL(std::distance(heap.begin(), heap.end()), 5);
		BOOST_CHECK_EQUAL(std::distance(cheap.begin(), cheap.end()), 5);
		BOOST_CHECK_EQUAL(std::distance(cheap.cbegin(), cheap.cend()), 5);
		BOOST_CHECK_EQUAL(std::distance(begin(heap), end(heap)), 5);
		BOOST_CHECK_EQUAL(std::distance(begin(cheap), end(cheap)), 5);
		BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), 5);

		std::set<int> values {boost::indirect_iterator<Heap::const_iterator>{cheap.cbegin()}, boost::indirect_iterator<Heap::const_iterator>{cheap.cend()}};
		std::set<int> expected{ 1, 2, 3, 4, 5 };
		BOOST_CHECK(values.size() == expected.size() && std::equal(std::begin(values), std::end(values), std::begin(expected)));

		auto i = begin(heap);
		std::advance(i, 2);
		Heap::const_iterator ii = i ;
		BOOST_CHECK_EQUAL(std::distance(ii, cend(heap)), 3);


	}
	BOOST_CHECK_EQUAL(std::distance(heap.begin(), heap.end()), 0);
	BOOST_CHECK_EQUAL(std::distance(cheap.cbegin(), cheap.cend()), 0);
	BOOST_CHECK_EQUAL(std::distance(begin(heap), end(heap)), 0);
	BOOST_CHECK_EQUAL(std::distance(begin(cheap), end(cheap)), 0);
	BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), 0);
}


BOOST_AUTO_TEST_CASE(HeapInsertTest)
{
	using Heap = concurrent::Heap<int>;
	Heap heap;
	auto bucketSize = heap.bucket_size();
	BOOST_CHECK_EQUAL(bucketSize, heap.capacity());
	std::vector<Heap::unique_ptr> pointers;
	for (decltype(bucketSize) i = 0; i < bucketSize; ++i)
		pointers.emplace_back(heap.emplace(int(i)));
	BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), pointers.size());
	for(auto const& pointer : heap)
		BOOST_CHECK(std::find_if(begin(pointers), end(pointers), [&pointer](Heap::unique_ptr const& ptr)
		{
			return ptr.get() == pointer.get();
		}) != end(pointers));

	while (!pointers.empty())
	{
		auto i = *pointers.back().get();
		BOOST_CHECK(std::find_if(cbegin(heap), cend(heap), [&i](std::shared_ptr<const int> pointer)
		{
			return *pointer.get() == i;
		}) != cend(heap));
		pointers.pop_back();
		BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), pointers.size());
		BOOST_CHECK(std::find_if(cbegin(heap), cend(heap), [&i](std::shared_ptr<const int> pointer)
		{
			return *pointer.get() == i;
		}) == cend(heap));
	}

	BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), 0);
}

template<typename T, typename U>
struct CountingEqual2
{
	using first_argument_type = T;
	using second_argument_type = U;
	using result_type = bool;

	bool operator()(first_argument_type const& l, second_argument_type const& r) const
	{	
		++i_;
		return l == *r;
	}

	bool operator()(second_argument_type const& l, first_argument_type const& r) const
	{	
		++i_;
		return *l == r;
	}

	size_t count() const { return i_.load(); }
private:
	mutable std::atomic<size_t> i_ = { 0 };
};

template<typename T>
struct Hash 
{
	size_t operator()(T const* val) const
	{
		return std::hash<T>{}(*val);
	}
};

BOOST_AUTO_TEST_CASE(HeapFindCountTest)
{
	static_assert(concurrent::detail::parameter::deducer::IsEqual2<CountingEqual2<float, int*>, float, int*>::value, "can't deduce CountingEqual2 as comprison operator float - *int");
	using Heap = concurrent::Heap<int, Hash<int>>;
	Heap heap;
	static_assert(sizeof(heap) == sizeof(concurrent::Heap<void>), "std allocator hash and compare shouldn't increase heap object size");
	static_assert(std::is_same<typename std::decay<decltype(heap.hash_function())>::type, Hash<int>>::value, "hash_function expected to be Hash<int>");

	auto bucketSize = heap.bucket_size();
	BOOST_CHECK_EQUAL(bucketSize, heap.capacity());
	std::vector<Heap::unique_ptr> pointers;
	static const Heap::size_type N = 1000;
	for (decltype(bucketSize) i = 0; i < N; ++i)
		pointers.emplace_back(heap.emplace(int(i)));
	BOOST_CHECK_EQUAL(std::distance(cbegin(heap), cend(heap)), pointers.size());

	CountingEqual2<int, int*> equal_func;
	for (auto const& pointer : pointers)
	{
		auto p = heap.find(*pointer.get(), equal_func);
		BOOST_CHECK_EQUAL(!p, false);
		BOOST_CHECK_EQUAL(*p, *pointer.get());
	}

	for (auto const& pointer : pointers)
	{
		auto p = heap.find(*pointer.get(), equal_func, std::hash<int>{});
		BOOST_CHECK_EQUAL(!p, false);
		BOOST_CHECK_EQUAL(*p, *pointer.get());
	}

	for (auto i = N; i < N + 20; ++i)
	{
		auto p = heap.find(int(i), equal_func);
		BOOST_CHECK(!p);
	}


	for (auto i = N; i < N + 20; ++i)
	{
		auto p = heap.find(int(i), equal_func, std::hash<int>{});
		BOOST_CHECK(!p);
	}
}


BOOST_AUTO_TEST_SUITE_END()

