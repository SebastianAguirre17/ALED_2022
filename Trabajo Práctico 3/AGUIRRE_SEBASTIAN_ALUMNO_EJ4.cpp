#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 21

int main(){
    mostrarTitulo("Ejercicio 4");

    char frase[TOPE] = "satse omoc aloH";

    mostrarTitulo(frase);
    invertirFrase(frase, TOPE);
    mostrarTitulo(frase);

	return EXIT_SUCCESS;
}
