// Copyright (c) 2017-2018 Serge Klimov serge.klim@outlook.com

#pragma once

#include <cassert>
#include <atomic>
#include <memory>
#include <array>
#include <type_traits>
#include <functional>
#include <iterator>

#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/placeholders.hpp>
#include "compressed_tuple.hpp"
#include "params.hpp"
#include "meta_prime.hpp"
#include "equal2.hpp"


namespace concurrent {

namespace detail {

template<size_t Size>
struct BucketSize : std::integral_constant<size_t, PrimeGreateOrEqual<Size>::value> {};

template<size_t Size>
struct ProbsPerBucket : std::integral_constant<size_t, Size> {};

namespace parameter {

namespace deducer {

	template<typename T, typename U, typename X = U* >
	struct IsAllocator : std::false_type {};

	template<typename T, typename U>
	struct IsAllocator < T, U, decltype(std::declval<T>().allocate(1)) > : std::true_type {};
	
	template<typename T, typename U, typename X = size_t >
	struct IsHasher : std::false_type {};

	template<typename T, typename U>
	struct IsHasher < T, U, decltype(std::declval<T>()(std::declval<U>())) > : std::true_type {};

	template<typename T, typename U, typename X = void >
	struct IsDeleter : std::false_type {};

	template<typename T, typename U>
	struct IsDeleter < T, U, decltype(std::declval<T>()(static_cast<U*>(nullptr))) > : std::true_type {};

	template<typename T>
	struct IsBucketSize : std::false_type {};

	template<size_t Size>
	struct IsBucketSize < BucketSize<Size> > : std::true_type {};

	template<typename T>
	struct IsProbsPerBucket : std::false_type {};

	template<size_t Size>
	struct IsProbsPerBucket < ProbsPerBucket<Size> > : std::true_type {};

	template<typename T, typename L, typename R, typename X = bool >
	struct IsEqual2 : std::false_type {};

	template<typename T, typename L, typename R>
	struct IsEqual2 < T, L, R, decltype(std::declval<T>()(std::declval<L>(), std::declval<R>())) > : std::true_type {};

}// namespace deducer

} // namespace parameter

template<typename T, typename ...Params>
class Heap
{
	using BucketSize = typename parameters::Type<parameter::deducer::IsBucketSize<boost::mpl::placeholders::_1>, Params...>::template defaulted<concurrent::detail::BucketSize<30>>;
	using ProbsPerBucket = typename parameters::Type<parameter::deducer::IsProbsPerBucket<boost::mpl::placeholders::_1>, Params...>::template defaulted<concurrent::detail::ProbsPerBucket<BucketSize::value - BucketSize::value/3>>;
	struct DeleteWithAllocator{};
public:
	using value_type = T*;
	using hasher = typename parameters::Type<concurrent::detail::parameter::deducer::IsHasher<boost::mpl::placeholders::_1, value_type>, Params...>::template defaulted<std::hash<value_type>>;
	using allocator_type = typename parameters::Type<concurrent::detail::parameter::deducer::IsAllocator<boost::mpl::placeholders::_1, value_type>, Params...>::template defaulted<std::allocator<T>>;
	using deleter_type = typename parameters::Type<concurrent::detail::parameter::deducer::IsDeleter<boost::mpl::placeholders::_1, T>, Params...>::template defaulted<DeleteWithAllocator>;
	using size_type = typename BucketSize::value_type;
private:
	using AllocatorRef = typename std::conditional<std::is_empty<allocator_type>::value, allocator_type, allocator_type&>::type;
	using ObjectDeleter = typename std::conditional<std::is_same<deleter_type, DeleteWithAllocator>::value, AllocatorRef, deleter_type>::type;

	struct Bucket
	{
		struct Slot
		{
			using Ref = boost::compressed_pair<Slot*, ObjectDeleter>;
			class Deleter
			{
				friend class Heap;
			public:
				Deleter(Ref&& slot) : slot_{ std::move(slot) } {}
				void operator ()(T* ptr) noexcept;
			private:
				static void delete_with(T* ptr, deleter_type& deleter);
				static void delete_with(T* ptr, allocator_type& allocator);
			private:
				Ref slot_;
			};

