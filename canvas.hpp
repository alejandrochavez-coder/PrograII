#pragma once

#include "vector2d.h"
#include <string>

namespace canvas {

typedef struct Instance_T* Instance;

Instance instance(size_t width, size_t height);

bool place(Instance instance, const Vector2D& position, char character);

void draw_line(Instance instance, const Vector2D& start, const Vector2D& end, char character);

void fill(Instance instance, char character);

std::string build(Instance instance);

void destroy(Instance instance);

}