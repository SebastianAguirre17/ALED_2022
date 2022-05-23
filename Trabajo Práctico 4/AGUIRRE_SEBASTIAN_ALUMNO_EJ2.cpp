#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 2 - Generar archivo de telefonos");

    tyTelefono telefonos[] = {
        "Nokia1", 15000.00, 
        "Moto1", 20000.00, 
        "Alcatel1", 18000.00, 
        "Uauei1", 19000.00, 
        "Nokia2", 14000.00, 
        "Nokia3", 17500.00, 
        "Samsung7", 25000.00, 
        "Moto2", 14000.00, 
        "Moto3", 13500.00, 
        "Alcatel2", 20000.00
    };
    FILE *fichero = NULL;
    char ruta[] = "telefonos.dat"; 
    char op[] = "wb";
    int size = sizeof(tyTelefono);
    bool result;

    abrirArchivo(ruta, op, fichero, result);

    if (result) {
        for (int i = 0; i < CANT_TEL; i++) {
            escribirArchivo(&telefonos[i], size, fichero, result);
        }
        cerrarArchivo(fichero, result);
    } 

	return EXIT_SUCCESS;
}
