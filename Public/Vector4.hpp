/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_VECTOR4_HPP
#define MATH_VECTOR4_HPP 1

#include "MathPrerequisites.hpp"

#include "Base/Vector4Real.inl"
#include "Base/Vector4Signed.inl"
#include "Base/Vector4Unsigned.inl"
#include "Base/Vector4b.inl"

#if MATH_USE_GREAPER_REFLECTION
#include "../../GreaperCore/Public/Reflection/ComplexType.hpp"

#define CreateVec4Refl(vectype)                                                                                        \
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
{ ((vectype*)obj)->Y = *((const vectype::value_type*)value); }),                                                       \
std::make_shared<refl::TField<vectype::value_type>>("Z"sv,                                                             \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const vectype*)obj)->Z); },                                                               \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((vectype*)obj)->Z = *((const vectype::value_type*)value); }),                                                       \
std::make_shared<refl::TField<vectype::value_type>>("W"sv,                                                             \
(std::function<const void* (const void*)>)[](const void* obj) ->                                                       \
	const void* { return &(((const vectype*)obj)->W); },                                                               \
(std::function<void(void*, const void*)>)[](void* obj, const void* value)                                              \
{ ((vectype*)obj)->W = *((const vectype::value_type*)value); })};}

CreateVec4Refl(greaper::math::Vector4f);
CreateVec4Refl(greaper::math::Vector4d);
CreateVec4Refl(greaper::math::Vector4i);
CreateVec4Refl(greaper::math::Vector4i8);
CreateVec4Refl(greaper::math::Vector4i16);
CreateVec4Refl(greaper::math::Vector4i64);
CreateVec4Refl(greaper::math::Vector4u);
CreateVec4Refl(greaper::math::Vector4u8);
CreateVec4Refl(greaper::math::Vector4u16);
CreateVec4Refl(greaper::math::Vector4u64);
CreateVec4Refl(greaper::math::Vector4b);

#undef CreateVec4Refl

#endif

#endif /* MATH_VECTOR4_HPP */