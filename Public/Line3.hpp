/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_LINE3_HPP
#define MATH_LINE3_HPP 1

#include "Vector3.hpp"

namespace greaper::math
{
	template<class T>
	class Line3T
	{
		static_assert(std::is_arithmetic_v<T>,
			"Line3T can only be instanced with an integer or a floating point type.");
	public:
		using value_type = typename std::conditional_t<std::is_floating_point_v<T>, math::Vector3Real<T>, 
							std::conditional_t<std::is_signed_v<T>, math::Vector3Signed<T>, math::Vector3Unsigned<T>>>;

		value_type Origin{};
		value_type Direction{ T(0), T(1), T(0) };

		constexpr Line3T()noexcept = default;
		INLINE constexpr Line3T(value_type origin, value_type direction)noexcept
			:Origin(origin), Direction(direction) {  }

		INLINE void Set(value_type origin, value_type direction)noexcept
		{
			Origin = origin;
			Direction = direction;
		}

		template<class T, typename std::enable_if<std::is_floating_point_v<T>, bool>::type = false>
		NODISCARD INLINE constexpr bool IsNearlyEqual(const Line3T& other,
														T tolerance = MATH_TOLERANCE<T>)const noexcept
		{
			return Origin.IsNearlyEqual(other.Origin, tolerance) && Direction.IsNearlyEqual(other.Direction, tolerance);
		}
		NODISCARD INLINE constexpr bool IsEqual(const Line3T& other)const noexcept
		{
			return Origin.IsEqual(other.Origin) && Direction.IsEqual(other.Direction);
		}

		NODISCARD INLINE String ToString()const noexcept
		{ 
			return std::format("{}, {}", Origin.ToString(), Direction.ToString());
		}
	};

	template<class T>
	NODISCARD INLINE constexpr bool operator==(const Line3T<T>& left, const Line3T<T>& right)noexcept
	{
		if constexpr (std::is_floating_point_v<T>)
		{
			return left.IsNearlyEqual(right);
		}
		else
		{
			return left.IsEqual(right);
		}
	}
	template<class T>
	NODISCARD INLINE constexpr bool operator!=(const Line3T<T>& left, const Line3T<T>& right)noexcept
	{
		return !(left == right);
	}
}

namespace std
{
	template<class T>
	struct hash<greaper::math::Line3T<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Line3T<T>& s)const noexcept
		{
			return ComputeHash(s.Origin, s.Direction);
		}
	};
}


#if MATH_USE_GREAPER_REFLECTION
#define CreateLine2Refl(linetype)                                                                                      \
namespace greaper{template<>                                                                                           \
const Vector<std::shared_ptr<refl::IField>> refl::ComplexType<linetype>::Fields = {                                    \
std::make_shared<refl::TField<linetype::value_type>>("Origin"sv,                                                       \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const linetype*)obj)->Origin); },                                                         \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((linetype*)obj)->Origin = *((const linetype::value_type*)value); }),                                                \
std::make_shared<refl::TField<linetype::value_type>>("Direction"sv,                                                    \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const linetype*)obj)->Direction); },                                                      \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((linetype*)obj)->Direction = *((const linetype::value_type*)value); })};}                                           \

CreateLine2Refl(greaper::math::Line3f);
CreateLine2Refl(greaper::math::Line3d);
CreateLine2Refl(greaper::math::Line3i);
CreateLine2Refl(greaper::math::Line3u);
#endif


#endif /* MATH_LINE3_HPP */