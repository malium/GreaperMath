/***********************************************************************************
*   Copyright 2022 Marcos Sánchez Torrent.                                         *
*   All Rights Reserved.                                                           *
***********************************************************************************/

#pragma once

#ifndef MATH_STRINGCONVERSION_H
#define MATH_STRINGCONVERSION_H 1

#include "../MathPrerequisites.h"

namespace greaper::math::Impl
{
	template<class T>
	struct Vec2Conv { };
	template<> struct Vec2Conv<int8> { static constexpr auto print = "%" PRIi8 ", %" PRIi8; static constexpr auto scan = "%" SCNi8 ", %" SCNi8; };
	template<> struct Vec2Conv<uint8> { static constexpr auto print = "%" PRIu8 ", %" PRIu8; static constexpr auto scan = "%" SCNu8 ", %" SCNu8; };
	template<> struct Vec2Conv<int16> { static constexpr auto print = "%" PRIi16 ", %" PRIi16; static constexpr auto scan = "%" SCNi16 ", %" SCNi16; };
	template<> struct Vec2Conv<uint16> { static constexpr auto print = "%" PRIu16 ", %" PRIu16; static constexpr auto scan = "%" SCNu16 ", %" SCNu16; };
	template<> struct Vec2Conv<int32> { static constexpr auto print = "%" PRIi32 ", %" PRIi32; static constexpr auto scan = "%" SCNi32 ", %" SCNi32; };
	template<> struct Vec2Conv<uint32> { static constexpr auto print = "%" PRIu32 ", %" PRIu32; static constexpr auto scan = "%" SCNu32 ", %" SCNu32; };
	template<> struct Vec2Conv<int64> { static constexpr auto print = "%" PRIi64 ", %" PRIi64; static constexpr auto scan = "%" SCNi64 ", %" SCNi64; };
	template<> struct Vec2Conv<uint64> { static constexpr auto print = "%" PRIu64 ", %" PRIu64; static constexpr auto scan = "%" SCNu64 ", %" SCNu64; };
	template<> struct Vec2Conv<float> { static constexpr auto print = "%f, %f"; static constexpr auto scan = "%f, %f"; };
	template<> struct Vec2Conv<double> { static constexpr auto print = "%lf, %lf"; static constexpr auto scan = "%lf, %lf"; };
	template<> struct Vec2Conv<long double> { static constexpr auto print = "%Lf, %Lf"; static constexpr auto scan = "%Lf, %Lf"; };
	
	template<class T>
	struct Vec3Conv { };
	template<> struct Vec3Conv<int8> { static constexpr auto print = "%" PRIi8 ", %" PRIi8 ", %" PRIi8; static constexpr auto scan = "%" SCNi8 ", %" SCNi8 ", %" SCNi8; };
	template<> struct Vec3Conv<uint8> { static constexpr auto print = "%" PRIu8 ", %" PRIu8 ", %" PRIu8; static constexpr auto scan = "%" SCNu8 ", %" SCNu8 ", %" SCNu8; };
	template<> struct Vec3Conv<int16> { static constexpr auto print = "%" PRIi16 ", %" PRIi16 ", %" PRIi16; static constexpr auto scan = "%" SCNi16 ", %" SCNi16 ", %" SCNi16; };
	template<> struct Vec3Conv<uint16> { static constexpr auto print = "%" PRIu16 ", %" PRIu16 ", %" PRIu16; static constexpr auto scan = "%" SCNu16 ", %" SCNu16 ", %" SCNu16; };
	template<> struct Vec3Conv<int32> { static constexpr auto print = "%" PRIi32 ", %" PRIi32 ", %" PRIi32; static constexpr auto scan = "%" SCNi32 ", %" SCNi32 ", %" SCNi32; };
	template<> struct Vec3Conv<uint32> { static constexpr auto print = "%" PRIu32 ", %" PRIu32 ", %" PRIu32; static constexpr auto scan = "%" SCNu32 ", %" SCNu32 ", %" SCNu32; };
	template<> struct Vec3Conv<int64> { static constexpr auto print = "%" PRIi64 ", %" PRIi64 ", %" PRIi64; static constexpr auto scan = "%" SCNi64 ", %" SCNi64 ", %" SCNi64; };
	template<> struct Vec3Conv<uint64> { static constexpr auto print = "%" PRIu64 ", %" PRIu64 ", %" PRIu64; static constexpr auto scan = "%" SCNu64 ", %" SCNu64 ", %" SCNu64; };
	template<> struct Vec3Conv<float> { static constexpr auto print = "%f, %f, %f"; static constexpr auto scan = "%f, %f, %f"; };
	template<> struct Vec3Conv<double> { static constexpr auto print = "%lf, %lf, %lf"; static constexpr auto scan = "%lf, %lf, %lf"; };
	template<> struct Vec3Conv<long double> { static constexpr auto print = "%Lf, %Lf, %Lf"; static constexpr auto scan = "%Lf, %Lf, %Lf"; };
	
