#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void printMensaje(string mensaje);
void printNumero(int numero);
void getNumber(string mensaje, int &numero);
void ordenarNumeros(int &valor1, int &valor2);
void verificarExtremos(int &desde, int &hasta, int ext);
void mostrarSerie(int desde, int hasta);

int main(){
    int num1, num2, extremo;

    getNumber("Ingrese un numero: ", num1);
    getNumber("Ingrese otro numero: ", num2);
    getNumber("Presione 0 para incluir extremos o 1 para excluirlos: ", extremo);
    ordenarNumeros(num1, num2);
    verificarExtremos(num1, num2, extremo);
    mostrarSerie(num1, num2);

	return 0;
}

void printMensaje(string mensaje) {
    cout << mensaje;
}

void printNumero(int numero) {
    cout << numero << endl;
}

void getNumber(string mensaje, int &numero) {
    printMensaje(mensaje);
    cin >> numero;
}

void ordenarNumeros(int &valor1, int &valor2) {
    int aux;
    if (valor1 > valor2) {
        aux = valor1;
        valor1 = valor2;
        valor2 = aux;
    }
}

void verificarExtremos(int &desde, int &hasta, int ext) {
    desde += ext;
    hasta -= ext;
}

void mostrarSerie(int desde, int hasta) {
    while (desde <= hasta) {
        printNumero(desde);
        desde++;
    }
}