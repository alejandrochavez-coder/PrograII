#pragma once

//Sources
//https://www.bytesbeneath.com/p/dynamic-arrays-in-c?utm_source=publication-search

#include <stddef.h>
#include <stdlib.h>

typedef struct {
	size_t element_size;
	size_t capacity;
	size_t size;
} ArrayData;

#ifdef __cplusplus
#define array_type(array) decltype(&(array[0]))
#else
#define array_type(array) void*
#endif

#define array(T) (T*)create_array(sizeof(T), 1)
#define array_data(array) ((ArrayData*)(array) - 1)
#define array_size(array) array_data(array)->size
#define array_capacity(array) array_data(array)->capacity
#define array_reserve(array, n) array = (array_type(array))dynamic_array_reserve(array, n)
#define array_append(array, x) 											\
	array_reserve(array, 1);      										\
	array[array_size(array)] = x; 										\
	array_data(array)->size++;											\

#define array_free(array) free(array_data(array))

static inline void* create_array(size_t element_size, size_t capacity) {
	size_t size = sizeof(ArrayData) + (element_size * capacity);
	ArrayData* data = (ArrayData*)malloc(size);

	if (!data) {
		return NULL;
	}

	data->element_size = element_size;
	data->capacity = capacity;
	data->size = 0;

	return (void*)(data + 1);
}

static inline void* dynamic_array_reserve(void* array, size_t additional) {
	ArrayData* data = array_data(array);

	size_t least_capacity = data->size + additional;
	if (data->capacity >= least_capacity) {
		return array;
	}

	size_t new_capacity = data->capacity * 2;
	while (least_capacity > new_capacity) {
		new_capacity *= 2;
	}

	size_t new_size = sizeof(ArrayData) + (data->element_size * new_capacity);
	ArrayData* new_data = (ArrayData*)realloc(data, new_size);

	if (new_data) {
		new_data->capacity = new_capacity;
		return (void*)(new_data + 1);
	}

	return array;
}