#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define CORTE -1

using namespace std;

void mostrarCantidadPorGrupo(int cantidad, int nroGrupo); 
void mostrarInterrumpciones(int cantidad);

int main() {
    mostrarTitulo("Ejercicio 4");

    int contDeGrupos = 0, acumPorGrupo, anterior;
    int numeroIngresado = pedirEntero("Ingrese un numero: ");
    
    while (numeroIngresado != CORTE) {
        acumPorGrupo = 0;
        anterior = numeroIngresado - 1;

        while (numeroIngresado != CORTE and numeroIngresado > anterior) {
            acumPorGrupo++;
            anterior = numeroIngresado;
            numeroIngresado = pedirEntero("Ingrese un numero: ");
        }

        contDeGrupos++;
        mostrarCantidadPorGrupo(acumPorGrupo, contDeGrupos);
    }
    mostrarInterrumpciones(contDeGrupos);

	return EXIT_SUCCESS;
}   

void mostrarCantidadPorGrupo(int cantidad, int nroGrupo) {
    cout << "\nEl grupo " << nroGrupo << " tiene " << cantidad << " numeros\n\n";
}

void mostrarInterrumpciones(int cantidad) {
    mostrarTitulo("Interrupciones");
    cout << "El orden ascendente se interrumpio " << cantidad << " veces.\n\n";
}
