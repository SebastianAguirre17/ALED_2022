#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void imprimirCaracter(char c, int cant); 
void mostrarTitulo(string mensaje);

void ingresarCadenaValida(char cadena[], int tope);
void mostrarPalabrasYQLetras(char cadena[], int tope);
void mostrarCantidadDePalabras(char cadena[], int tope);
void mostrarLongitudDeParrafo(char cadena[], int tope);

void pedirString(string &str, int tope);
void convertirStringACadenaChar(string &source, char dest[]);

bool validarLongitudString(string &str, int tope);
bool esCaracterEspecial(char c);

int contarCantidadDeCaracteres(char cadena[], int tope);


#define TOPE 50

int main() {
    mostrarTitulo("TP 2 - Ejercicio 4");

    char parrafo[TOPE] = "Hola, como    estan? Bravo!! Veamos: ej4: si?"; // Cadena de prueba.
    // char parrafo[TOPE];

    // ingresarCadenaValida(parrafo, TOPE);
    mostrarPalabrasYQLetras(parrafo, TOPE);
    mostrarCantidadDePalabras(parrafo, TOPE);
    mostrarLongitudDeParrafo(parrafo, TOPE);

    return 0;
}

void imprimirCaracter(char c, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << c;
    }
}

void mostrarTitulo(string mensaje) {
    int longitud = mensaje.length();
    cout << endl;
    imprimirCaracter('*', longitud + 10);
    cout << endl << "     " << mensaje << endl;
    imprimirCaracter('*', longitud + 10);
    cout << endl << endl;
}

void ingresarCadenaValida(char cadena[], int tope) {
    string auxString;
    bool cadValida;

    do {
        pedirString(auxString, tope);
        cadValida = validarLongitudString(auxString, tope - 1); // Resto 1 para incluir el '\0'
    } while (not cadValida);

    convertirStringACadenaChar(auxString, cadena);
}

void mostrarPalabrasYQLetras(char cadena[], int tope) {
    mostrarTitulo("Punto a: Motrar Palabras y cantidad de letras");

    int i = 0, k = 0;
    char auxPalabra[tope];

    while (cadena[i] != '\0') {

        if (not esCaracterEspecial(cadena[i])) {
            auxPalabra[k] = cadena[i];
            k++;
        } else {
            if (strlen(auxPalabra) > 0) {
                auxPalabra[k] = '\0';
                cout << "La palabra '" << auxPalabra << "' tiene " << strlen(auxPalabra) << " letras." <<endl;
                auxPalabra[0] = '\0';
                k = 0;
            }
        }
        i++;
    }
    cout << endl;
    system("PAUSE");
}

void mostrarCantidadDePalabras(char cadena[], int tope) {
    mostrarTitulo("Punto b: Motrar cantidad de Palabras del parrafo");

    int cont = 0, i = 0, longitud = contarCantidadDeCaracteres(cadena, tope);

    for(i; i < longitud; i++) {
        if(esCaracterEspecial(cadena[i]) and not esCaracterEspecial(cadena[i - 1])) {
            cont++;
        }
    }

    cout << "El parrafo tiene: " << cont << " palabras." << endl << endl;  
    system("PAUSE");
}

void mostrarLongitudDeParrafo(char cadena[], int tope) {
    mostrarTitulo("Punto c: Motrar Longitud del parrafo");

    int longitud = contarCantidadDeCaracteres(cadena, tope); 
    cout << "La longitud del parrafo es de: " << longitud << " caracteres." << endl << endl;
    system("PAUSE");
}

void pedirString(string &str, int tope) {
    cout << "Ingrese un parrafo de menos de " << tope << " caracteres: ";
    getline(cin, str);
}

bool validarLongitudString(string &str, int tope) {
    bool retorno = true;

    if (str.length() > tope)
        retorno = false;

    return retorno;
}

void convertirStringACadenaChar(string &source, char dest[]) {
    int i = 0, longitud = source.length();

    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = '\0';
}

int contarCantidadDeCaracteres(char cadena[], int tope) {
    int i = 0;

    while (cadena[i] != '\0' and i < tope) {
        i++;
    }

    return i;
}

bool esCaracterEspecial(char c) {
    bool retorno = false;

    if (c == '.' or c == ',' or c == ';' or c == ':' or c == '!' or c == '¡' or c == '¿' or c == '?' or c == ' ')
        retorno = true;

    return retorno;
}
