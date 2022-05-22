#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 4");

    tyVenta ventas[] = {
        "Juan", "Alcatel1", 2, 25, 
        "Heriberto", "Falso", 3, 8,
        "Carlos", "Moto3", 0, 14, 
        "Maria", "Uauei1", 2, 32, 
        "Juana", "Moto1", 4, 26, 
        "Diana", "Alcatel1", 5, 12, 
        "Falso", "Samsung7", 1, 20, 
        "Marcos", "Nokia2", 3, 22, 
        "Natalia", "Nokia3", 4, 10, 
        "Nicolas", "Moto2", 2, 6
    };
    
    FILE *fichero = NULL;
    char ruta[] = "ventas.dat"; 
    char op[] = "ab";
    int size = sizeof(tyVenta);

    if (abrirArchivo(ruta, op, fichero)) {
        for (int i = 0; i < 10; i++) {
            if (not escribirArchivo(&ventas[i], size, fichero)) {
                cout << "Error al guardar venta" << endl; 
            }
        }
        if (cerrarArchivo(fichero)) {
            cout << "Archivo de ventas guardado." << endl;
        }
    } else {
        cout << "Archivo no encontrado." << endl;
    }

	return EXIT_SUCCESS;
}
