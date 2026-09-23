#pragma once

// Calcula la posicion cartesiana (x, y) del efector final a partir de
// los angulos (grados) y longitudes de los dos eslabones. Resultado por referencia.
void cinematicaDirecta(float theta1, float theta2, float L1, float L2,
                        float &x, float &y);

// Convierte (x, y) flotante a un indice entero (fila, columna) de la grilla.
void mapearAGrilla(float x, float y, int &fila, int &columna, int rows, int columns);