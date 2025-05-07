/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_MATRIX3_HPP
#define MATH_MATRIX3_HPP 1

#include "Vector3.hpp"
#include "Matrix2.hpp"

namespace greaper::math
{
	template<class T>
	class Matrix3Real
	{
		static_assert(std::is_floating_point_v<T>, "Matrix3Real can only work with float, double or long double types");

	public:
		using value_type = T;
		using vector_type = Vector3Real<value_type>;

		static constexpr sizet RowCount = 3;
		static constexpr sizet ColumnCount = 3;
		static constexpr sizet ComponentCount = RowCount * ColumnCount;

		vector_type R0, R1, R2;

		constexpr Matrix3Real()noexcept = default;
		INLINE constexpr Matrix3Real(value_type r00, value_type r01, value_type r02, value_type r10, value_type r11,
										value_type r12, value_type r20, value_type r21, value_type r22)noexcept
			:R0(r00, r01, r02), R1(r10, r11, r12), R2(r20, r21, r22) {  }
		INLINE constexpr explicit Matrix3Real(const std::array<value_type, ComponentCount>& arr)noexcept
			:R0(arr[0], arr[1], arr[2]), R1(arr[3], arr[4], arr[5]), R2(arr[6], arr[7], arr[8]) {  }
		INLINE constexpr Matrix3Real(const vector_type& r0, const vector_type& r1,
										const vector_type& r2)noexcept
			:R0(r0), R1(r1), R2(r2) {  }
		INLINE constexpr explicit Matrix3Real(const Matrix2Real<value_type>& m2)noexcept
			:R0(m2.R0, value_type(0)), R1(m2.R1, value_type(0)), R2(value_type(0), value_type(0), value_type(1)) {  }
			
		NODISCARD INLINE explicit operator value_type*() noexcept
		{
			return reinterpret_cast<value_type*>(this);
		}

		NODISCARD INLINE explicit operator const value_type*()const noexcept
		{
			return reinterpret_cast<const value_type*>(this);
		}

		NODISCARD INLINE explicit operator vector_type*() noexcept
		{
			return reinterpret_cast<vector_type*>(this);
		}

		NODISCARD INLINE explicit operator const vector_type*()const noexcept
		{
			return reinterpret_cast<const vector_type*>(this);
		}

		NODISCARD INLINE value_type& operator[](sizet index)noexcept
		{
			VerifyLess(index, ComponentCount, std::format(                                                             \
				"Trying to access a Matrix3, but the index {} was out of range.", index));
			return ((value_type*)(this))[index];
		}
		NODISCARD INLINE constexpr const value_type& operator[](sizet index)const noexcept
		{
			VerifyLess(index, ComponentCount, std::format(                                                             \
				"Trying to access a Matrix3, but the index {} was out of range.", index));
			return ((const value_type*)(this))[index];
		}

