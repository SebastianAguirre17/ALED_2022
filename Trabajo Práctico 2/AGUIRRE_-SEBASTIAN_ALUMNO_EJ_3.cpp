#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define TOPE 25
#define FIN '\n'

void buscarCaracter(char cadena[], int tope, char caracter);

int main() {
    char buscado = 'a';
    char cadena[TOPE] = "Bienvenidos a algoritmos";

    buscarCaracter(cadena, TOPE, buscado);

    return 0;
}

void buscarCaracter(char cadena[], int tope, char caracter) {
    int i = 0, cont = 0;
    while (cadena[i] != FIN) {
        if (cadena[i] == caracter) {
            cout << "Se encontró el caracter '" << caracter << "' en la posicion " << i << endl; 
            cont++;
        }
    }
}