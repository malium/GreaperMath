/***********************************************************************************
*   Copyright 2022 Marcos Sánchez Torrent.                                         *
*   All Rights Reserved.                                                           *
***********************************************************************************/

#pragma once

#ifndef MATH_VECTOR3SIGNED_H
#define MATH_VECTOR3SIGNED_H 1

#include "Vector2Signed.inl"
#include "VecRef.h"

namespace greaper::math
{
	template<class T>
	class Vector3Signed
	{
		static_assert(std::is_integral_v<T> && !std::is_unsigned_v<T>, "Vector3Signed can only work with signed intXX types");

	public:
		static constexpr sizet ComponentCount = 3;
		using value_type = T;

		T X{ 0 };
		T Y{ 0 };
		T Z{ 0 };

		constexpr Vector3Signed()noexcept = default;
		INLINE constexpr Vector3Signed(T x, T y, T z)noexcept :X(x), Y(y), Z(z) {  }
		INLINE constexpr explicit Vector3Signed(const std::array<T, ComponentCount>& arr) : X(arr[0]), Y(arr[1]), Z(arr[2]) {  }
		INLINE constexpr explicit Vector3Signed(const Vector2Signed<T>& v2, T z)noexcept :X(v2.X), Y(v2.Y), Z(z) {  }
		INLINE constexpr Vector3Signed operator-()const noexcept { return { -X, -Y, -Z }; }

		NODISCARD INLINE constexpr T& operator[](sizet index)noexcept
		{
			VerifyLess(index, ComponentCount, "Trying to access a Vector3, but the index %" PRIuPTR " was out of range.", index);
			return (&X)[index];
		}
		NODISCARD INLINE constexpr const T& operator[](sizet index)const noexcept
		{
			VerifyLess(index, ComponentCount, "Trying to access a Vector3, but the index %" PRIuPTR " was out of range.", index);
			return (&X)[index];
		}
		DEF_SWIZZLE_VEC3();
		NODISCARD INLINE constexpr std::array<T, ComponentCount> ToArray()const noexcept
		{
			return { X, Y, Z };
		}
		INLINE void Set(const Vector3Signed& other)noexcept
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
		}
		INLINE void Set(T x, T y, T z)noexcept
		{
			X = x;
			Y = y;
			Z = z;
		}
		INLINE void SetZero()noexcept
		{
			X = T(0);
			Y = T(0);
			Z = T(0);
		}
		NODISCARD INLINE constexpr bool IsEqual(const Vector3Signed& other)const noexcept
		{
			return X == other.X && Y == other.Y && Z == other.Z;
		}
		NODISCARD INLINE constexpr bool IsZero()const noexcept
		{
			return IsEqual({ T(0), T(0), T(0) });
		}
		NODISCARD INLINE constexpr bool AreComponentsEqual()const noexcept
		{
			return X == Y && X == Z;
		}
		NODISCARD INLINE constexpr Vector3Signed GetAbs()const noexcept
		{
			return { ::Abs(X), ::Abs(Y), ::Abs(Z) };
		}
		NODISCARD INLINE constexpr T GetMaxComponent()const noexcept
		{
			return ::Max3(X, Y, Z);
		}
		NODISCARD INLINE constexpr T GetAbsMaxComponent()const noexcept
		{
			return ::Max3(::Abs(X), ::Abs(Y), ::Abs(Z));
		}
		NODISCARD INLINE constexpr T GetMinComponent()const noexcept
		{
			return ::Min3(X, Y, Z);
		}
		NODISCARD INLINE constexpr T GetAbsMinComponent()const noexcept
		{
			return ::Min3(::Abs(X), ::Abs(Y), ::Abs(Z));
		}
		NODISCARD INLINE constexpr Vector3Signed GetClampledAxes(T minAxeVal, T maxAxeVal)const noexcept
		{
			return Vector3Signed{
				::Clamp(X, minAxeVal, maxAxeVal),
				::Clamp(Y, minAxeVal, maxAxeVal),
				::Clamp(Z, minAxeVal, maxAxeVal)
			};
		}
		NODISCARD INLINE constexpr Vector3Signed GetClamped(const Vector3Signed& min, const Vector3Signed& max)const noexcept
		{
			return Vector3Signed{
				::Clamp(X, min.X, max.X),
				::Clamp(Y, min.Y, max.Y),
				::Clamp(Z, min.Z, max.Z)
			};
		}
		NODISCARD INLINE constexpr Vector3Signed GetSignVector()const noexcept
		{
			return Vector3Signed{ ::Sign(X), ::Sign(Y), ::Sign(Z) };
		}
		NODISCARD INLINE String ToString()const noexcept
		{
			return Format(Impl::Vec3Conv<T>::print, X, Y, Z);
		}
		INLINE void FromString(StringView str)noexcept
		{
			sscanf(str.data(), Impl::Vec3Conv<T>::scan, &X, &Y, &Z);
		}