	template<class T>
	struct Vec4Conv { };
	template<> struct Vec4Conv<int8> { static constexpr auto print = "%" PRIi8 ", %" PRIi8 ", %" PRIi8 ", %" PRIi8; static constexpr auto scan = "%" SCNi8 ", %" SCNi8 ", %" SCNi8 ", %" SCNi8; };
	template<> struct Vec4Conv<uint8> { static constexpr auto print = "%" PRIu8 ", %" PRIu8 ", %" PRIu8 ", %" PRIu8; static constexpr auto scan = "%" SCNu8 ", %" SCNu8 ", %" SCNu8 ", %" SCNu8; };
	template<> struct Vec4Conv<int16> { static constexpr auto print = "%" PRIi16 ", %" PRIi16 ", %" PRIi16 ", %" PRIi16; static constexpr auto scan = "%" SCNi16 ", %" SCNi16 ", %" SCNi16 ", %" SCNi16; };
	template<> struct Vec4Conv<uint16> { static constexpr auto print = "%" PRIu16 ", %" PRIu16 ", %" PRIu16 ", %" PRIu16; static constexpr auto scan = "%" SCNu16 ", %" SCNu16 ", %" SCNu16 ", %" SCNu16; };
	template<> struct Vec4Conv<int32> { static constexpr auto print = "%" PRIi32 ", %" PRIi32 ", %" PRIi32 ", %" PRIi32; static constexpr auto scan = "%" SCNi32 ", %" SCNi32 ", %" SCNi32 ", %" SCNi32; };
	template<> struct Vec4Conv<uint32> { static constexpr auto print = "%" PRIu32 ", %" PRIu32 ", %" PRIu32 ", %" PRIu32; static constexpr auto scan = "%" SCNu32 ", %" SCNu32 ", %" SCNu32 ", %" SCNu32; };
	template<> struct Vec4Conv<int64> { static constexpr auto print = "%" PRIi64 ", %" PRIi64 ", %" PRIi64 ", %" PRIi64; static constexpr auto scan = "%" SCNi64 ", %" SCNi64 ", %" SCNi64 ", %" SCNi64; };
	template<> struct Vec4Conv<uint64> { static constexpr auto print = "%" PRIu64 ", %" PRIu64 ", %" PRIu64 ", %" PRIu64; static constexpr auto scan = "%" SCNu64 ", %" SCNu64 ", %" SCNu64 ", %" SCNu64; };
	template<> struct Vec4Conv<float> { static constexpr auto print = "%f, %f, %f, %f"; static constexpr auto scan = "%f, %f, %f, %f"; };
	template<> struct Vec4Conv<double> { static constexpr auto print = "%lf, %lf, %lf, %lf"; static constexpr auto scan = "%lf, %lf, %lf, %lf"; };
	template<> struct Vec4Conv<long double> { static constexpr auto print = "%Lf, %Lf, %Lf, %Lf"; static constexpr auto scan = "%Lf, %Lf, %Lf, %Lf"; };
}

#endif /* MATH_STRINGCONVERSION_H */
