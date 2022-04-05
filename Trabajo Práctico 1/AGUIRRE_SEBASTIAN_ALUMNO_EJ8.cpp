#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Llamado {
    string comercio;
    string codigo;
    char tipo;
    int duracion;
};

void printMensaje(string mensaje);
int getIntNumber(string mensaje);
string getString(string mensaje);

int main(){
   

	return 0;
}

void printString(string mensaje) {
    cout << mensaje;
}

int getIntNumber(string mensaje) {
    int numero;
    printString(mensaje);
    cin >> numero;
    return numero;
}

string getString(string mensaje) {
    string dato;
    printString(mensaje);
    cin >> dato;
    return dato;
}