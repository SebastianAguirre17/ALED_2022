#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 
using namespace std;

#define TOPE 10

void solicitarDatos(char cadChar[], int tope, char &c1, char &c2);
void mostrarResultado(int pos);

int main(){
    mostrarTitulo("Aguirre Sebastian - Ejercicio 2 Primer Parcial");

    char cadena[TOPE];
    char car1, car2;
    int posicion;

    solicitarDatos(cadena, TOPE, car1, car2);
    posicion = buscarCaracteresEnCadenaChar(cadena, TOPE, car1, car2);
    mostrarResultado(posicion);
    
	return EXIT_SUCCESS;
}

void solicitarDatos(char cadChar[], int tope, char &c1, char &c2) {
    string texto;
    pedirCadenaCharValida(cadChar, tope);
    c1 = pedirCaracter("\nIngrese un caracter: ");
    c2 = pedirCaracter("Ingrese un caracter: ");
}

void mostrarResultado(int pos) {
    mostrarTitulo("Resultado");
    if (pos == EXIT_ERROR)
        cout << "NO ESTAN" << endl;
    else    
        cout << "AL MENOS UNO" << endl << endl;      
}

