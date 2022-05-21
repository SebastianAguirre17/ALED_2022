#ifndef _PROMOTORES_Y_TELEFONOS_H_
#define  _PROMOTORES_Y_TELEFONOS_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_PROM   30
#define CANT_PROM   10
#define TOPE_DESC   20
#define CANT_TEL    10

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

void cargarTelefonos(tyTelefono telefonos[], int tope, char nombreArchivo[], char op[]) {
    tyTelefono telefono;
    int i = 0, size = sizeof(telefono);
    FILE *fichero = NULL;
    bool result, finDeArchivo;

    if (abrirArchivo(nombreArchivo, op, fichero)) {
        leerArchivo(fichero, &telefono, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            telefonos[i++] = telefono;
            leerArchivo(fichero, &telefono, size, finDeArchivo, result);
        }
        if (cerrarArchivo(fichero)) {
            cout << "Telefonos cargados." << endl;
        }
    } else {
        cout << "Error al abrir archivo: " << nombreArchivo << endl;
    }
}

void cargarPromotores(tyPromotor promotores[], int tope, char nombreArchivo[], char op[]) {
    tyPromotor promotor;
    int i = 0, size = sizeof(promotor);
    FILE *fichero = NULL;
    bool result, finDeArchivo;

    if (abrirArchivo(nombreArchivo, op, fichero)) {
        leerArchivo(fichero, &promotor, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            promotores[i++] = promotor;
            leerArchivo(fichero, &promotor, size, finDeArchivo, result);
        }
        if (cerrarArchivo(fichero)) {
            cout << "Promotores cargados." << endl;
        }
    } else {
        cout << "Error al abrir archivo: " << nombreArchivo << endl;
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

#endif


