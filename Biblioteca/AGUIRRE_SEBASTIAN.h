#ifndef _AGUIRRE_SEBASTIAN_H_
#define  _AGUIRRE_SEBASTIAN_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

#define EXIT_ERROR      -1
#define FIN_LINEA       '\0'
#define REPETICIONES    10

using namespace std;

// ENTEROS
void ingresarEntero(int &valor, string mensaje) {
    cout << mensaje;
    cin >> valor;
}

void ingresarEnteroPositivo(int &valor, string mensaje) {
    do {
        cout << mensaje;
        cin >> valor;
    } while (valor <= 0);
}

void ingresarEnteroEnRango(int &valor, int desde, int hasta, string mensaje) {
    do {
        cout << mensaje;
        cin >> valor;
    } while (valor < desde or valor > hasta);
}

// FLOTANTES
void ingresarFlotante(float &valor, string mensaje) {
    cout << mensaje;
    cin >> valor;
}

void ingresarFlotantePositivo(float &valor, string mensaje) {
    do {
        cout << mensaje;
        cin >> valor;
    } while (valor <= 0);
}

// CARACTERES
void ingresarCaracter(char &dest, string msg) {
    cout << msg;
    cin >> dest;
}

void repetirCaracter(char c, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << c;
    }
}

int contarCaracteresDeCadenaChar(char cadChar[], int tope) {
    int i = 0;
    while (cadChar[i] != FIN_LINEA and i < tope) {
        i++;
    }
    return i;
}

int buscarCaracterEnCadenaChar(char cadChar[], int tope, char c) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);

    while (i < longitud and i < tope and cadChar[i] != c and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i >= longitud) 
        i = EXIT_ERROR;

    return i;
}

bool esCaracterValido(char c, char validos[], int tope) { 
    return (buscarCaracterEnCadenaChar(validos, tope, c) != EXIT_ERROR);
}

void ingresarCaracterValido(char &dest, char validos[], int tope, string mensaje) {
    bool charValido;
    do {
        ingresarCaracter(dest, mensaje);
        charValido = esCaracterValido(dest, validos, tope);
    } while (not charValido);
}

// STRINGS
void ingresarString(string &dest, string mensaje) {
    cout << mensaje;
    getline(cin, dest);
}

void mostrarTitulo(string mensaje) {
    int longitud = mensaje.length();
    cout << endl;
    repetirCaracter('-', longitud + REPETICIONES);
    cout << endl << "     " << mensaje << endl;
    repetirCaracter('-', longitud + REPETICIONES);
    cout << endl << endl;
}


// CADENAS

// ARRAYS
void inicializarArrayNumerico(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        numeros[i] = 0;
    }
}

void ordenamientoPorSeleccion(int numeros[], int tope) {
    int i, j, aux, min;
    for (i = 0; i < tope; i++) {
        min = i;
        for (j = i + 1; j < tope ; j++) {
            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
    }
}

void ordenamientoPorInsercion(int numeros[], int tope) {
    int i, pos, aux;
    for (i = 0; i < tope; i++) {
        pos = i;
        aux = numeros[i];
        while (pos > 0 and numeros[pos -1] > aux) {
            numeros[pos] = numeros[pos - 1];
            pos--; 
        }
        numeros[pos] = aux;
    }
}

int busquedaSecuencial(int numeros[], int tope, int buscado) {
    int i = 0;
    while (i < tope and numeros[i] != buscado) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void mostrarArrayNumerico(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        cout << numeros[i] << endl;
    }
}

void mostrarArrayNumericoConIndice(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        cout << "Indice: " << i << " - Valor: " << numeros[i] << endl;
    }
    cout << endl;
}

void cargarVecRandom(int vec[], int tope, int mod) {
    int i;
    for (i = 0; i < tope; i++) {
        vec[i] = rand() % (mod);
    }
}

#endif
