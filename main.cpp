#include "inverse_kinematics.hpp"
#include <iostream>
#include "vector2d.h"

struct Segment {
    Vector2D root;
    Vector2D target;
    double length;
};

void segments_reach_targets(Segment* segments, size_t segment_count) {

    for (size_t i = 0; i < segment_count; i++) {
        Segment& segment = segments[i];

        Vector2D direction = vector_subtract(segment.root, segment.target);
        direction = vector_normalize(direction);

        Vector2D offset = vector_multiply(direction, segment.length);
        segment.root = vector_add(segment.target, offset);

    }

}

void segments_offset(Segment* segments, size_t segment_count, const Vector2D& offset) {

    for (size_t i = 0; i < segment_count; i++) {

        Segment& segment = segments[i];

        segment.root = vector_add(segment.root, offset);
        segment.target = vector_add(segment.target, offset);

    }

}

Segment* create_segments(size_t segment_count, const Vector2D& origin, const Vector2D& direction) {
    
    Segment* segments = (Segment*)malloc(sizeof(Segment) * segment_count);

    for (size_t i = 0; i < segment_count; i++) {

        segments[i] = Segment {
            .root = vector_add(origin, vector_multiply(direction, segment_count - i)),
            .target = vector_add(origin, vector_multiply(direction, segment_count - i - 1)),
            .length = (double)(i)
        };

    }

    return segments;
}

int main() {

    // Vector2D direction = Vector2D{0, 1};
    // Vector2D anchor = Vector2D{4, 4};
    // size_t segment_count = 4;

    // Segment* segments = create_segments(segment_count, anchor, direction);
    // Vector2D offset = vector_subtract(anchor, segments[segment_count - 1].root);

    // segments_reach_targets(segments, segment_count);
    // segments_offset(segments, segment_count, offset);

    ik::Instance instance = ik::create_instance();

    ik::destroy_instance(instance);
    
    while (true) {

    }
    // free(segments);

    return 0;

}
