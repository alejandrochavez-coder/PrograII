#include "grid.h"
#include <iostream>

char** crearGrilla(int rows, int columns) {
    char** grilla = new char*[rows];
    for (int i = 0; i < rows; i++) {

        grilla[i] = new char[columns];
        for (int j = 0; j < columns; j++) grilla[i][j] = '.';

    }

    grilla[rows / 2][columns / 2] = 'B';
    return grilla;
}

void colocarObstaculos(char** grilla, int rows, int columns) {
    int obstaculos[3][2] = { {1, 1}, {2, columns - 3}, {rows - 2, 2} };
    for (int i = 0; i < 3; i++) {
        int f = obstaculos[i][0], c = obstaculos[i][1];
        if (movimientoValido(grilla, f, c, rows, columns)) grilla[f][c] = '#';
    }
}

void draw_grid(char** grilla, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << grilla[i][j] << ' ';
        }
        
        std::cout << '\n';
    }
}

void actualizarPosicionRobot(char** grilla, int filaAnt, int colAnt,
                              int filaNueva, int colNueva) {
    if (grilla[filaAnt][colAnt] == 'R'){
        grilla[filaAnt][colAnt] = '.';
    } 

    grilla[filaNueva][colNueva] = 'R';
}

bool movimientoValido(char** grilla, int fila, int columna, int rows, int columns) {
    bool dentroDelMapa = (fila >= 0) && (fila < rows) && (columna >= 0) && (columna < columns);
    return dentroDelMapa && grilla[fila][columna] != '#';
}

void liberarGrilla(char** grilla, int rows) {
    for (int i = 0; i < rows; i++) delete[] grilla[i];
    delete[] grilla;
}
