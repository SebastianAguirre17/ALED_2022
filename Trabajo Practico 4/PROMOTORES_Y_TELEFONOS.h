#ifndef _PROMOTORES_Y_TELEFONOS_H_
#define  _PROMOTORES_Y_TELEFONOS_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_PROM   31
#define CANT_PROM   10
#define TOPE_DESC   21
#define CANT_TEL    10
#define CANT_DIAS   31


struct tyPromotor {
    char nombre[TOPE_PROM];
    float comision;
};

struct tyTelefono {
    char descripcion[TOPE_DESC];
    float precio;
};

struct tyVenta {
    char promotor[TOPE_PROM];
    char descripcion[TOPE_DESC];
    int cantidad;
    int dia;
};

void cargarTelefonos(tyTelefono telefonos[], int tope, char nombreArchivo[]) {
    tyTelefono telefono;
    int i = 0, size = sizeof(telefono);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(nombreArchivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &telefono, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            telefonos[i++] = telefono;
            leerArchivo(fichero, &telefono, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarTelefonos(tyTelefono telefonos[], int tope) {
    mostrarTitulo("Telefonos");
    int i = 0;
    for (i = 0; i < tope; i++) {
        cout << "Telefono: " << telefonos[i].descripcion << "  \tPrecio: $ " << telefonos[i].precio << endl;
    }
}

void cargarPromotores(tyPromotor promotores[], int tope, char nombreArchivo[]) {
    tyPromotor promotor;
    int i = 0, size = sizeof(promotor);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(nombreArchivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &promotor, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            promotores[i++] = promotor;
            leerArchivo(fichero, &promotor, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarPromotores(tyPromotor promotores[], int tope) {
    mostrarTitulo("Promotores");
    int i = 0;
    for (i = 0; i < tope; i++) {
        cout << "Promotor: " << promotores[i].nombre << "   \tComision: " << promotores[i].comision << " %"<< endl;
    }
}

int buscarPromotor(tyPromotor promotores[], int tope, string nombre) {
    int i = 0;
    while (i < tope and promotores[i].nombre != nombre) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

int buscarTelefono(tyTelefono telefonos[], int tope, string descripcion) {
    int i = 0;
    while (i < tope and telefonos[i].descripcion != descripcion) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

bool validarVenta(tyPromotor promotores[], int topeProm, tyTelefono telefonos[], int topeTel, tyVenta venta) {
    return (
        buscarPromotor(promotores, topeProm, venta.promotor) != EXIT_ERROR and 
        buscarTelefono(telefonos, topeTel, venta.descripcion) != EXIT_ERROR and
        venta.cantidad > 0 and venta.dia > 0 and venta.dia < 32
    ); 
}

void mostrarVenta(tyVenta venta) {
    cout << "Nombre del promotor     : " << venta.promotor << endl;
    cout << "Descripcion del telefono: " << venta.descripcion << endl;
    cout << "Cantidad Vendida        : " << venta.cantidad << endl;
    cout << "Dia del mes             : " << venta.dia << endl << endl;
    cout << endl;
}

void mostrarVentas(char nombreArchivo[]) {
    tyVenta venta;
    int i = 0, size = sizeof(venta);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(nombreArchivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            mostrarVenta(venta);
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}


#endif


