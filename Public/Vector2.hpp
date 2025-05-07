/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_VECTOR2_HPP
#define MATH_VECTOR2_HPP 1

#include "MathPrerequisites.hpp"

#include "Base/Vector2Real.inl"
#include "Base/Vector2Signed.inl"
#include "Base/Vector2Unsigned.inl"
#include "Base/Vector2b.inl"
#include "Reflection/MathAsContainer.hpp"

ReflectAsContainer(greaper::math::Vector2f, 	greaper::refl::RTI_Vector2f);
ReflectAsContainer(greaper::math::Vector2d, 	greaper::refl::RTI_Vector2d);
ReflectAsContainer(greaper::math::Vector2i, 	greaper::refl::RTI_Vector2i);
ReflectAsContainer(greaper::math::Vector2i8, 	greaper::refl::RTI_Vector2i8);
ReflectAsContainer(greaper::math::Vector2i16, 	greaper::refl::RTI_Vector2i16);
ReflectAsContainer(greaper::math::Vector2i64, 	greaper::refl::RTI_Vector2i64);
ReflectAsContainer(greaper::math::Vector2u, 	greaper::refl::RTI_Vector2u);
ReflectAsContainer(greaper::math::Vector2u8, 	greaper::refl::RTI_Vector2u8);
ReflectAsContainer(greaper::math::Vector2u16, 	greaper::refl::RTI_Vector2u16);
ReflectAsContainer(greaper::math::Vector2u64, 	greaper::refl::RTI_Vector2u64);
ReflectAsContainer(greaper::math::Vector2b, 	greaper::refl::RTI_Vector2b);

#endif /* MATH_VECTOR2_HPP */