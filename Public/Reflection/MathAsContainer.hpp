/***********************************************************************************************************************
 *                                   Copyright 2025 Marcos Sánchez Torrent (@malium)                                   *
 *                                               All Rights Reserved                                                   *
 **********************************************************************************************************************/

#pragma once
#ifndef MATH_REFLECTION_MATH_AS_CONTAINER_HPP
#define MATH_REFLECTION_MATH_AS_CONTAINER_HPP 1

#if MATH_USE_GREAPER_REFLECTION
#include "../../GreaperCore/Public/Reflection/ContainerType.hpp"

#define ReflectAsContainer(type, rti)                                                                                  \
namespace greaper::refl{                                                                                               \
template<class T>                                                                                                      \
struct ContainerType<type> : public BaseType<type>{                                                                    \
using Type = type;                                                                                                     \
using ArrayValueType = typename Type::value_type;                                                                      \
using ValueCat = typename TypeInfo_t<ArrayValueType>::Type;                                                            \
static_assert(!std::is_same_v<ValueCat, void>,                                                                         \
	"[refl::ContainerType<"#type">] Trying to use a Container with not refl value_type!");                             \
static inline constexpr ReflectedSize_t StaticSize = ValueCat::StaticSize * Type::ComponentCount;                      \
static inline constexpr ReflectedTypeID_t ID = rti;                                                                    \
static inline constexpr TypeCategory_t Category = TypeCategory_t::Container;                                           \
REFL_CREATE_METHODS(type);                                                                                             \
static std::expected<ReflectedSize_t, String> ToStream(const Type& data, IStream& stream) {                            \
	ReflectedSize_t size = 0;                                                                                          \
	size += stream.Write(data.data(), StaticSize);                                                                     \
	if (size == StaticSize)                                                                                            \
		return size;                                                                                                   \
	return std::unexpected(std::format("[refl::ContainerType<"#type">::ToStream] "                                     \
		"Failure while writing to stream, not all data was written, expected:{} obtained:{}.",                         \
		expectedSize, size)); }                                                                                        \
static std::expected<ReflectedSize_t, String> FromStream(Type& data, IStream& stream) {                                \
	ReflectedSize_t size = 0;                                                                                          \
	size += stream.Read(data.data(), StaticSize);                                                                      \
	if (size == StaticSize)                                                                                            \
		return size;                                                                                                   \
	return std::unexpected(std::format("[refl::ContainerType<"#type">::FromStream] "                                   \
		"Failure while reading from stream, not all data was read, expected:{} obtained:{}.",                          \
		expectedSize, size)); }                                                                                        \
static std::expected<cJSON*, String> ToJSON_Item(const Type& data) {                                                   \
	cJSON* arrayObject = cJSON_CreateArray();                                                                          \
	for (sizet i = 0; i < Type::ComponentCount; ++i) {                                                                 \
		auto res = ValueCat::ToJSON_Item(data[i]);                                                                     \
		if (!res.has_value())                                                                                          \
			return std::unexpected(res.error());                                                                       \
		cJSON_bool ok = cJSON_AddItemToArray(arrayObject, res.value());                                                \
		if (ok == 0)                                                                                                   \
			return std::unexpected(std::format("[refl::ContainerType<"#type">::ToJSON_Item] "                          \
				"Error while adding an item to the array, idx {}.", i)); }                                             \
	return arrayObject; }                                                                                              \
static std::expected<void, String> FromJSON_Item(Type& data, cJSON* arrayObject) {                                     \
	if (!cJSON_IsArray(arrayObject))                                                                                   \
		return std::unexpected("[refl::ContainerType<"#type">::FromJSON_Item] "                                        \
			"Couldn't obtain the value from json, the item was not an array.");                                        \
	sizet arraySize = cJSON_GetArraySize(arrayObject);                                                                 \
	if (arraySize != Type::ComponentCount)                                                                             \
		return std::unexpected(std::format("[refl::ContainerType<"#type">::FromJSON_Item] "                            \
			"Couldn't obtain the value from json, the array "                                                          \
			"have an expected size {} but obtained {}.", Type::ComponentCount, arraySize));                            \
	for (sizet i = 0; i < Type::ComponentCount; ++i) {                                                                 \
		cJSON* item = cJSON_GetArrayItem(arrayObject, i);                                                              \
		if (item == nullptr)                                                                                           \
			return std::unexpected(std::format("[refl::ContainerType<"#type">::FromJSON_Item] "                        \
				"Couldn't obtain the value from json, the array "                                                      \
				"returned a null child at index {}.", i));                                                             \
		auto res = ValueCat::FromJSON_Item(data[i], item);                                                             \
		if (!res.has_value())                                                                                          \
			return std::unexpected(res.error()); }                                                                     \
	return {}; }                                                                                                       \
static std::expected<String, String> ToString(const Type& data) {                                                      \
	String output {};                                                                                                  \
	output += "[";                                                                                                     \
	for (sizet i = 0; i < Type::ComponentCount; ++i) {                                                                 \
		auto res = ValueCat::ToString(data[i]);                                                                        \
		if (!res.has_value())                                                                                          \
			return std::unexpected(res.error());                                                                       \
		output += res.value();                                                                                         \
		if (i < (Type::ComponentCount -1))                                                                             \
			output += ", "; }                                                                                          \
	output += "]";                                                                                                     \
	return output; }                                                                                                   \
static std::expected<ReflectedSize_t, String> GetDynamicSize(const Type& data) { return 0ull; }                        \
static std::expected<ReflectedSize_t, String> GetArraySize(const Type& data) { return Type::ComponentCount; }          \
static std::expected<void, String> SetArraySize(Type& data, ReflectedSize_t size) {                                    \
	if (size == Type::ComponentCount)                                                                                  \
		return {};                                                                                                     \
	return std::unexpected("[refl::ContainerType<"#type">::GetArrayValue] "                                            \
		"Trying to change the size of an array, different than its initial size."); }                                  \
static std::expected<const ArrayValueType*, String> GetArrayValue(const Type& data, ReflectedSize_t index){            \
	if (index < Type::ComponentCount)                                                                                  \
		return &data[index];                                                                                           \
	return std::unexpected(std::format("[refl::ContainerType<"#type">::GetArrayValue] "                                \
		"Index '{}' out of bounds [0,{}]", index, Type::ComponentCount));}                                             \
static std::expected<void, String> SetArrayValue(Type& data, const ArrayValueType& value, ReflectedSize_t index){      \
	if (index < Type::ComponentCount){                                                                                 \
		data[index] = value;                                                                                           \
		return {};}                                                                                                    \
	return std::unexpected(std::format("[refl::ContainerType<"#type">::SetArrayValue] "                                \
		"Index '{}' out of bounds [0,{}]", index, Type::ComponentCount)); }};}

ReflectAsContainer(greaper::math::Vector2f, greaper::refl::RTI_Vector2f);
ReflectAsContainer(greaper::math::Vector2d, greaper::refl::RTI_Vector2d);
ReflectAsContainer(greaper::math::Vector2i, greaper::refl::RTI_Vector2i);
ReflectAsContainer(greaper::math::Vector2i8, greaper::refl::RTI_Vector2i8);
ReflectAsContainer(greaper::math::Vector2i16, greaper::refl::RTI_Vector2i16);
ReflectAsContainer(greaper::math::Vector2i64, greaper::refl::RTI_Vector2i64);
ReflectAsContainer(greaper::math::Vector2u, greaper::refl::RTI_Vector2u);
ReflectAsContainer(greaper::math::Vector2u8, greaper::refl::RTI_Vector2u8);
ReflectAsContainer(greaper::math::Vector2u16, greaper::refl::RTI_Vector2u16);
ReflectAsContainer(greaper::math::Vector2u64, greaper::refl::RTI_Vector2u64);
ReflectAsContainer(greaper::math::Vector2b, greaper::refl::RTI_Vector2b);

#else
#define ReflectAsContainer(...) 
#endif

#endif /* MATH_REFLECTION_MATH_AS_CONTAINER_HPP */