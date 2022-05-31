#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define FILAS       2
#define COLUMNAS    3

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas); 
void mostrarMatrizTraspuesta(int matriz[][FILAS], int filas, int columnas); 

int main(){
    mostrarTitulo("Ejercicio 3 - Trasponer Matriz");

    int matriz[FILAS][COLUMNAS] = {{1, 2, 3}, {4, 5, 6}};
    int matrizT[COLUMNAS][FILAS];

    mostrarString("Matriz Principal\n\n");
    mostrarMatriz(matriz, FILAS, COLUMNAS);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matrizT[j][i] = matriz[i][j];
        }
    }

    mostrarString("\n\nMatriz Traspuesta\n\n");
    mostrarMatrizTraspuesta(matrizT, COLUMNAS, FILAS);

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

void mostrarMatrizTraspuesta(int matriz[][FILAS], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
        cout << "| ";
        for (j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
}