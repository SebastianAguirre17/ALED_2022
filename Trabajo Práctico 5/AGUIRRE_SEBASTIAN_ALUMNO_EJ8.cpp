#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
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

void cargarVentas(char archivo[], char errores[], Producto productos[], int topeProd, Grupo grupos[], int topeGrupo, TipoProd tipos[], int topeTipos, 
    float tablaTiposGrupos[][TOPE_GRUPOS], int acumGrupoConDescuento[], int acumVentasPorTipo[], int &totalVentas);

void cargarProductos(char archivo[], Producto productos[], int topeProd, int &topeReal);
void cargarTipos(char archivo[], TipoProd tipos[], int tope);
void cargarGrupos(char archivo[], Grupo grupos[], int tope);

int buscarProducto(Producto productos[], int tope, char codigo[]);
int buscarGrupo(Grupo grupo[], int tope, int buscado);

void inicializarTablaTiposGrupos(float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);

void acumularRecaudacionPorTipoYGrupo(float tablaTiposGrupos[][TOPE_GRUPOS], int posGrupo, int posTipo, char descontar, float precio, float porcentaje);
void acumularVentasConDescuento(int acumulador[], int posGrupo);
void acumularVentasPorTipo(int acumVentasPorTipo[], int posTipo);

void mostrarRecaudacionPorTipoYGrupo(TipoProd tipos[], Grupo grupos[], float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);
void mostrarGrupoDeMayorVentaConDescuento(Grupo grupos[], int acumulador[], int tope);
void mostrarPorcentajesDeVentasPorTipo(TipoProd tipos[], int acumVentasPorTipo[], int tope, int totalVentas);

int main(){
    char pathMovimientos[] = "movimientosEJ8.dat";
    char pathProductos[] = "productos.dat";
    char pathErrores[] = "errores.dat";
    char pathGrupos[] = "grupos.dat";
    char pathTipos[] = "tipos.dat";

    int cantidadDeProductos = 0;
    int cantidadDeVentas = 0;

    float tablaTiposGrupos[TOPE_TIPOS][TOPE_GRUPOS];
    int acumGrupoConDescuento[TOPE_GRUPOS];
    int acumVentasPorTipo[TOPE_TIPOS];

    Producto productos[MAX_PRODUCTOS];
    TipoProd tipos[TOPE_TIPOS];
    Grupo grupos[TOPE_GRUPOS];

    inicializarTablaTiposGrupos(tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);
    inicializarArrayNumerico(acumGrupoConDescuento, TOPE_GRUPOS);
    inicializarArrayNumerico(acumVentasPorTipo, TOPE_TIPOS);

    cargarProductos(pathProductos, productos, MAX_PRODUCTOS, cantidadDeProductos);
    cargarGrupos(pathGrupos, grupos, TOPE_GRUPOS);
    cargarTipos(pathTipos, tipos, TOPE_TIPOS);

    cargarVentas(pathMovimientos, pathErrores, productos, MAX_PRODUCTOS, grupos, TOPE_GRUPOS, tipos, TOPE_TIPOS, 
        tablaTiposGrupos, acumGrupoConDescuento, acumVentasPorTipo, cantidadDeVentas);

    // mostrarRecaudacionPorTipoYGrupo(tipos, grupos, tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);
    // mostrarComprasPorGrupo();
    // mostrarGrupoDeMayorVentaConDescuento(grupos, acumGrupoConDescuento, TOPE_GRUPOS);
    // mostrarPorcentajesDeVentasPorTipo(tipos, acumVentasPorTipo, TOPE_TIPOS, cantidadDeVentas);

	return EXIT_SUCCESS;
}

