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
    int size = sizeof(tyTelefono);

    if (abrirArchivo(ruta, "ab", fichero)) {
        for (int i = 0; i < CANT_TEL; i++) {
            if (not escribirArchivo(&telefonos[i], size, fichero)) {
                cout << "Error al guardar telefono: " << telefonos[i].descripcion << endl; 
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
