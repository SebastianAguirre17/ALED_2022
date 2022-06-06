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

void cargarProductos(char archivo[], Producto productos[], int topeProd, int &topeReal);
void mostrarProductos(Producto productos[], int tope);
int buscarProducto(Producto productos[], int tope, char codigo[]);

void cargarGrupos(char archivo[], Grupo grupos[], int tope);
void mostrarGrupos(Grupo grupos[], int tope);
int buscarGrupo(Grupo grupo[], int tope, int buscado);

void cargarTipos(char archivo[], TipoProd tipos[], int tope);
void mostrarTipos(TipoProd tipos[], int tope);

void cargarVentas(char archivo[], char errores[], Producto productos[], int topeProd, Grupo grupos[], int topeGrupo, 
    TipoProd tipos[], int topeTipos, float tablaTiposGrupos[][TOPE_GRUPOS]);
void acumularRecaudacionPorTipoYGrupo(Producto productos[], int posProd, int posGrupo, float tablaTiposGrupos[][TOPE_GRUPOS]);

void inicializarTablaTiposGrupos(float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);
void mostrarAcumuladoPorTipoYGrupo(float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);

int main(){
    mostrarTitulo("Ejercicio 8");

    char pathMovimientos[] = "movimientosEJ8.dat";
    char pathProductos[] = "productos.dat";
    char pathErrores[] = "errores.dat";
    char pathGrupos[] = "grupos.dat";
    char pathTipos[] = "tipos.dat";
    int cantProd = 0;
    float tablaTiposGrupos[TOPE_TIPOS][TOPE_GRUPOS];

    Producto productos[MAX_PRODUCTOS];
    TipoProd tipos[TOPE_TIPOS];
    Grupo grupos[TOPE_GRUPOS];

    inicializarTablaTiposGrupos(tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);
    cargarProductos(pathProductos, productos, MAX_PRODUCTOS, cantProd);
    cargarGrupos(pathGrupos, grupos, TOPE_GRUPOS);
    cargarTipos(pathTipos, tipos, TOPE_TIPOS);


    // mostrarProductos(productos, cantProd);
    // mostrarTipos(tipos, TOPE_TIPOS);
    // mostrarGrupos(grupos, TOPE_GRUPOS);

    //cargarVentas(pathMovimientos, pathErrores, productos, cantProd, grupos, TOPE_GRUPOS, tipos, TOPE_TIPOS, tablaTiposGrupos);

    mostrarAcumuladoPorTipoYGrupo(tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);


	return EXIT_SUCCESS;
}

void cargarProductos(char archivo[], Producto productos[], int topeProd, int &topeReal) {
    Producto producto;
    int size = sizeof(producto);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";
    topeReal = 0;

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &producto, size, finDeArchivo, result);
        while (result and not finDeArchivo and topeReal < topeProd) {
            productos[topeReal++] = producto;
            leerArchivo(fichero, &producto, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarProductos(Producto productos[], int tope) {
    mostrarTitulo("Productos");
    cout << "Indice\tCodigo\tTipo\tPrecio\tDescripcion" << endl;
    for (int i = 0; i < tope; i++) {
        cout << i << "\t" << productos[i].codigo << "\t" << productos[i].tipo << "\t$" << productos[i].precio << "\t" << productos[i].descripcion << endl;
    }
}

int buscarProducto(Producto productos[], int tope, char codigo[]) {
    int i = 0;
    while (i < tope and strcmp(productos[i].codigo, codigo) != 0) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void cargarGrupos(char archivo[], Grupo grupos[], int tope) {
    Grupo grupo;
    int i = 0, size = sizeof(grupo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &grupo, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            grupos[i++] = grupo;
            leerArchivo(fichero, &grupo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarGrupos(Grupo grupos[], int tope) {
    mostrarTitulo("Grupos");
    cout << "Edad desde\tEdad hasta" << endl;
    for (int i = 0; i < tope; i++) {
        cout << grupos[i].edadDesde << "\t\t" << grupos[i].edadHasta << endl;
    }
}

int buscarGrupo(Grupo grupo[], int tope, int buscado) {
    int i = 0;
    while (i < tope and buscado < grupo[i].edadDesde or buscado > grupo[i].edadHasta) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void cargarTipos(char archivo[], TipoProd tipos[], int tope) {
    TipoProd tipo;
    int i = 0, size = sizeof(tipo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &tipo, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            tipos[i++] = tipo;
            leerArchivo(fichero, &tipo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarTipos(TipoProd tipos[], int tope) {
    mostrarTitulo("Tipos");
    cout << "Indice\tNombre\t\tDescuento" << endl;
    for (int i = 0; i < tope; i++) {
        cout << i<< "\t" << tipos[i].nombre << "\t%" << tipos[i].descuento << endl;
    }
}

void cargarVentas(char archivo[], char errores[], Producto productos[], int topeProd, Grupo grupos[], int topeGrupo, 
    TipoProd tipos[], int topeTipos, float tablaTiposGrupos[][TOPE_GRUPOS]) {

    Venta venta;
    FILE *fichero = NULL, *ficheroE = NULL;
    int posProd, posGrupo, size = sizeof(venta);
    bool result, resultE, finDeArchivo;
    char op[] = "rb", opE[] = "wb";

    abrirArchivo(archivo, op, fichero, result);
    abrirArchivo(errores, opE, ficheroE, resultE);
    if (result and resultE) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            posProd = buscarProducto(productos, topeProd, venta.codigo);
            if (posProd != EXIT_ERROR) {
                posGrupo = buscarGrupo(grupos, topeGrupo, venta.edad);
                acumularRecaudacionPorTipoYGrupo(productos, posProd, posGrupo, tablaTiposGrupos);
                cout << posGrupo << " ";
            } else {
                escribirArchivo(&venta, size, ficheroE, resultE);
            }
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
        cerrarArchivo(ficheroE, resultE);
    } 
}

void acumularRecaudacionPorTipoYGrupo(Producto productos[], int posProd, int posGrupo, float tablaTiposGrupos[][TOPE_GRUPOS]) {
   


}

void mostrarAcumuladoPorTipoYGrupo(float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    int i, j;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "| Tipo\t| 6-10\t| 11-15\t| 16-21\t| 22-30\t| 31-35\t| 36-45\t| 46-55\t| 56-60\t| 61-70\t| 11-100|" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (i = 0; i < filas; i++) {
        cout << "| " << i << "\t|";
        for (j = 0; j < columnas; j++) {
            cout << " " << tablaTiposGrupos[i][j] << "\t|";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------" << endl;

}

void inicializarTablaTiposGrupos(float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablaTiposGrupos[i][j] = 0;
        }
    }
}

/*Se pide informar:
a) Por cada Tipo de Producto: Nombre del Tipo de Producto y Recaudación por cada Grupo de Edad.
b) Por cada Grupo de Edad: Nombre del Tipo de Producto y Cantidad de Compras.
c) Grupo de Edad en que se vendió mayor cantidad de productos con descuento.
d) Por cada Tipo de Producto: Nombre del Tipo de Producto y Porcentaje de productos vendidos en relación a la totalidad de ventas.*/