			using unique_ptr = std::unique_ptr<T, Deleter>;
			std::atomic<size_t> counter = { 0 };
			std::atomic<value_type> ptr = { nullptr };
		};
		using Slots = std::array<Slot, BucketSize::value>;
		mutable Slots slots;
		std::atomic<Bucket*> next = { nullptr };
	};

	using BucketAllocator = typename std::allocator_traits<allocator_type>::template rebind_alloc<Bucket>;
	using BucketPointer = typename std::allocator_traits<BucketAllocator>::pointer;
	using BucketPointerConst = typename std::allocator_traits<BucketAllocator>::const_pointer;

	template<typename U>
	class IteratorType : public boost::iterator_facade<IteratorType<U>, std::shared_ptr<U>, boost::forward_traversal_tag, std::shared_ptr<U>>
	{
		template<class V>
		friend class IteratorType;
	public:
		IteratorType(Bucket const* bucket, typename Bucket::Slot::Ref ref);
		IteratorType() = default;
		IteratorType(IteratorType&&) = default;
		IteratorType& operator= (IteratorType&&) = default;
		IteratorType(IteratorType const&) = default;
		IteratorType& operator= (IteratorType const&) = default;
		template<typename V, typename = typename std::enable_if<std::is_convertible<V*, U*>::value>::type>
		IteratorType(IteratorType<V> const& other) : bucket_{ other.bucket_ }, value_{ other.value_ } {}
		template <typename V, typename = typename std::enable_if<std::is_convertible<V*, U*>::value>::type>
		IteratorType(IteratorType<V>&& other) : bucket_{ other.bucket_ }, value_{ std::move(other.value_) } { other.bucket_ = nullptr; return *this; }
		template<typename V, typename = typename std::enable_if<std::is_convertible<V*, U*>::value>::type>
		IteratorType& operator=(IteratorType<V> const& other) { bucket_ = other.bucket_; value_ = other.value_; }
		template <typename V, typename = typename std::enable_if<std::is_convertible<V*, U*>::value>::type>
		IteratorType& operator=(IteratorType<V>&& other) { bucket_ = other.bucket_; value_ = std::move(other.value_); other.bucket_ = nullptr; return *this; }

		void increment();
		std::shared_ptr<U> dereference() const { return value_; }
		template<typename V>
		bool equal(IteratorType<V> const& other) const { return other.value_.get() == value_.get(); }
	private:
		void increment(typename Bucket::Slot::Ref ref);
	private:
		Bucket const* bucket_ = nullptr;
		mutable std::shared_ptr<U> value_;
	};


	template<typename U>
	static U default_param()
	{
		static_assert(std::is_default_constructible<U>::value, "default constructible type expected");
		return U{};
	}

	using CompressedTuple = aux::CompressedTuple<BucketPointer, BucketAllocator, allocator_type, deleter_type, hasher>;
	template<typename U>
	static CompressedTuple make_compressed_tuple(U /*const&*/ params)
	{
		auto allocator = parameters::get<allocator_type>(params, &default_param<allocator_type>);
		auto bucketAllocator = BucketAllocator{ allocator };
		return {BucketPointer{nullptr},
											std::move(bucketAllocator),
											std::move(allocator),
											 /*params[boost::parameter::keyword<detail::parameter::tag::allocator>::instance || &default_param<allocator_type>],*/
											 parameters::get<deleter_type>(params, parameters::Default<deleter_type>{}),
											 parameters::get<hasher>(params, parameters::Default<hasher>{})};
	}
public:
	using unique_ptr = typename Bucket::Slot::unique_ptr;

	Heap() :tuple_{ make_compressed_tuple(std::tuple<>{})} { get<BucketPointer>(tuple_) = new_bucket(); }
	Heap(Heap const&) = delete;
	Heap(Heap&&) = default;
	Heap& operator = (Heap const&) = delete;
	Heap& operator = (Heap&&) = default;

