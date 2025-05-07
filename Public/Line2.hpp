/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_LINE2_HPP
#define MATH_LINE2_HPP 1

#include "Vector2.hpp"

namespace greaper::math
{
	template<class T>
	class Line2T
	{
		static_assert(std::is_arithmetic_v<T>,
			"Line2T can only be instanced with an integer or a floating point type.");
	public:
		using value_type = typename std::conditional_t<std::is_floating_point_v<T>, math::Vector2Real<T>, 
							std::conditional_t<std::is_signed_v<T>, math::Vector2Signed<T>, math::Vector2Unsigned<T>>>;

		value_type Origin{};
		value_type Direction{ T(0), T(1) };

		constexpr Line2Real()noexcept = default;
		INLINE constexpr Line2Real(value_type origin, value_type direction)noexcept
			:Origin(origin), Direction(direction) {  }

		INLINE void Set(value_type origin, value_type direction)noexcept
		{
			Origin = origin;
			Direction = direction;
		}
		
		NODISCARD INLINE constexpr bool IsNearlyEqual(const Line2Real& other,
														T tolerance = MATH_TOLERANCE<T>)const noexcept
		{
			return Origin.IsNearlyEqual(other.Origin, tolerance) && Direction.IsNearlyEqual(other.Direction, tolerance);
		}
		NODISCARD INLINE constexpr bool IsEqual(const Line2Real& other)const noexcept
		{
			return Origin.IsEqual(other.Origin) && Direction.IsEqual(other.Direction);
		}
		
		NODISCARD INLINE String ToString()const noexcept
		{ 
			return std::format("{}, {}", Origin.ToString(), Direction.ToString());
		}
	};

	template<class T>
	NODISCARD INLINE constexpr bool operator==(const Line2T<T>& left, const Line2T<T>& right)noexcept
	{
		return left.IsNearlyEqual(right);
	}
	template<class T>
	NODISCARD INLINE constexpr bool operator!=(const Line2T<T>& left, const Line2T<T>& right)noexcept
	{
		return !(left == right);
	}
}

namespace std
{
	template<class T>
	struct hash<greaper::math::Line2T<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Line2T<T>& s)const noexcept
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

CreateLine2Refl(greaper::math::Line2f);
CreateLine2Refl(greaper::math::Line2d);
CreateLine2Refl(greaper::math::Line2i);
CreateLine2Refl(greaper::math::Line2u);
#endif

#endif /* MATH_LINE2_HPP */