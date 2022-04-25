#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 
using namespace std;

void mostrarButacas(int filas, int columnas);

int main(){
    mostrarTitulo("Ejercicio 3");

    int filas = pedirEnteroMayorA("Ingrese la cantidad de filas: ", 0);
    int columnas = pedirEnteroMayorA("Ingrese la cantidad de columnas: ", 0);
    mostrarButacas(filas, columnas);

	return EXIT_SUCCESS;
}

void mostrarButacas(int filas, int columnas) {
    mostrarTitulo("Mostrar Butacas");
    int i, j, acum = 0;

    for (int i = 1; i <= filas; i++) {
        cout << "Fila " << i << ": ";
        for (j = 1; j <= columnas; j++) {
            acum++;
            if (esNumeroPar(i) and esNumeroPar(acum))
                cout << acum << ", ";
            else if (not esNumeroPar(i) and not esNumeroPar(acum))
                cout << acum << ", ";
        }
        cout << endl;
    }
}