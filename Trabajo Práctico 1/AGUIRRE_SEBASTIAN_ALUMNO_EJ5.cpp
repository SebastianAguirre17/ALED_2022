#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void printNumber(int num);
void printString(string mensaje);
void getNumber(string mensaje, int &numero);
void printCantidadPorGrupo(int cantidad, int posicion);
void printInterrumpciones(int cantidad);

string retCantidadPorGrupo(int cantidad, int posicion);

int main(){
	int i = 0; // -- DEBUG --
	int lista[] = { 4, 7, 18, 5, 189, 204, 205, 7, 8, 12, 23, 35, 2, -1}; // -- DEBUG --

	int numIngresado, anterior = -1, contGrupos = 0, acumPorGrupo = 0;
    string cantidadPorGrupo = "";

	do {
        numIngresado = lista[i]; // -- DEBUG --

        // getNumber("Ingrese un numero: ", numIngresado);

        if (numIngresado <= anterior) {
            contGrupos++;
            cantidadPorGrupo += retCantidadPorGrupo(acumPorGrupo, contGrupos);
            acumPorGrupo = 1;
        } else {
            acumPorGrupo++;
        }

        anterior = numIngresado;
        i++; // -- DEBUG --
	} while (numIngresado != -1);

    printString(cantidadPorGrupo);
    printInterrumpciones(contGrupos);
	return 0;
}

void printNumber(int num) {
    cout << num << endl;
}

void printString(string mensaje) {
    cout << mensaje;
}

void getNumber(string mensaje, int &numero) {
    printString(mensaje);
    cin >> numero;
}

void printCantidadPorGrupo(int cantidad, int posicion) {
    cout << "El grupo: " << posicion << " tiene " << cantidad << " numeros" << endl;
}

void printInterrumpciones(int cantidad) {
    cout << "El orden ascendente se interrumpio " << cantidad << " de veces." << endl;
}

string retCantidadPorGrupo(int cantidad, int posicion ){
    string mensaje = "El grupo ";
    mensaje += to_string(posicion);
    mensaje += " tiene ";
    mensaje += to_string(cantidad);
    mensaje += " numeros.\n";
    return mensaje;
}
