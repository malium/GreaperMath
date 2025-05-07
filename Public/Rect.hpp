/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_RECT_HPP
#define MATH_RECT_HPP 1

#include "Vector2.hpp"
#if PLT_WINDOWS
#include "../../GreaperCore/Public/Win/Win32Base.h"
#endif
#include "Base/IntersectionResult.hpp"

namespace greaper::math
{
	template<class T>
	class RectT
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "RectT can only be instanced with an integer or a floating point type.");

		using value_type = T;
		
		using point_type = typename std::conditional_t<std::is_floating_point_v<T>, math::Vector2Real<T>, 
							std::conditional_t<std::is_signed_v<T>, math::Vector2Signed<T>, math::Vector2Unsigned<T>>>;

		using TCategory = typename refl::TypeInfo<T>::Type;
		
		T Left = T(0);
		T Top = T(0);
		T Right = T(0);
		T Bottom = T(0);

		constexpr RectT() = default;
		constexpr RectT(T left, T top, T right, T bottom) noexcept;
		
		constexpr T GetWidth()const noexcept;
		constexpr T GetHeight()const noexcept;

		constexpr point_type GetSize()const noexcept;

		constexpr point_type GetLT()const noexcept;
		constexpr point_type GetRT()const noexcept;
		constexpr point_type GetLB()const noexcept;
		constexpr point_type GetRB()const noexcept;

		void Set(const RectT& other)noexcept;
		void Set(T left, T top, T right, T bottom) noexcept;

		constexpr IntersectionResult_t IsInside(T x, T y)const noexcept;
		constexpr IntersectionResult_t IsInside(const point_type& point)const noexcept;
		constexpr IntersectionResult_t IsInside(const RectT& other)const noexcept;

		constexpr T GetArea()const noexcept;
		constexpr bool IsEmpty()const noexcept;

		constexpr bool IsEqual(const RectT& other)const noexcept;

		String ToString()const noexcept;
		bool FromString(const String& str) noexcept;
#if PLT_WINDOWS
		INLINE constexpr explicit RectT(const RECT& rect)noexcept
		{
			Set((T)rect.left, (T)rect.top, (T)rect.right, (T)rect.bottom);
		}
		NODISCARD INLINE constexpr operator RECT()const noexcept { return ToRECT(); }
		INLINE void Set(const RECT& rect) noexcept
		{
			Set((T)rect.left, (T)rect.top, (T)rect.right, (T)rect.bottom);
		}
		NODISCARD INLINE constexpr RECT ToRECT()const noexcept
		{
			return RECT{
					(LONG)Left,
					(LONG)Top,
					(LONG)Right,
					(LONG)Bottom
				};
		}
		NODISCARD INLINE constexpr bool IsInside(const POINT& p)const noexcept
		{
			return IsInside((T)p.x, (T)p.y);
		}
