#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h"

using namespace std;

#define TOPE        200
#define TOPE_ESP    8

bool esCaracterValido(char c) { 
    char caracteresEspeciales[TOPE_ESP] = {' ', '!', '?', '.', ':', ',', ';'};
    return (buscarCaracterEnCadenaChar(caracteresEspeciales, TOPE_ESP, c) == EXIT_ERROR);
}

void saltarCaracteresEspeciales(int &i, char cadChar[], int tope) {
    while (i < tope and not esCaracterValido(cadChar[i])) {
        i++;
    }
}

void mostrarPalabrasYContarLetras(int &i, char cadChar[], int tope, int &qLetras, int longitud) {
    mostrarCaracter('\'');
    while (i < longitud and esCaracterValido(cadChar[i]) and cadChar[i] != '\0') {
        mostrarCaracter(cadChar[i]);
        qLetras++;
        i++;
    }
    mostrarCaracter('\'');
}

void mostrarCantidadDeLetras(int qLetras) {
    cout << " tiene " << qLetras << " letras." << endl;
}

void procesarParrafo(char cadChar[], int tope, int &qPalabras) {
    mostrarTitulo("Punto a: Mostrar Palabras y cantidad de letras");

    int i = 0, qLetras, longitud = contarCaracteresDeCadenaChar(cadChar, tope);

    saltarCaracteresEspeciales(i, cadChar, tope);
    while (i < tope and i < longitud and cadChar[i] != '\0') {
        qLetras = 0;
        mostrarPalabrasYContarLetras(i, cadChar, tope, qLetras, longitud);
        mostrarCantidadDeLetras(qLetras);
        qPalabras++;
        saltarCaracteresEspeciales(i, cadChar, tope);
    }
}

void mostrarCantidadDePalabras(int qPalabras) {
    mostrarTitulo("Punto b: Mostrar cantidad de Palabras del parrafo");

    cout << "El parrafo tiene: " << qPalabras << " palabras." << endl;  
}

void mostrarLongitudDeParrafo(char cadChar[], int tope) {
    mostrarTitulo("Punto c: Mostrar Longitud del parrafo");

    cout << "La longitud del parrafo es de: " << contarCaracteresDeCadenaChar(cadChar, tope) << " caracteres." << endl;
}

int main() {
    mostrarTitulo("TP 2 - Ejercicio 4");

    int cantDePalabras = 0;
    // char parrafo[TOPE] = "??Hola, como estan? Bravo!! Veamos: ej4: Si?"; // Parrafo de prueba
    char parrafo[TOPE];
    pedirCadenaCharValida(parrafo, TOPE);

    if (strlen(parrafo) > 0) {
        procesarParrafo(parrafo, TOPE, cantDePalabras);
        mostrarCantidadDePalabras(cantDePalabras);
        mostrarLongitudDeParrafo(parrafo, TOPE);
    } else {
        mostrarMensaje("\nNo ha ingresado una frase, asi que aqui nos despedimos.\nGracias por usar este programa.\n\n");
    }


    return EXIT_SUCCESS;
}

