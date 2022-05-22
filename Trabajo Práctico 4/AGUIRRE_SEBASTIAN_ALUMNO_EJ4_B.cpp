#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"


int main(){
    mostrarTitulo("Ejercicio 4 - B");

    tyTelefono telefonos[CANT_TEL];
    tyPromotor promotores[CANT_PROM];
    tyVenta venta;
    int i = 0, size = sizeof(venta);
    FILE *fichero = NULL, *fVentasValidas = NULL, *fVentasErroneas = NULL;
    bool result, finDeArchivo;
    char rutaVentas[] = "ventas.dat";
    char opLectura[] = "rb";
    char opEscritura[] = "ab";
    char rutaTelefonos[] = "telefonos.dat";
    char rutaPromotores[] = "promotores.dat";
    char rutaVentasValidas[] = "ventasValidas.dat";
    char rutaVentasErroneas[] = "ventasErroneas.dat";

    cargarTelefonos(telefonos, CANT_TEL, rutaTelefonos, opLectura);
    cargarPromotores(promotores, CANT_PROM, rutaPromotores, opLectura);

    if (abrirArchivo(rutaVentas, opEscritura, fichero)) {
        if (abrirArchivo(rutaVentasValidas, opEscritura, fVentasValidas)) {
            if (abrirArchivo(rutaVentasErroneas, opEscritura, fVentasErroneas)) {

                leerArchivo(fichero, &venta, size, finDeArchivo, result);
                while (result and not finDeArchivo) {
                    if (validarVenta)
                    leerArchivo(fichero, &venta, size, finDeArchivo, result);
                    if (validarVenta(promotores, CANT_PROM, telefonos, CANT_TEL, venta)) {
                        if (not escribirArchivo(&venta, size, fVentasValidas)) {
                            cout << "Error al guardar venta: " << endl; 
                        }
                    } else {
                        if (not escribirArchivo(&venta, size, fVentasErroneas)) {
                            cout << "Error al guardar venta: " << endl; 
                        }
                    }
                }
                if (cerrarArchivo(fichero)) {
                    cout << "Ventas cargadas." << endl;
                }
            } else {
                cout << "Error al abrir archivo: " << rutaVentasErroneas << endl;
            }
        } else {
            cout << "Error al abrir archivo: " << rutaVentasValidas << endl;
        }

    } else {
        cout << "Error al abrir archivo: " << rutaVentas << endl;
    }

	return EXIT_SUCCESS;
}

