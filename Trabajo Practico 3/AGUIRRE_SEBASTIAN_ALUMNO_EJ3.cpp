#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 100
#define MOD 100

int main(){
    mostrarTitulo("Ejercicio 3");

    int vec[TOPE], buscado;
    cargarVecRandom(vec, TOPE, MOD);
    mostrarArrayNumericoConIndice(vec, TOPE);

    ingresarEnteroPositivo(buscado, "Ingrese un numero: ");
    cout << endl << endl << "POS: " << busquedaSecuencial(vec, TOPE, buscado) << endl;

	return EXIT_SUCCESS;
}
