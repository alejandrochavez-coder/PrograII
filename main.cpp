#include <iostream>
#include "globals.h"
#include "grilla.h"
#include "cinematica.h"
#include "recursion.h"
using namespace std;

int FILAS, COLUMNAS, FILA_BASE, COL_BASE; // definicion de las globales

int main() {
    cout << "=== SIMULADOR DE BRAZO ROBOTICO ===\n\n";
    cout << "Ingrese numero de filas (N): ";  cin >> FILAS;
    cout << "Ingrese numero de columnas (M): "; cin >> COLUMNAS;
    FILA_BASE = FILAS / 2;
    COL_BASE  = COLUMNAS / 2;

    char** grilla = crearGrilla();
    colocarObstaculos(grilla);

    float xActual = 0, yActual = 0;
    int filaActual = FILA_BASE, colActual = COL_BASE;

    cout << "\nGrilla inicial:\n";
    imprimirGrilla(grilla);

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        float theta1, theta2, L1, L2;
        cout << "\n--- Nuevo movimiento ---\n";
        cout << "Angulo theta1 (grados): "; cin >> theta1;
        cout << "Angulo theta2 (grados): "; cin >> theta2;
        cout << "Longitud L1: "; cin >> L1;
        cout << "Longitud L2: "; cin >> L2;

        float xDestino, yDestino;
        cinematicaDirecta(theta1, theta2, L1, L2, xDestino, yDestino);
        cout << "\nPosicion calculada: x = " << xDestino << ", y = " << yDestino << "\n";

        int filaDestino, colDestino;
        mapearAGrilla(xDestino, yDestino, filaDestino, colDestino);
        cout << "Posicion en grilla: fila = " << filaDestino << ", columna = " << colDestino << "\n";

        cout << "\nVerificando trayectoria...\n";
        if (trayectoriaEsSegura(grilla, xActual, yActual, xDestino, yDestino, 3)) {
            cout << "Trayectoria segura. Moviendo robot...\n";
            actualizarPosicionRobot(grilla, filaActual, colActual, filaDestino, colDestino);
            xActual = xDestino; yActual = yDestino;
            filaActual = filaDestino; colActual = colDestino;
        } else {
            cout << "Movimiento rechazado: la trayectoria no es segura.\n";
        }

        cout << "\nGrilla actual:\n";
        imprimirGrilla(grilla);

        cout << "\nDesea ingresar otro movimiento? (s/n): ";
        cin >> continuar;
    }

    liberarGrilla(grilla);
    cout << "\nSimulacion finalizada.\n";
    return 0;
}
