#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPE 41

void copiarCadena(char dest[], char source[]);
void ingresarCadenaChar(char cadch[], int tope);

int main() {
    
    char cad1[TOPE];
    char cad2[TOPE] = "universidad nacional de avellaneda";

    copiarCadena(cad1, cad2);
    ingresarCadenaChar(cad2, TOPE);
    copiarCadena(cad1, cad2);
	
    return 0;
}

void copiarCadena(char dest[], char source[]) {
    strcpy(dest, source);
    cout << endl << "Copia de cadena ... \n\n";
    cout << "Valor CAD1: " << dest << endl;
    cout << "CAD1 tiene " << strlen(dest) << " caracteres." << endl;
    cout << "\nValor CAD2: " << source << endl;
    cout << "CAD2 tiene " << strlen(source) << " caracteres.\n\n";
	system("PAUSE");
}

void ingresarCadenaChar(char cadch[], int tope) {
	cout << endl << "Ingrese nuevo contenido en CAD2: ";
	cin.getline(cadch, tope);
	system("PAUSE");
}
