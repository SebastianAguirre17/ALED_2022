#ifndef _AGUIRRE_SEBASTIAN_H_
#define  _AGUIRRE_SEBASTIAN_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define EXIT_ERROR      -1
#define FIN_LINEA       '\0'
#define REPETICIONES    10

using namespace std;

// PROTOTIPOS
void mostrarCaracter(char c);
void mostrarMensaje(string msg);
void mostrarNumeroEntero(int numero);
void mostrarTitulo(string mensaje);
void mostrarArrayNumerico(int numeros[], int tope);

int pedirEntero(string msg);
int pedirEnteroPositivo(string msg);
int pedirEnteroMayorA(string msg, int min);
float pedirFlotante(string msg);
float pedirFlotanteMayorA(string msg, int min);
char pedirCaracter(string msg);
string retornarString(string mensaje);
void pedirEnteroEnRango(int &valor, int desde, int hasta);
void pedirDosCaracteres(char &c1, char &c2);
void pedirCaracterValido(char &dest, char validos[], int tope);
void pedirCadenaChar(string msg, char dest[], int tope);
void pedirString(string msg, string &dest);
void pedirStringConTope(string &dest, int tope);
void pedirCadenaCharValida(char cadChar[], int tope);

int contarCaracteresDeCadenaChar(char cadChar[], int tope);
int contarCaracter(char cadChar[], int tope, char c);
int buscarCaracterEnCadenaChar(char cadChar[], int tope, char c);
int buscarDosCarConsecutivos(char cadchar[], int tope, char car1, char car2);
int buscarCaracteresEnCadenaChar(char cadChar[], int tope, char &c1, char &c2);
void copiarCadenaChar(char dest[], char source[], int tope);
void convertirStringACadenaChar(string source, char dest[]);

void inicializarArrayNumerico(int numeros[], int tope);
void ordenamientoBurbuja(int numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);
void ordenamientoPorInsercion(int numeros[], int tope);
int busquedaSecuencial(int numeros[], int tope, int buscado);
int busquedaBinaria(int numeros[], int tope, int buscado);

void repetirCaracter(char c, int cant);
int calcularNumeroInverso(int num);
int sumarDivisores(int num);

bool existenDosCarNoConsecutivos(char cadChar[], int tope, char car1, char car2);
bool validarLongitudString(string str, int tope);
bool validarNumeroEnRago(int valor, int min, int max);
bool esCaracterValido(char c, char validos[], int tope);
bool esNumeroCapicua(int num);
bool sonNumerosAmigos(int num1, int num2);
bool esNumeroPar(int num);

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
    repetirCaracter('-', longitud + REPETICIONES);
    cout << endl << "     " << mensaje << endl;
    repetirCaracter('-', longitud + REPETICIONES);
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

int pedirEnteroPositivo(string msg) {
    int num;
    do {
        mostrarMensaje(msg);
        cin >> num;
    } while (num < 0);
    return num;
}

