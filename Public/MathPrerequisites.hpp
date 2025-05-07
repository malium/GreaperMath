/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_PREREQUISITES_HPP
#define MATH_PREREQUISITES_HPP 1

#include "../../GreaperCore/Public/CorePrerequisites.hpp"

#ifndef MATH_USE_GREAPER_REFLECTION
#define MATH_USE_GREAPER_REFLECTION 1
#endif

namespace greaper::math
{
	template<class T> class Vector2Real;
	using Vector2f = Vector2Real<float>;
	using Vector2d = Vector2Real<double>;
	template<class T> class Vector2Signed;
	using Vector2i8 = Vector2Signed<int8>;
	using Vector2i16 = Vector2Signed<int16>;
	using Vector2i = Vector2Signed<int32>;
	using Vector2i64 = Vector2Signed<int64>;
	template<class T> class Vector2Unsigned;
	using Vector2u8 = Vector2Unsigned<uint8>;
	using Vector2u16 = Vector2Unsigned<uint16>;
	using Vector2u = Vector2Unsigned<uint32>;
	using Vector2u64 = Vector2Unsigned<uint64>;
	class Vector2b;

	template<class T> class Vector3Real;
	using Vector3f = Vector3Real<float>;
	using Vector3d = Vector3Real<double>;
	template<class T> class Vector3Signed;
	using Vector3i8 = Vector3Signed<int8>;
	using Vector3i16 = Vector3Signed<int16>;
	using Vector3i = Vector3Signed<int32>;
	using Vector3i64 = Vector3Signed<int64>;
	template<class T> class Vector3Unsigned;
	using Vector3u8 = Vector3Unsigned<uint8>;
	using Vector3u16 = Vector3Unsigned<uint16>;
	using Vector3u = Vector3Unsigned<uint32>;
	using Vector3u64 = Vector3Unsigned<uint64>;
	class Vector3b;

	template<class T> class Vector4Real;
	using Vector4f = Vector4Real<float>;
	using Vector4d = Vector4Real<double>;
	template<class T> class Vector4Signed;
	using Vector4i8 = Vector4Signed<int8>;
	using Vector4i16 = Vector4Signed<int16>;
	using Vector4i = Vector4Signed<int32>;
	using Vector4i64 = Vector4Signed<int64>;
	template<class T> class Vector4Unsigned;
	using Vector4u8 = Vector4Unsigned<uint8>;
	using Vector4u16 = Vector4Unsigned<uint16>;
	using Vector4u = Vector4Unsigned<uint32>;
	using Vector4u64 = Vector4Unsigned<uint64>;
	class Vector4b;

	template<class T> class Matrix2Real;
	using Matrix2f = Matrix2Real<float>;
	using Matrix2d = Matrix2Real<double>;
	template<class T> class Matrix3Real;
	using Matrix3f = Matrix3Real<float>;
	using Matrix3d = Matrix3Real<double>;
	template<class T> class Matrix43Real;
	using Matrix43f = Matrix43Real<float>;
	using Matrix43d = Matrix43Real<double>;
	template<class T> class Matrix4Real;
	using Matrix4f = Matrix4Real<float>;
	using Matrix4d = Matrix4Real<double>;
	
	class Matrix4SSE;

	template<class T> class QuaternionReal;
	using QuaternionF = QuaternionReal<float>;
	using QuaternionD = QuaternionReal<double>;

	template<class T> class Segment2T;
	using Segment2f = Segment2T<float>;
	using Segment2d = Segment2T<double>;
	using Segment2i = Segment2T<int32>;
	using Segment2u = Segment2T<uint32>;

	template<class T> class Segment3T;
	using Segment3f = Segment3T<float>;
	using Segment3d = Segment3T<double>;
	using Segment3i = Segment3T<int32>;
	using Segment3u = Segment3T<uint32>;

	template<class T> class Line2T;
	using Line2f = Line2T<float>;
	using Line2d = Line2T<double>;
	using Line2i = Line2T<int32>;
	using Line2u = Line2T<uint32>;

	template<class T> class Line3T;
	using Line3f = Line3T<float>;
	using Line3d = Line3T<double>;
	using Line3i = Line3T<int32>;
	using Line3u = Line3T<uint32>;

	template<class T> class RectT;
	using RectF = RectT<float>;
	using RectD = RectT<double>;
	using RectI = RectT<int32>;
	using RectU = RectT<uint32>;

	class Half;
}

namespace greaper
{
	using PropertyVector2f = TProperty<math::Vector2f>;
	using PropertyVector2i = TProperty<math::Vector2i>;
	using PropertyVector2u = TProperty<math::Vector2u>;

	using PropertyVector3f = TProperty<math::Vector3f>;
	using PropertyVector3i = TProperty<math::Vector3i>;
	using PropertyVector3u = TProperty<math::Vector3u>;

	using PropertyVector4f = TProperty<math::Vector4f>;
	using PropertyVector4i = TProperty<math::Vector4i>;
	using PropertyVector4u = TProperty<math::Vector4u>;

	using PropertyRectF = TProperty<math::RectF>;
	using PropertyRectI = TProperty<math::RectI>;
	using PropertyRectU = TProperty<math::RectU>;
}

namespace greaper::refl
{
	enum MathReflectedTypeID : ReflectedTypeID_t
	{
		// Math 
		RTI_Vector2f = 40,
		RTI_Vector2d,
		RTI_Vector2i,
		RTI_Vector2i8,
		RTI_Vector2i16,
		RTI_Vector2i64,
		RTI_Vector2u,
		RTI_Vector2u8,
		RTI_Vector2u16,
		RTI_Vector2u64,
		RTI_Vector2b,

