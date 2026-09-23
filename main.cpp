#include <iostream>
#include "grid.h"
#include "cinematica.h"
#include "vector2d.h"
#include "recursion.h"

int main() {
    std::cout << "=== SIMULADOR DE BRAZO ROBOTICO ===\n\n";

    int columns;
    std::cout << "Ingrese numero de columnas (M): "; 
    std::cin >> columns;

    int rows;
    std::cout << "Ingrese numero de filas (N): ";  
    std::cin >> rows;

    char** grid = create_grid(rows, columns);
    place_obstacles(grid, rows, columns);

    float xActual = 0, yActual = 0;
    Vector2D current_position{0, 0};

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

        Vector2D target_position = direct_kinematic(first_angle, second_angle, first_length, second_length);
        std::cout << "\nPosicion calculada: " << vector_to_string(target_position) << std::endl;

        int filaDestino, colDestino;
        map_to_grid(target_position, filaDestino, colDestino, rows, columns);
        std::cout << "Posicion en grilla: fila = " << filaDestino << ", columna = " << colDestino << "\n";

        std::cout << "\nVerificando trayectoria...\n";
        if (is_trayectory_safe(grid, xActual, yActual, target_position, 3, rows, columns)) {
            std::cout << "Trayectoria segura. Moviendo robot...\n";
            actualizarPosicionRobot(grid, current_row, current_column, filaDestino, colDestino);
            xActual = target_position.x;
            yActual = target_position.y;
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
