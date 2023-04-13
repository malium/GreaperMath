/***********************************************************************************
*   Copyright 2022 Marcos Sánchez Torrent.                                         *
*   All Rights Reserved.                                                           *
***********************************************************************************/

#pragma once

#ifndef MATH_RECT_H
#define MATH_RECT_H 1

#include "MathPrerequisites.h"
#include "../../GreaperCore/Public/StringUtils.h"
#include "Vector2.h"
#if PLT_WINDOWS
#include "../../GreaperCore/Public/Win/Win32Base.h"
#endif
#include "Base/IntersectionResult.h"

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
		String left = TCategory::ToString(Left);
		String top = TCategory::ToString(Top);
		String right = TCategory::ToString(Right);
		String bottom = TCategory::ToString(Bottom);
		return String{'[' + left + ", " + top + "](" + right + ", " + bottom + ')'};
	}

	template<class T>
	INLINE bool RectT<T>::FromString(const String& str) noexcept
	{
		const auto ltBegin = str.find_first_of('[');
		const auto ltEnd = str.find_first_of(']');
		const auto rbBegin = str.find_first_of('(');
		const auto rbEnd = str.find_last_of(')');

		if(ltBegin == String::npos || ltEnd == String::npos
			|| rbBegin == String::npos || rbEnd == String::npos)
		{
			return false; // Tokens not found
		}

		StringVec ltSplit = StringUtils::Tokenize(str.substr(ltBegin+1, ltEnd - ltBegin), ',');
		for(auto& s : ltSplit) StringUtils::TrimSelf(s);
		StringVec rbSplit = StringUtils::Tokenize(str.substr(rbBegin + 1, rbEnd - rbBegin), ',');
		for(auto& s : rbSplit) StringUtils::TrimSelf(s);

		if(ltSplit.size() != 2 || rbSplit.size() != 2)
		{
			return false; // Wrong split size
		}
		
		if(TCategory::FromString(Left, ltSplit[0]).HasFailed()) 
			return false;
		if(TCategory::FromString(Top, ltSplit[1]).HasFailed())
			return false;

		if(TCategory::FromString(Right, rbSplit[0]).HasFailed())
			return false;
		if(TCategory::FromString(Bottom, rbSplit[1]).HasFailed())
			return false;

		return true;
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

#endif /* MATH_RECT_H */