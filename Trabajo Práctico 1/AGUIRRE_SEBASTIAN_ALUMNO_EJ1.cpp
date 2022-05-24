#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define DESDE 2
#define HASTA 9
#define TOPE 100

void mostrarMultiplos(int valor, int tope, char orden);
void mostarMultiplosAscendentes(int valor, int limite);
void mostrarMultiplosDescendentes(int valor, int limite);

int main(){
    mostrarTitulo("Ejercicio 1");

	int valor;
	ingresarEnteroEnRango(valor, 2, 9, "Ingrese un numero entre 2 y 9: ");

	cout << "Orden Ascendente" << endl;
	mostrarMultiplos(valor, TOPE, 'A');
	cout << endl << "Orden Descendente" << endl;
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
            cout << i << endl;
        }
    }
}

void mostrarMultiplosDescendentes(int valor, int limite) {
    for (int i = limite; i >=  valor; i--) {
        if (i % valor == 0) {
            cout << i << endl;
        }
    }
}