		NODISCARD INLINE std::array<value_type&, vector_type::ComponentCount> C0()noexcept
		{
			return { R0.X, R1.X, R2.X };
		}
		NODISCARD INLINE std::array<const value_type&, vector_type::ComponentCount> C0()const noexcept
		{
			return { R0.X, R1.X, R2.X };
		}
		NODISCARD INLINE std::array<value_type&, vector_type::ComponentCount> C1()noexcept
		{
			return { R0.Y, R1.Y, R2.Y };
		}
		NODISCARD INLINE std::array<const value_type&, vector_type::ComponentCount> C1()const noexcept
		{
			return { R0.Y, R1.Y, R2.Y };
		}
		NODISCARD INLINE std::array<value_type&, vector_type::ComponentCount> C2()noexcept
		{
			return { R0.Z, R1.Z, R2.Z };
		}
		NODISCARD INLINE std::array<const value_type&, vector_type::ComponentCount> C2()const noexcept
		{
			return { R0.Z, R1.Z, R2.Z };
		}
		NODISCARD INLINE constexpr std::array<value_type, ComponentCount> ToArray()const noexcept
		{
			return { R0.X, R0.Y, R0.Z, R1.X, R1.Y, R1.Z, R2.X, R2.Y, R2.Z };
		}
		INLINE void Set(const Matrix3Real& other)noexcept
		{
			R0 = other.R0;
			R1 = other.R1;
			R2 = other.R2;
		}
		INLINE void Set(value_type r00, value_type r01, value_type r02, value_type r10, value_type r11, value_type r12,
						value_type r20, value_type r21, value_type r22)noexcept
		{
			R0.Set(r00, r01, r02);
			R1.Set(r10, r11, r12);
			R2.Set(r20, r21, r22);
		}
		INLINE void Set(const vector_type& r0, const vector_type& r1, const vector_type& r2)noexcept
		{
			R0 = r0;
			R1 = r1;
			R2 = r2;
		}
		INLINE void SetZero()noexcept
		{
			R0.Zero();
			R1.Zero();
			R2.Zero();
		}
		INLINE void SetIdentity()noexcept
		{
			R0.Set(value_type(1), value_type(0), value_type(0));
			R1.Set(value_type(0), value_type(1), value_type(0));
			R2.Set(value_type(0), value_type(0), value_type(1));
		}
		INLINE constexpr value_type Determinant()const noexcept
		{
			return R0.X * Matrix2Real<value_type>{R1.Y, R1.Z, R2.Y, R2.Z}.Determinant() 
				- R0.Y * Matrix2Real<value_type>{R1.X, R1.Z, R2.X, R2.Z}.Determinant() 
				+ R0.Z * Matrix2Real<value_type>{R1.X, R1.Y, R2.X, R2.Y}.Determinant();
		}
		NODISCARD INLINE constexpr Matrix3Real GetTransposed()const noexcept
		{
			return {	R0.X, R1.X, R2.X,
						R0.Y, R1.Y, R2.Y,
						R0.Z, R1.Z, R2.Z };
		}
		INLINE void Transpose()noexcept
		{
			Set(GetTransposed());
		}
		NODISCARD INLINE constexpr Matrix3Real GetAdjoint()const noexcept
		{
			auto r0c0 = Matrix2Real<value_type>{R1.Y, R1.Z, R2.Y, R2.Z}.Determinant();
			auto r0c1 = Matrix2Real<value_type>{R1.X, R1.Z, R2.X, R2.Z}.Determinant();
			auto r0c2 = Matrix2Real<value_type>{R1.X, R1.Y, R2.X, R2.Y}.Determinant();

			auto r1c0 = Matrix2Real<value_type>{R0.Y, R0.Z, R2.Y, R2.Z}.Determinant();
			auto r1c1 = Matrix2Real<value_type>{R0.X, R0.Z, R2.X, R2.Z}.Determinant();
			auto r1c2 = Matrix2Real<value_type>{R0.X, R0.Y, R2.X, R2.Y}.Determinant();

			auto r2c0 = Matrix2Real<value_type>{R0.Y, R0.Z, R1.Y, R1.Z}.Determinant();
			auto r2c1 = Matrix2Real<value_type>{R0.X, R0.Z, R1.X, R1.Z}.Determinant();
			auto r2c2 = Matrix2Real<value_type>{R0.X, R0.Y, R1.X, R1.Y}.Determinant();

			return Matrix3Real {
				 r0c0, -r0c1,  r0c2,
				-r1c0,  r1c1, -r1c2,
				 r2c0, -r2c1,  r2c2
			};
		}
		NODISCARD INLINE constexpr Matrix3Real GetInverted()const noexcept
		{
			value_type determinant = Determinant();
			if (::IsNearlyEqual(determinant, value_type(0)))
				return *this; // No inverse

			value_type invDeterminant = value_type(1) / determinant;
			Matrix3Real inv = GetAdjoint().GetTransposed();
			return {
				inv.R0 * invDeterminant,
				inv.R1 * invDeterminant,
				inv.R2 * invDeterminant
			};
		}
		INLINE void Inverse()noexcept
		{
			Set(GetInverted());
		}
		NODISCARD INLINE constexpr float Trace()const noexcept
		{
			return R0.X + R1.Y + R2.Z;
		}
		NODISCARD INLINE constexpr bool IsNearlyEqual(const Matrix3Real& other,
														value_type tolerance = MATH_TOLERANCE<value_type>)const noexcept
		{
			return R0.IsNearlyEqual(other.R0, tolerance) && R1.IsNearlyEqual(other.R1, tolerance)
				&& R2.IsNearlyEqual(other.R2, tolerance);
		}
		NODISCARD INLINE constexpr bool IsEqual(const Matrix3Real& other)const noexcept
		{
			return R0.IsEqual(other.R0) && R1.IsEqual(other.R1) && R2.IsEqual(other.R2);
		}
		NODISCARD INLINE constexpr bool IsNearlyZero(value_type tolerance = MATH_TOLERANCE<value_type>)const noexcept
		{
			return IsNearlyEqual({
				value_type(0), value_type(0), value_type(0),
				value_type(0), value_type(0), value_type(0),
				value_type(0), value_type(0), value_type(0)
			}, tolerance);
		}
		NODISCARD INLINE constexpr bool IsZero()const noexcept
		{
			return IsEqual({
				value_type(0), value_type(0), value_type(0),
				value_type(0), value_type(0), value_type(0),
				value_type(0), value_type(0), value_type(0)
			});
		}
		NODISCARD INLINE constexpr bool IsNearlyIdentity(value_type tolerance =MATH_TOLERANCE<value_type>)const noexcept
		{
			return IsNearlyEqual({
				value_type(1),value_type(0), value_type(0),
				value_type(0), value_type(1), value_type(0),
				value_type(0), value_type(0), value_type(1)
			}, tolerance);
		}
		NODISCARD INLINE constexpr bool IsIdentity()const noexcept
		{
			return IsEqual({
				value_type(1), value_type(0), value_type(0),
				value_type(0), value_type(1), value_type(0),
				value_type(0), value_type(0), value_type(1)
			});
		}
		NODISCARD INLINE constexpr bool IsNearlySymmetric(value_type tolerance=MATH_TOLERANCE<value_type>)const noexcept
		{
			return ::IsNearlyEqual(R1.X, R0.Y, tolerance)
				&& ::IsNearlyEqual(R1.Z, R2.Y, tolerance)
				&& ::IsNearlyEqual(R2.X, R0.Z, tolerance);
		}
		NODISCARD INLINE constexpr bool IsSymmetric()const noexcept
		{
			return R1.X == R0.Y 
				&& R1.Z == R2.Y
				&& R2.X == R0.Z;
		}
		NODISCARD INLINE constexpr bool IsNearlyDiagonal(value_type tolerance =MATH_TOLERANCE<value_type>)const noexcept
		{
			return ::IsNearlyEqual(R0.Y, value_type(0), tolerance)
				&& ::IsNearlyEqual(R0.Z, value_type(0), tolerance)
				&& ::IsNearlyEqual(R1.X, value_type(0), tolerance)
				&& ::IsNearlyEqual(R1.Z, value_type(0), tolerance)
				&& ::IsNearlyEqual(R2.X, value_type(0), tolerance)
				&& ::IsNearlyEqual(R2.Y, value_type(0), tolerance);
		}
		NODISCARD INLINE constexpr bool IsDiagonal()const noexcept
		{
			return R0.Y == value_type(0)
				&& R0.Z == value_type(0)
				&& R1.X == value_type(0)
				&& R1.Z == value_type(0)
				&& R2.X == value_type(0)
				&& R2.Y == value_type(0);
		}
		NODISCARD INLINE String ToString()const noexcept
		{
			return std::format("{}, {}, {}, {}, {}, {}, {}, {}, {}",
				R0.X, R0.Y, R0.Z, R1.X, R1.Y, R1.Z, R2.X, R2.Y, R2.Z);
		}

