#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPE 50
#define FIN_LINEA '\0'

void mostrarMensaje(string mensaje);
void mostrarTitulo(string mensaje);
void pasarStringACadena(string &source, char dest[]);

void mostrarPalabrasYLetras(char cadena[]);
void mostrarCantidadDePalabras(char parrafo[],int tope);
void mostrarLongitudParrafo(char parrafo[],int tope);

void pedirCadenaValida(char cadena[], int tope);

bool validarLongitudString(string texto, int tope); 
bool esCaracterEspecial(char c);


int main() {

    mostrarTitulo("Ejercicio 4");
    
    // char parrafo[TOPE] = "Esto! es una prueba: del? programa.";
    char parrafo[TOPE];
    pedirCadenaValida(parrafo, TOPE);

    mostrarPalabrasYLetras(parrafo);
    mostrarCantidadDePalabras(parrafo, TOPE);
    mostrarLongitudParrafo(parrafo, TOPE);


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

bool esCaracterEspecial(char c) {
    bool retorno = false;
    if (c == '.' or c == ',' or c == ':' or c == '!' or c == '¡' or c == '¿' or c == '?')
        retorno = true;
    return retorno;
}

bool validarLongitudString(string texto, int tope) {
    bool retorno = true;
    if (texto.length() > tope)
        retorno = false;
    return retorno;
}

void pedirCadenaValida(char cadena[], int tope) {
    string auxString;
    bool cadValida;

    do {
        cout << "Ingrese un parrafo de menos de " << tope << " caracteres: ";
        getline(cin, auxString);
        cadValida = validarLongitudString(auxString, tope - 1); // Resto 1 para incluir el '\0'
    } while (not cadValida);

    pasarStringACadena(auxString, cadena);
}

void pasarStringACadena(string &source, char dest[]){
    int i = 0, longitud = source.length();

    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = FIN_LINEA;
}

void mostrarPalabrasYLetras(char cadena[]) {
    int i = 0;
    while (cadena[i] != FIN_LINEA) {
        cout << cadena[i] << endl;
        i++;
    }
}

void mostrarCantidadDePalabras(char parrafo[],int tope) {


}

void mostrarLongitudParrafo(char parrafo[],int tope) {


}