#endif
	};

	template<class T> NODISCARD INLINE constexpr bool operator==(const RectT<T>& left, const RectT<T>& right) noexcept
	{
		return left.IsEqual(right);
	}
	template<class T> NODISCARD INLINE constexpr bool operator!=(const RectT<T>& left, const RectT<T>& right) noexcept
	{
		return !(left == right);
	}
	
	template<class T>
	INLINE constexpr RectT<T>::RectT(T left, T top, T right, T bottom) noexcept
	{
		Set(left, top, right, bottom);
	}

	template<class T>
	NODISCARD INLINE constexpr T RectT<T>::GetWidth()const noexcept
	{
		return Abs(Right - Left);
	}

	template<class T>
	NODISCARD INLINE constexpr T RectT<T>::GetHeight()const noexcept
	{
		return Abs(Bottom - Top);
	}

	template<class T>
	NODISCARD INLINE constexpr typename RectT<T>::point_type RectT<T>::GetSize() const noexcept
	{
		return point_type(GetWidth(), GetHeight());
	}

	template<class T>
	NODISCARD INLINE constexpr typename RectT<T>::point_type RectT<T>::GetLT() const noexcept
	{
		return point_type(Left, Top);
	}

	template<class T>
	NODISCARD INLINE constexpr typename RectT<T>::point_type RectT<T>::GetRT() const noexcept
	{
		return point_type(Right, Top);
	}

	template<class T>
	NODISCARD INLINE constexpr typename RectT<T>::point_type RectT<T>::GetLB() const noexcept
	{
		return point_type(Left, Bottom);
	}

	template<class T>
	NODISCARD INLINE constexpr typename RectT<T>::point_type RectT<T>::GetRB() const noexcept
	{
		return point_type(Right, Bottom);
	}

	template<class T>
	INLINE void RectT<T>::Set(const RectT& other) noexcept
	{
		memcpy(this, &other, sizeof(RectT<T>));
	}

	template<class T>
	INLINE void RectT<T>::Set(T left, T top, T right, T bottom) noexcept
	{
		Left = left;
		Top = top;
		Right = right;
		Bottom = bottom;

		if (Left > Right)
			std::swap(Left, Right);

		if (Top < Bottom)
			std::swap(Top, Bottom);
	}

	template<class T>
	NODISCARD INLINE constexpr IntersectionResult_t RectT<T>::IsInside(T x, T y)const noexcept
	{
		if(IsEmpty())
			return IntersectionResult_t::OUTSIDE;

		if(Left < x && Right > x && Top > y && Bottom < y)
			return IntersectionResult_t::FULLY_INSIDE;
		
		if(((Left == x || Right == x) && Top >= y && Bottom <= y) ||
			((Top == y || Bottom == y) && Left <= x && Right >= x))
			return IntersectionResult_t::ON_THE_EDGE;
		
		return IntersectionResult_t::OUTSIDE;
	}

	template<class T>
	NODISCARD INLINE constexpr IntersectionResult_t RectT<T>::IsInside(const point_type& point) const noexcept
	{
		return IsInside(point.X, point.Y);
	}

	template<class T>
	NODISCARD INLINE constexpr IntersectionResult_t RectT<T>::IsInside(const RectT<T>& other)const noexcept
	{
		if  (IsEmpty() || other.IsEmpty())
			return IntersectionResult_t::OUTSIDE;

		IntersectionResult_t ltInside = IsInside(other.GetLT());
		IntersectionResult_t lbInside = IsInside(other.GetLB());
		IntersectionResult_t rtInside = IsInside(other.GetRT());
		IntersectionResult_t rbInside = IsInside(other.GetRB());

		if (ltInside == IntersectionResult_t::FULLY_INSIDE &&
			lbInside == IntersectionResult_t::FULLY_INSIDE &&
			rtInside == IntersectionResult_t::FULLY_INSIDE &&
			rbInside == IntersectionResult_t::FULLY_INSIDE)
			return IntersectionResult_t::FULLY_INSIDE;
		
		if (ltInside == IntersectionResult_t::FULLY_INSIDE ||
			lbInside == IntersectionResult_t::FULLY_INSIDE ||
			rtInside == IntersectionResult_t::FULLY_INSIDE ||
			rbInside == IntersectionResult_t::FULLY_INSIDE)
			return IntersectionResult_t::PARTIALLY_INSIDE;
		
		if (ltInside == IntersectionResult_t::ON_THE_EDGE ||
			lbInside == IntersectionResult_t::ON_THE_EDGE ||
			rtInside == IntersectionResult_t::ON_THE_EDGE ||
			rbInside == IntersectionResult_t::ON_THE_EDGE)
			return IntersectionResult_t::ON_THE_EDGE;

		return IntersectionResult_t::OUTSIDE;
	}

	template<class T>
	NODISCARD INLINE constexpr T RectT<T>::GetArea()const noexcept
	{
		return GetWidth() * GetHeight();
	}

	template<class T>
	NODISCARD INLINE constexpr bool RectT<T>::IsEmpty() const noexcept
	{
		return GetArea() <= T(0);
	}

	template<class T>
	NODISCARD INLINE constexpr bool RectT<T>::IsEqual(const RectT& other)const noexcept
	{
		return Left == other.Left
			&& Top == other.Top
			&& Right == other.Right
			&& Bottom == other.Bottom;
	}
	
	template<class T>
	NODISCARD INLINE String RectT<T>::ToString()const noexcept
	{ 
		return std::format("{}, {}, {}, {}", Left, Top, Right, Bottom);
	}
}

namespace std
{
	template<class T>
	struct hash<greaper::math::RectT<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::RectT<T>& r)const noexcept
		{
			return ComputeHash(r.Left, r.Top, r.Right, r.Bottom);
		}
	};
}

#if MATH_USE_GREAPER_REFLECTION
#define CreateRectRefl(recttype)\
namespace greaper{template<>                                                                                           \
const Vector<std::shared_ptr<refl::IField>> refl::ComplexType<recttype>::Fields = {                                    \
std::make_shared<refl::TField<recttype::value_type>>("Left"sv,                                                         \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const recttype*)obj)->Left); },                                                           \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((recttype*)obj)->Left = *((const recttype::value_type*)value); }),                                                  \
std::make_shared<refl::TField<recttype::value_type>>("Top"sv,                                                          \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const recttype*)obj)->Top); },                                                            \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((recttype*)obj)->Top = *((const recttype::value_type*)value); }),                                                   \
std::make_shared<refl::TField<recttype::value_type>>("Right"sv,                                                        \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const recttype*)obj)->Right); },                                                          \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((recttype*)obj)->Right = *((const recttype::value_type*)value); }),                                                 \
std::make_shared<refl::TField<recttype::value_type>>("Bottom"sv,                                                       \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const recttype*)obj)->Bottom); },                                                         \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((recttype*)obj)->Bottom = *((const recttype::value_type*)value); })};}

CreateRectRefl(greaper::math::RectF);
CreateRectRefl(greaper::math::RectD);
CreateRectRefl(greaper::math::RectI);
CreateRectRefl(greaper::math::RectU);
#endif

#endif /* MATH_RECT_HPP */