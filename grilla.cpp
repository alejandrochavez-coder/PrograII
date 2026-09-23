#include "grilla.h"
#include "globals.h"
#include <iostream>
using namespace std;

char** crearGrilla() {
    char** grilla = new char*[FILAS];
    for (int i = 0; i < FILAS; i++) {
        grilla[i] = new char[COLUMNAS];
        for (int j = 0; j < COLUMNAS; j++) grilla[i][j] = '.';
    }
    grilla[FILA_BASE][COL_BASE] = 'B';
    return grilla;
}

void colocarObstaculos(char** grilla) {
    int obstaculos[3][2] = { {1, 1}, {2, COLUMNAS - 3}, {FILAS - 2, 2} };
    for (int i = 0; i < 3; i++) {
        int f = obstaculos[i][0], c = obstaculos[i][1];
        if (movimientoValido(grilla, f, c)) grilla[f][c] = '#';
    }
}

void imprimirGrilla(char** grilla) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) cout << grilla[i][j] << ' ';
        cout << '\n';
    }
}

void actualizarPosicionRobot(char** grilla, int filaAnt, int colAnt,
                              int filaNueva, int colNueva) {
    if (grilla[filaAnt][colAnt] == 'R') grilla[filaAnt][colAnt] = '.';
    grilla[filaNueva][colNueva] = 'R';
}

bool movimientoValido(char** grilla, int fila, int columna) {
    bool dentroDelMapa = fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS;
    return dentroDelMapa && grilla[fila][columna] != '#';
}

void liberarGrilla(char** grilla) {
    for (int i = 0; i < FILAS; i++) delete[] grilla[i];
    delete[] grilla;
}
