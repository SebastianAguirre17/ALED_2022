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

int contarCaracteres(char cadena[], int tope);
int contarPalabras(char cadena[]);
void copiarCadena(char source[], char dest[]);

void ordenamientoBurbuja(int numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);


int main(int argc, char const *argv[]) {

    /* code */
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
    cin >> texto;
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