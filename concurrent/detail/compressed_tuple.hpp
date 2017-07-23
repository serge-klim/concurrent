// Copyright (c) 2017-2018 Serge Klimov serge.klim@outlook.com

#pragma once
#include <type_traits>
#include <boost/compressed_pair.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/begin_end_fwd.hpp>
#include <boost/mpl/push_front_fwd.hpp>
#include <boost/mpl/push_back_fwd.hpp>
#include <boost/mpl/count.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/placeholders.hpp>


//#include <boost/mpl/unique.hpp>

namespace concurrent { namespace aux {

namespace detail { struct CompressedTupleTag {}; }

template<typename ...Params>
class CompressedTuple
{
public:
	using tag = detail::CompressedTupleTag;
	static constexpr size_t size = 0;

	template<typename X>
	struct PushBack { using type = CompressedTuple<Params..., X>; };
	template<typename X>
	struct PushFront { using type = CompressedTuple<X, Params...>; };
};

namespace detail { template <typename U> struct CompressedTupleIterator; }

template<typename T>
class CompressedTuple<T>
{
	friend struct detail::CompressedTupleIterator<CompressedTuple<T>>;
	using value_type = boost::compressed_pair<T, T>;
public:
	using tag = detail::CompressedTupleTag;
	static constexpr size_t size = 1;
	using first_type = typename value_type::first_type;
	using first_reference = typename value_type::first_reference;
	using first_const_reference = typename value_type::first_const_reference;

	template<typename X>
	struct PushBack { using type = CompressedTuple<T, X>; };
	template<typename X>
	struct PushFront { using type = CompressedTuple<X, T>; };

	CompressedTuple() = default;
	CompressedTuple(T&& value) : value( std::forward<T>(value) ) {}

	template<size_t N>
	auto nth() -> typename std::enable_if<N == 0, first_reference>::type { return value; }

	template<size_t N>
	auto nth() const -> typename std::enable_if<N == 0, first_const_reference>::type { return value; }
private:
	T value;
};

template<typename T, typename ...Params>
class CompressedTuple<T, Params...>
{
	friend struct detail::CompressedTupleIterator<CompressedTuple<T, Params...>>;
	using value_type = boost::compressed_pair< T, CompressedTuple<Params...> >;
public:
	using tag = detail::CompressedTupleTag;
	static constexpr size_t size = 1 + sizeof...(Params);
	using first_type = typename value_type::first_type;
	using first_reference = typename value_type::first_reference;
	using first_const_reference = typename value_type::first_const_reference;

	template<typename X>
	struct PushBack { using type = CompressedTuple<T, Params..., X>; };
	template<typename X>
	struct PushFront { using type = CompressedTuple<X, T, Params...>; };

	CompressedTuple() = default;

	template<typename U, typename ...Args>
	CompressedTuple(U&& u, Args&& ...args)
		: value{ std::forward<U>(u), CompressedTuple<Params...>{std::forward<Args>(args)...} } {}

	template<size_t N>
	auto nth() -> typename std::enable_if<N == 0, first_reference>::type
	{
		return value.first();
	}

	template<size_t N>
	auto nth() -> typename std::enable_if< N != 0, decltype((static_cast<typename value_type::second_type*>(nullptr)->/*std::declval<typename value_type::second_type>().*/template nth<N - 1>()))>::type
	{
		static_assert(N < size, "N out of bound");
		return value.second().template nth<N - 1>();
	}

	template<size_t N>
	auto nth() const -> typename std::enable_if<N == 0, first_const_reference>::type 
	{
		return value.first();
	}

