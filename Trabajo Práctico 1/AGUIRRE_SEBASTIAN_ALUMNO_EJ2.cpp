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

	int edad, mayor, menores, edadLaborar, porJubilarse;

	cout << "Ingrese la edad: ";
	cin >> edad;

	if (edad > -1 and edad < 100) {
		mayor = edad;
	}

	while(edad != -1) {
		if (edad < -1 or edad > 100) {
			cout << "Edad incorrecta!\n";
		}
		else {
			cout << "Edad correcta";
		}


		cout << "\nIngrese la edad: ";
		cin >> edad;
	}


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
    cout << "El orden ascendente se interrumpio " << cantidad << " de veces.\n\n";
}

string retCantidadPorGrupo(int cantidad, int posicion ){
    string mensaje = "El grupo ";
    mensaje += to_string(posicion);
    mensaje += " tiene ";
    mensaje += to_string(cantidad);
    mensaje += " numeros.\n";
    return mensaje;
}
