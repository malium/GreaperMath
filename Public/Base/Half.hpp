/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_HALF_HPP
#define MATH_HALF_HPP 1

#include "../MathPrerequisites.hpp"

namespace greaper::math
{
	class Half
	{
		int16 m_Value = 0;

		union Cvt
		{
			int32 i;
			decltype(m_Value) t;
		};
		
		void _Set(float v)
		{
			__m128 v1 = _mm_set_ss(v);
			__m128i v2 = _mm_cvtps_ph(v1, 0);
			int32 res = _mm_cvtsi128_si32(v2);
			Cvt u{ res };
			m_Value = u.t;
		}
		
	public:
		constexpr Half()noexcept = default;
		template<class T, typename std::enable_if<std::is_convertible_v<T, float>, bool>::type = false>
		INLINE explicit Half(T v)noexcept
		{
			Set(v);
		}
		template<class T, typename std::enable_if<std::is_convertible_v<T, float>, bool>::type = false>
		INLINE explicit operator T ()const noexcept
		{
			return static_cast<T>(Get());
		}

		template<class T, typename std::enable_if<std::is_convertible_v<T, float>, bool>::type = false>
		INLINE void Set(T v)noexcept
		{
			Set(static_cast<float>(v));
		}
		INLINE float Get()const noexcept
		{
			Cvt u{ m_Value };
			__m128i v1 = _mm_cvtsi32_si128(u.i);
			__m128 v2 = _mm_cvtph_ps(v1);
			return _mm_cvtss_f32(v2);
		}
		INLINE int16 GetRaw()const noexcept
		{
			return m_Value;
		}
		INLINE void SetRaw(int16 rawValue)noexcept
		{
			m_Value = rawValue;
		}
	};

	INLINE constexpr bool operator==(const Half& left, const Half& right)noexcept
	{
		return left.GetRaw() == right.GetRaw();
	}
	
	INLINE constexpr bool operator!=(const Half& left, const Half& right)noexcept
	{
		return !(left == right);
	}
}

#if MATH_USE_GREAPER_REFLECTION
#include "../../../GreaperCore/Public/Reflection/PlainType.hpp"

namespace greaper::refl
{
	template<>
	struct PlainType<math::Half> : public BaseType<math::Half>
	{
		static inline constexpr TypeCategory_t Category = TypeCategory_t::Plain;
		
		REFL_CREATE_METHODS(math::Half);
		static std::expected<ReflectedSize_t, String> ToStream(const math::Half& data, IStream& stream)
		{ 
			ReflectedSize_t size = stream.Write(&data, sizeof(data));
			if(size == sizeof(data))
				return size;
			return std::unexpected(std::format("[refl::PlainType<Half>]::ToStream "
				"Failure while writing to stream, not all data was written, expected:{} obtained:{}.",
				sizeof(data), size));
		}
		static std::expected<ReflectedSize_t, String> FromStream(math::Half& data, IStream& stream)
		{ 
			ReflectedSize_t size = stream.Read(&data, sizeof(data));
			if(size == sizeof(data))
				return size;
			return std::unexpected(std::format("[refl::PlainType<Half>]::FromStream "
				"Failure while reading from stream, not all data was read, expected:{} obtained:{}.",
				sizeof(data), size));
		}
		
		static std::expected<cJSON*, String> ToJSON(const math::Half& data, cJSON* json, StringView name)
		{
			return PlainType<float>::ToJSON(data.Get(), json, name);
		}
		static std::expected<void, String> FromJSON(math::Half& data, cJSON* json, StringView name)
		{
			float temp;
			auto res = PlainType<float>::FromJSON(temp, json, name);
			if(!res.has_value())
				return res;
			data.Set(temp);
			return {};
		}
		static std::expected<String, String> ToString(const math::Half& data)
		{
			return PlainType<float>::ToString(data.Get());
		}

		static std::expected<ReflectedSize_t, String> GetDynamicSize(UNUSED const math::Half& data)
		{
			return 0ll; 
		}

		static std::expected<ReflectedSize_t, String> GetArraySize(UNUSED const math::Half& data)
		{
			return std::unexpected(
				"[refl::PlainType<Half>]::GetArraySize Trying to use a PlainType for array operations!");
		}

		static std::expected<void, String> SetArraySize(UNUSED math::Half& data, UNUSED ReflectedSize_t size)
		{
			return std::unexpected(
				"[refl::PlainType<Half>]::SetArraySize Trying to use a PlainType for array operations!");
		}

		static std::expected<const ArrayValueType*, String> GetArrayValue(UNUSED const math::Half& data,                      
			UNUSED ReflectedSize_t index)
		{
			return std::unexpected(
				"[refl::PlainType<Half>]::GetArrayValue Trying to use a PlainType for array operations!");
		}

		static std::expected<void, String> SetArrayValue(UNUSED math::Half& data, UNUSED const ArrayValueType& value,         
			UNUSED ReflectedSize_t index)
		{
			return std::unexpected(
				"[refl::PlainType<Half>]::SetArrayValue Trying to use a PlainType for array operations!");
		}
	};
}
#endif

#endif /* MATH_HALF_HPP */