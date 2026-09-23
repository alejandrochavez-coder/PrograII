#pragma once

#include "vector2d.h"

// Verifica por biseccion recursiva si el segmento (x1,y1)-(x2,y2) esta
// libre de colisiones. 'profundidad' limita cuantas veces se subdivide.
bool is_trayectory_safe(char** grilla, float x1, float y1, const Vector2D& target_position,
                          int profundidad, int rows, int columns);
