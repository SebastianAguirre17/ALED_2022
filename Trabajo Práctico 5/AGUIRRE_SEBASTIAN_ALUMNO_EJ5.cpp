#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define FILAS       3
#define COLUMNAS    5
#define TOPE_VEC    6

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas);
bool existeEnMatriz(int matriz[][COLUMNAS], int filas, int columnas, int buscado);

int main(){
    mostrarTitulo("Ejercicio 5");

    int matriz[FILAS][COLUMNAS] = {
        {8, 3, 6, 2, 5},
        {1, 22, 0, 4, 3},
        {7, 15, 8, 1, 4}
    };
    int vector[TOPE_VEC] = {25, 4, 7, 9, 15, 6};
    int topeResult = 0, result[TOPE_VEC];

    for (int i = 0; i < TOPE_VEC; i++) {
        if (not existeEnMatriz(matriz, FILAS, COLUMNAS, vector[i])) {
            result[topeResult++] = vector[i];
        }
    }

    mostrarTitulo("Matriz");
    mostrarMatriz(matriz, FILAS, COLUMNAS);

    mostrarTitulo("Vector Original");
    mostrarArrayNumericoConIndice(vector, TOPE_VEC);

    mostrarTitulo("Vector Resultante");
    mostrarArrayNumericoConIndice(result, topeResult);

	return EXIT_SUCCESS;
}

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
        cout << "|";
        for (j = 0; j < columnas; j++) {
            cout << " " << matriz[i][j] << "\t|";
        }
        cout << endl;
    }
}

bool existeEnMatriz(int matriz[][COLUMNAS], int filas, int columnas, int buscado) {
    int i = 0, j = 0;
    while (i < filas and matriz[i][j] != buscado) {
        j++;
        if (j == columnas) {
            i++;
            j = 0;
        }
    }
    return (i != filas);
}
