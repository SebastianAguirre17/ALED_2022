#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_M 10
#define TOPE_N 5
#define TOPE_R TOPE_M + TOPE_N


int main(){
    mostrarTitulo("Ejercicio 5 - Punto B");

    int vec1[TOPE_M] = { 12, 5, 4, 5, 9, 11, 5, 4, 13, 7 };
    int vec2[TOPE_N] = { 0, 9, 3, 7, 10 };

    // Ordeno Vectores
    ordenamientoPorSeleccion(vec1, TOPE_M);
    ordenamientoPorSeleccion(vec2, TOPE_N);

	return EXIT_SUCCESS;
}
