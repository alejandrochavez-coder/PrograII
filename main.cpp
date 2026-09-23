#include <iostream>
#include "grid.h"
#include "cinematica.h"
#include "recursion.h"

int main() {
    std::cout << "=== SIMULADOR DE BRAZO ROBOTICO ===\n\n";

    int columns;
    std::cout << "Ingrese numero de columnas (M): "; 
    std::cin >> columns;

    int rows;
    std::cout << "Ingrese numero de filas (N): ";  
    std::cin >> rows;

    char** grid = crearGrilla(rows, columns);
    colocarObstaculos(grid, rows, columns);

    float xActual = 0, yActual = 0;
    int current_column = columns;
    int current_row = rows;

    std::cout << "\nGrilla inicial:\n";
    draw_grid(grid, rows, columns);

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {

        float first_angle, second_angle, first_length, second_length;
        std::cout << "\n--- Nuevo movimiento ---\n";

        std::cout << "Primer angulo (sexahesimales): "; 
        std::cin >> first_angle;

        std::cout << "Segundo angulo (sexahesimales): "; 
        std::cin >> second_angle;

        std::cout << "Longitud L1: "; 
        std::cin >> first_length;

        std::cout << "Longitud L2: "; 
        std::cin >> second_length;

        float xDestino, yDestino;
        cinematicaDirecta(first_angle, second_angle, first_length, second_length, xDestino, yDestino);
        std::cout << "\nPosicion calculada: x = " << xDestino << ", y = " << yDestino << "\n";

        int filaDestino, colDestino;
        mapearAGrilla(xDestino, yDestino, filaDestino, colDestino, rows, columns);
        std::cout << "Posicion en grilla: fila = " << filaDestino << ", columna = " << colDestino << "\n";

        std::cout << "\nVerificando trayectoria...\n";
        if (trayectoriaEsSegura(grid, xActual, yActual, xDestino, yDestino, 3, rows, columns)) {
            std::cout << "Trayectoria segura. Moviendo robot...\n";
            actualizarPosicionRobot(grid, current_row, current_column, filaDestino, colDestino);
            xActual = xDestino; 
            yActual = yDestino;
            current_row = filaDestino; current_column = colDestino;
        } else {
            std::cout << "Movimiento rechazado: la trayectoria no es segura.\n";
        }

        std::cout << "\nGrilla actual:\n";
        draw_grid(grid, rows, columns);

        std::cout << "\nDesea ingresar otro movimiento? (s/n): ";
        std::cin >> continuar;
    }

    liberarGrilla(grid, rows);
    std::cout << "\nSimulacion finalizada.\n";
    return 0;
}
