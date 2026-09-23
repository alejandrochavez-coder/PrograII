#include "cinematica.h"
#include <numbers>
#include <cmath>

void cinematicaDirecta(float first_angle, float second_angle, float L1, float L2,
                        float &x, float &y) {
    float r1 = first_angle * std::numbers::pi / 180.0f;
    float r2 = (first_angle + second_angle) * std::numbers::pi / 180.0f;

    x = L1 * cos(r1) + L2 * cos(r2);
    y = L1 * sin(r1) + L2 * sin(r2);
}

void mapearAGrilla(float x, float y, int &fila, int &columna, int rows, int columns) {
    columna = rows / 2 + (int)round(x);
    fila = columns / 2 - (int)round(y); // 'y' crece hacia arriba, las filas hacia abajo
}