void cargarVentas(char archivo[], char errores[], Producto productos[], int topeProd, Grupo grupos[], int topeGrupo, TipoProd tipos[], int topeTipos, 
    float tablaTiposGrupos[][TOPE_GRUPOS], int acumGrupoConDescuento[], int acumVentasPorTipo[], int &totalVentas) {

    Venta venta;
    FILE *fichero = NULL, *ficheroE = NULL;
    int posProd, posGrupo, posTipo, size = sizeof(venta);
    bool result, resultE, finDeArchivo;
    char op[] = "rb", opE[] = "wb";

    abrirArchivo(archivo, op, fichero, result);
    abrirArchivo(errores, opE, ficheroE, resultE);
    if (result and resultE) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            //cout << venta.codigo << " " << venta.descuento << " " << venta.edad << endl;
            
            posProd = buscarProducto(productos, topeProd, venta.codigo);
            if (posProd != EXIT_ERROR) {
                totalVentas++;
                posGrupo = buscarGrupo(grupos, topeGrupo, venta.edad);
                posTipo = productos[posProd].tipo - 1; // Para coincidir con posicion en vector
                
                acumularRecaudacionPorTipoYGrupo(tablaTiposGrupos, posGrupo, posTipo, venta.descuento, productos[posProd].precio, tipos[posTipo].descuento);
                acumularVentasPorTipo(acumVentasPorTipo, posTipo);
                if (venta.descuento == 'S') {
                    acumularVentasConDescuento(acumGrupoConDescuento, posGrupo);
                }
            } else {
                escribirArchivo(&venta, size, ficheroE, resultE);
            }
            leerArchivo(fichero, &venta, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
        cerrarArchivo(ficheroE, resultE);
    } 
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
            // cout << producto.codigo << " " << producto.tipo << " " << producto.precio << " " << producto.descripcion << endl;
            leerArchivo(fichero, &producto, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
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
            // cout << grupo.edadDesde << " " << grupo.edadHasta << endl;
            leerArchivo(fichero, &grupo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
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
            // cout << tipo.nombre << " " << tipo.descuento << endl;
            leerArchivo(fichero, &tipo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
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

int buscarGrupo(Grupo grupo[], int tope, int buscado) {
    int i = 0;
    while (i < tope and buscado < grupo[i].edadDesde or buscado > grupo[i].edadHasta) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void inicializarTablaTiposGrupos(float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablaTiposGrupos[i][j] = 0;
        }
    }
}

void acumularRecaudacionPorTipoYGrupo(float tablaTiposGrupos[][TOPE_GRUPOS], int posGrupo, int posTipo, char descontar, float precio, float porcentaje) {
    if (descontar == 'S') {
        tablaTiposGrupos[posTipo][posGrupo] += (precio - (precio * porcentaje)); 
    } else {
        tablaTiposGrupos[posTipo][posGrupo] += precio; 
    }  
}

void acumularVentasConDescuento(int acumulador[], int posGrupo) {
    acumulador[posGrupo]++;
}

void acumularVentasPorTipo(int acumVentasPorTipo[], int posTipo) {
    acumVentasPorTipo[posTipo]++;
}

void mostrarRecaudacionPorTipoYGrupo(TipoProd tipos[], Grupo grupos[], float tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    mostrarTitulo("Punto A - Tipo de Producto y Recaudacion por Grupo de Edad");
    int i = 0, j = 0;
    while (i < filas) {
        mostrarTitulo(tipos[i].nombre);
        while (j < columnas) {
            cout << "Grupo [" << grupos[j].edadDesde << "-" << grupos[j].edadHasta << "]:\t$ " << tablaTiposGrupos[i][j] << endl;
            j++;
        }
        j = 0;
        i++;
    }
}

void mostrarGrupoDeMayorVentaConDescuento(Grupo grupos[], int acumulador[], int tope) {
    mostrarTitulo("Punto C - Grupo de mayor cantidad de productos con descuento");

    int posMax;
    buscarPosMaxEnArrayNumerico(acumulador, tope, posMax);
    cout << "El grupo " << posMax << " [" << grupos[posMax].edadDesde << "-" << grupos[posMax].edadHasta << "] vendio " << acumulador[posMax] << " productos con descuento" << endl;
}

void mostrarPorcentajesDeVentasPorTipo(TipoProd tipos[], int acumVentasPorTipo[], int tope, int totalVentas) {
    mostrarTitulo("Punto D - Porcentaje de vendidos por Tipo");
    double porcentaje;
    for (int i = 0; i < tope; i++) {
        porcentaje = acumVentasPorTipo[i] * 100 / (float)totalVentas;
        cout << "El tipo '" << tipos[i].nombre << "' represento el " << std::fixed << std::setprecision(2) << porcentaje << " % de las ventas" <<endl;
    }
}