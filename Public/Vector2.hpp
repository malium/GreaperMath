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

#if MATH_USE_GREAPER_REFLECTION
#include "../../GreaperCore/Public/Reflection/ComplexType.hpp"
#define CreateVec2Refl(vectype)                                                                                        \
namespace greaper{template<>                                                                                           \
const Vector<std::shared_ptr<refl::IField>> refl::ComplexType<vectype>::Fields = {                                     \
std::make_shared<refl::TField<vectype::value_type>>("X"sv,                                                             \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const vectype*)obj)->X); },                                                               \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((vectype*)obj)->X = *((const vectype::value_type*)value); }),                                                       \
std::make_shared<refl::TField<vectype::value_type>>("Y"sv,                                                             \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const vectype*)obj)->Y); },                                                               \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((vectype*)obj)->Y = *((const vectype::value_type*)value); })};}                                                     \


CreateVec2Refl(greaper::math::Vector2f);
CreateVec2Refl(greaper::math::Vector2d);
CreateVec2Refl(greaper::math::Vector2i);
CreateVec2Refl(greaper::math::Vector2i8);
CreateVec2Refl(greaper::math::Vector2i16);
CreateVec2Refl(greaper::math::Vector2i64);
CreateVec2Refl(greaper::math::Vector2u);
CreateVec2Refl(greaper::math::Vector2u8);
CreateVec2Refl(greaper::math::Vector2u16);
CreateVec2Refl(greaper::math::Vector2u64);
CreateVec2Refl(greaper::math::Vector2b);

#undef CreateVec2Refl

#endif

#endif /* MATH_VECTOR2_HPP */