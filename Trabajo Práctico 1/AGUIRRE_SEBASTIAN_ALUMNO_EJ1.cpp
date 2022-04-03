#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void printNumber(int numero);
void printString(string mensaje);
void getNumber(string mensaje, int &numero);
void imprimirMultiplos(int valor, char orden);
void imprimirMultiplosAscendentes(int valor, int limite); 
void imprimirMultiplosDescendentes(int valor, int limite); 

int main(){
    
	int numeroIngresado;

	do {
        getNumber("Ingrese un numero entre 2 y 9: ", numeroIngresado);
	} while(numeroIngresado < 2 or numeroIngresado > 9);

    printString("\nOrden Ascendente\n");
    imprimirMultiplos(numeroIngresado, 'A');

    printString("\nOrden Inverso\n");
    imprimirMultiplos(numeroIngresado, 'D');

	return 0;
}

void printNumber(int numero) {
    cout << numero << endl;
}

void printString(string mensaje) {
    cout << mensaje;
}

void getNumber(string mensaje, int &numero) {
    printString(mensaje);
    cin >> numero;
}

void imprimirMultiplos(int valor, char orden) {
    int limite = 100;

    if (orden == 'A') {
        imprimirMultiplosAscendentes(valor, limite);
    } else {
        imprimirMultiplosDescendentes(valor, limite);
    }
}

void imprimirMultiplosAscendentes(int valor, int limite) {
    for (int i = valor; i <= limite ; i++) {
        if (i % valor == 0) {
            printNumber(i);
        }
    }
}

void imprimirMultiplosDescendentes(int valor, int limite) {
    for (int i = limite; i >=  valor; i--) {
        if (i % valor == 0) {
            printNumber(i);
        }
    }
}