		static const Matrix3Real IDENTITY;
		static const Matrix3Real ZERO;
	};

	template<class T> const Matrix3Real<T> Matrix3Real<T>::IDENTITY = { T(1), T(0), T(0),
																		T(0), T(1), T(0), 
																		T(0), T(0), T(1) };
	template<class T> const Matrix3Real<T> Matrix3Real<T>::ZERO = {  };

	template<class T>
	NODISCARD INLINE constexpr Matrix3Real<T> operator+(const Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		return { left.R0 + right.R0, left.R1 + right.R1, left.R2 + right.R2 };
	}
	template<class T>
	NODISCARD INLINE constexpr Matrix3Real<T> operator-(const Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		return { left.R0 - right.R0, left.R1 - right.R1, left.R2 - right.R2 };
	}
	template<class T>
	NODISCARD INLINE constexpr Matrix3Real<T> operator*(const Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		auto r0c0 = left.R0.X * right.R0.X + left.R0.Y * right.R1.X + left.R0.Z * right.R2.X;
		auto r0c1 = left.R0.X * right.R0.Y + left.R0.Y * right.R1.Y + left.R0.Z * right.R2.Y;
		auto r0c2 = left.R0.X * right.R0.Z + left.R0.Y * right.R1.Z + left.R0.Z * right.R2.Z;

		auto r1c0 = left.R1.X * right.R0.X + left.R1.Y * right.R1.X + left.R1.Z * right.R2.X;
		auto r1c1 = left.R1.X * right.R0.Y + left.R1.Y * right.R1.Y + left.R1.Z * right.R2.Y;
		auto r1c2 = left.R1.X * right.R0.Z + left.R1.Y * right.R1.Z + left.R1.Z * right.R2.Z;

		auto r2c0 = left.R2.X * right.R0.X + left.R2.Y * right.R1.X + left.R2.Z * right.R2.X;
		auto r2c1 = left.R2.X * right.R0.Y + left.R2.Y * right.R1.Y + left.R2.Z * right.R2.Y;
		auto r2c2 = left.R2.X * right.R0.Z + left.R2.Y * right.R1.Z + left.R2.Z * right.R2.Z;
		return Matrix3Real {
			r0c0, r0c1, r0c2,
		   	r1c0, r1c1, r1c2,
			r2c0, r2c1, r2c2
	   };
	}
	template<class T>
	INLINE Matrix3Real<T>& operator*=(Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		left = (left * right); return left;
	}
	template<class T>
	NODISCARD INLINE constexpr Vector3Real<T> operator*(const Vector3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		return {
			left.X * right.R0.X + left.Y * right.R0.Y + left.Z * right.R0.Z,
			left.X * right.R1.X + left.Y * right.R1.Y + left.Z * right.R1.Z, 
			left.X * right.R2.X + left.Y * right.R2.Y + left.Z * right.R2.Z 
		};
	}
	template<class T>
	INLINE Vector3Real<T>& operator*=(Vector3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		left = (left * right); return left;
	}
	template<class T>
	NODISCARD INLINE constexpr Vector3Real<T> operator*(const Matrix3Real<T>& left, const Vector3Real<T>& right)noexcept
	{
		return {
			left.R0.X * right.X + left.R0.Y * right.Y + left.R0.Z * right.Z,
			left.R1.X * right.X + left.R1.Y * right.Y + left.R1.Z * right.Z,
			left.R2.X * right.X + left.R2.Y * right.Y + left.R2.Z * right.Z
		};
	}

