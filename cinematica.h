#pragma once

#include "vector2d.h"

// Calcula la posicion cartesiana (x, y) del efector final a partir de
// los angulos (grados) y longitudes de los dos eslabones. Resultado por referencia.
Vector2D direct_kinematic(float theta1, float theta2, float L1, float L2);

// Convierte (x, y) flotante a un indice entero (fila, columna) de la grilla.
void map_to_grid(const Vector2D& position, int &fila, int &columna, int rows, int columns);