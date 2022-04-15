#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void mostrarMensaje(string mensaje);
void mostrarTitulo(string mensaje);

string pedirTexto(string mensaje);
int pedirNumeroEntero(string mensaje);
float pedirNumeroFlotante(string mensaje);
char pedirCaracter(string mensaje);
void pedirCadena(string mensaje, char cadena[], int tope);
string pedirCadenaValida(int tope); 

int contarCaracteres(char cadena[], int tope);
int contarPalabras(char cadena[]);
void copiarCadena(char source[], char dest[]);
bool esCaracterEspecial(char c);
bool validarLongitudString(string texto, int tope);
void pasarStringACadena(string &source, char dest[]);

void ordenamientoBurbuja(int numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);


int main(int argc, char const *argv[]) {

    string texto;
    mostrarMensaje("Ingrese una frase: ");
    getline (cin, texto);
    cout << texto << endl;

    return 0;
}


void mostrarMensaje(string mensaje) {
    cout << mensaje;
}

void mostrarTitulo(string titulo) {
    mostrarMensaje("****************************\n");
    cout << "\t" << titulo << endl;
    mostrarMensaje("****************************\n\n");
}

string pedirTexto(string mensaje) {
    string texto;
    mostrarMensaje(mensaje);
    getline (cin, texto);
    return texto;
}

int pedirNumeroEntero(string mensaje) {
    int numero;
    mostrarMensaje(mensaje);
    cin >> numero;
    return numero;
}

float pedirNumeroFlotante(string mensaje) {
    float numero;
    mostrarMensaje(mensaje);
    cin >> numero;
    return numero;
}

char pedirCaracter(string mensaje) {
    char caracter;
    mostrarMensaje(mensaje);
    cin >> caracter;
    return caracter;
}

void pedirCadena(string mensaje, char cadena[], int tope) {
	mostrarMensaje(mensaje);
	cin.getline(cadena, tope);
}

int contarCaracteres(char cadena[], int tope) {
    int i = 0;
    while (cadena[i] != '\0' and i < tope) {
        i++;
    }
    return i;
}

bool esCaracterEspecial(char c) {
    if (c == '.' or c == ',' or c == ':' or c == '!' or c == '¡' or c == '¿' or c == '?')
        return true;
    return false;
}

bool validarLongitudString(string texto, int tope) {
    if (texto.length() > tope)
        return false;
    return true;
}

string pedirCadenaValida(int tope) {
    string cadena;
    bool cadValida;
    do {
        cout << "Ingrese un parrafo de menos de " << tope << " caracteres: ";
        getline(cin, cadena);
        cadValida = validarLongitudString(cadena, tope);
    } while (not cadValida);

    return cadena;
}

void pasarStringACadena(string &source, char dest[]) {
    int i = 0, longitud = source.length();

    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = FIN_LINEA;
}