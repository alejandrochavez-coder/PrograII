#include "inverse_kinematics.hpp"
#include <iostream>
#include <cstdlib>

namespace ik {

struct Segment {
    Vector2D root;
    double length;
};

struct Instance_T {
    Segment* segments = nullptr;
    Vector2D tip = Vector2D{0, 0};
    size_t capacity = 1;
    size_t size = 0;
};

Instance create_instance() {
    Instance_T* instance = (Instance_T*)malloc(sizeof(Instance_T));
    instance->segments = (Segment*)malloc(sizeof(Segment));

    return instance;
}

// void append(Instance instance, const Vector2D& line) {

//     if (instance->size == instance->capacity) {
//         instance->capacity *= 2;
//         instance->segments = (Segment*)realloc(instance->segments, instance->capacity);
//     }

//     instance->segments[instance->size] = Segment{instance->tip, vector_length(line)};
//     instance->tip = instance->segments[instance->size];
//     instance->size++;

// }

void destroy_instance(Instance instance) {
    free(instance->segments);
    free(instance);
}

}