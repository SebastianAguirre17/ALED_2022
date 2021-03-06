#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 20
#define MOD 10

int main(){
    mostrarTitulo("Ejercicio 2");

    int vec[TOPE], n, cont;
    cargarVecRandom(vec, TOPE, MOD);

    mostrarArrayNumericoConIndice(vec, TOPE);
    ingresarEnteroPositivo(n, "\nIngrese el valor a buscar: ");
    cont = contarRepeticionesEnVecNumerico(vec, TOPE, n);
    cout << endl << "El numero " << n << " se repite " << cont << " veces." << endl;

	return EXIT_SUCCESS;
}
