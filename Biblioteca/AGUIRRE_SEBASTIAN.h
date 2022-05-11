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
    cin.ignore(); // Limpiar buffer cin para usar getline
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

void invertirFrase(char cadChar[], int tope) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope), j = longitud - 1;
    char aux;

    while (cadChar[i] != FIN_LINEA and i < longitud / 2) {
        aux = cadChar[i];
        cadChar[i] = cadChar[j];
        cadChar[j] = aux;
        i++;
        j--;
    }
}

int buscarCaracteresEnCadenaChar(char cadChar[], int tope, char c1, char c2) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);

    while (i < longitud and i < tope and cadChar[i] != c1 and cadChar[i] != c2 and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i >= longitud) 
        i = EXIT_ERROR;

    return i;
}

// STRINGS
void mostrarString(string mensaje) {
    cout << mensaje;
}

bool validarLongitudString(string str, int tope) {
    return (str.length() < tope);
}

void ingresarString(string &dest, string mensaje) {
    cout << mensaje;
    getline(cin, dest);
}

void ingresarStringValido(string &dest, int min, int max, string mensaje) {
    do {
        cout << mensaje;
        getline(cin, dest);
    } while (dest.length() < min or dest.length() > max);
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
void pedirStringConTope(string &dest, int tope) {
    cout << "Ingrese un texto de menos de " << tope << " caracteres: ";
    getline(cin, dest);
}

void convertirStringACadenaChar(string source, char dest[]) {
    int i = 0, longitud = source.length();
    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = FIN_LINEA;
}

void ingresarCadenaCharValida(char cadChar[], int tope, string mensaje) {
    string auxString;
    bool cadValida;
    do {
        cout << mensaje;
        getline(cin, auxString);
        cadValida = validarLongitudString(auxString, tope);
    } while (not cadValida);
    convertirStringACadenaChar(auxString, cadChar);
} 

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
        cout << "Vuelta: " << i << endl;
        for (j = i + 1; j < tope ; j++) {
            cout << "J: " << j << endl;

            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
    }
}

void ordenamientoPorSeleccionV2(int numeros[], int tope) {
    int i, j, aux, min, max;
    for (i = 0; i < tope; i++) {
        min = max = i;
        cout << "Vuelta: " << i << endl;
        for (j = i + 1; j < tope ; j++) {
            cout << "J: " << j << endl;

            if (numeros[j] < numeros[min]) {
                min = j;
            }
            if (numeros[j] > numeros[max]) {
                max = j;
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
        aux = numeros[tope - 1];
        numeros[tope - 1] = numeros[max];
        numeros[max] = aux;
        tope--;
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
}

void cargarVecRandom(int vec[], int tope, int mod) {
    int i;
    for (i = 0; i < tope; i++) {
        vec[i] = rand() % (mod);
    }
}

int contarRepeticionesEnVecNumerico(int vec[], int tope, int buscado) {
    int i, q = 0;
    for (i = 0; i < tope; i++) {
        if (vec[i] == buscado)
            q++;
    }
    return q;
}

#endif
