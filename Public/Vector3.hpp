/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_VECTOR3_HPP
#define MATH_VECTOR3_HPP 1

#include "Vector2.hpp"

#include "Base/Vector3Real.inl"
#include "Base/Vector3Signed.inl"
#include "Base/Vector3Unsigned.inl"
#include "Base/Vector3b.inl"
#include "Reflection/MathAsContainer.hpp"

ReflectAsContainer(greaper::math::Vector3f, 	greaper::refl::RTI_Vector3f);
ReflectAsContainer(greaper::math::Vector3d, 	greaper::refl::RTI_Vector3d);
ReflectAsContainer(greaper::math::Vector3i, 	greaper::refl::RTI_Vector3i);
ReflectAsContainer(greaper::math::Vector3i8, 	greaper::refl::RTI_Vector3i8);
ReflectAsContainer(greaper::math::Vector3i16, 	greaper::refl::RTI_Vector3i16);
ReflectAsContainer(greaper::math::Vector3i64, 	greaper::refl::RTI_Vector3i64);
ReflectAsContainer(greaper::math::Vector3u, 	greaper::refl::RTI_Vector3u);
ReflectAsContainer(greaper::math::Vector3u8, 	greaper::refl::RTI_Vector3u8);
ReflectAsContainer(greaper::math::Vector3u16, 	greaper::refl::RTI_Vector3u16);
ReflectAsContainer(greaper::math::Vector3u64, 	greaper::refl::RTI_Vector3u64);
ReflectAsContainer(greaper::math::Vector3b, 	greaper::refl::RTI_Vector3b);

#endif /* MATH_VECTOR3_HPP */