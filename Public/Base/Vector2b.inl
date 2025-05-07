/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

namespace greaper::math
{
	class Vector2b
	{
	public:
		static constexpr sizet ComponentCount = 2;
		using value_type = bool;

		bool X{ false };
		bool Y{ false };

		constexpr Vector2b()noexcept = default;
		INLINE constexpr Vector2b(bool x, bool y)noexcept :X(x), Y(y) {  }
		INLINE constexpr explicit Vector2b(const std::array<bool, ComponentCount>& arr) : X(arr[0]), Y(arr[1]) {  }

		NODISCARD INLINE explicit operator value_type*() noexcept
		{
			return reinterpret_cast<value_type*>(this);
		}

		NODISCARD INLINE explicit operator const value_type*()const noexcept
		{
			return reinterpret_cast<const value_type*>(this);
		}

		NODISCARD INLINE constexpr bool& operator[](sizet index)
		{
			VerifyLess(index, ComponentCount, std::format(                                                             \
				"Trying to access a Vector2, but the index {} was out of range.", index));
			return (&X)[index];
		}
		NODISCARD INLINE constexpr const bool& operator[](sizet index)const
		{
			VerifyLess(index, ComponentCount, std::format(                                                             \
				"Trying to access a Vector2, but the index {} was out of range.", index));
			return (&X)[index];
		}
		NODISCARD INLINE constexpr std::array<bool, ComponentCount> ToArray()const noexcept
		{
			return { X, Y };
		}
		INLINE void Set(const Vector2b& other)noexcept
		{
			X = other.X;
			Y = other.Y;
		}
		INLINE void Set(bool x, bool y)noexcept
		{
			X = x;
			Y = y;
		}
		INLINE void SetZero()noexcept
		{
			X = false;
			Y = false;
		}
		NODISCARD INLINE constexpr bool IsEqual(const Vector2b& other)const noexcept
		{
			return X == other.X && Y == other.Y;
		}
		NODISCARD INLINE constexpr bool IsZero()const noexcept
		{
			return IsEqual({ false, false });
		}
		NODISCARD INLINE constexpr bool AreComponentsEqual()const noexcept
		{
			return X == Y;
		}
		NODISCARD INLINE String ToString()const noexcept
		{
			return std::format("{}, {}", X, Y);
		}

		static const Vector2b ZERO;
		static const Vector2b UNIT;
	};

	inline const Vector2b Vector2b::ZERO = Vector2b{};
	inline const Vector2b Vector2b::UNIT = Vector2b(true, true);

	NODISCARD INLINE constexpr bool operator==(const Vector2b& left, const Vector2b& right)noexcept
	{
		return left.IsEqual(right);
	}
	NODISCARD INLINE constexpr bool operator!=(const Vector2b& left, const Vector2b& right)noexcept
	{
		return !(left == right);
	}
}

namespace std
{
	template<>
	struct hash<greaper::math::Vector2b>
	{
		NODISCARD INLINE size_t operator()(const greaper::math::Vector2b& v)const noexcept
		{
			return ComputeHash(v.X, v.Y);
		}
	};
}