	template<class T>
	INLINE Matrix3Real<T> operator+=(Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		left.R0 += right.R0; left.R1 += right.R1; left.R2 += right.R2; return left;
	}
	template<class T>
	INLINE Matrix3Real<T> operator-=(Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		left.R0 -= right.R0; left.R1 -= right.R1; left.R2 -= right.R2; return left;
	}
	template<class T>
	INLINE Matrix3Real<T> operator*=(Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		left = (left * right); return left;
	}

	template<class T>
	NODISCARD INLINE constexpr Matrix3Real<T> operator*(const Matrix3Real<T>& left, T right)noexcept
	{
		return { left.R0 * right, left.R1 * right, left.R2 * right };
	}
	template<class T>
	INLINE Matrix3Real<T> operator*=(Matrix3Real<T>& left, T right)noexcept
	{
		left.R0 *= right; left.R1 *= right; left.R2 *= right; return left;
	}
	template<class T>
	NODISCARD INLINE constexpr Matrix3Real<T> operator*(T left, const Matrix3Real<T>& right)noexcept
	{
		return { right.R0 * left, right.R1 * left, right.R2 * left };
	}

	template<class T>
	NODISCARD INLINE constexpr bool operator==(const Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		return left.IsNearlyEqual(right);
	}
	template<class T>
	NODISCARD INLINE constexpr bool operator!=(const Matrix3Real<T>& left, const Matrix3Real<T>& right)noexcept
	{
		return !(left == right);
	}
}

namespace std
{
	template<class T>
	struct hash<greaper::math::Matrix3Real<T>>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Matrix3Real<T>& m)const noexcept
		{
			return ComputeHash(m.R0, m.R1, m.R2);
		}
	};
}

ReflectAsContainer(greaper::math::Matrix3f, 	greaper::refl::RTI_Matrix3f);
ReflectAsContainer(greaper::math::Matrix3d, 	greaper::refl::RTI_Matrix3d);

#endif /* MATH_MATRIX3_HPP */