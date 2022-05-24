#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 2 - Generar archivo de telefonos");

    tyTelefono telefonos[] = {
        "Nokia1", 15999.99, 
        "Moto1", 20499.99, 
        "Alcatel1", 18499.99, 
        "Uauei1", 19899.99, 
        "Nokia2", 14499.99, 
        "Nokia3", 17599.99, 
        "Samsung7", 25299.99, 
        "Moto2", 14399.99, 
        "Moto3", 13599.99, 
        "Alcatel2", 20299.99
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
