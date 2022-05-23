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
    char op[] = "ab";
    int size = sizeof(promotores[0]);
    bool result;

    abrirArchivo(ruta, op, fichero, result);
    if (result) {
        for (int i = 0; i < CANT_PROM; i++) {
            escribirArchivo(&promotores[i], size, fichero, result);
        }
        cerrarArchivo(fichero, result);
    }

	return EXIT_SUCCESS;
}
