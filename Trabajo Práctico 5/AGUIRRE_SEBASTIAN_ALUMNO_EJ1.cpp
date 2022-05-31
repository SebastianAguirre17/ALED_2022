#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_MATRIZ     5

int mostrarMatriz(int matriz[][TOPE_MATRIZ], int filas, int columnas);
int sumarDiagonalPrincipal(int matriz[][TOPE_MATRIZ], int columnas);

int main(){
    mostrarTitulo("Ejercicio 1");

    int matriz[5][5] = {{5,2,3,4,5}, {1,6,3,4,5}, {1,2,7,4,5}, {1,2,3,8,5}, {1,2,3,4,9}};
    int total = sumarDiagonalPrincipal(matriz, TOPE_MATRIZ);

    mostrarMatriz(matriz, TOPE_MATRIZ, TOPE_MATRIZ);
    cout << endl << "TOTAL: " << total << endl << endl;

	return EXIT_SUCCESS;
}

int mostrarMatriz(int matriz[][TOPE_MATRIZ], int filas, int columnas) {
    int i, j, total = 0;
    for (i = 0; i < filas; i++) {
        cout << "| ";
        for (j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
    return total;
}

int sumarDiagonalPrincipal(int matriz[][TOPE_MATRIZ], int filas) {
    int i, total = 0;
    for (i = 0; i < filas; i++) {
        total += matriz[i][i];
    }
    return total;
}
