#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 1 - Generar archivo de promotores");

    tyPromotor promotores[] = {
        "Juan", 1.2, 
        "Heriberto", 1.3, 
        "Carlos", 1.4, 
        "Maria", 1.8, 
        "Juana", 1.7, 
        "Diana", 1.6, 
        "Leonor", 1.1, 
        "Marcos", 1.2, 
        "Natalia", 2.1, 
        "Nicolas", 2.5
    };
    FILE *fichero = NULL;
    char ruta[] = "promotores.dat"; 
    int size = sizeof(tyPromotor);

    if (abrirArchivo(ruta, "ab", fichero)) {
        for (int i = 0; i < CANT_PROM; i++) {
            if (not escribirArchivo(&promotores[i], size, fichero)) {
                cout << "Error al guardar promotor: " << promotores[i].nombre << endl; 
            }
        }
        if (not cerrarArchivo(fichero)) {
            cout << "Error al cerrar el archivo" << endl;
        }
    } else {
        cout << "Archivo no encontrado." << endl;
    }
    
	return EXIT_SUCCESS;
}
