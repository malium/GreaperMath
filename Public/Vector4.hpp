/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_VECTOR4_HPP
#define MATH_VECTOR4_HPP 1

#include "Vector3.hpp"

#include "Base/Vector4Real.inl"
#include "Base/Vector4Signed.inl"
#include "Base/Vector4Unsigned.inl"
#include "Base/Vector4b.inl"
#include "Reflection/MathAsContainer.hpp"

ReflectAsContainer(greaper::math::Vector4f, 	greaper::refl::RTI_Vector4f);
ReflectAsContainer(greaper::math::Vector4d, 	greaper::refl::RTI_Vector4d);
ReflectAsContainer(greaper::math::Vector4i, 	greaper::refl::RTI_Vector4i);
ReflectAsContainer(greaper::math::Vector4i8, 	greaper::refl::RTI_Vector4i8);
ReflectAsContainer(greaper::math::Vector4i16, 	greaper::refl::RTI_Vector4i16);
ReflectAsContainer(greaper::math::Vector4i64, 	greaper::refl::RTI_Vector4i64);
ReflectAsContainer(greaper::math::Vector4u, 	greaper::refl::RTI_Vector4u);
ReflectAsContainer(greaper::math::Vector4u8, 	greaper::refl::RTI_Vector4u8);
ReflectAsContainer(greaper::math::Vector4u16, 	greaper::refl::RTI_Vector4u16);
ReflectAsContainer(greaper::math::Vector4u64, 	greaper::refl::RTI_Vector4u64);
ReflectAsContainer(greaper::math::Vector4b, 	greaper::refl::RTI_Vector4b);

#endif /* MATH_VECTOR4_HPP */