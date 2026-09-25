#include "dynamic_array.h"
#include "canvas.hpp"
#include <iostream>
#include <cmath>

namespace canvas {

struct Instance_T {
    char** buffer;
    size_t height;
    size_t width;
};

Instance instance(size_t width, size_t height) {
    Instance_T* instance = new Instance_T{};
    instance->buffer = array_allocate(char*, height);
    instance->height = height;
    instance->width = width;

    for (size_t i = 0; i < height; i++) {

        char* row = array_allocate(char, width + 1);

		for (size_t j = 0; j < width; j++) {
			array_append(row, ' ');
		}

		array_append(row, '\0');
		array_append(instance->buffer, row);
    }

    return instance;
}

bool place(Instance instance, const Vector2D& position, char character) {
    int i = (int)(instance->height / 2 + position.y);
    int j = (int)(instance->width / 2 + position.x);

    if (i < 0 || j < 0 || instance->height <= i || instance->width <= j) {
        return false;
    }

    instance->buffer[i][j] = character;
    return true;
}

double abs(double x) {
    if (0 < x) {
        return x;
    }

    return -x;
}

//https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
void draw_line(Instance instance, const Vector2D& start, const Vector2D& end, char character) {
    double dx = (end.x - start.x);
    double dy = (end.y - start.y);

    double step = abs(dy);
    if (abs(dx) >= abs(dy)) {
        step = abs(dx);
    }

    dx /= step;
    dy /= step;

    double x = start.x;
    double y = start.y;

    int i = 0;

    while (i <= step) {
        Vector2D position = Vector2D{std::round(x), -std::round(y)};
        canvas::place(instance, position, character);

        x = x + dx;
        y = y + dy;
        i++;
    }

}

void fill(Instance instance, char character) {

    for (size_t i = 0; i < array_size(instance->buffer); i++) {

        for (size_t j = 0; j < instance->width; j++) {

            instance->buffer[i][j] = character;

        }

    }

}

std::string build(Instance instance) {

    std::string buffer = "";

    for (size_t i = 0; i < array_size(instance->buffer); i++) {
        std::string row_string(instance->buffer[i]);
        buffer += row_string;

        if (i + 1 != array_size(instance->buffer)) {
            buffer += '\n';
        }
    }

    return buffer;

}

void destroy(Instance instance) {

    for (size_t i = 0; i < array_size(instance->buffer); i++) {
        array_free(instance->buffer[i]);
    }

    array_free(instance->buffer);
    free(instance);

}

}