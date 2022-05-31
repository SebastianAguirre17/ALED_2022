#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_MATRIZ     5

int mostrarMatriz(int matriz[][TOPE_MATRIZ], int filas, int columnas);
int sumarDiagonalPrincipal(int matriz[][TOPE_MATRIZ], int columnas);
int sumarDiagonalInversa(int matriz[][TOPE_MATRIZ], int filas); 
int sumarDiagonal(int matriz[][TOPE_MATRIZ], int filas, char op);

int main(){
    mostrarTitulo("Ejercicio 2");

    int matriz[5][5] = {{5,2,3,4,5}, {1,6,3,4,5}, {1,2,7,4,5}, {1,2,3,8,5}, {1,2,3,4,9}};

    mostrarMatriz(matriz, TOPE_MATRIZ, TOPE_MATRIZ);


    int total = sumarDiagonal(matriz, TOPE_MATRIZ, 'p');
    cout << endl << "TOTAL PRINCIPAL: " << total << endl;

    total = sumarDiagonal(matriz, TOPE_MATRIZ, 'i');
    cout << endl << "TOTAL PRINCIPAL: " << total << endl;

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

int sumarDiagonalInversa(int matriz[][TOPE_MATRIZ], int filas) {
    int i, total = 0;
    filas--;
    for (i = 0; i <= filas; ++i) {
        total +=  matriz[i][filas - i];
    }
    return total;
}

int sumarDiagonal(int matriz[][TOPE_MATRIZ], int filas, char op) {
    int total = EXIT_ERROR;
    if (op == 'p' or op == 'P') {
        total = sumarDiagonalPrincipal(matriz, filas);
    } else if (op == 'i' or op == 'I') {
        total = sumarDiagonalInversa(matriz, filas);
    } else {
        cout << "La opcion ingresada es incorrecta." << endl;
    }
    return total;
}