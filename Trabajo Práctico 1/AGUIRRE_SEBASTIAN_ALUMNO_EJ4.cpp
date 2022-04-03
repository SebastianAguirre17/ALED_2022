#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

void printString(string mensaje);
void getNumber(string mensaje, int &numero);
void printCantidadPorGrupo(int cantidad, int posicion);
void printInterrumpciones(int cantidad);
void clearScreen();

int main(){

	int numIngresado, anterior = -9999999, contGrupos = 0, acumPorGrupo = 0;

	do {
        getNumber("Ingrese un numero: ", numIngresado);

        if (numIngresado <= anterior) {
            contGrupos++;
            clearScreen();
            printCantidadPorGrupo(acumPorGrupo, contGrupos);
            acumPorGrupo = 1;
        } else {
            acumPorGrupo++;
        }

        anterior = numIngresado;
	} while (numIngresado != -1);

    printInterrumpciones(contGrupos);

	return 0;
}

void printString(string mensaje) {
    cout << mensaje;
}

void getNumber(string mensaje, int &numero) {
    printString(mensaje);
    cin >> numero;
}

void printCantidadPorGrupo(int cantidad, int nroGrupo) {
    cout << "El grupo: " << nroGrupo << " tiene " << cantidad << " numeros\n\n";
}

void printInterrumpciones(int cantidad) {
    cout << "El orden ascendente se interrumpio " << cantidad << " de veces.\n\n";
}

void clearScreen() {
    system("cls");
}