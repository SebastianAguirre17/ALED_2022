#include <iostream>
#include <cstdlib>
#include <cstdio>

#define CORTE -1

using namespace std;

void mostrarMensaje(string mensaje);
void mostrarTitulo(string titulo);
void mostrarCantidadPorGrupo(int cantidad, int nroGrupo); 
void mostrarInterrumpciones(int cantidad);
int pedirNumeroEntero(string mensaje);

int main() {
    mostrarTitulo("Ejercicio 4");

    int contDeGrupos = 0, acumPorGrupo, anterior;
    int numeroIngresado = pedirNumeroEntero("Ingrese un numero: ");
    
    while (numeroIngresado != CORTE) {
        acumPorGrupo = 0;
        anterior = numeroIngresado - 1;

        while (numeroIngresado != CORTE and numeroIngresado > anterior) {
            acumPorGrupo++;
            anterior = numeroIngresado;
            numeroIngresado = pedirNumeroEntero("Ingrese un numero: ");
        }

        contDeGrupos++;
        mostrarCantidadPorGrupo(acumPorGrupo, contDeGrupos);
    }

    mostrarInterrumpciones(contDeGrupos);

	return EXIT_SUCCESS;
}   

void mostrarMensaje(string mensaje) {
    cout << mensaje;
}

void mostrarTitulo(string titulo) {
    mostrarMensaje("****************************\n");
    cout << "\t" << titulo << endl;
    mostrarMensaje("****************************\n\n");
}

void mostrarCantidadPorGrupo(int cantidad, int nroGrupo) {
    cout << "\nEl grupo " << nroGrupo << " tiene " << cantidad << " numeros\n\n";
}

void mostrarInterrumpciones(int cantidad) {
    mostrarMensaje("*************************************************\n");
    cout << "\nEl orden ascendente se interrumpio " << cantidad << " veces.\n\n";
    mostrarMensaje("*************************************************\n");
}

int pedirNumeroEntero(string mensaje) {
    int numero;
    mostrarMensaje(mensaje);
    cin >> numero;
    return numero;
}
