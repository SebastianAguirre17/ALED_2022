#include <iostream>
#include <cstdlib>
#include <cstdio>

#define DESDE 2
#define HASTA 9
#define TOPE 100

using namespace std;

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h"

void mostrarMultiplos(int valor, int tope);

int main(){
    
	int valor;
	pedirEnteroEnRango(valor, 2, 9);

	return 0;
}

void mostrarMultiplos(int valor, int tope, char orden) {

}

/*
Ejercicio 1: A partir de un valor ingresado por el usuario (el cual deberá estar
comprendido entre 2 y 9, inclusive), generar y mostrar todos los múltiplos del
mismo menores a 100, primero en forma ascendente y luego en sentido inverso
dentro del mismo programa.
*/