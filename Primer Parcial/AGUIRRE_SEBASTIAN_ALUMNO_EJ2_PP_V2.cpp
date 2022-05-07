#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 
using namespace std;

#define TOPE 10

void ingresarFraseYCaracteres(char cadChar[], int tope, char &c1, char &c2);

int main(){
    mostrarTitulo("Aguirre Sebastian - Ejercicio 2 Primer Parcial");

    char cadena[TOPE];
    char car1, car2;
    int posicion;

    ingresarFraseYCaracteres(cadena, TOPE, car1, car2);

    if (buscarCaracteresEnCadenaChar(cadena, TOPE, car1, car2) != EXIT_ERROR)
        cout << "\nAL MENOS UNO\n\n";      
    else
        cout <<"\nNO ESTAN\n\n";

	return EXIT_SUCCESS;
}

void ingresarFraseYCaracteres(char cadChar[], int tope, char &c1, char &c2) {
    string texto;
    ingresarCadenaCharValida(cadChar, tope, "Ingrese una frase: ");
    ingresarCaracter(c1, "\nIngrese un caracter: ");
    ingresarCaracter(c2, "Ingrese un caracter: ");
}
