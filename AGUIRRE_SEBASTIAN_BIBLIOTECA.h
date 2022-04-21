#ifndef _AGUIRRE_SEBASTIAN_H_
#define  _AGUIRRE_SEBASTIAN_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define R_OK    0
#define R_ERROR -1

using namespace std;

// PROTOTIPOS
void mostrarCaracter(char c);
void mostrarMensaje(string msg);
void mostrarNumeroEntero(int numero);
void mostrarTitulo(string mensaje);
void mostrarArrayNumerico(int numeros[], int tope);

void repetirCaracter(char c, int cant);

int pedirEntero(string msg);
void pedirEnteroEnRango(int &valor, int desde, int hasta);
float pedirFlotante(string msg);
char pedirCaracter(string msg);
void pedirCadenaChar(string msg, char dest[], int tope);
void pedirString(string msg, string &dest);
void pedirStringConTope(string &dest, int tope);
void pedirCadenaCharValida(char cadChar[], int tope);

int contarCaracteresDeCadenaChar(char cadChar[], int tope);
int contarCaracter(char cadChar[], int tope, char c);
int buscarCaracterEnCadenaChar(char cadChar[], int tope, char c);
void copiarCadenaChar(char dest[], char source[], int tope);
void convertirStringACadenaChar(string &source, char dest[]);

void inicializarArrayNumerico(int numeros[], int tope);
void ordenamientoBurbuja(int numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);
void ordenamientoPorInsercion(int numeros[], int tope);

bool validarLongitudString(string &str, int tope);
bool validarNumeroEnRago(int valor, int min, int max);

// DESARROLLO DE FUNCIONES
void mostrarCaracter(char c) {
    cout << c;
}

void mostrarMensaje(string msg) {
    cout << msg;
}

void mostrarNumeroEntero(int numero) {
    cout << numero << endl;
}

void mostrarTitulo(string mensaje) {
    int longitud = mensaje.length();
    cout << endl;
    repetirCaracter('-', longitud + 10);
    cout << endl << "     " << mensaje << endl;
    repetirCaracter('-', longitud + 10);
    cout << endl << endl;
}

void mostrarArrayNumerico(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        cout << numeros[i] << endl;
    }
}

void repetirCaracter(char c, int cant) {
    for (int i = 0; i < cant; i++) {
        mostrarCaracter(c);
    }
}

int pedirEntero(string msg) {
    int num;
    mostrarMensaje(msg);
    cin >> num;
    return num;
}

void pedirEnteroEnRango(int &valor, int desde, int hasta) {
    do {
        cout << "Ingrese un numero entre " << desde << " y " << hasta << ": ";
        cin >> valor;
    } while (valor < desde or valor > hasta);
}

float pedirFlotante(string msg) {
    float num;
    mostrarMensaje(msg);
    cin >> num;
    return num;
}

char pedirCaracter(string msg) {
    char c;
    mostrarMensaje(msg);
    cin >> c;
    return c;
}

void pedirCadenaChar(string msg, char dest[], int tope) {
    mostrarMensaje(msg);
	cin.getline(dest, tope);
}

void pedirString(string msg, string &dest) {
    mostrarMensaje(msg);
    getline(cin, dest);
}

void pedirStringConTope(string &dest, int tope) {
    cout << "Ingrese un texto de menos de " << tope << " caracteres: ";
    getline(cin, dest);
}

void pedirCadenaCharValida(char cadChar[], int tope) {
    string auxString;
    bool cadValida;
    do {
        pedirStringConTope(auxString, tope);
        cadValida = validarLongitudString(auxString, tope);
    } while (not cadValida);
    convertirStringACadenaChar(auxString, cadChar);
} 

int contarCaracteresDeCadenaChar(char cadChar[], int tope) {
    int i = 0;
    while (cadChar[i] != '\0' and i < tope) {
        i++;
    }
    return i;
}

int contarCaracter(char cadChar[], int tope, char c) {
    int i, q = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);
    for (i = 0; i < longitud; i++) {
        if (cadChar[i] == c)
            q++;
    }

    return q;
}

int buscarCaracterEnCadenaChar(char cadChar[], int tope, char c) {
    int i = 0;
    while (i < tope and cadChar[i] != c) {
        i++;
    }
    if (i == tope) 
        i = -1;
    return i;
}

void copiarCadenaChar(char dest[], char source[], int tope) {
    int i = 0;
    while (i < tope and source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

void convertirStringACadenaChar(string &source, char dest[]) {
    int i = 0, longitud = source.length();
    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = '\0';
}

void inicializarArrayNumerico(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        numeros[i] = 0;
    }
}

void ordenamientoBurbuja(int numeros[], int tope) {
    int i, j, aux;
    for (i = 0; i < tope; i++) {
        for (j = 0; j < tope ; j++) {
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
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

bool validarLongitudString(string &str, int tope) {
    return (str.length() < tope);
}

bool validarNumeroEnRago(int valor, int min, int max) {
    return (valor > min and valor < max);
}


#endif