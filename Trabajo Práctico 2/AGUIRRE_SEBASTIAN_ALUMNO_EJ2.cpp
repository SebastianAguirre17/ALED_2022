#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h"

using namespace std;

#define TOPE 41

void mostrarLongitudDeCadena(char cad1[], char cad2[]);

int main() {
    mostrarTitulo("TP 2 - Ejercicio 2");
    
    char cad1[TOPE];
    char cad2[TOPE] = "universidad nacional de avellaneda";

    copiarCadenaChar(cad1, cad2, TOPE);
    mostrarLongitudDeCadena(cad1, cad2);

    pedirCadenaCharValida(cad2, TOPE);
    copiarCadenaChar(cad1, cad2, TOPE);
    mostrarLongitudDeCadena(cad1, cad2);
	
    return EXIT_SUCCESS;
}

void mostrarLongitudDeCadena(char cad1[], char cad2[]) {
    cout << endl << "Valor CAD1: " << cad1 << endl;
    cout << "CAD1 tiene " << strlen(cad1) << " caracteres." << endl;
    cout << "\nValor CAD2: " << cad2 << endl;
    cout << "CAD2 tiene " << strlen(cad2) << " caracteres.\n\n";
}


