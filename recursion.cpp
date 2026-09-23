#include "recursion.h"
#include "cinematica.h"
#include "grilla.h"
using namespace std;

bool trayectoriaEsSegura(char** grilla, float x1, float y1, float x2, float y2,
                          int profundidad) {
    int fila, columna;
    mapearAGrilla(x2, y2, fila, columna);
    if (!movimientoValido(grilla, fila, columna)) return false;

    if (profundidad <= 0) return true; // caso base: paso ya es suficientemente fino

    float xm = (x1 + x2) / 2.0f, ym = (y1 + y2) / 2.0f;
    return trayectoriaEsSegura(grilla, x1, y1, xm, ym, profundidad - 1)
        && trayectoriaEsSegura(grilla, xm, ym, x2, y2, profundidad - 1);
}
