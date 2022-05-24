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
    bool result, finDeArchivo;
    char op[] = "rb";
    char opE[] = "wb";
    char rutaVentas[] = "ventas.dat";
    char rutaTelefonos[] = "telefonos.dat";
    char rutaPromotores[] = "promotores.dat";
    char rutaVentasValidas[] = "ventasValidas.dat";
    char rutaVentasErroneas[] = "ventasErroneas.dat";

    cargarTelefonos(telefonos, CANT_TEL, rutaTelefonos);
    cargarPromotores(promotores, CANT_PROM, rutaPromotores);

    abrirArchivo(rutaVentas, op, fichero, result);
    if (result) {
        abrirArchivo(rutaVentasValidas, opE, fVentasValidas, result);
        if (result) {
            abrirArchivo(rutaVentasErroneas, opE, fVentasErroneas, result);
            if (result) {
                leerArchivo(fichero, &venta, size, finDeArchivo, result);
                while (result and not finDeArchivo) {
                    if (validarVenta(promotores, CANT_PROM, telefonos, CANT_TEL, venta)) {
                        escribirArchivo(&venta, size, fVentasValidas, result);
                    } else {
                        escribirArchivo(&venta, size, fVentasErroneas, result);
                    }
                    leerArchivo(fichero, &venta, size, finDeArchivo, result);
                }
                cout << "Archivos generados." << endl;
                cerrarArchivo(fVentasErroneas, result);
            }
            cerrarArchivo(fVentasValidas, result);
        }
        cerrarArchivo(fichero, result);
    }

	return EXIT_SUCCESS;
}

