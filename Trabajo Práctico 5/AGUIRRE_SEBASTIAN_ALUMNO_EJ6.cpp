#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define CANT_SUCURSALES 4
#define CANT_ARTICULOS  30

struct tyArticulo {
    int codigo;
    int sucursal;
    char movimiento;
    int cantidad;
};

void cargarArticulos(char nombreArchivo[], int tablaStock[][CANT_SUCURSALES]);
void mostrarTablaDeStock(int matriz[][CANT_SUCURSALES], int filas, int columnas);
bool validarArticulo(tyArticulo articulo);
void inicializarMatrizDeStock(int matriz[][CANT_SUCURSALES], int filas, int columnas);
void cargarArticuloEnTabla(int tablaStock[][CANT_SUCURSALES], tyArticulo articulo);
void mostrarListaDeStockNegativo(int matriz[][CANT_SUCURSALES], int filas, int columnas);

int main(){
    mostrarTitulo("Ejercicio 6");

    char archivo[] = "movimientosEJ6.dat";
    int tablaStock[CANT_ARTICULOS][CANT_SUCURSALES];
    
    inicializarMatrizDeStock(tablaStock, CANT_ARTICULOS, CANT_SUCURSALES);
    mostrarTitulo("Stock Inicial");
    mostrarTablaDeStock(tablaStock, CANT_ARTICULOS, CANT_SUCURSALES);

    cargarArticulos(archivo, tablaStock);
    mostrarTitulo("Cantidad en stock de cada articulo");
    mostrarTablaDeStock(tablaStock, CANT_ARTICULOS, CANT_SUCURSALES);

    mostrarTitulo("Articulos con saldo cero o negativo");
    mostrarListaDeStockNegativo(tablaStock, CANT_ARTICULOS, CANT_SUCURSALES);

	return EXIT_SUCCESS;
}

void cargarArticulos(char nombreArchivo[], int tablaStock[][CANT_SUCURSALES] ) {
    tyArticulo articulo;
    int size = sizeof(articulo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(nombreArchivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &articulo, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            if (validarArticulo(articulo)) {
                cargarArticuloEnTabla(tablaStock, articulo);
            }
            leerArchivo(fichero, &articulo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarTablaDeStock(int matriz[][CANT_SUCURSALES], int filas, int columnas) {
    int i, j;
    cout << "-----------------------------------------" << endl;
    cout << "| Art\t| Suc 0\t| Suc 1\t| Suc 2\t| Suc 3\t|" << endl;
    cout << "-----------------------------------------" << endl;

    for (i = 0; i < filas; i++) {
        cout << "| " << i << "\t|";
        for (j = 0; j < columnas; j++) {
            cout << " " << matriz[i][j] << "\t|";
        }
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
}

bool validarArticulo(tyArticulo articulo) {
    return (
        articulo.codigo >= 0 and articulo.codigo < 30 and
        articulo.sucursal >= 0 and articulo.sucursal < 4 and
        (articulo.movimiento == 'e' or articulo.movimiento == 's') and
        articulo.cantidad > 0
    ); 
}

void inicializarMatrizDeStock(int matriz[][CANT_SUCURSALES], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 5;
        }
    }
}

void cargarArticuloEnTabla(int tablaStock[][CANT_SUCURSALES], tyArticulo articulo) {
    if (articulo.movimiento == 'e') {
        tablaStock[articulo.codigo][articulo.sucursal] += articulo.cantidad;
    } else {
        tablaStock[articulo.codigo][articulo.sucursal] -= articulo.cantidad;
    }
}

void mostrarListaDeStockNegativo(int matriz[][CANT_SUCURSALES], int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
        if (suma <= 0) {
            cout << "El articulo " << i << " tiene stock " << suma << endl;
        }
        suma = 0;
    }
}