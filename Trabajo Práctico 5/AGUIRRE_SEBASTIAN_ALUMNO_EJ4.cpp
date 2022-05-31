#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define FILAS       3
#define COLUMNAS    4

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas);
void buscarValorEnMatriz(int matriz[][COLUMNAS], int filas, int columnas, int buscado, int &fila, int &columna);

int main(){
    mostrarTitulo("Ejercicio 4");

    // Falta el 7
    int matriz[FILAS][COLUMNAS] = {{2, 3, 6, 8}, {5, 1, 9, 4}, {0, 5, 3, 4}};
    mostrarMatriz(matriz, FILAS, COLUMNAS);


	return EXIT_SUCCESS;
}

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
        cout << "| ";
        for (j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
}

void buscarValorEnMatriz(int matriz[][COLUMNAS], int filas, int columnas, int buscado, int &fila, int &columna) {

}