	template<typename ...Args>
	explicit Heap(Args&&... args) : tuple_{ make_compressed_tuple(parameters::ParametersPack<CompressedTuple>(std::forward<Args>(args)...)) } {
		get<BucketPointer>(tuple_) = new_bucket();
	}
	~Heap();
	constexpr size_type bucket_size() const noexcept { return BucketSize::value; }
	constexpr size_type probs_per_bucket() const noexcept { return ProbsPerBucket::value; }
	deleter_type& get_deleter() noexcept { return get<deleter_type>(tuple_); }
	deleter_type const& get_deleter() const noexcept { return get<deleter_type>(tuple_); }
	allocator_type get_allocator() const { return get<allocator_type>(tuple_); }
	hasher hash_function() const { return get<hasher>(tuple_); }
	inline size_type capacity() const;

	using iterator = IteratorType<T>;
	iterator begin() { return iterator{ first_bucket(), make_slot_ref(first_bucket()->slots[0]) }; }
	iterator end() { return iterator{}; }

	using const_iterator = IteratorType<T const>;
	const_iterator cbegin() const { return const_iterator{ first_bucket(), make_slot_ref(first_bucket()->slots[0]) }; }
	const_iterator cend() const { return const_iterator{}; }

	unique_ptr insert(value_type ptr) noexcept;
protected:
	template<typename U, typename ...Args>
	unique_ptr emplace(U, Args&& ...args);
	template<class Key, class KeyHasher, class KeyEqual>
	unique_ptr find(Key key, KeyHasher&& hash_func, KeyEqual&& equal_func) const noexcept;
protected:
	allocator_type& get_allocator_ref() { return get<allocator_type>(tuple_); }
	hasher& hash_function_ref() { return get<hasher>(tuple_); }
	hasher& hash_function_ref() const { return get<hasher>(tuple_); }
private:
	BucketPointer first_bucket() { return get<BucketPointer>(tuple_);}
	BucketPointerConst first_bucket() const { return get<BucketPointer>(tuple_);}
	BucketAllocator& bucket_allocator() { return get<BucketAllocator>(tuple_); }
	/*[[nodiscard]]*/ BucketPointer new_bucket();
	void delete_bucket(BucketPointer bucket);
	typename Bucket::Slot::Ref make_slot_ref(typename Bucket::Slot& slot) const { return make_slot_ref(slot, get_deleter()); }
	typename Bucket::Slot::Ref make_slot_ref(typename Bucket::Slot& slot, DeleteWithAllocator) const { return { &slot, get_allocator() }; }
	template<typename U>
	typename Bucket::Slot::Ref make_slot_ref(typename Bucket::Slot& slot, U deleter) const { return { &slot, std::move(deleter) }; }
	unique_ptr make_unique(value_type ptr, typename Bucket::Slot& slot) { return unique_ptr(ptr, typename Bucket::Slot::Deleter{ make_slot_ref(slot) }); }
	unique_ptr make_unique(/*std::nullptr_t*/) { return unique_ptr(nullptr); }
	static unique_ptr acquire(typename Bucket::Slot::Ref slot) noexcept;
private:
	CompressedTuple tuple_;
};

} // namespace detail 

} // namespace concurrent 

template<typename T, typename ...Params>
void concurrent::detail::Heap<T, Params...>::Bucket::Slot::Deleter::operator ()(T* ptr) noexcept
{
	if (ptr != nullptr)
	{
		assert(slot_.first() != nullptr);
		for (;;)
		{
			auto tmp = ptr;
			if (slot_.first()->ptr.compare_exchange_weak(tmp, nullptr))
			{
				if (--slot_.first()->counter == 0)
					//slot_.second()(ptr); // delete ptr;
					delete_with(ptr, slot_.second());
				else
					slot_.first()->ptr.store(ptr);
				break;
			}
			else
			{
				assert(tmp == nullptr);
			}
		}
	}
}

