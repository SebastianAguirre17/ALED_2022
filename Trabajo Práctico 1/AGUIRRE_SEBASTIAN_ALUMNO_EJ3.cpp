#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h"  

using namespace std;

#define PROM_MAXIMO 20
#define TOPE_LISTA 10

int main() {
    mostrarTitulo("Ejercicio 3");

    int numeroIngresado, cantLeidos = 0, acumNumeros = 0;
    float promedio = 0;

    while (promedio < PROM_MAXIMO and cantLeidos < TOPE_LISTA) {
        ingresarEntero(numeroIngresado, "Ingrese un numero: ");
        acumNumeros += numeroIngresado;
        cantLeidos++;
        promedio = acumNumeros / cantLeidos;
        
    }
    
    cout << endl << "La cantidad de numeros ingresados fueron: " << cantLeidos << endl;

    return EXIT_SUCCESS;
}

