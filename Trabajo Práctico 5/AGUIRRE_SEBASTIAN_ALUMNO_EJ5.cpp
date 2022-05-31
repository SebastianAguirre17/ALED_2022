#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_MATRIZ     5

int mostrarMatriz(int matriz[][TOPE_MATRIZ], int filas, int columnas);
int sumarDiagonalPrincipal(int matriz[][TOPE_MATRIZ], int columnas);
int sumarDiagonalInversa(int matriz[][TOPE_MATRIZ], int filas); 

int main(){
    mostrarTitulo("Ejercicio 5");

	return EXIT_SUCCESS;
}

