#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 50

int main(){
    mostrarTitulo("Prueba de Funciones");

    char cadena[TOPE] = "Esto es una frase de prueba!";
    char c1, c2;

    pedirDosCaracteres(c1, c2);

    while (c1 != '*') {
        existenDosCarNoConsecutivos(cadena, TOPE, c1, c2) ?
            mostrarMensaje("Estan\n") :
            mostrarMensaje("No estan\n");
        
        pedirDosCaracteres(c1, c2);
    }

	return EXIT_SUCCESS;
}

