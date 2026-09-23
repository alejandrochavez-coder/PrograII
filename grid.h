#pragma once

// Reserva memoria dinamica para la grilla (FILAS x COLUMNAS),
// la llena con '.' y coloca la base 'B' en el centro.
char** create_grid(int rows, int columns);

// Coloca obstaculos '#' en posiciones fijas.
void place_obstacles(char** grilla, int rows, int columns);

// Imprime la grilla en consola.
void draw_grid(char** grilla, int rows, int columns);

// Mueve el efector 'R' de una celda a otra.
void actualizarPosicionRobot(char** grilla, int filaAnt, int colAnt,
                              int filaNueva, int colNueva);

// true si (fila, columna) esta dentro del mapa y libre de obstaculos.
bool movimientoValido(char** grilla, int fila, int columna, int rows, int columns);

// Libera toda la memoria reservada dinamicamente.
void liberarGrilla(char** grilla, int rows);
