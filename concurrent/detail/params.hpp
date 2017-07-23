// Copyright (c) 2017-2018 Serge Klimov serge.klim@outlook.com

#pragma once
#include <type_traits>
#include <tuple>
#include <boost/mpl/void.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/fusion/adapted/std_tuple.hpp>

namespace parameters { 

namespace details {

template<typename Pred, typename ...Params>
struct TypeBase
{
protected:
	using Parameters = boost::mpl::vector<Params...>;
	using I = typename boost::mpl::find_if<Parameters, Pred>::type;
	using type = typename std::conditional<std::is_same<I, typename boost::mpl::end<Parameters>::type>::value, boost::mpl::void_, typename boost::mpl::deref<I>::type>::type;
};

namespace value {

template<typename T, typename U>
struct Position
{
};

template<typename T, typename ...Params>
class Position<T, std::tuple<Params...>>
{
	using Types = std::tuple<Params...>;
	using I = typename boost::mpl::find_if<Types, std::is_same< typename std::decay<T>::type, std::decay<boost::mpl::placeholders::_1>>>::type;
public:
	static constexpr size_t value = boost::mpl::distance<typename boost::mpl::begin<Types>::type, I>::value;
};

template<typename T, typename U, typename X = std::true_type>
struct Type
{
};

template<typename T, typename ...Params>
struct Type<T, std::tuple<Params...>, std::integral_constant<bool, (sizeof...(Params) > Position<T, std::tuple<Params...>>::value)>>
{
	using type = typename std::tuple_element<Position<T, std::tuple<Params...>>::value, std::tuple<Params...>>::type;
};

} // namespace value

template<typename T>
T parameter_not_found();

} // namespace details

template<typename T, typename ...Params>
typename std::enable_if<boost::mpl::is_sequence<T>::value, std::tuple<Params&&...>>::type ParametersPack(Params&& ...params)
{
	using expected = typename boost::mpl::fold<T, boost::mpl::set0<>, boost::mpl::insert<boost::mpl::placeholders::_1, std::decay<boost::mpl::placeholders::_2>>>::type;
	using provided = typename boost::mpl::fold<boost::mpl::vector<Params...>, boost::mpl::set0<>, boost::mpl::insert<boost::mpl::placeholders::_1, std::decay<boost::mpl::placeholders::_2>>>::type;
	static_assert(boost::mpl::size<expected>::value == boost::mpl::size<T>::value, "expected parameters contains non unique type");
	static_assert(boost::mpl::size<provided>::value == sizeof...(Params), "provided parameters contains non unique type");
	static_assert(std::is_same<typename boost::mpl::find_if<provided, boost::mpl::not_<boost::mpl::has_key<expected, boost::mpl::placeholders::_1>>>::type,
		typename boost::mpl::end<provided>::type>::value, "unable to match all provided parameters to corresponding expectations");
	return std::tuple<Params&&...>{std::forward<Params>(params)...};
}

template<typename T, typename ...ExpectedParams, typename ...Params>
typename std::enable_if<!boost::mpl::is_sequence<T>::value, std::tuple<Params&&...>>::type ParametersPack(Params&& ...params)
{
	return ParametersPack<boost::mpl::vector<T, ExpectedParams...>>(std::forward<Params>(params)...);
}

template<typename ...Params>
using Signature = boost::mpl::vector<Params...>;

template<typename Pred, typename ...Params>
struct Type : private details::TypeBase<Pred, Params...>
{
	static_assert(boost::mpl::count_if<typename details::TypeBase<Pred, Params...>::Parameters, Pred>::value < 2, "predicate is ambiguous for specified parameters");
	using type = typename details::TypeBase<Pred, Params...>::type;
	template<typename U>
	using defaulted = typename std::conditional<boost::mpl::is_void_<type>::value, U, type>::type;
};

template<typename T>
struct Default
{
	T operator()() const { return construct<typename std::decay<T>::type>(); }
private:
	template<typename U>
	typename std::enable_if<std::is_default_constructible<U>::value && !std::is_pointer<U>::value, U>::type construct() const { return U{}; }

	template<typename U>
	typename std::enable_if<std::is_pointer<U>::value && !std::is_function<typename std::remove_pointer<U>::type>::value, U>::type construct() const { return U{}; }
};

template<typename T, typename Params, typename Default = boost::mpl::void_>
auto get(Params& params, Default def = boost::mpl::void_{}) ->  typename details::value::Type<T, Params>::type
{
	return std::forward<typename std::tuple_element<details::value::Position<T, Params>::value, Params>::type>(std::get<details::value::Position<T, Params>::value>(params));
}
template<typename T, typename Params>
auto get(Params& params) ->  typename std::enable_if< (std::tuple_size<Params>::value == details::value::Position<T, Params>::value), T>::type
{
	return details::parameter_not_found<T>();
}

template<typename T, typename Params, typename Default>
auto get(Params& params, Default def) ->  typename std::enable_if< (std::tuple_size<Params>::value == details::value::Position<T, Params>::value), decltype(def())>::type
{
	return def();
}

} // namespace parameters

