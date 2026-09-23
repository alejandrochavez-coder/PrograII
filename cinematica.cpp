#include "cinematica.h"
#include "globals.h"
#include <cmath>

const float PI = 3.14159265f;

void cinematicaDirecta(float theta1, float theta2, float L1, float L2,
                        float &x, float &y) {
    float r1 = theta1 * PI / 180.0f;
    float r2 = (theta1 + theta2) * PI / 180.0f;
    x = L1 * cos(r1) + L2 * cos(r2);
    y = L1 * sin(r1) + L2 * sin(r2);
}

void mapearAGrilla(float x, float y, int &fila, int &columna) {
    columna = COL_BASE + (int)round(x);
    fila = FILA_BASE - (int)round(y); // 'y' crece hacia arriba, las filas hacia abajo
}
