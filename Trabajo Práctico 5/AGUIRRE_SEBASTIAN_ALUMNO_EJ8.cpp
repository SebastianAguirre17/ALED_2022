#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_COD_PROD   6
#define TOPE_COD_DESC   31
#define TOPE_TIPO_PROD  31
#define MAX_PRODUCTOS   50
#define TOPE_TIPOS      12
#define TOPE_GRUPOS     10

struct Venta {
    char codigo[TOPE_COD_PROD];
    char descuento;
    int edad;
};

struct Producto {
    char codigo[TOPE_COD_PROD];
    char descripcion[TOPE_COD_DESC];
    float precio;
    int tipo;
};

struct TipoProd {
    char nombre[TOPE_TIPO_PROD];
    float descuento;
};

struct Grupo {
    int edadDesde;
    int edadHasta;
};


void cargarVentas(char archivo[]) {
    Venta venta;
    int size = sizeof(venta);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            cout << venta.codigo << " - " << venta.descuento << " - " << venta.edad << endl;
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void cargarProductos(char archivo[]) {
    Producto producto;
    int size = sizeof(producto);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &producto, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            cout << producto.codigo << " - " << producto.descripcion << " - " << producto.precio << " - " << producto.tipo << endl;
            leerArchivo(fichero, &producto, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void cargarTipos(char archivo[]) {
    TipoProd tipo;
    int size = sizeof(tipo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &tipo, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            cout << tipo.nombre << " - " << tipo.descuento << endl;
            leerArchivo(fichero, &tipo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void cargarGrupos(char archivo[]) {
    Grupo grupo;
    int size = sizeof(grupo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &grupo, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            cout << grupo.edadDesde << " - " << grupo.edadHasta << endl;
            leerArchivo(fichero, &grupo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

int main(){
    mostrarTitulo("Ejercicio 8");

    char pathMovimientos[]  = "movimientosEJ8.dat";
    char pathErrores[]      = "errores.dat";
    char pathGrupos[]       = "grupos.dat";
    char pathProductos[]    = "productos.dat";
    char pathTipos[]        = "tipos.dat";

    

    // cargarVentas(pathMovimientos);
    // cargarGrupos(pathGrupos);
    // cargarProductos(pathProductos);
    // cargarTipos(pathTipos);

	return EXIT_SUCCESS;
}