	template<size_t N>
	auto nth() const -> typename std::enable_if< N != 0, decltype((static_cast<typename value_type::second_type const*>(nullptr)->/*std::declval<typename std::add_canst<typename value_type::second_type>>::type>().*/template nth<N - 1>()))>::type
	{
		static_assert(N < size, "N out of bound");
		return value.second().template nth<N - 1>();
	}
private:
	value_type value;
};

namespace detail
{
	template<typename ...Params>
	using DecayCompressedTuple = boost::mpl::transform<CompressedTuple<Params...>, typename std::decay<boost::mpl::placeholders::_1>>;
} //namespace detail

template<typename ...Args>
typename detail::DecayCompressedTuple<Args...>::type make_compressed_tuple(Args&& ...args) { return typename detail::DecayCompressedTuple<Args...>::type{ std::forward<Args>(args)... }; }

namespace detail {

// MPL sequence support
template <typename T>
struct CompressedTupleIterator
{
	using category = boost::mpl::forward_iterator_tag;
	using next = CompressedTupleIterator<CompressedTuple<>>;
	using type = CompressedTuple<>;
};

template<typename T>
struct CompressedTupleIterator<CompressedTuple<T>>
{
	using category = boost::mpl::forward_iterator_tag;
	using next = CompressedTupleIterator<CompressedTuple<>>;
	using type = typename CompressedTuple<T>::first_type;
};


template<typename T, typename ...Params>
struct CompressedTupleIterator<CompressedTuple<T, Params...>>
{
	using category = boost::mpl::forward_iterator_tag;

	// The incremented iterator
	using next = CompressedTupleIterator<typename CompressedTuple<T, Params...>::value_type::second_type>;

	// dereferencing yields the key type
	using type = typename CompressedTuple<T, Params...>::first_type;
};

} //namespace detail

}/*namespace concurrent*/ }//namespace aux 

// MPL sequence support
namespace boost { namespace mpl {

template <>
struct begin_impl<concurrent::aux::detail::CompressedTupleTag>
{
	template <typename S>
	struct apply
	{
		using type = concurrent::aux::detail::CompressedTupleIterator<S>;
	};
};

template <>
struct end_impl<concurrent::aux::detail::CompressedTupleTag>
{
	template <typename >
	struct apply
	{
		using type = concurrent::aux::detail::CompressedTupleIterator<concurrent::aux::CompressedTuple<>>;
	};
};

template<>
struct push_back_impl< concurrent::aux::detail::CompressedTupleTag >
{
	template< typename CompressedTuple, typename T > struct apply
	{
		using type = typename CompressedTuple::template PushBack<T>::type;
	};
};

template<>
struct push_front_impl< concurrent::aux::detail::CompressedTupleTag >
{
	template< typename CompressedTuple, typename T > struct apply
	{
		using type = typename CompressedTuple::template PushFront<T>::type;
	};
};


template <>
struct clear_impl<concurrent::aux::detail::CompressedTupleTag>
{
	template <typename CompressedTuple> struct apply
	{
		using type = concurrent::aux::CompressedTuple<>;
	};
};


} /* namespace mpl*/ } // namespace boost



template<size_t N, typename ...Params>
auto get(concurrent::aux::CompressedTuple<Params...>& value) -> decltype((value.template nth<N>())) { return value.template nth<N>(); }

template<size_t N, typename ...Params>
auto get(concurrent::aux::CompressedTuple<Params...> const& value) -> decltype((value.template nth<N>())) { return value.template nth<N>(); }

template<typename T, typename ...Params>
typename std::enable_if<boost::mpl::count<concurrent::aux::CompressedTuple<Params...>, T>::value == 1, T const&>::type 
	get(concurrent::aux::CompressedTuple<Params...> const& value)
{
	return get<
		boost::mpl::distance<typename boost::mpl::begin<concurrent::aux::CompressedTuple<Params...>>::type, typename boost::mpl::find<concurrent::aux::CompressedTuple<Params...>, T>::type>::value
	>(value);
}

template<typename T, typename ...Params>
typename std::enable_if<boost::mpl::count<concurrent::aux::CompressedTuple<Params...>, T>::value == 1, T&>::type 
	get(concurrent::aux::CompressedTuple<Params...>& value)
{
	return get<
		boost::mpl::distance<typename boost::mpl::begin<concurrent::aux::CompressedTuple<Params...>>::type, typename boost::mpl::find<concurrent::aux::CompressedTuple<Params...>, T>::type>::value
	>(value);
}
