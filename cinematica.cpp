#include "cinematica.h"
#include <numbers>
#include <cmath>

Vector2D direct_kinematic(float first_angle, float second_angle, float L1, float L2) {
    float r1 = first_angle * std::numbers::pi / 180.0f;
    float r2 = (first_angle + second_angle) * std::numbers::pi / 180.0f;

    double x = L1 * cos(r1) + L2 * cos(r2);
    double y = L1 * sin(r1) + L2 * sin(r2);

    return Vector2D{x, y};
}

void map_to_grid(const Vector2D& position, int &fila, int &columna, int rows, int columns) {
    columna = rows / 2 + (int)round(position.x);
    fila = columns / 2 - (int)round(position.y); // 'y' crece hacia arriba, las filas hacia abajo
}