		static const Vector3Signed ZERO;
		static const Vector3Signed UNIT;
		static const Vector3Signed UP;
		static const Vector3Signed DOWN;
		static const Vector3Signed LEFT;
		static const Vector3Signed RIGHT;
		static const Vector3Signed FRONT;
		static const Vector3Signed BACK;
	};

	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::ZERO = Vector3Signed<T>{};
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::UNIT = Vector3Signed<T>((T)1, (T)1, (T)1);
	
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::UP 		= Vector3Signed<T>((T)0,  (T)1,  (T)0);
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::DOWN 	= Vector3Signed<T>((T)0,  (T)-1, (T)0);
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::LEFT 	= Vector3Signed<T>((T)-1, (T)0,  (T)0);
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::RIGHT 	= Vector3Signed<T>((T)1,  (T)0,  (T)0);
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::FRONT 	= Vector3Signed<T>((T)0,  (T)0,  (T)1);
	template<class T> inline const Vector3Signed<T> Vector3Signed<T>::BACK 	= Vector3Signed<T>((T)0,  (T)0,  (T)-1);

	template<class T> NODISCARD INLINE constexpr Vector3Signed<T> operator+(const Vector3Signed<T>& left, const Vector3Signed<T>& right)noexcept { return Vector3Signed<T>{ left.X + right.X, left.Y + right.Y, left.Z + right.Z }; }
	template<class T> NODISCARD INLINE constexpr Vector3Signed<T> operator-(const Vector3Signed<T>& left, const Vector3Signed<T>& right)noexcept { return Vector3Signed<T>{ left.X - right.X, left.Y - right.Y, left.Z - right.Z }; }
	template<class T> INLINE Vector3Signed<T>& operator+=(Vector3Signed<T>& left, const Vector3Signed<T>& right)noexcept { left.X += right.X; left.Y += right.Y; left.Z += right.Z; return left; }
	template<class T> INLINE Vector3Signed<T>& operator-=(Vector3Signed<T>& left, const Vector3Signed<T>& right)noexcept { left.X -= right.X; left.Y -= right.Y; left.Z -= right.Z; return left; }

	template<class T> NODISCARD INLINE constexpr Vector3Signed<T> operator*(const Vector3Signed<T>& left, T right)noexcept { return Vector3Signed<T>{ left.X* right, left.Y* right, left.Z* right }; }
	template<class T> NODISCARD INLINE constexpr Vector3Signed<T> operator/(const Vector3Signed<T>& left, T right)noexcept { return Vector3Signed<T>{ left.X / right, left.Y / right, left.Z / right }; }
	template<class T> NODISCARD INLINE constexpr Vector3Signed<T> operator*(T left, const Vector3Signed<T>& right)noexcept { return Vector3Signed<T>{ left* right.X, left* right.Y, left* right.Z }; }
	template<class T> INLINE Vector3Signed<T>& operator*=(Vector3Signed<T>& left, T right)noexcept { left.X *= right; left.Y *= right; left.Z *= right; return left; }
	template<class T> INLINE Vector3Signed<T>& operator/=(Vector3Signed<T>& left, T right)noexcept { left.X /= right; left.Y /= right; left.Z /= right; return left; }

	template<class T> NODISCARD INLINE constexpr bool operator==(const Vector3Signed<T>& left, const Vector3Signed<T>& right)noexcept { return left.IsEqual(right); }
	template<class T> NODISCARD INLINE constexpr bool operator!=(const Vector3Signed<T>& left, const Vector3Signed<T>& right)noexcept { return !(left == right); }
}

#define INSTANTIATE_VEC3S_UTILS(type)\
template<> NODISCARD INLINE constexpr greaper::math::Vector3Signed<type> Abs<greaper::math::Vector3Signed<type>>(const greaper::math::Vector3Signed<type> a)noexcept{\
	return a.GetAbs();\
}\
template<> NODISCARD INLINE constexpr greaper::math::Vector3Signed<type> Clamp<greaper::math::Vector3Signed<type>>(const greaper::math::Vector3Signed<type> a, const greaper::math::Vector3Signed<type> min, const greaper::math::Vector3Signed<type> max)noexcept{\
	return a.GetClamped(min, max);\
}\
template<> NODISCARD INLINE constexpr greaper::math::Vector3Signed<type> Sign<greaper::math::Vector3Signed<type>>(const greaper::math::Vector3Signed<type> a)noexcept{\
	return a.GetSignVector();\
}

INSTANTIATE_VEC3S_UTILS(int8);
INSTANTIATE_VEC3S_UTILS(int16);
INSTANTIATE_VEC3S_UTILS(int32);
INSTANTIATE_VEC3S_UTILS(int64);

#undef INSTANTIATE_VEC3S_UTILS

namespace std
{
	template<class T>
	struct hash<greaper::math::Vector3Signed<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Vector3Signed<T>& v)const noexcept
		{
			return ComputeHash(v.X, v.Y, v.Z);
		}
	};
}

#endif /* MATH_VECTOR3SIGNED_H */