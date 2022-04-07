#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

void printString(string mensaje);
void getNumber(string mensaje, int &numero);
void printCantidadPorGrupo(int cantidad, int posicion);
void printInterrumpciones(int cantidad);
void solicitarNumeros(int &contGrupos);
void printTitulo(string titulo);

int main() {
    printTitulo("Ejercicio 4");

	int contGrupos = 0;
    solicitarNumeros(contGrupos);

    if (contGrupos == 0) {
        printString("\nGracias por utilizar este simple programa.\n");
    } else {
        printInterrumpciones(contGrupos);
    }

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
    cout << "\nEl grupo: " << nroGrupo << " tiene " << cantidad << " numeros\n\n";
}

void printInterrumpciones(int cantidad) {
    printString("*************************************************\n");
    cout << "\nEl orden ascendente se interrumpio " << cantidad << " de veces.\n\n";
    printString("*************************************************\n");
}

void solicitarNumeros(int &contGrupos) {
    int numIngresado, anterior = -9999999, acumPorGrupo = 0;

    do {
        getNumber("Ingrese un numero (-1 para salir): ", numIngresado);

        if (numIngresado <= anterior) {
            contGrupos++;
            printCantidadPorGrupo(acumPorGrupo, contGrupos);
            acumPorGrupo = 1;
        } else {
            acumPorGrupo++;
        }

        anterior = numIngresado;
	} while (numIngresado != -1);
}

void printTitulo(string titulo) {
    printString("****************************\n");
    cout << "\t" << titulo << endl;
    printString("****************************\n\n");
}