		RTI_Vector3f,
		RTI_Vector3d,
		RTI_Vector3i,
		RTI_Vector3i8,
		RTI_Vector3i16,
		RTI_Vector3i64,
		RTI_Vector3u,
		RTI_Vector3u8,
		RTI_Vector3u16,
		RTI_Vector3u64,
		RTI_Vector3b,

		RTI_Vector4f,
		RTI_Vector4d,
		RTI_Vector4i,
		RTI_Vector4i8,
		RTI_Vector4i16,
		RTI_Vector4i64,
		RTI_Vector4u,
		RTI_Vector4u8,
		RTI_Vector4u16,
		RTI_Vector4u64,
		RTI_Vector4b,

		RTI_Matrix2f,
		RTI_Matrix2d,

		RTI_Matrix3f,
		RTI_Matrix3d,

		RTI_Matrix4f,
		RTI_Matrix4d,

		RTI_QuaternionF,
		RTI_QuaternionD,

		RTI_Segment2f,
		RTI_Segment2d,

		RTI_Segment3f,
		RTI_Segment3d,

		RTI_Line2f,
		RTI_Line2d,

		RTI_Line3f,
		RTI_Line3d,

		RTI_Half,

		RTI_RectF,
		RTI_RectD,
		RTI_RectI,
		RTI_RectU,
	};
}

CREATE_TYPEINFO_CNAME(greaper::math::Half, 			greaper::refl::RTI_Half,		PlainType, "Half");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2f,		greaper::refl::RTI_Vector2f,	ComplexType, "Vector2f");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2d,		greaper::refl::RTI_Vector2d,	ComplexType, "Vector2d");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2i,		greaper::refl::RTI_Vector2i,	ComplexType, "Vector2i");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2i8,		greaper::refl::RTI_Vector2i8,	ComplexType, "Vector2i8");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2i16,	greaper::refl::RTI_Vector2i16,	ComplexType, "Vector2i16");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2i64,	greaper::refl::RTI_Vector2i64,	ComplexType, "Vector2i64");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2u,		greaper::refl::RTI_Vector2u,	ComplexType, "Vector2u");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2u8,		greaper::refl::RTI_Vector2u8,	ComplexType, "Vector2u8");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2u16,	greaper::refl::RTI_Vector2u16,	ComplexType, "Vector2u16");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2u64,	greaper::refl::RTI_Vector2u64,	ComplexType, "Vector2u64");
CREATE_TYPEINFO_CNAME(greaper::math::Vector2b,		greaper::refl::RTI_Vector2b,	ComplexType, "Vector2b");

CREATE_TYPEINFO_CNAME(greaper::math::Vector3f,		greaper::refl::RTI_Vector3f,	ComplexType, "Vector3f");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3d,		greaper::refl::RTI_Vector3d,	ComplexType, "Vector3d");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3i,		greaper::refl::RTI_Vector3i,	ComplexType, "Vector3i");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3i8,		greaper::refl::RTI_Vector3i8,	ComplexType, "Vector3i8");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3i16,	greaper::refl::RTI_Vector3i16,	ComplexType, "Vector3i16");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3i64,	greaper::refl::RTI_Vector3i64,	ComplexType, "Vector3i64");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3u,		greaper::refl::RTI_Vector3u,	ComplexType, "Vector3u");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3u8,		greaper::refl::RTI_Vector3u8,	ComplexType, "Vector3u8");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3u16,	greaper::refl::RTI_Vector3u16,	ComplexType, "Vector3u16");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3u64,	greaper::refl::RTI_Vector3u64,	ComplexType, "Vector3u64");
CREATE_TYPEINFO_CNAME(greaper::math::Vector3b,		greaper::refl::RTI_Vector3b,	ComplexType, "Vector3b");

CREATE_TYPEINFO_CNAME(greaper::math::Vector4f,		greaper::refl::RTI_Vector4f,	ComplexType, "Vector4f");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4d,		greaper::refl::RTI_Vector4d,	ComplexType, "Vector4d");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4i,		greaper::refl::RTI_Vector4i,	ComplexType, "Vector4i");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4i8,		greaper::refl::RTI_Vector4i8,	ComplexType, "Vector4i8");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4i16,	greaper::refl::RTI_Vector4i16,	ComplexType, "Vector4i16");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4i64,	greaper::refl::RTI_Vector4i64,	ComplexType, "Vector4i64");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4u,		greaper::refl::RTI_Vector4u,	ComplexType, "Vector4u");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4u8,		greaper::refl::RTI_Vector4u8,	ComplexType, "Vector4u8");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4u16,	greaper::refl::RTI_Vector4u16,	ComplexType, "Vector4u16");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4u64,	greaper::refl::RTI_Vector4u64,	ComplexType, "Vector4u64");
CREATE_TYPEINFO_CNAME(greaper::math::Vector4b,		greaper::refl::RTI_Vector4b,	ComplexType, "Vector4b");

CREATE_TYPEINFO_CNAME(greaper::math::Matrix2f,		greaper::refl::RTI_Matrix2f,	ContainerType, "Matrix2f");
CREATE_TYPEINFO_CNAME(greaper::math::Matrix2d,		greaper::refl::RTI_Matrix2d,	ContainerType, "Matrix2d");

CREATE_TYPEINFO_CNAME(greaper::math::Matrix3f,		greaper::refl::RTI_Matrix3f,	ContainerType, "Matrix3f");
CREATE_TYPEINFO_CNAME(greaper::math::Matrix3d,		greaper::refl::RTI_Matrix3d,	ContainerType, "Matrix3d");

