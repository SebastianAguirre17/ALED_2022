#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "AGUIRRE_SEBASTIAN.h" 

#define TOPE    10

struct tyEjemplo {
    int campo;
    char cadena[50];
};

int main() {
    mostrarTitulo("Aguirre Sebastian - Segudo Parcial");


	return EXIT_SUCCESS;
}

void inicializarMatriz(int matriz[][TOPE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }
}

void mostrar(tyEjemplo lista[], int tope) {
    mostrarTitulo("Lista");
    int i = 0;
    for (i = 0; i < tope; i++) {
        cout << "Ejemplo: " << lista[i].cadena << endl;
    }
}

int buscarEjemplo(tyEjemplo lista[], int tope, char cadena[]) {
    int i = 0;
    while (i < tope and strcmp(lista[i].cadena, cadena) != 0) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void cargarEjemplo(char archivo[], tyEjemplo lista[], int tope) {
    tyEjemplo ejemplo;
    int i = 0, size = sizeof(ejemplo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &ejemplo, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            lista[i++] = ejemplo;
            leerArchivo(fichero, &ejemplo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void procesarEjemplo(char archivo[]) {

    tyEjemplo ejemplo;
    FILE *fichero = NULL;
    int size = sizeof(ejemplo);
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &ejemplo, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            /* Logica del programa */


            leerArchivo(fichero, &ejemplo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}