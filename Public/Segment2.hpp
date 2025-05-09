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
		using decimal = typename std::conditional_t<std::is_same_v<T, double>, double, float>;
		using vector = typename std::conditional_t<std::is_same_v<T, double>, Vector2d, Vector2f>;

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

		NODISCARD INLINE decimal Length()const noexcept
		{
			return vector((decimal)Begin.X, (decimal)Begin.Y).Distance(vector((decimal)End.X, (decimal)End.X));
		}
		NODISCARD INLINE constexpr vector GetDirectionWithMagnitude()const noexcept
		{
			return (vector((decimal)End.X, (decimal)End.Y) - vector((decimal)Begin.X, (decimal)Begin.Y));
		}
		NODISCARD INLINE vector GetDirection()const noexcept
		{
			return GetDirectionWithMagnitude().GetNormalized();
		}
		NODISCARD INLINE constexpr value_type PointAt(decimal segmentPCT)const noexcept
		{
			auto lrp = Lerp(vector((decimal)Begin.X, (decimal)Begin.Y),
				vector((decimal)End.X, (decimal)End.Y), segmentPCT);
			return value_type((T)lrp.X, (T)lrp.Y);
		}
		NODISCARD INLINE constexpr value_type PointAtUnclamped(decimal segmentPCT)const noexcept
		{
			auto lrp = LerpUnclamped(vector((decimal)Begin.X, (decimal)Begin.Y),
				vector((decimal)End.X, (decimal)End.Y), segmentPCT);
			return value_type((T)lrp.X, (T)lrp.Y);
		}
//		INLINE constexpr std::optional<vector> Intersects(const Segment2T<T>& other)const noexcept
//		{
//			std::tuple<bool, T, T> res = Impl::Line2LineIntersection(
//				vector((decimal)Begin.X, (decimal)Begin.Y), GetDirectionWithMagnitude(),
//				vector((decimal)other.Begin.X, (decimal)other.Begin.Y), other.GetDirectionWithMagnitude());
//				
//			if (std::get<0>(res))
//			{
//				T tA = std::get<1>(res);
//				T tB = std::get<2>(res);
//				Vector2Real<T> point = PointAtUnclamped(tA);
//				if(IsPointInside(point) && other.IsPointInside(point))
//					return Return::CreateSuccess(point);
//			}
//			return Return::CreateFailure<Vector2Real<T>>();
//		}
		template<class T, typename std::enable_if<std::is_floating_point_v<T>, bool>::type = false>
		NODISCARD INLINE constexpr bool IsNearlyEqual(const Segment2T<T>& other,
			T tolerance = MATH_TOLERANCE<T>)const noexcept
		{
			return Begin.IsNearlyEqual(other.Begin, tolerance) && End.IsNearlyEqual(other.End, tolerance);
		}
		
		NODISCARD INLINE constexpr bool IsEqual(const Segment2T<T>& other)const noexcept
		{
			return Begin.IsEqual(other.Begin) && End.IsEqual(other.End);
		}

		NODISCARD INLINE String ToString()const noexcept
		{ 
			return std::format("{}, {}", Origin.ToString(), Direction.ToString());
		}
	};

	template<class T>
	NODISCARD INLINE constexpr bool operator==(const Segment2T<T>& left, const Segment2T<T>& right)noexcept
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
	NODISCARD INLINE constexpr bool operator!=(const Segment2T<T>& left, const Segment2T<T>& right)noexcept
	{
		return !(left == right);
	}
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

#if MATH_USE_GREAPER_REFLECTION
#include "../../GreaperCore/Public/Reflection/ComplexType.hpp"
#define CreateSegment2Refl(segmenttype)                                                                                \
namespace greaper{template<>                                                                                           \
const Vector<std::shared_ptr<refl::IField>> refl::ComplexType<segmenttype>::Fields = {                                 \
std::make_shared<refl::TField<segmenttype::value_type>>("Begin"sv,                                                     \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const segmenttype*)obj)->Begin); },                                                       \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((segmenttype*)obj)->Begin = *((const segmenttype::value_type*)value); }),                                           \
std::make_shared<refl::TField<segmenttype::value_type>>("End"sv,                                                       \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const segmenttype*)obj)->End); },                                                         \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((segmenttype*)obj)->End = *((const segmenttype::value_type*)value); })};}                                           \

CreateSegment2Refl(greaper::math::Segment2f);
CreateSegment2Refl(greaper::math::Segment2d);
CreateSegment2Refl(greaper::math::Segment2i);
CreateSegment2Refl(greaper::math::Segment2u);

#endif
#endif /* MATH_SEGMENT2_HPP */