int pedirEnteroMayorA(string msg, int min) {
    int num;
    do {
        mostrarMensaje(msg);
        cin >> num;
    } while (num <= min);
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

float pedirFlotanteMayorA(string msg, int min) {
    float num;
    do {
        mostrarMensaje(msg);
        cin >> num;
    } while (num <= min);
    return num;
}

char pedirCaracter(string msg) {
    char c;
    mostrarMensaje(msg);
    cin >> c;
    return c;
}

void pedirDosCaracteres(char &c1, char &c2) {
    c1 = pedirCaracter("Ingrese un caracter: ('*' para cancelar): ");
    if (c1 != '*') {
        c2 = pedirCaracter("Ingrese un caracter: ");
    }
}

void pedirCadenaChar(string msg, char dest[], int tope) {
    mostrarMensaje(msg);
	cin.getline(dest, tope);
}

void pedirString(string msg, string &dest) {
    mostrarMensaje(msg);
    getline(cin, dest);
}

string retornarString(string mensaje) {
    string msg;
    mostrarMensaje(mensaje);
    cin >> msg;
    return msg;
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
    while (cadChar[i] != FIN_LINEA and i < tope) {
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
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);

    while (i < longitud and i < tope and cadChar[i] != c and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i >= longitud) 
        i = EXIT_ERROR;

    return i;
}

int buscarCaracterEnRango(char cadChar[], int desde, int hasta, char c) {
    int i = desde;

    while (i < hasta and cadChar[i] != c and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i == hasta) 
        i = EXIT_ERROR;
    return i;
}

int buscarDosCarConsecutivos(char cadChar[], int tope, char car1, char car2) {
    int i = 0, pos, longitud = contarCaracteresDeCadenaChar(cadChar, tope) - 1;
    while (i < tope and i < longitud and (cadChar[i] != car1 or cadChar[i + 1] != car2)) {
        i++;
    }
    pos = i < longitud ? i : EXIT_ERROR;
    return pos;
}

bool existenDosCarNoConsecutivos(char cadChar[], int tope, char car1, char car2) {
    int i, longitud = contarCaracteresDeCadenaChar(cadChar, tope);
    bool ret;
    i = buscarCaracterEnRango(cadChar, 0, longitud, car1);  
    if (i != EXIT_ERROR) {
        i = buscarCaracterEnRango(cadChar, i, longitud, car2);
        ret = i != EXIT_ERROR;   
    }
    return ret;
}

void copiarCadenaChar(char dest[], char source[], int tope) {
    int i = 0;
    while (i < tope and source[i] != FIN_LINEA) {
        dest[i] = source[i];
        i++;
    }
    dest[i] = FIN_LINEA;
}

void convertirStringACadenaChar(string source, char dest[]) {
    int i = 0, longitud = source.length();
    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = FIN_LINEA;
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

bool validarLongitudString(string str, int tope) {
    return (str.length() < tope);
}

bool validarNumeroEnRango(int valor, int min, int max) {
    return (valor >= min and valor <= max);
}

bool validarNumeroEnRangoExcluyente(int valor, int min, int max) {
    return (valor > min and valor < max);
}

void pedirCaracterValido(char &dest, char validos[], int tope, string mensaje) {
    bool charValido;
    do {
        dest = pedirCaracter(mensaje);
        charValido = esCaracterValido(dest, validos, tope);
    } while (not charValido);
}

bool esCaracterValido(char c, char validos[], int tope) { 
    return (buscarCaracterEnCadenaChar(validos, tope, c) != EXIT_ERROR);
}

int calcularNumeroInverso(int num) {
    int inv = 0;
    while (num > 0) {
        inv = num % 10 + inv * 10;
        num = num / 10;
    }
    return inv;
}

bool esNumeroCapicua(int num) {
    return (num == calcularNumeroInverso(num));
}

bool sonNumerosAmigos(int num1, int num2) {
    int div1 = sumarDivisores(num1);
    int div2 = sumarDivisores(num2);

    return (num1 == div2 and num2 == div1);
}

int sumarDivisores(int num) {
    int div = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            div += i;
    }
    return div;
}   

bool esNumeroPar(int num) {
    return (num % 2 == 0);
}

int busquedaSecuencial(int numeros[], int tope, int buscado) {
    int i = 0;
    bool encontrado = false;

    while (not encontrado and i < tope) {
        if (numeros[i] == buscado)
            encontrado = true;
        i++;
    }
    i = encontrado ? i - 1 : EXIT_ERROR;
    return i;
} 

int busquedaBinaria(int numeros[], int tope, int buscado) {
    int inf = 0, sup = tope, mitad;
    bool encontrado = false;

    while (not encontrado and inf <= sup) {
        mitad = (inf + sup) / 2;

        if (numeros[mitad] == buscado) {
            encontrado = true;
        }
        if (numeros[mitad] > buscado) {
            sup = mitad;
            mitad = (inf + sup) / 2;
        }
        if (numeros[mitad] < buscado) {
            inf = mitad;
            mitad = (inf + sup) / 2;
        }
    }

    mitad = encontrado ? mitad : EXIT_ERROR;
    return mitad;
} 

int buscarCaracteresEnCadenaChar(char cadChar[], int tope, char &c1, char &c2) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);
    bool encontrado = false;

    while (not encontrado and i < tope and i < longitud and cadChar[i] != FIN_LINEA) {
        if (cadChar[i] == c1 or cadChar[i] == c2) {
            encontrado = true;
            i--;
        }
        i++;
    }
    if (not encontrado)
        i = EXIT_ERROR;

    return i;
}

#endif
