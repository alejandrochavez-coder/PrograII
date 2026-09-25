#pragma once

#include "vector2d.h"

namespace dynamics {

struct SecondOrder {
    Vector2D x = Vector2D{0, 0};
    Vector2D y = Vector2D{0, 0};
    Vector2D dy = Vector2D{0, 0};
};

void initialize_second_order(SecondOrder& dynamics, Vector2D position) {
    dynamics.x = position;
    dynamics.y = position;
}

Vector2D update_second_order(SecondOrder& dynamics, double delta, const Vector2D& position, double k1, double k2, double k3) {
    Vector2D dx = vector_subtract(position, dynamics.x);
    dx = vector_divide_number(dx, delta);

    dynamics.y = vector_add(dynamics.y, vector_multiply(dynamics.dy, delta));
    
    Vector2D acceleration = position;
    acceleration = vector_add(acceleration, vector_multiply(dx, k3));
    acceleration = vector_subtract(acceleration, dynamics.y);
    acceleration = vector_subtract(acceleration, vector_multiply(dynamics.dy, k1));
    acceleration = vector_divide_number(acceleration, k2); 

    acceleration = vector_multiply(acceleration, delta);

    dynamics.dy = vector_add(dynamics.dy, acceleration);
    dynamics.x = position;

    return dynamics.y;
}

}