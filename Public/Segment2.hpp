/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_SEGMENT2_HPP
#define MATH_SEGMENT2_HPP 1

#include "Vector2.hpp"

namespace greaper::math
{
	template<class T>
	class Segment2T
	{
		static_assert(std::is_arithmetic_v<T>,
			"Segment2T can only be instanced with an integer or a floating point type.");
	public:
		using value_type = typename std::conditional_t<std::is_floating_point_v<T>, math::Vector2Real<T>, 
							std::conditional_t<std::is_signed_v<T>, math::Vector2Signed<T>, math::Vector2Unsigned<T>>>;
		using decimal_rtn = typename std::conditional_t<std::is_same_v<T, double>, double, float>;
		using vector_rtn = typename std::conditional_t<std::is_same_v<T, double>, Vector2d, Vector2f>;

		value_type Begin{};
		value_type End{};

		constexpr Segment2T()noexcept = default;
		INLINE constexpr Segment2T(value_type begin, value_type end)noexcept :Begin(begin), End(end) {  }

		INLINE void Set(value_type begin, value_type end)noexcept
		{
			Begin = begin;
			End = end;
		}
		INLINE void Set(const Segment2T& other)noexcept
		{
			Begin = other.Begin;
			End = other.End;
		}

		NODISCARD INLINE T Length()const noexcept
		{
			return Begin.Distance(End);
		}
		NODISCARD INLINE constexpr vector_rtn GetDirectionWithMagnitude()const noexcept
		{
			return (End - Begin);
		}
		NODISCARD INLINE vector_rtn GetDirection()const noexcept
		{
			return GetDirectionWithMagnitude().GetNormalized();
		}
		NODISCARD INLINE constexpr value_type PointAt(T segmentPCT)const noexcept
		{
			return Lerp(Begin, End, segmentPCT);
		}
		NODISCARD INLINE constexpr value_type PointAtUnclamped(T segmentPCT)const noexcept
		{
			return LerpUnclamped(Begin, End, segmentPCT);
		}
		INLINE constexpr TReturn<Vector2Real<T>> Intersects(const Segment2Real<T>& other)const noexcept
		{
			std::tuple<bool, T, T> res = Impl::Line2LineIntersection(Begin, GetDirectionWithMagnitude(), other.Begin, other.GetDirectionWithMagnitude());
			if (std::get<0>(res))
			{
				T tA = std::get<1>(res);
				T tB = std::get<2>(res);
				Vector2Real<T> point = PointAtUnclamped(tA);
				if(IsPointInside(point) && other.IsPointInside(point))
					return Return::CreateSuccess(point);
			}
			return Return::CreateFailure<Vector2Real<T>>();
		}

		NODISCARD INLINE constexpr bool IsNearlyEqual(const Segment2T& other, T tolerance = MATH_TOLERANCE<T>)const noexcept
		{
			return Begin.IsNearlyEqual(other.Begin, tolerance) && End.IsNearlyEqual(other.End, tolerance);
		}
		NODISCARD INLINE constexpr bool IsEqual(const Segment2T& other)const noexcept
		{
			return Begin.IsEqual(other.Begin) && End.IsEqual(other.End);
		}
	};

	template<class T>
	NODISCARD INLINE constexpr bool operator==(const Segment2T<T>& left, const Segment2T<T>& right)noexcept { return left.IsNearlyEqual(right); }
	template<class T>
	NODISCARD INLINE constexpr bool operator!=(const Segment2T<T>& left, const Segment2T<T>& right)noexcept { return !(left == right); }
}

namespace std
{
	template<class T>
	struct hash<greaper::math::Segment2T<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Segment2T<T>& s)const noexcept
		{
			return ComputeHash(s.Begin, s.End);
		}
	};
}

#endif /* MATH_SEGMENT2_HPP */