CREATE_TYPEINFO_CNAME(greaper::math::Matrix4f,		greaper::refl::RTI_Matrix4f,	ContainerType, "Matrix4f");
CREATE_TYPEINFO_CNAME(greaper::math::Matrix4d,		greaper::refl::RTI_Matrix4d,	ContainerType, "Matrix4d");

CREATE_TYPEINFO_CNAME(greaper::math::QuaternionF, 	greaper::refl::RTI_QuaternionF, ComplexType, "QuaternionF");
CREATE_TYPEINFO_CNAME(greaper::math::QuaternionD, 	greaper::refl::RTI_QuaternionD, ComplexType, "QuaternionD");

CREATE_TYPEINFO_CNAME(greaper::math::RectF, greaper::refl::RTI_RectF, ComplexType, "RectF");
CREATE_TYPEINFO_CNAME(greaper::math::RectD, greaper::refl::RTI_RectD, ComplexType, "RectD");
CREATE_TYPEINFO_CNAME(greaper::math::RectI, greaper::refl::RTI_RectI, ComplexType, "RectI");
CREATE_TYPEINFO_CNAME(greaper::math::RectU, greaper::refl::RTI_RectU, ComplexType, "RectU");

#ifndef MATH_USE_OPTIMIZATIONS
#define MATH_USE_OPTIMIZATIONS 1
#endif

#if COMPILER_MSVC
#include <intrin.h>
#else
#include <x86intrin.h>
#endif
#include <cmath>

namespace greaper::math
{
	namespace Impl
	{
		template<class T>
		struct TOLERANCE_t
		{
			static_assert(std::is_floating_point_v<T>);

			static constexpr T Value = 
#ifndef MATH_TOLERANCE_VAL
				T(0.0001);
#else
				T(MATH_TOLERANCE_VAL);
#endif
		};
		template<class T>
		struct PI_t
		{
			static_assert(std::is_floating_point_v<T>);
			static constexpr T Value = T(3.1415926535897932384626433832795);
		};
		template<class T>
		struct E_t
		{
			static_assert(std::is_floating_point_v<T>);
			static constexpr T Value = T(2.7182818284590452353602874713527);
		};
		template<class T>
		struct GoldenRatio_t
		{
			static_assert(std::is_floating_point_v<T>);
			static constexpr T Value = T(1.6180339887498948482045868343656);

		};
		template<class T>
		struct SqrtTwo_t
		{
			static_assert(std::is_floating_point_v<T>);
			static constexpr T Value = T(1.4142135623730950488016887242097);
		};
		template<class T>
		struct SqrtThree_t
		{
			static_assert(std::is_floating_point_v<T>);
			static constexpr T Value = T(1.7320508075688772935274463415059);
		};
		template<class T>
		struct MathRetType { using Type = void; };
		template<> struct MathRetType<float> { using Type = float; };
		template<> struct MathRetType<double> { using Type = double; };
		template<> struct MathRetType<long double> { using Type = long double; };
		template<> struct MathRetType<int8> { using Type = float; };
		template<> struct MathRetType<int16> { using Type = float; };
		template<> struct MathRetType<int32> { using Type = float; };
		template<> struct MathRetType<int64> { using Type = double; };
		template<> struct MathRetType<uint8> { using Type = float; };
		template<> struct MathRetType<uint16> { using Type = float; };
		template<> struct MathRetType<uint32> { using Type = float; };
		template<> struct MathRetType<uint64> { using Type = double; };

		template<class T>
		using MathRetType_t = typename MathRetType<T>::Type;
	}
	
	template<class T> constexpr inline T MATH_TOLERANCE = Impl::TOLERANCE_t<T>::Value;
	template<class T> constexpr inline T PI = Impl::PI_t<T>::Value;
	template<class T> constexpr inline T TWO_PI = T(2) * PI<T>;
	template<class T> constexpr inline T HALF_PI = T(0.5) * PI<T>;
	template<class T> constexpr inline T THREE_HALF_PI = T(3) * HALF_PI<T>;
	template<class T> constexpr inline T ONEFOURTH_PI = T(0.25) * PI<T>;
	template<class T> constexpr inline T ONEOVER_PI = T(1) / PI<T>;
	template<class T> constexpr inline T ONEOVER_TWOPI = T(1) / TWO_PI<T>;
	template<class T> constexpr inline T E = Impl::E_t<T>::Value;
	template<class T> constexpr inline T GOLDEN_RATIO = Impl::GoldenRatio_t<T>::Value;
	template<class T> constexpr inline T SQRT_TWO = Impl::SqrtTwo_t<T>::Value;
	template<class T> constexpr inline T SQRT_THREE = Impl::SqrtThree_t<T>::Value;
	template<class T> constexpr inline T SQRT_ONEOVERTWO = T(1) / Impl::SqrtTwo_t<T>::Value;
	template<class T> constexpr inline T SQRT_ONEOVERTHREE = T(1) / Impl::SqrtThree_t<T>::Value;
	template<class T> constexpr inline T DEG2RAD = PI<T> / T(180);
	template<class T> constexpr inline T RAD2DEG = T(180) * ONEOVER_PI<T>;
	template<class T> constexpr inline T EPSILON = std::numeric_limits<T>::epsilon();

	template<class T> constexpr T Pow(T base, T power)noexcept;

