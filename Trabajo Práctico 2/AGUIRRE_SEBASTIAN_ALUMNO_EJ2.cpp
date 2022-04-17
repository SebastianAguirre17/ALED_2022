#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "AGUIRRE_SEBASTIAN_BIBLIOTECA.h"

using namespace std;

#define TOPE 41

void copiarCadena(char dest[], char source[]);
void ingresarCadenaChar(char cadch[], int tope);

int main() {
    mostrarTitulo("TP 2 - Ejercicio 2");
    
    char cad1[TOPE];
    char cad2[TOPE] = "universidad nacional de avellaneda";

    copiarCadena(cad1, cad2);
    pedirCadenaCharValida(cad2, TOPE);
    copiarCadena(cad1, cad2);
	
    return 0;
}

void copiarCadena(char dest[], char source[]) {
    strcpy(dest, source);
    mostrarMensaje("\nCopiando cadena...\n\n");
    cout << "Valor CAD1: " << dest << endl;
    cout << "CAD1 tiene " << strlen(dest) << " caracteres." << endl;
    cout << "\nValor CAD2: " << source << endl;
    cout << "CAD2 tiene " << strlen(source) << " caracteres.\n\n";
}
