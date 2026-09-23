#ifndef GRILLA_H
#define GRILLA_H

// Reserva memoria dinamica para la grilla (FILAS x COLUMNAS),
// la llena con '.' y coloca la base 'B' en el centro.
char** crearGrilla();

// Coloca obstaculos '#' en posiciones fijas.
void colocarObstaculos(char** grilla);

// Imprime la grilla en consola.
void imprimirGrilla(char** grilla);

// Mueve el efector 'R' de una celda a otra.
void actualizarPosicionRobot(char** grilla, int filaAnt, int colAnt,
                              int filaNueva, int colNueva);

// true si (fila, columna) esta dentro del mapa y libre de obstaculos.
bool movimientoValido(char** grilla, int fila, int columna);

// Libera toda la memoria reservada dinamicamente.
void liberarGrilla(char** grilla);

#endif
