#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

#define CANT_FACTURAS 20

int main(){
    mostrarTitulo("Ejercicio 4 A - Generar el archivo ingresoVentas.dat");

    tyVenta ventas[] = {
        "Juan", "Alcatel1", 2, 25, 
        "Heriberto", "Falso", 3, 8, // Erroneo
        "Carlos", "Moto3", 0, 14, // Erroneo
        "Maria", "Uauei1", 2, 32, // Erroneo
        "Juana", "Moto1", 4, 16, 
        "Diana", "Alcatel1", 5, 12, 
        "Falso", "Samsung7", 1, 20, // Erroneo
        "Marcos", "Nokia2", 3, 22, 
        "Marcos", "Uauei1", 3, 21, 
        "Natalia", "Nokia3", 4, 14, 
        "Natalia", "Moto1", 3, 16, 
        "Heriberto", "Samsung7", 1, 14,
        "Nicolas", "Moto2", 2, 6,
        "Juan", "Alcatel1", 2, 25, 
        "Falso", "Falso", 3, 8, // Erroneo
        "Carlos", "Moto3", 6, 16,
        "Maria", "Uauei1", 2, 30,
        "Juana", "Moto1", 4, 2, 
        "Diana", "Alcatel1", 5, 33, // Erroneo
        "Maria", "Samsung7", 1, 20, 
    };
    
    FILE *fichero = NULL;
    char ruta[] = "ventas.dat"; 
    char op[] = "wb";
    int size = sizeof(tyVenta);
    bool result;

    abrirArchivo(ruta, op, fichero, result);
    if (result) {
        for (int i = 0; i < CANT_FACTURAS; i++) {
            escribirArchivo(&ventas[i], size, fichero, result);
        }  
        cerrarArchivo(fichero, result);
        cout << "Archivo generado." << endl; 
    } 
    
	return EXIT_SUCCESS;
}
