#pragma once

// Verifica por biseccion recursiva si el segmento (x1,y1)-(x2,y2) esta
// libre de colisiones. 'profundidad' limita cuantas veces se subdivide.
bool trayectoriaEsSegura(char** grilla, float x1, float y1, float x2, float y2,
                          int profundidad, int rows, int columns);
