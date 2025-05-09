/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_SEGMENT3_HPP
#define MATH_SEGMENT3_HPP 1

#include "Vector3.hpp"

namespace greaper::math
{
	template<class T>
	class Segment3T
	{
		static_assert(std::is_floating_point_v<T>,
			"Segment3T can only be instanced with an integer or a floating point type.");
	public:
		using value_type = typename std::conditional_t<std::is_floating_point_v<T>, math::value_type, 
							std::conditional_t<std::is_signed_v<T>, math::Vector3Signed<T>, math::Vector3Unsigned<T>>>;
		using decimal = typename std::conditional_t<std::is_same_v<T, double>, double, float>;
		using vector = typename std::conditional_t<std::is_same_v<T, double>, Vector3d, Vector3f>;

		value_type Begin{};
		value_type End{};

		constexpr Segment3T()noexcept = default;
		INLINE constexpr Segment3T(value_type begin, value_type end)noexcept :Begin(begin), End(end) {  }

		INLINE void Set(value_type begin, value_type end)noexcept
		{
			Begin = begin;
			End = end;
		}
		INLINE void Set(const Segment3T& other)noexcept
		{
			Begin = other.Begin;
			End = other.End;
		}

		NODISCARD INLINE decimal Length()const noexcept
		{
			return vector((decimal)Begin.X, (decimal)Begin.Y, (decimal)Begin.Z).Distance(
				vector((decimal)End.X, (decimal)End.X, (decimal)End.Z));
		}
		NODISCARD INLINE constexpr vector GetDirectionWithMagnitude()const noexcept
		{
			return vector((decimal)End.X, (decimal)End.Y, (decimal)End.Z)
				- vector((decimal)Begin.X, (decimal)Begin.Y, (decimal)Begin.Z);
		}
		NODISCARD INLINE vector GetDirection()const noexcept
		{
			return GetDirectionWithMagnitude().GetNormalized();
		}
		NODISCARD INLINE constexpr value_type PointAt(T segmentPCT)const noexcept
		{
			auto lrp = Lerp(vector((decimal)Begin.X, (decimal)Begin.Y, (decimal)Begin.Z),
				vector((decimal)End.X, (decimal)End.Y, (decimal)End.Z), segmentPCT);
			return value_type((T)lrp.X, (T)lrp.Y, (T)lrp.Z);
		}
		NODISCARD INLINE constexpr value_type PointAtUnclamped(T segmentPCT)const noexcept
		{
			auto lrp = LerpUnclamped(vector((decimal)Begin.X, (decimal)Begin.Y, (decimal)Begin.Z),
				vector((decimal)End.X, (decimal)End.Y, (decimal)End.Z), segmentPCT);
			return value_type((T)lrp.X, (T)lrp.Y, (T)lrp.Z);
		}
//		NODISCARD INLINE constexpr bool IsPointInside(const value_type& point)const noexcept
//		{
//			value_type ba = End - Begin;
//			value_type ca = point - Begin;
//			T cross = ba.CrossProduct(ca);
//			if(!::IsNearlyEqual(cross, T(0), MATH_TOLERANCE<T>))
//				return false;
//			
//			T dot = ba.DotProduct(ca);
//			if(dot < T(0))
//				return false;
//			
//			T sqrtLengthBA = ba.LengthSquared();
//			return dot <= sqrtLengthBA;
//		}
//		INLINE constexpr TReturn<value_type> Intersects(const Segment3T<T>& other)const noexcept
//		{
//			std::tuple<bool, T, T> res = Impl::Line2LineIntersection(Begin, GetDirectionWithMagnitude(), other.Begin, other.GetDirectionWithMagnitude());
//			if (std::get<0>(res))
//			{
//				T tA = std::get<1>(res);
//				T tB = std::get<2>(res);
//				value_type point = PointAtUnclamped(tA);
//				if(IsPointInside(point) && other.IsPointInside(point))
//					return Return::CreateSuccess(point);
//			}
//			return Return::CreateFailure<value_type>();
//		}

		template<class T, typename std::enable_if<std::is_floating_point_v<T>, bool>::type = false>
		NODISCARD INLINE constexpr bool IsNearlyEqual(const Segment3T& other, T tolerance = MATH_TOLERANCE<T>)const noexcept
		{
			return Begin.IsNearlyEqual(other.Begin, tolerance) && End.IsNearlyEqual(other.End, tolerance);
		}
		NODISCARD INLINE constexpr bool IsEqual(const Segment3T& other)const noexcept
		{
			return Begin.IsEqual(other.Begin) && End.IsEqual(other.End);
		}

		NODISCARD INLINE String ToString()const noexcept
		{
			return std::format("{}, {}", Origin.ToString(), Direction.ToString());
		}
	};
	
	template<class T>
	NODISCARD INLINE constexpr bool operator==(const Segment3T<T>& left, const Segment3T<T>& right)noexcept
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
	NODISCARD INLINE constexpr bool operator!=(const Segment3T<T>& left, const Segment3T<T>& right)noexcept
	{
		return !(left == right);
	}
}

namespace std
{
	template<class T>
	struct hash<greaper::math::Segment3T<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Segment3T<T>& s)const noexcept
		{
			return ComputeHash(s.Begin, s.End);
		}
	};
}

#if MATH_USE_GREAPER_REFLECTION
#include "../../GreaperCore/Public/Reflection/ComplexType.hpp"
#define CreateSegment3Refl(segmenttype)                                                                                \
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

CreateSegment3Refl(greaper::math::Segment3f);
CreateSegment3Refl(greaper::math::Segment3d);
CreateSegment3Refl(greaper::math::Segment3i);
CreateSegment3Refl(greaper::math::Segment3u);

#endif
#endif /* MATH_SEGMENT3_HPP */