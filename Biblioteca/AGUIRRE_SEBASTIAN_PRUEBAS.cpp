#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "AGUIRRE_SEBASTIAN.h" 

#define TOPE1 10
#define TOPE2 5
#define TOPE3 TOPE1 + TOPE2


int buscarValor(int vector[], int tope, int val) {
	int k = 0;
	while (k < tope and vector[k] != val) {
		k++;
	}
	if(k == tope) {
		k = -1;
	}
	return k;
}

int main(){

	int vec1[TOPE1] = { 12, 5, 4, 5, 9, 11, 5, 4, 13, 7 };
    int vec2[TOPE2] = { 0, 9, 3, 7, 10 };
    int vec3[TOPE3];
	int topeAux = 0; 

     for (int i = 0; i < TOPE1; i++) {
		if (buscarValor(vec3, topeAux, vec1[i]) == -1) {
			vec3[topeAux] = vec1[i];
			topeAux++;
		}
	}

	mostrarArrayNumerico(vec3, topeAux);

	return EXIT_SUCCESS;
}

