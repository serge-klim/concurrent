#pragma once

namespace concurrent { namespace aux {

template<typename T, typename U>
struct EqualTo
{
	using first_argument_type = T;
	using second_argument_type = U;
	using result_type = bool;

	constexpr bool operator()(first_argument_type const& l, second_argument_type const& r) const
	{	// apply operator== to operands
		return l == r;
	}

	constexpr bool operator()(second_argument_type const& l, first_argument_type const& r) const
	{	// apply operator== to operands
		return l == r;
	}
};

template<typename T>
struct EqualTo<T, T>
{
	using equal_to = std::equal_to<T>;
	using first_argument_type = typename equal_to::first_argument_type;
	using second_argument_type = typename equal_to::second_argument_type;
	constexpr bool operator()(first_argument_type const& l, second_argument_type const& r) const
	{
		return equal_to{}(l, r);
	}
};

template<typename T>
struct EqualTo<T*, T*>
{
	using equal_to = std::equal_to<T*>;
	using first_argument_type = typename equal_to::first_argument_type;
	using second_argument_type = typename equal_to::second_argument_type;
	constexpr bool operator()(first_argument_type const& l, second_argument_type const& r) const
	{
		return equal_to{}(l, r);
	}
};

template<typename T, typename U>
struct EqualTo<T*, U*>
{
	using first_argument_type = T*;
	using second_argument_type = U*;
	using result_type = bool;

	constexpr bool operator()(first_argument_type l, second_argument_type r) const
	{	
		return static_cast<void const*>(l) == static_cast<void const*>(r);
	}

	constexpr bool operator()(second_argument_type l, first_argument_type r) const
	{	
		return static_cast<void const*>(l) == static_cast<void const*>(r);
	}
};

template<typename T, typename U>
struct EqualTo<T, U*>
{
	using first_argument_type = T;
	using second_argument_type = U const*;
	using result_type = bool;

	constexpr bool operator()(T const& l, U const* r) const
	{
		return l == *r;
	}

	constexpr bool operator()(U const* l, T const& r) const
	{
		return *l == r;
	}
};

} /*namespace aux*/ } /*namespace concurrent*/