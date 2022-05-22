#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 5");

    tyTelefono telefonos[CANT_TEL];
    tyPromotor promotores[CANT_PROM];
    tyVenta venta;
    int i = 0, size = sizeof(venta);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char rutaTelefonos[] = "telefonos.dat";
    char rutaPromotores[] = "promotores.dat";
    char rutaVentas[] = "ventasValidas.dat";
    char op[] = "rb";

    cargarTelefonos(telefonos, CANT_TEL, rutaTelefonos, op);
    cargarPromotores(promotores, CANT_PROM, rutaPromotores, op);

    if (abrirArchivo(rutaVentas, op, fichero)) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
  
            
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        if (not cerrarArchivo(fichero)) {
            cout << "Error al cerrar archivo: " << rutaVentas << endl;
        }
    } else {
        cout << "Error al abrir archivo: " << rutaVentas << endl;
    }

	return EXIT_SUCCESS;
}

void arVentas(tyVenta ventas[], char nombreArchivo[], char op[]) {
    tyVenta venta;
    int i = 0, size = sizeof(venta);
    FILE *fichero = NULL;
    bool result, finDeArchivo;

    if (abrirArchivo(nombreArchivo, op, fichero)) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            ventas[i++] = venta;
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        if (cerrarArchivo(fichero)) {
            cout << "ventaes cargados." << endl;
        }
    } else {
        cout << "Error al abrir archivo: " << nombreArchivo << endl;
    }
}