#include "recursion.h"
#include "cinematica.h"
#include "grid.h"
using namespace std;

bool is_trayectory_safe(char** grilla, float x1, float y1, const Vector2D& target_position,
                          int profundidad, int rows, int columns) {
    int fila, columna;
    map_to_grid(target_position, fila, columna, rows, columns);
    if (!movimientoValido(grilla, fila, columna, rows, columns)) return false;

    if (profundidad <= 0) return true; // caso base: paso ya es suficientemente fino

    float xm = (x1 + target_position.x) / 2.0f, ym = (y1 + target_position.y) / 2.0f;
    return is_trayectory_safe(grilla, x1, y1, target_position, profundidad - 1, rows, columns)
        && is_trayectory_safe(grilla, xm, ym, target_position, profundidad - 1, rows, columns);
}
