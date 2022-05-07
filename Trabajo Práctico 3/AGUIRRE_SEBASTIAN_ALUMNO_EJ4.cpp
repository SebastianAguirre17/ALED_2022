#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 21

int main(){
    mostrarTitulo("Ejercicio 4");

    char frase[TOPE] = "satse omoc aloH";

    mostrarTitulo(frase);
    invertirFrase(frase, TOPE);
    mostrarTitulo(frase);

	return EXIT_SUCCESS;
}
