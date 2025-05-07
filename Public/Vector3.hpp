/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once

#ifndef MATH_VECTOR3_HPP
#define MATH_VECTOR3_HPP 1

#include "MathPrerequisites.hpp"

#include "Base/Vector3Real.inl"
#include "Base/Vector3Signed.inl"
#include "Base/Vector3Unsigned.inl"
#include "Base/Vector3b.inl"

#if MATH_USE_GREAPER_REFLECTION
#include "../../GreaperCore/Public/Reflection/ComplexType.hpp"

#define CreateVec3Refl(vectype)                                                                                        \
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
{ ((vectype*)obj)->Z = *((const vectype::value_type*)value); })};}

CreateVec3Refl(greaper::math::Vector3f);
CreateVec3Refl(greaper::math::Vector3d);
CreateVec3Refl(greaper::math::Vector3i);
CreateVec3Refl(greaper::math::Vector3i8);
CreateVec3Refl(greaper::math::Vector3i16);
CreateVec3Refl(greaper::math::Vector3i64);
CreateVec3Refl(greaper::math::Vector3u);
CreateVec3Refl(greaper::math::Vector3u8);
CreateVec3Refl(greaper::math::Vector3u16);
CreateVec3Refl(greaper::math::Vector3u64);
CreateVec3Refl(greaper::math::Vector3b);

#undef CreateVec3Refl
#endif

#endif /* MATH_VECTOR3_HPP */