	/* Converts a floating point value into an integer with truncation towards zero. */
	template<class T>
	NODISCARD INLINE constexpr int32 TruncInt(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
#if MATH_USE_OPTIMIZATIONS
				return _mm_cvtt_ss2si(_mm_set_ss(val));
#else
				return static_cast<int32>(truncf(val));
#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
#if MATH_USE_OPTIMIZATIONS
				return _mm_cvttsd_si32(_mm_set_sd(val));
#else
				return static_cast<int32>(trunc(val));
#endif
			}
			else // long double
			{
				return static_cast<int32>(truncl(val));
			}
		}
		else // integral
		{
			return static_cast<int32>(val);
		}
	}
	/* Converts a floating point value into an integer64 with truncation towards zero. */
	template<class T>
	NODISCARD INLINE constexpr int64 TruncInt64(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
#if MATH_USE_OPTIMIZATIONS
				return _mm_cvttss_si64(_mm_set_ss(val));
#else
				return static_cast<int64>(truncf(val));
#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
#if MATH_USE_OPTIMIZATIONS
				return _mm_cvttsd_si64(_mm_set_sd(val));
#else
				return static_cast<int64>(truc(val));
#endif
			}
			else // long double
			{
				return static_cast<int64>(truncl(val));
			}
		}
		else // integral
		{
			return static_cast<int64>(val);
		}
	}
	/* Truncates towards zero a floating point value. */
	template<class T>
	NODISCARD INLINE constexpr T Trunc(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
				return static_cast<float>(TruncInt<float>(val));
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<double>(TruncInt64<double>(val));
			}
			else // long double
			{
				return static_cast<T>(truncl(val));
			}
		}
		else // integral
		{
			return val;
		}
	}
	/* Converts a float to the nearest less or equal integer */
	template<class T>
	NODISCARD INLINE int32 FloorInt(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
				// Slower than floorf
				/*
				auto sign = _mm_set_ps1(-0.f);
				auto one = _mm_set_ps1(1.f);
				auto maxValue = _mm_set_ps1(2147483648.f);

				auto f = _mm_set_ss(val);
				auto t = _mm_cvtepi32_ps(_mm_cvtps_epi32(f));
				auto r = _mm_sub_ss(t, _mm_and_ps(_mm_cmplt_ss(f, t), one));
				auto m = _mm_cmple_ss(maxValue, _mm_andnot_ps(sign, f));

				r = _mm_or_ps(_mm_andnot_ps(m, r), _mm_and_ps(m, f));

				return static_cast<int32>(_mm_cvtss_f32(r));
				*/
				// Slower than floorf
				// return _mm_cvt_ss2si(_mm_round_ss(_mm_setzero_ps(), _mm_set_ss(val), (_MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC)));
				// Faster than floorf, sometimes returns wrong values
				// return _mm_cvt_ss2si(_mm_set_ss(val + val - 0.5f)) >> 1;
//#if MATH_USE_OPTIMIZATIONS
//				return _mm_cvt_ss2si(_mm_set_ss(val + val - 0.5f)) >> 1;
//#else
				return static_cast<int32>(floorf(val));
//#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<int32>(floor(val));
			}
			else // long double
			{
				return static_cast<int32>(floorl(val));
			}
		}
		else // integral
		{
			return static_cast<int32>(val);
		}
	}
	/* Converts a float to the nearest less or equal integer64 */
	template<class T>
	NODISCARD INLINE constexpr int64 FloorInt64(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
//#if MATH_USE_OPTIMIZATIONS
//				return _mm_cvtss_si64(_mm_set_ss(val + val - 0.5f)) >> 1;
//#else
				return static_cast<int64>(floorf(val));
//#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
//#if MATH_USE_OPTIMIZATIONS
//				return _mm_cvtsd_si64(_mm_set_sd(val + val - 0.5f)) >> 1;
//#else
				return static_cast<int64>(floor(val));
//#endif
			}
			else // long double
			{
				return static_cast<int64>(floorl(val));
			}
		}
		else // integral
		{
			return static_cast<int64>(val);
		}
	}
	/* Converts a float to the nearest less or equal integer */
	template<class T>
	NODISCARD INLINE constexpr T Floor(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
				return static_cast<float>(FloorInt<float>(val));
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<double>(FloorInt64<double>(val));
			}
			else // long double
			{
				return static_cast<T>(floorl(val));
			}
		}
		else // integral
		{
			return val;
		}
	}
	/* Converts a float to the nearest integer. Rounds up when the fraction is .5 */
	template<class T>
	NODISCARD INLINE constexpr int32 RoundInt(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
//#if MATH_USE_OPTIMIZATIONS
//				return _mm_cvt_ss2si(_mm_set_ss(val + val + 0.5f)) >> 1;
//#else
				return FloorInt<float>(val + 0.5f);
//#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return FloorInt<double>(val + 0.5);
			}
			else // long double
			{
				return static_cast<int32>(roundl(val));
			}
		}
		else // integral
		{
			return static_cast<int32>(val);
		}
	}
	/* Converts a float to the nearest integer. Rounds up when the fraction is .5 */
	template<class T>
	NODISCARD INLINE constexpr int64 RoundInt64(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
//#if MATH_USE_OPTIMIZATIONS
//				return _mm_cvtss_si64(_mm_set_ss(val + val + 0.5f)) >> 1;
//#else
				return FloorInt64<float>(val + 0.5f);
//#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return FloorInt64<double>(val + 0.5);
			}
			else // long double
			{
				return static_cast<int64>(roundl(val));
			}
		}
		else // integral
		{
			return static_cast<int64>(val);
		}
	}
	/* Converts a float to the nearest integer. Rounds up when the fraction is .5 */
	template<class T>
	NODISCARD INLINE constexpr T Round(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
				return static_cast<float>(RoundInt<float>(val));
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<double>(RoundInt64<double>(val));
			}
			else // long double
			{
				return static_cast<T>(roundl(val));
			}
		}
		else // integral
		{
			return val;
		}
	}
	/* Converts a float to the nearest greater or equal integer */
	template<class T>
	NODISCARD INLINE constexpr int32 CeilInt(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
//#if MATH_USE_OPTIMIZATIONS
//				return -(_mm_cvt_ss2si(_mm_set_ss(-0.5f - (val + val))) >> 1);
//#else
				return static_cast<int32>(ceilf(val));
//#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<int32>(ceil(val));
			}
			else // long double
			{
				return static_cast<int32>(ceill(val));
			}
		}
		else // integral
		{
			return static_cast<int32>(val);
		}
	}
	/* Converts a float to the nearest greater or equal integer64 */
	template<class T>
	NODISCARD INLINE constexpr int64 CeilInt64(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
//#if MATH_USE_OPTIMIZATIONS
//				return -(_mm_cvt_ss2si(_mm_set_ss(-0.5f - (val + val))) >> 1);
//#else
				return static_cast<int64>(ceilf(val));
//#endif
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<int64>(ceil(val));
			}
			else // long double
			{
				return static_cast<int64>(ceill(val));
			}
		}
		else // integral
		{
			return static_cast<int64>(val);
		}
	}
	/* Converts a float to the nearest greater or equal integer */
	template<class T>
	NODISCARD INLINE constexpr T Ceil(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
			{
				return static_cast<float>(CeilInt<float>(val));
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				return static_cast<double>(CeilInt64<double>(val));
			}
			else // long double
			{
				return static_cast<T>(ceill(val));
			}
		}
		else // integral
		{
			return val;
		}
	}
	/* Returns the signed fractional part of a float */
	template<class T>
	NODISCARD INLINE constexpr T Fractional(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		return val - Trunc<T>(val);
	}
	/* Breaks the given value into an integer and a fractional part */
	template<class T>
	NODISCARD INLINE constexpr std::tuple<int32, T> Split(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		int32 i = TruncInt<T>(val);
		return { i, val - T(i) };
	}
	/* Breaks the given value into an integer and a fractional part */
	template<class T>
	NODISCARD INLINE constexpr std::tuple<int64, T> Split64(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		int64 i = TruncInt64<T>(val);
		return { i, val - T(i) };
	}
	/* Returns the modulus of two integers also on negative values */
	template<class T>
	NODISCARD INLINE constexpr T Modulus(T a, T b)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_integral_v<T>)
		{
			return ((a %= b) < T(0)) ? a + b : a;
		}
		else // is floating point
		{
			auto mod = Abs(a);
			auto bb = Abs(b);

			while (mod >= bb)
				mod -= bb;

			if (a < T(0))
				return (-mod) + b;
			return mod;
		}
	}
	/* Returns e^val */
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> Exp(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return expf(val);
			else if constexpr (std::is_same_v<T, double>)
				return exp(val);
			else // long double
				return expl(val);
		}
		else // integral
		{
			return Exp(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	/* Returns 2^val */
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> Exp2(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return exp2f(val);
			else if constexpr (std::is_same_v<T, double>)
				return exp2(val);
			else // long double
				return exp2l(val);
		}
		else // integral
		{
			return Pow(T(2), val);
		}
	}
	/* Returns ln(val) */
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> LogN(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return logf(val);
			else if constexpr (std::is_same_v<T, double>)
				return log(val);
			else // long double
				return logl(val);
		}
		else // integral
		{
			return LogN(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	/* Returns log[base](value) */
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> LogB(T base, T value)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return LogN(value) / LogN(base);
		else // integral
			return LogB(static_cast<Impl::MathRetType_t<T>>(base), static_cast<Impl::MathRetType_t<T>>(value));
	}
	/* Returns log2(val) */
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> Log2(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			static constexpr T ONEOVERLOG2 = T(1.4426950408889634073599246810019);
			return LogN(val) * ONEOVERLOG2;
		}
		else // integral
		{
			return Log2(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	/* Returns log10(val) */
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> Log10(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			static constexpr T ONEOVERLOG10 = T(0.43429448190325182765112891891661);
			return LogN(val) * ONEOVERLOG10;
		}
		else // integral
		{
			return Log10(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Sin(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return sinf(val);
			else if constexpr (std::is_same_v<T, double>)
				return sin(val);
			else // long double
				return sinl(val);
		}
		else // integral
		{
			return Sin(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ASin(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return asinf(val);
			else if constexpr (std::is_same_v<T, double>)
				return asin(val);
			else // long double
				return asinl(val);
		}
		else // integral
		{
			return ASin(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Sinh(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return sinhf(val);
			else if constexpr (std::is_same_v<T, double>)
				return sinh(val);
			else // long double
				return sinhl(val);
		}
		else // integral
		{
			return Sinh(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ASinh(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return asinhf(val);
			else if constexpr (std::is_same_v<T, double>)
				return asinh(val);
			else // long double
				return asinhl(val);
		}
		else // integral
		{
			return ASinh(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Cos(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return cosf(val);
			else if constexpr (std::is_same_v<T, double>)
				return cos(val);
			else // long double
				return cosl(val);
		}
		else // integral
		{
			return Cos(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ACos(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return acosf(val);
			else if constexpr (std::is_same_v<T, double>)
				return acos(val);
			else // long double
				return acosl(val);
		}
		else // integral
		{
			return ACos(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Cosh(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return coshf(val);
			else if constexpr (std::is_same_v<T, double>)
				return cosh(val);
			else // long double
				return coshl(val);
		}
		else // integral
		{
			return Cosh(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ACosh(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return acoshf(val);
			else if constexpr (std::is_same_v<T, double>)
				return acosh(val);
			else // long double
				return acoshl(val);
		}
		else // integral
		{
			return ACosh(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Tan(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return tanf(val);
			else if constexpr (std::is_same_v<T, double>)
				return tan(val);
			else // long double
				return tanl(val);
		}
		else // integral
		{
			return Tan(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ATan(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return atanf(val);
			else if constexpr (std::is_same_v<T, double>)
				return atan(val);
			else // long double
				return atanl(val);
		}
		else // integral
		{
			return ATan(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ATan2(T y, T x)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return atan2f(y, x);
			else if constexpr (std::is_same_v<T, double>)
				return atan2(y, x);
			else // long double
				return atan2l(y, x);
		}
		else // integral
		{
			return ATan2(static_cast<Impl::MathRetType_t<T>>(y), static_cast<Impl::MathRetType_t<T>>(x));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Tanh(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return tanhf(val);
			else if constexpr (std::is_same_v<T, double>)
				return tanh(val);
			else // long double
				return tanhl(val);
		}
		else // integral
		{
			return Tanh(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> ATanh(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return atanhf(val);
			else if constexpr (std::is_same_v<T, double>)
				return atanh(val);
			else // long double
				return atanhl(val);
		}
		else // integral
		{
			return ATanh(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE std::tuple<Impl::MathRetType_t<T>, Impl::MathRetType_t<T>> SinCos(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			T sin, cos;
			if constexpr (std::is_same_v<T, float>)
			{
				sincosf(val, &sin, &cos);
				return { sin, cos };
			}
			else if constexpr (std::is_same_v<T, double>)
			{
				sincos(val, &sin, &cos);
				return { sin, cos };
			}
			else // long double
			{
				sincosl(val, &sin, &cos);
				return { sin, cos };
			}
		}
		else // integral
		{
			return SinCos(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Cosecant(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return T(1) / Sin(val);
		else // integral
			return Cosecant(static_cast<Impl::MathRetType_t<T>>(val));
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Secant(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return T(1) / Cos(val);
		else // integral
			return Secant(static_cast<Impl::MathRetType_t<T>>(val));
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Cotangent(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return T(1) / Tan(val);
		else // integral
			return Cotangent(static_cast<Impl::MathRetType_t<T>>(val));
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Versine(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return T(1) - Cos(val);
		else // integral
			return Versine(static_cast<Impl::MathRetType_t<T>>(val));
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Coversine(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return T(1) - Sin(val);
		else // integral
			return Coversine(static_cast<Impl::MathRetType_t<T>>(val));
	}
	template<class T>
	NODISCARD INLINE Impl::MathRetType_t<T> SmoothCosZeroToOne(const T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		return Cos(static_cast<Impl::MathRetType_t<T>>(val) * PI<Impl::MathRetType_t<T>>) * Impl::MathRetType_t<T>(-0.5) + Impl::MathRetType_t<T>(0.5);
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> Sqrt(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
		{
			if constexpr (std::is_same_v<T, float>)
				return sqrtf(val);
			else if constexpr (std::is_same_v<T, double>)
				return sqrt(val);
			else // long double
				return sqrtl(val);
		}
		else // integral
		{
			return Sqrt(static_cast<Impl::MathRetType_t<T>>(val));
		}
	}
	template<class T> 
	NODISCARD INLINE constexpr T Pow(T base, T power)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr(std::is_integral_v<T>)
		{
			T r = base;
			while (power > 1)
			{
				r *= base;
				--power;
			}
			return r;
		}
		else // is floating point
		{
			if constexpr (std::is_same_v<T, float>)
				return powf(base, power);
			else if constexpr (std::is_same_v<T, double>)
				return pow(base, power);
			else // long double
				return powl(base, power);
		}
	}
	template<class T> 
	NODISCARD INLINE Impl::MathRetType_t<T> InvSqrt(T val)noexcept
	{
		static_assert(std::is_arithmetic_v<T>);
		if constexpr (std::is_floating_point_v<T>)
			return T(1) / Sqrt(val);
		else // integral
			return InvSqrt(static_cast<Impl::MathRetType_t<T>>(val));
	}
 	// Currently 1 / sqrt is faster than Carmack 
	/*NODISCARD INLINE float InvSqrtFast(float val)noexcept
	{
		float y = val;
		float y2 = val * 0.5f;
		int32 i = *reinterpret_cast<int32*>(&y);
		i = 0x5f3759df - (i >> 1);
		y = *reinterpret_cast<float*>(&i);
		y = y * (1.5f - (y2 * y * y));

#if 1
		y = y * (1.5f - (y2 * y * y));
#endif
		return y;
	}
	NODISCARD INLINE double InvSqrtFast(double val)noexcept
	{
		double y = val;
		double y2 = val * 0.5;
		int64 i = *reinterpret_cast<int64*>(&y);
		i = 0x5fe6eb50c7b537a9 - (i >> 1ull);
		y = *reinterpret_cast<double*>(&i);
		y = y * (1.5 - (y2 * y * y));

#if 1
		y = y * (1.5 - (y2 * y * y));
#endif
		return y;
	}*/
}

namespace greaper::math::SSE
{
	using Vector4f = __m128;
	using Vector4i = __m128i;
	using Vector2d = __m128d;

	/* Basic functions */
	INLINE Vector4f CreateV4f()noexcept
	{
		return _mm_setzero_ps();
	}
	
	INLINE Vector4f CreateV4f(float a)noexcept
	{
		return _mm_set_ps1(a);
	}
	
	INLINE Vector4f CreateV4f(float x, float y, float z, float w)noexcept
	{
		return _mm_set_ps(x, y, z, w);
	}
	
	INLINE Vector2d CreateV2d()noexcept
	{
		return _mm_setzero_pd();
	}
	
	INLINE Vector2d CreateV2d(double a)noexcept
	{
		return _mm_set_pd1(a);
	}
	
	INLINE Vector2d CreateV2d(double x, double y)noexcept
	{
		return _mm_set_pd(x, y);
	}
	
	INLINE Vector4i CreateV4i()noexcept
	{
		return _mm_setzero_si128();
	}
	
	INLINE Vector4i CreateV4i(int32 a)noexcept
	{
		return _mm_set1_epi32(a);
	}
	
	INLINE Vector4i CreateV4i(int32 x, int32 y, int32 z, int32 w)noexcept
	{
		return _mm_set_epi32(x, y, z, w);
	}
	
	INLINE std::tuple<float, float, float, float> Extract(Vector4f v)noexcept
	{
		alignas(16) float values[4];
		_mm_store_ps(values, v);
		return { values[0], values[1], values[2], values[3] };
	}
	
	INLINE std::tuple<double, double> Extract(Vector2d v)noexcept
	{
		alignas(16) double values[2];
		_mm_store_pd(values, v);
		return { values[0], values[1] };
	}
	
	INLINE std::tuple<int32, int32, int32, int32> Extract(Vector4i v)noexcept
	{
		std::tuple<int32, int32, int32, int32> values;
		
		std::get<0>(values) = _mm_extract_epi32(v, 0);
		std::get<1>(values) = _mm_extract_epi32(v, 1);
		std::get<2>(values) = _mm_extract_epi32(v, 2);
		std::get<3>(values) = _mm_extract_epi32(v, 3);
		return values;
	}
	
	/* Arithmetic */
	INLINE Vector4f Add(Vector4f left, Vector4f right)noexcept
	{
		return _mm_add_ps(left, right);
	}
	
	INLINE Vector2d Add(Vector2d left, Vector2d right)noexcept
	{
		return _mm_add_pd(left, right);
	}
	
	INLINE Vector4i Add(Vector4i left, Vector4i right)noexcept
	{
		return _mm_add_epi32(left, right);
	}
	
	INLINE Vector4f Sub(Vector4f left, Vector4f right)noexcept
	{
		return _mm_sub_ps(left, right);
	}
	
	INLINE Vector2d Sub(Vector2d left, Vector2d right)noexcept
	{
		return _mm_sub_pd(left, right);
	}
	
	INLINE Vector4i Sub(Vector4i left, Vector4i right)noexcept
	{
		return _mm_sub_epi32(left, right);
	}
	
	INLINE Vector4f Mul(Vector4f left, Vector4f right)noexcept
	{
		return _mm_mul_ps(left, right);
	}
	
	INLINE Vector2d Mul(Vector2d left, Vector2d right)noexcept
	{
		return _mm_mul_pd(left, right);
	}
	
	INLINE Vector4i Mul(Vector4i left, Vector4i right)noexcept
	{
		return _mm_mul_epi32(left, right);
	}
	
	INLINE Vector4f Mul(float left, Vector4f right)noexcept
	{
		return _mm_mul_ps(_mm_set_ps1(left), right);
	}
	
	INLINE Vector2d Mul(double left, Vector2d right)noexcept
	{
		return _mm_mul_pd(_mm_set_pd1(left), right);
	}
	
	INLINE Vector4i Mul(int32 left, Vector4i right)noexcept
	{
		return _mm_mul_epi32(_mm_set1_epi32(left), right);
	}
	
	INLINE Vector4f Mul(Vector4f left, float right)noexcept
	{
		return _mm_mul_ps(left, _mm_set_ps1(right));
	}
	
	INLINE Vector2d Mul(Vector2d left, double right)noexcept
	{
		return _mm_mul_pd(left, _mm_set_pd1(right));
	}
	
	INLINE Vector4i Mul(Vector4i left, int32 right)noexcept
	{
		return _mm_mul_epi32(left, _mm_set1_epi32(right));
	}

	INLINE Vector4f Div(Vector4f left, Vector4f right)noexcept
	{
		return _mm_div_ps(left, right);
	}

	INLINE Vector2d Div(Vector2d left, Vector2d right)noexcept
	{
		return _mm_div_pd(left, right);
	}

	INLINE Vector4i Div(Vector4i left, Vector4i right)noexcept
	{
		auto l = Extract(left);
		auto r = Extract(right);

		auto i0 = std::get<0>(l) / std::get<0>(r);
		auto i1 = std::get<1>(l) / std::get<1>(r);
		auto i2 = std::get<2>(l) / std::get<2>(r);
		auto i3 = std::get<3>(l) / std::get<3>(r);
		return CreateV4i(i0, i1, i2, i3);
	}

	INLINE Vector4f Div(float left, Vector4f right)noexcept
	{
		return _mm_div_ps(_mm_set_ps1(left), right);
	}

	INLINE Vector2d Div(double left, Vector2d right)noexcept
	{
		return _mm_div_pd(_mm_set_pd1(left), right);
	}
	
	INLINE Vector4i Div(int32 left, Vector4i right)noexcept
	{
		auto r = Extract(right);

		auto i0 = left / std::get<0>(r);
		auto i1 = left / std::get<1>(r);
		auto i2 = left / std::get<2>(r);
		auto i3 = left / std::get<3>(r);
		return CreateV4i(i0, i1, i2, i3);
	}

	INLINE Vector4f Div(Vector4f left, float right)noexcept
	{
		return Mul(left, 1.f / right);
	}

	INLINE Vector2d Div(Vector2d left, double right)noexcept
	{
		return Mul(left, 1.0 / right);
	}

	INLINE Vector4i Div(Vector4i left, int32 right)noexcept
	{
		auto l = Extract(left);

		auto i0 = std::get<0>(l) / right;
		auto i1 = std::get<1>(l) / right;
		auto i2 = std::get<2>(l) / right;
		auto i3 = std::get<3>(l) / right;
		return CreateV4i(i0, i1, i2, i3);
	}

	/* Comparision */
	INLINE bool Equal(Vector4f left, Vector4f right)noexcept
	{
		/*
		auto cmp = _mm_castps_si128(_mm_cmpeq_ps(left, right));
		auto res = _mm_movemask_epi8(cmp);
		*/
		return _mm_movemask_epi8(_mm_castps_si128(_mm_cmpeq_ps(left, right))) == 0xFFFF;
	}

	INLINE bool NearlyEqual(Vector4f left, Vector4f right, float tolerance = MATH_TOLERANCE<float>)noexcept
	{
		auto mask = _mm_set_ps1(-0.f);
		auto t = _mm_set_ps1(tolerance);

		auto f = _mm_sub_ps(left, right);
		auto abs = _mm_andnot_ps(mask, f);
		auto cmp = _mm_castps_si128(_mm_cmple_ps(abs, t));
		auto res = _mm_movemask_epi8(cmp);
		return res == 0xFFFF;
	}

	/* Vector functions */
	INLINE float DotProduct(Vector4f a, Vector4f b)noexcept
	{
#define DOTPRODUCT_VER 2
#if DOTPRODUCT_VER == 0 // Same speed as Vector4 implementation
		auto m = Mul(a, b);
		alignas(16) float values[4];
		_mm_store_ps(values, m);
		return values[0] + values[1] + values[2] + values[3];
#elif DOTPRODUCT_VER == 1 // Slower than the other implementations
		return _mm_cvtss_f32(_mm_dp_ps(a, b, 0xFF));
#elif DOTPRODUCT_VER == 2 // Faster than other implementations
		auto m0 = Mul(a, b);
		auto m1 = _mm_shuffle_ps(m0, m0, _MM_SHUFFLE(2, 3, 0, 1));
		m0 = Add(m0, m1);
		m1 = _mm_shuffle_ps(m0, m0, _MM_SHUFFLE(0, 1, 2, 3));
		m0 = Add(m0, m1);

		return _mm_cvtss_f32(m0);
#elif DOTPRODUCT_VER == 3 // A bit slower than Vector4 implementation
		auto m0 = Mul(a, b);
		m0 = _mm_hadd_ps(m0, m0);
		m0 = _mm_hadd_ps(m0, m0);
		return _mm_cvtss_f32(m0);
#endif
#undef DOTPRODUCT_VER
	}

	INLINE float LengthSquared(Vector4f v)noexcept
	{
		return DotProduct(v, v);
	}

	INLINE float Length(Vector4f v)noexcept
	{
		return Sqrt(LengthSquared(v));
	}

	INLINE float DistanceSquared(Vector4f a, Vector4f b)noexcept
	{
		auto t = Sub(a, b);
		auto m0 = Mul(t, t);
#define DISTANCE_VER 1
#if DISTANCE_VER == 0 // Faster than Vector4 implementation
		alignas(16) float values[4];
		_mm_store_ps(values, m0);
		return values[0] + values[1] + values[2] + values[3];
#elif DISTANCE_VER == 1 // A bit faster than VER 0 & 2
		auto m1 = _mm_shuffle_ps(m0, m0, _MM_SHUFFLE(2, 3, 0, 1));
		m0 = Add(m0, m1);
		m1 = _mm_shuffle_ps(m0, m0, _MM_SHUFFLE(0, 1, 2, 3));
		m0 = Add(m0, m1);

		return _mm_cvtss_f32(m0);
#elif DISTANCE_VER == 2 // Same speed as VER 0
		m0 = _mm_hadd_ps(m0, m0);
		m0 = _mm_hadd_ps(m0, m0);
		return _mm_cvtss_f32(m0);
#endif
#undef DISTANCE_VER
	}

	INLINE float Distance(Vector4f a, Vector4f b)noexcept
	{
		return Sqrt(DistanceSquared(a, b));
	}

	INLINE Vector4f Normalize(Vector4f v, float tolerance = MATH_TOLERANCE<float>)noexcept
	{
		auto lenSqrt = LengthSquared(v);
		if (lenSqrt > (tolerance * tolerance))
		{
			auto invScale = InvSqrt(lenSqrt);
			return Mul(v, _mm_set_ps1(invScale));
		}
		return v;
	}

	INLINE Vector4f Clamp(Vector4f val, float min, float max)noexcept
	{
		/*
		auto m0 = _mm_set_ps1(min);
		auto m1 = _mm_set_ps1(max);
		auto t0 = _mm_max_ps(val, m0);
		auto t1 = _mm_min_ps(t0, m1);
		return t1;
		*/
		return _mm_min_ps(_mm_max_ps(val, _mm_set_ps1(min)), _mm_set_ps1(max));
	}

	INLINE Vector4f Clamp(Vector4f val, Vector4f min, Vector4f max)noexcept
	{
		/*
		auto t0 = _mm_max_ps(val, min);
		auto t1 = _mm_min_ps(t0, max);
		return t1;
		*/
		return _mm_min_ps(_mm_max_ps(val, min), max);
	}

	INLINE Vector4f Sign(Vector4f v)noexcept
	{
		return _mm_and_ps(v, _mm_set_ps1(-0.f));
	}
}

#endif /* MATH_PREREQUISITES_HPP */