template<typename T, typename ...Params>
void concurrent::detail::Heap<T, Params...>::Bucket::Slot::Deleter::delete_with(T* ptr, deleter_type& deleter)
{
	assert(ptr != nullptr);
	deleter(ptr);
}

template<typename T, typename ...Params>
void concurrent::detail::Heap<T, Params...>::Bucket::Slot::Deleter::delete_with(T* ptr, allocator_type& allocator)
{
	assert(ptr != nullptr);
	std::allocator_traits<allocator_type>::destroy(allocator, ptr);
	std::allocator_traits<allocator_type>::deallocate(allocator, ptr, 1);
}

template<typename T, typename ...Params>
template<typename U>
concurrent::detail::Heap<T, Params...>::IteratorType<U>::IteratorType(Bucket const* bucket, typename Bucket::Slot::Ref ref)
	: bucket_{ bucket }
{
	assert(bucket_ != nullptr);
	assert(size_t(std::distance(bucket_->slots.data(), ref.first())) < bucket_->slots.size());
	if (auto value = Heap::acquire(ref))
		value_ = std::move(value);
	else
		increment(std::move(ref));
}


template<typename T, typename ...Params>
template<typename U>
void concurrent::detail::Heap<T, Params...>::IteratorType<U>::increment(typename Bucket::Slot::Ref ref)
{
	assert(bucket_ != nullptr);
	auto slot = ref.first();
	do
	{
		if (++slot == bucket_->slots.data() + bucket_->slots.size())
		{
			bucket_ = bucket_->next.load();
			if (bucket_ == nullptr)
				break;
			slot = bucket_->slots.data();
		}
		value_ = Heap::acquire(typename Bucket::Slot::Ref{slot, ref.second() });
	} while (!value_);
}

template<typename T, typename ...Params>
template<typename U>
void concurrent::detail::Heap<T, Params...>::IteratorType<U>::increment()
{
	assert(bucket_ != nullptr);
	auto deleter = std::get_deleter<typename Bucket::Slot::Deleter>(value_);
	assert(deleter != nullptr);
	increment(deleter->slot_ );
}


template<typename T, typename ...Params>
concurrent::detail::Heap<T, Params...>::~Heap()
{
	static_assert(BucketSize::value != 0, "bucket size shouldn't be zero");
	static_assert(ProbsPerBucket::value != 0, "probs per bucket shouldn't be zero");
	static_assert(BucketSize::value > ProbsPerBucket::value, "probs per bucket expected to be less then bucket size");
	auto bucket = first_bucket();
	do
	{
		assert(bucket != nullptr);
		auto cur = bucket;
		bucket = bucket->next.load();
		delete_bucket(cur);
	} while (bucket != nullptr);
}

template<typename T, typename ...Params>
typename concurrent::detail::Heap<T, Params...>::BucketPointer concurrent::detail::Heap<T, Params...>::new_bucket()
{
	auto& allocator = bucket_allocator();
	auto bucket = std::allocator_traits<BucketAllocator>::allocate(allocator, 1);
	std::allocator_traits<BucketAllocator>::construct(allocator, bucket);
	return bucket;
}


template<typename T, typename ...Params>
void concurrent::detail::Heap<T, Params...>::delete_bucket(BucketPointer bucket)
{
	auto& allocator = bucket_allocator();
	std::allocator_traits<BucketAllocator>::destroy(allocator, bucket);
	std::allocator_traits<BucketAllocator>::deallocate(allocator, bucket, 1);
}

template<typename T, typename ...Params>
inline typename concurrent::detail::Heap<T, Params...>::size_type concurrent::detail::Heap<T, Params...>::capacity() const
{
	size_type n = 0;
	for (auto bucket = first_bucket(); bucket != nullptr; ++n, bucket = bucket->next.load()) {}
	return n * bucket_size();
}

