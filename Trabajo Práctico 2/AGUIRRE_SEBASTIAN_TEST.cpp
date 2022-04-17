#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "AGUIRRE_SEBASTIAN.h"

using namespace std;

#define TOPE 5

int main() {
    
    // int numeros[TOPE] = {3, 0, 7, 2, 8, 9, 4, 5, 6, 1};

    // ordenamientoPorSeleccion(numeros, TOPE);
    // mostrarArrayNumerico(numeros, TOPE);
     char cadena[TOPE];

    pedirCadenaCharValida("Ingrese una cadena de menos de 20 caracteres: ", cadena, TOPE);

    return 0;
}
