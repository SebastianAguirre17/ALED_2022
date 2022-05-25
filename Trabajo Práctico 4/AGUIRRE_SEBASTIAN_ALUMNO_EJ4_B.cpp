#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 4 - Punto B");

    tyTelefono telefonos[CANT_TEL];
    tyPromotor promotores[CANT_PROM];
    tyVenta venta;
    int i = 0, size = sizeof(venta);
    FILE *fichero = NULL, *fVentasValidas = NULL, *fVentasErroneas = NULL;
    bool result, resultV, resultE, finDeArchivo;
    char op[] = "rb";
    char opE[] = "wb";
    char rutaVentas[] = "ingresoVentas.dat";
    char rutaTelefonos[] = "telefonos.dat";
    char rutaPromotores[] = "promotores.dat";
    char rutaVentasValidas[] = "ventasValidas.dat";
    char rutaVentasErroneas[] = "ventasErroneas.dat";

    cargarTelefonos(telefonos, CANT_TEL, rutaTelefonos);
    // mostrarTelefonos(telefonos, CANT_TEL); // -- DEBUG -- 
    cargarPromotores(promotores, CANT_PROM, rutaPromotores);
    // mostrarPromotores(promotores, CANT_PROM); // -- DEBUG -- 

    abrirArchivo(rutaVentas, op, fichero, result);
    abrirArchivo(rutaVentasValidas, opE, fVentasValidas, resultV);
    abrirArchivo(rutaVentasErroneas, opE, fVentasErroneas, resultE);
    if (result and resultV and resultE) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            if (validarVenta(promotores, CANT_PROM, telefonos, CANT_TEL, venta)) {
                escribirArchivo(&venta, size, fVentasValidas, result);
            } else {
                escribirArchivo(&venta, size, fVentasErroneas, result);
            }
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
        cerrarArchivo(fVentasValidas, resultV);
        cerrarArchivo(fVentasErroneas, resultE);
        cout << "Archivos '" << rutaVentasValidas << "' y '" << rutaVentasErroneas << "' generados." <<  endl;
    }

	return EXIT_SUCCESS;
}

