// Copyright (c) 2017-2018 Serge Klimov serge.klim@outlook.com

#pragma once
#include "detail/heap.hpp"

namespace concurrent {

using detail::BucketSize;
using detail::ProbsPerBucket;

/// Heap<T...> is lock-free reference counting pointers forward iterable container;
/// it accepts following optional parameters:
/// - allocator - std::allocator<T> compatible allocator used to allocate bucket and elements if deleter is not specified (default is std::allocator<T>)
/// - deleter - the function object or lvalue reference to function or to function object, to be called from the destructor of unique_ptr (default is undefined);
///	specifying deleter disables emplace
/// - hasher - std::hash<T*> compatible hash function used to optimise insertion position of pointers (default is std::hash<T*>)
/// - BucketSize<N> - allows to customize size of bucket N is substituted by closest equal or greater prime number (default is BucketSize<31>)
/// - ProbsPerBucket<N> - limits number of probs per bucket before go to next one (default is two thirds of BucketSize<N>)

template<typename T, typename ...Params>
class Heap : detail::Heap<T, Params...>
{
	using Base = detail::Heap<T, Params...>;
public:
	using value_type = typename Base::value_type;
	using hasher = typename Base::hasher;
	using allocator_type = typename Base::allocator_type;
	using deleter_type = typename Base::deleter_type;
	using size_type = typename Base::size_type;
	using unique_ptr = typename Base::unique_ptr;

	/// ForwardIterator which yelds std::shared_ptr<T>
	using iterator = typename Base::iterator;
	using const_iterator = typename Base::const_iterator;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;


	Heap() = default;
	Heap(Heap const&) = delete;
	Heap(Heap&&) = default;
	Heap& operator = (Heap const&) = delete;
	Heap& operator = (Heap&&) = default;

	/// Heap constructor optional parameters:
	/// - allocator - std::allocator<T> compatible allocator used to allocate bucket and elements if deleter is not specified (default is std::allocator<T>)
	/// - deleter - the function object or lvalue reference to function or to function object, to be called from the destructor of unique_ptr (default is undefined);
	///	specifying deleter disables emplace
	/// - hasher - std::hash<T*> compatible hash function used to optimise insertion position of pointers (default is std::hash<T*>)
	using detail::Heap<T, Params...>::Heap;

	/// returns bucket size
	constexpr size_type bucket_size() const noexcept { return Base::bucket_size(); }
	/// returns current heap capacity
	constexpr size_type capacity() const noexcept { return Base::capacity(); }
	/// returns the deleter that is used for destruction of the managed by unique_ptr object
	/// if one is specified during Heap template instantiation otherwise undefined
	deleter_type& get_deleter() noexcept { return Base::get_deleter(); }
	deleter_type const& get_deleter() const noexcept { return Base::get_deleter(); }
	/// returns the associated allocator by default std::allocator<T>
	allocator_type get_allocator() const { return Base::get_allocator(); }
	/// returns function used to hash the T*
	hasher hash_function() const { return Base::hash_function(); }

	///returns an iterator to the beginning
	iterator begin() { return Base::begin(); }
	///returns an iterator to the end
	iterator end() { return Base::end(); }

	///returns a const iterator to the beginning
	const_iterator begin() const { return cbegin(); }
	///returns a const iterator to the end
	const_iterator end() const { return cend(); }

	///returns a const iterator to the beginning
	const_iterator cbegin() const { return Base::cbegin(); }
	///returns a const iterator to the end
	const_iterator cend() const { return Base::cend(); }


	/// inserts a new element into the container constructed in-place by allocator with the given args;
	/// it returns unique_ptr pointing to constructed element
	/// emplace is not working if Heap is specialized with custom deleter
	template<typename ...Args>
	unique_ptr emplace(Args&& ...args) { return Base::emplace(get_deleter(), std::forward<Args>(args)...); }
	/// inserts a new element into the container 
	unique_ptr insert(value_type ptr) noexcept { return Base::insert(ptr); }

	unique_ptr find(T* key) const noexcept { return Base::find(key, Base::hash_function_ref(), Base::key_eq_ref()); }
	/// finds a key based on provided hash and compare functions 
	/// if Key key is equal to T* ptr provided hash<Key>(key) should be equal to result of Heap::hash_function()(ptr) and 
	/// and provided equal function should return true only if key === ptr;  
	template<typename Key, typename ...Args>
	unique_ptr find(Key const& key, Args&& ...args) const noexcept;
};

template<typename ...Args>
typename Heap<Args... >::iterator begin(Heap<Args...>& heap) { return heap.begin(); }
template<typename ...Args>
typename Heap<Args...>::iterator end(Heap<Args...>& heap) { return heap.end(); }
template<typename ...Args>
typename Heap<Args...>::const_iterator begin(Heap<Args...> const& heap) { return heap.cbegin(); }
template<typename ...Args>
typename Heap<Args...>::const_iterator end(Heap<Args...> const& heap) { return heap.cend(); }
template<typename ...Args>
typename Heap<Args...>::const_iterator cbegin(Heap<Args...> const& heap) { return heap.cbegin(); }
template<typename ...Args>
typename Heap<Args...>::const_iterator cend(Heap<Args...> const& heap) { return heap.cend(); }

} // namespace concurrent 

template<typename T, typename ...Params>
template<typename Key, typename ...Args>
typename concurrent::Heap<T, Params...>::unique_ptr concurrent::Heap<T, Params...>::find(Key const& key, Args&& ...args) const noexcept
{
	using hasher = typename parameters::Type<concurrent::detail::parameter::deducer::IsHasher<boost::mpl::placeholders::_1, Key>, Args...>::template defaulted<std::hash<Key>>;
	using key_equal = typename parameters::Type<concurrent::detail::parameter::deducer::IsEqual2<boost::mpl::placeholders::_1, Key, value_type>, Args...>::template defaulted<aux::EqualTo<Key, value_type>>;
	auto params = parameters::ParametersPack<hasher, key_equal>(std::forward<Args>(args)...);
	return Base::find(key, parameters::get<hasher>(params, parameters::Default<std::hash<Key>>{}), parameters::get<key_equal>(params, parameters::Default<key_equal>{}));
}
