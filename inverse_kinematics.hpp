#pragma once

#include "vector2d.h"

namespace ik {

struct Segment {
	Vector2D root_position;
	Vector2D tip_position;
	double length;
};

typedef struct Instance_T* Instance;

Instance instance();

Vector2D tip(Instance instance);

Vector2D root(Instance instance);

void append(Instance instance, const Vector2D& line);

void reach_target(Instance instance, const Vector2D& target);

void offset(Instance instance, Vector2D offset);

void enumerate_segments(Instance instance, size_t& out_count, Segment* out_ptr);

void destroy(Instance instance);

}