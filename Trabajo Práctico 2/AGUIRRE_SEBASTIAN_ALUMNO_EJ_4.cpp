#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPE 200

void ingresarCadenaChar(char cadena[], int tope);
void mostrarPalabras(char cadena[], int tope); 
void contarPalabras(char cadena[], int tope);
int calcularLongitudParrafo(char cadena[], int tope);

int main() {
    
    char cadena[TOPE];    
	
    ingresarCadenaChar(cadena, TOPE);

    cout << "La cadena es: " << cadena << endl;
    cout << "La cantidad de caracteres es de: " << calcularLongitudParrafo(cadena, TOPE) << endl;

    return 0;
}

void ingresarCadenaChar(char cadena[], int tope) {
	cout << endl << "Ingrese el texto: ";
	cin.getline(cadena, tope);
}

void mostrarPalabras(char cadena[], int tope) {
    
}

void contarPalabras(char cadena[], int tope) {
    
}

int calcularLongitudParrafo(char cadena[], int tope) {
    int cant = 0;
    while (cant < tope && cadena[cant] != '\0'){
		cant++;
	}
    return cant;
}


