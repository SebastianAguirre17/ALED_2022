#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

void escribir();


int main(){
    mostrarTitulo("Prueba de Archivos");
    
    escribir();
    
	return EXIT_SUCCESS;
}

void escribir() {
    ofstream archivo;

    archivo.open("Prueba.dat", ios::out); // Apertura de archivo

    if (archivo.fail()) {
        cout << "No se puedo abrir el archivo" << endl;
        exit(1);
    }

    archivo << "Hola que tal";

    archivo.close();
}