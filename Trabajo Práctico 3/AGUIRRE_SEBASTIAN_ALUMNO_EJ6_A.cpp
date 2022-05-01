#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE_M 10
#define TOPE_N 5
#define TOPE_R TOPE_M + TOPE_N

void mezclarVectoresNumericos(int vec1[], int topeN, int vec2[], int topeM, int result[], int &topeR);

int main(){
    mostrarTitulo("Ejercicio 5 - Punto A");

    int vec1[TOPE_M] = { 12, 5, 4, 5, 9, 11, 5, 4, 13, 7 };
    int vec2[TOPE_N] = { 0, 9, 3, 7, 10 };
    int result[TOPE_R], topeResult; 

    mezclarVectoresNumericos(vec1, TOPE_M, vec2, TOPE_N, result, topeResult);
    mostrarArrayNumericoConIndice(result, topeResult);

	return EXIT_SUCCESS;
}

void mezclarVectoresNumericos(int vec1[], int topeM, int vec2[], int topeN, int result[], int &topeR) {
    int i;
    topeR = 0;

    concatNumerosNoRepetidos(vec1, topeM, result, topeR);
    concatNumerosNoRepetidos(vec2, topeN, result, topeR);
}
