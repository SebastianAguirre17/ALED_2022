#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define DESDE 2
#define HASTA 9
#define TOPE 100

void mostrarMultiplos(int valor, int tope, char orden);
void mostarMultiplosAscendentes(int valor, int limite);
void mostrarMultiplosDescendentes(int valor, int limite);

int main(){
	int valor;
	pedirEnteroEnRango(valor, 2, 9);

	mostrarMensaje("Orden Ascendente: \n");
	mostrarMultiplos(valor, TOPE, 'A');
	mostrarMensaje("\nOrden Descendente: \n");
	mostrarMultiplos(valor, TOPE, 'D');
    
	return EXIT_SUCCESS;
}

void mostrarMultiplos(int valor, int tope, char orden) {
	if (orden == 'a' or orden == 'A') {
        mostarMultiplosAscendentes(valor, tope);
	} else {
        mostrarMultiplosDescendentes(valor, tope);
	}
}

void mostarMultiplosAscendentes(int valor, int limite) {
    for (int i = valor; i <= limite ; i++) {
        if (i % valor == 0) {
            mostrarNumeroEntero(i);
        }
    }
}

void mostrarMultiplosDescendentes(int valor, int limite) {
    for (int i = limite; i >=  valor; i--) {
        if (i % valor == 0) {
            mostrarNumeroEntero(i);
        }
    }
}