template<typename T, typename ...Params>
template<typename U, typename ...Args>
typename concurrent::detail::Heap<T, Params...>::unique_ptr concurrent::detail::Heap<T, Params...>::emplace(U, Args&& ...args)
{
	static_assert(std::is_same<U, DeleteWithAllocator>::value, "can't emplace if custom deleter was specified");
	auto& allocator = get_allocator_ref();
	auto ptr = std::allocator_traits<allocator_type>::allocate(allocator, 1);
	std::allocator_traits<allocator_type>::construct(allocator, ptr, std::forward<Args>(args)...);
	return insert(ptr);
}

template<typename T, typename ...Params>
typename concurrent::detail::Heap<T, Params...>::unique_ptr concurrent::detail::Heap<T, Params...>::insert(value_type ptr) noexcept
{
	assert(ptr != nullptr);
	auto n = probs_per_bucket();
	auto const& hash = hash_function_ref()(ptr);
	auto bucket = first_bucket();
	for (size_type i = 0; i != n; ++i)
	{
		assert(bucket != nullptr);
		assert(bucket->slots.size() >= n);
		for(;;)
		{
			auto& slot = bucket->slots[(hash * (i + 1) + i) % n];
			size_t counter = 0;
			if (slot.counter.compare_exchange_strong(counter, 1))
			{
				assert(slot.ptr == nullptr);
				slot.ptr.store(ptr);
				return make_unique(ptr, slot);
			}
			auto next = bucket->next.load();
			if(next == nullptr)
				break;
			bucket = next;
		} 
	}

	for (;;) 
	{
		auto next = bucket->next.load();
		if (next == nullptr)
		{
			auto nu = new_bucket();
			if (!bucket->next.compare_exchange_strong(next, nu))
				delete_bucket(nu);
			next = bucket->next.load();
		}
		assert(next != nullptr);
		bucket = next;
		for (size_type i = 0; i != n; ++i)
		{
			auto& slot = bucket->slots[(hash * (i + 1) + i) % n];
			size_t counter = 0;
			if (slot.counter.compare_exchange_strong(counter, 1))
			{
				assert(slot.ptr == nullptr);
				slot.ptr.store(ptr);
				return make_unique(ptr, slot);
			}
		}
	}
}

template<typename T, typename ...Params>
template<class Key, class KeyHasher, class KeyEqual>
typename concurrent::detail::Heap<T, Params...>::unique_ptr concurrent::detail::Heap<T, Params...>::find(Key key, KeyHasher&& hash_func, KeyEqual&& equal_func) const noexcept
{
	auto n = probs_per_bucket();
	auto hash = hash_func(key);
	for (size_type i = 0; i != n; ++i)
	{
		for (auto bucket = first_bucket(); bucket != nullptr; bucket = bucket->next.load())
		{
			auto& slot = bucket->slots[(hash * (i + 1) + i) % n];
			if (auto ptr = acquire(make_slot_ref(slot)))
			{
				if (equal_func(key, ptr.get()))
					return ptr;
			}
		}
	}
	return unique_ptr{ nullptr, typename Bucket::Slot::Deleter{ make_slot_ref(first_bucket()->slots[0]) } };
}

template<typename T, typename ...Params>
typename concurrent::detail::Heap<T, Params...>::unique_ptr concurrent::detail::Heap<T, Params...>::acquire(typename Bucket::Slot::Ref ref) noexcept
{
	auto slot = ref.first();
	auto res = unique_ptr{nullptr, typename Bucket::Slot::Deleter{std::move(ref)}};
	while (slot->counter.load())
	{
		if (auto ptr = slot->ptr.load())
		{
			if (slot->ptr.compare_exchange_weak(ptr, nullptr))
			{
				assert(slot->counter.load() != 0);
				assert(slot->ptr.load() == nullptr);
				res.reset(ptr);
				++slot->counter;
				assert(slot->counter.load() != 0);
				assert(slot->ptr.load() == nullptr);
				slot->ptr.store(ptr);
				break;
			}
		}
	}
	return res;
}

