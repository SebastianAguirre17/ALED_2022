#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_1 10
#define TOPE_2 5
#define TOPE_R TOPE_1 + TOPE_2

void apareoDeVectores(int vec1[], int tope1, int vec2[], int tope2, int result[], int &topeR);

int main(){
    mostrarTitulo("Ejercicio 5 - Punto B");

    int vec1[TOPE_1] = { 12, 5, 4, 5, 9, 11, 5, 4, 13, 7 };
    int vec2[TOPE_2] = { 0, 9, 3, 7, 10 };
    int result[TOPE_R];
    int topeResult = 0; 

    ordenamientoPorSeleccion(vec1, TOPE_1);
    mostrarTitulo("Vector 1");
    mostrarArrayNumericoConIndice(vec1, TOPE_1);
    
    ordenamientoPorSeleccion(vec2, TOPE_2);
    mostrarTitulo("Vector 2");
    mostrarArrayNumericoConIndice(vec2, TOPE_2);

    mostrarTitulo("Mezcla de Vectores");
    apareoDeVectores(vec1, TOPE_1, vec2, TOPE_2, result, topeResult);
    mostrarArrayNumericoConIndice(result, topeResult);

	return EXIT_SUCCESS;
}

void apareoDeVectores(int vec1[], int tope1, int vec2[], int tope2, int result[], int &topeR) {
    int i = 0, j = 0;
    topeR = 0;

    if (vec1[i] < vec2[j]) {
        result[topeR] = vec1[i];
        i++;
    } else {
        result[topeR] = vec2[j];
        j++;
    }
    topeR++;

    while (i < tope1 and j < tope2) {
        if (vec1[i] < vec2[j] ) {
            if (result[topeR - 1] < vec1[i]) {
                result[topeR] = vec1[i];
                topeR++;
            }
            i++;
        } else {
            if (result[topeR - 1] < vec2[j]) {
                result[topeR] = vec2[j];
                topeR++;
            }
            j++;
        }
    }
    
    for (i; i < tope1; i++) {
        if (result[topeR - 1] < vec1[i]) {
            result[topeR] = vec1[i];
            topeR++;
        }
    }

    for (j; j < tope2; j++) {
        if (result[topeR - 1] < vec2[j]) {
            result[topeR] = vec2[j];
            topeR++;
        }
    } 
}
