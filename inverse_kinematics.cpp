#include "inverse_kinematics.hpp"
#include "dynamic_array.h"
#include "vector2d.h"
#include <iostream>

namespace ik {

struct Instance_T {
    Segment* segments;
};

Instance instance() {
    Instance_T* instance = new Instance_T{};
    instance->segments = array(Segment);

    return instance;
}

Vector2D tip(Instance instance) {
    size_t size = array_size(instance->segments);

    if (size == 0) {
        return Vector2D{0, 0};
    }

    return instance->segments[size - 1].tip_position;
}

Vector2D root(Instance instance) {

    if (array_size(instance->segments) == 0) {
        return Vector2D{0, 0};
    }

    return instance->segments[0].root_position;
}

void append(Instance instance, const Vector2D& line) {
    Segment segment = Segment{};
    Vector2D tip = ik::tip(instance);

    segment.root_position = tip;
    segment.tip_position = vector_add(tip, line);
    segment.length = vector_length(line);

    array_append(instance->segments, segment);
}

void reach_target(Instance instance, const Vector2D& target) {

    Vector2D current_target = target;

    for (int i = array_size(instance->segments) - 1; i >= 0; i--) {

        Segment& segment = instance->segments[i];

        Vector2D direction = vector_subtract(segment.root_position, current_target);
        direction = vector_normalize(direction);

        Vector2D offset = vector_multiply(direction, segment.length);
        segment.root_position = vector_add(current_target, offset);
        segment.tip_position = current_target;

        current_target = segment.root_position;

    }

}

void offset(Instance instance, Vector2D offset) {
    for (size_t i = 0; i < array_size(instance->segments); i++) {

        Segment& segment = instance->segments[i];
        segment.root_position = vector_add(segment.root_position, offset);
        segment.tip_position = vector_add(segment.tip_position, offset);
    }
}

void enumerate_segments(Instance instance, size_t& out_count, Segment* out_ptr) {
    out_count = array_size(instance->segments);

    if (!out_ptr) {
        return;
    }

    for (size_t i = 0; i < array_size(instance->segments); i++) {
        out_ptr[i] = instance->segments[i];
    }
}

void destroy(Instance instance) {
    array_free(instance->segments);
    free(instance);
}

}