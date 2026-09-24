#include <cmath>
#include <iostream>
#include "vector2d.h"
#include "dynamic_array.h"
#include "inverse_kinematics.hpp"

void print_vector(const Vector2D& vector) {
	std::cout << "(" << vector.x << ", " << vector.y << ")" << std::endl;
}

int main() {
	ik::Instance instance = ik::create_instance();
	ik::append(instance, Vector2D{0, 1});
    ik::append(instance, Vector2D{0, 1});
	const Vector2D anchor{0, 0};

	while (true) {
		ik::reach_target(instance, Vector2D{0, -2});
		
		Vector2D offset = vector_subtract(anchor, ik::root(instance));
		ik::offset(instance, offset);

		size_t segment_count;
		ik::enumerate_segments(instance, segment_count, nullptr);

		ik::Segment* segments = array_allocate(ik::Segment, segment_count);
		ik::enumerate_segments(instance, segment_count, segments);

		for (size_t i = 0; i < segment_count; i++) {

			ik::Segment& segment = segments[i];
			print_vector(segment.root_position);
            print_vector(segment.tip_position);

		}

        std::cout << std::endl;
	}

	ik::destroy_instance(instance);
	return 0;
}