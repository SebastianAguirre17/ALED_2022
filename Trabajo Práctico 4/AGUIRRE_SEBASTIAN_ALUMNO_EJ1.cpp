#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 1 - Generar archivo de promotores");

    tyPromotor promotores[] = {
        "Juan",     2.2, 
        "Carlos",   2.4, 
        "Maria",    2.8, 
        "Juana",    2.7, 
        "Diana",    2.6, 
        "Leonor",   3.1, 
        "Marcos",   3.2, 
        "Natalia",  2.1, 
        "Nicolas",  2.5,
        "Heriberto",3.3
    };
    FILE *fichero = NULL;
    char ruta[] = "promotores.dat"; 
    char op[] = "wb";
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
