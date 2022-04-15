#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define TOPE 25
#define FIN '\0'

void buscarCaracter(char cadena[], int tope, char caracter);

int main() {
    char buscado = 'z';
    char cadena[TOPE] = "Bien";

    buscarCaracter(cadena, TOPE, buscado);

    return 0;
}

void buscarCaracter(char cadena[], int tope, char caracter) {
    int i = 0, cont = 0;
    while (cadena[i] != FIN or i <= tope) {
        if (cadena[i] == caracter) {
            cout << "Se encontro el caracter '" << caracter << "' en la posicion " << i << endl; 
            cont++;
        }
        cout << i;
        i++;
    }

    if (cont == 0) {
        cout << "El caracter no existe en el arreglo" << endl;
    } else {
        cout << endl << "El caracter '" << caracter << "' aparecio " << cont << " veces" << endl; 
    }
}