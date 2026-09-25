#include <thread>
#include <chrono>
#include "inverse_kinematics.hpp"
#include "dynamic_array.h"
#include "dynamics.hpp"
#include "vector2d.h"
#include "canvas.hpp"
#include <iostream>
#include <string>
#include <numbers>
#include <cmath>

double to_radians(double degrees) {
	return degrees * std::numbers::pi / 180.0;
}

void vector_print(Vector2D vector) {
	std::cout << vector.x << " " << vector.y << std::endl;
}

Vector2D request_vector() {
	double x, y;

	std::cout << "Target" << std::endl;
	std::cout << "X: ";
	std::cin >> x;

	std::cout << "Y: ";
	std::cin >> y;

	return Vector2D{x, y};
}

int main() {
	std::cout << "\x1b[2J" << "\x1b[H" << "Inicio" << std::endl;

	size_t segment_amount;
	std::cout << "Cantidad de segmentos: ";
	std::cin >> segment_amount;

	double segment_length;
	std::cout << "Longitud de segmento: ";
	std::cin >> segment_length;

	std::cout << "\n";

	Vector2D requested_target = request_vector();

	double speed;
	std::cout << "Speed: ";
	std::cin >> speed;

	Vector2D target = Vector2D{0, 0};
	Vector2D origin = Vector2D{0, 0};

	int width = 161;
	int height = 41;

	double rotations_per_second = 1;

	int fps = 144;
	double delta = 1.0 / fps;

	ik::Instance kinematics = ik::instance();

	for (int i = 0; i < segment_amount; i++) {
		ik::append(kinematics, Vector2D{0, segment_length});
	}


	dynamics::SecondOrder dynamics{};
	dynamics::initialize_second_order(dynamics, ik::tip(kinematics));

	int counter = 1;

	while (true) {
		std::cout << "\x1b[2J" << "\x1b[H";

		target = dynamics::update_second_order(dynamics, delta, requested_target, 2 / speed, 1.0 / (speed * speed), 0);
		ik::reach_target(kinematics, target);

		Vector2D offset = vector_subtract(origin, ik::root(kinematics));
		ik::offset(kinematics, offset);

		canvas::Instance canvas = canvas::instance(width, height);
		canvas::fill(canvas, ' ');

		size_t segment_count;
		ik::enumerate_segments(kinematics, segment_count, nullptr);

		ik::Segment* segments = array_allocate(ik::Segment, segment_count);
		ik::enumerate_segments(kinematics, segment_count, segments);

		for (size_t i = 0; i < segment_count; i++) {

			ik::Segment& segment = segments[i];
			canvas::draw_line(canvas, segment.root_position, segment.tip_position, '#');

		}

		std::cout << canvas::build(canvas) << std::endl;
		canvas::destroy(canvas);

		Vector2D distance = vector_subtract(requested_target, target);
		if (vector_length(distance) < 0.1) {
			requested_target = request_vector();
			std::cout << "Speed: ";
			std::cin >> speed;
		} else {
			vector_print(target);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000 * delta)));
	}

	ik::destroy(kinematics);

	return 0;
}