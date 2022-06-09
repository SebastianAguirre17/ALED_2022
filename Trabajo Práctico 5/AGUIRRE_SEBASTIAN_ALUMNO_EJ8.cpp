#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "AGUIRRE_SEBASTIAN.h" 

#define TOPE_COD_PROD   6
#define TOPE_COD_DESC   31
#define TOPE_TIPO_PROD  31
#define MAX_PRODUCTOS   50
#define TOPE_TIPOS      12
#define TOPE_GRUPOS     10
#define EDAD_MINIMA     6
#define EDAD_MAXIMA     100

struct tyVenta {
    char codigo[TOPE_COD_PROD];
    char descuento;
    int edad;
};

struct tyProducto {
    char codigo[TOPE_COD_PROD];
    char descripcion[TOPE_COD_DESC];
    float precio;
    int tipo;
};

struct tyTipoProd {
    char nombre[TOPE_TIPO_PROD];
    float descuento;
};

struct tyGrupo {
    int edadDesde;
    int edadHasta;
};

struct tyAcumulador {
    int cantidad;
    float importe;
};

void procesarVentas(char archivo[], char errores[], tyProducto productos[], int topeProd, tyGrupo grupos[], int topeGrupo, tyTipoProd tipos[], 
    tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int acumGrupoConDescuento[], int acumVentasPorTipo[], int &totalVentas);
bool validarVenta(tyProducto productos[], int topeProd, tyVenta venta, int &posProd);
bool validarEdad(int edad);
bool validarOpcionDescuento(char d);
void cargarProductos(char archivo[], tyProducto productos[], int topeProd, int &topeReal);
void cargarTipos(char archivo[], tyTipoProd tipos[], int tope);
void cargarGrupos(char archivo[], tyGrupo grupos[], int tope);
int buscarProducto(tyProducto productos[], int tope, char codigo[]);
int buscarGrupo(tyGrupo grupo[], int tope, int buscado);
void inicializarTablaTiposGrupos(tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);
void acumularRecYCantPorTipoYGrupo(tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int posGrupo, int posTipo, float precio);
void acumularVentasConDescuento(int acumulador[], int posGrupo);
void acumularVentasPorTipo(int acumVentasPorTipo[], int posTipo);
void contarVentas(int &totalVentas);
float calcularPrecio(char descontar, tyProducto productos[], tyTipoProd tipos[], int posProd, int posTipo);
void mostrarRecaudacionPorTipoYGrupo(tyTipoProd tipos[], tyGrupo grupos[], tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);
void mostrarGrupoDeMayorVentaConDescuento(tyGrupo grupos[], int acumulador[], int tope);
void mostrarPorcentajesDeVentasPorTipo(tyTipoProd tipos[], int acumVentasPorTipo[], int tope, int totalVentas);
void mostrarComprasPorGrupo(tyTipoProd tipos[], tyGrupo grupos[], tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas);

int main(){
    char pathMovimientos[] = "movimientosEJ8.dat";
    char pathProductos[] = "productos.dat";
    char pathErrores[] = "errores.dat";
    char pathGrupos[] = "grupos.dat";
    char pathTipos[] = "tipos.dat";

    int cantidadDeProductos = 0;
    int cantidadDeVentas = 0;

    tyAcumulador tablaTiposGrupos[TOPE_TIPOS][TOPE_GRUPOS];
    int acumGrupoConDescuento[TOPE_GRUPOS];
    int acumVentasPorTipo[TOPE_TIPOS];

    tyProducto productos[MAX_PRODUCTOS];
    tyTipoProd tipos[TOPE_TIPOS];
    tyGrupo grupos[TOPE_GRUPOS];

    inicializarTablaTiposGrupos(tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);
    inicializarArrayNumerico(acumGrupoConDescuento, TOPE_GRUPOS);
    inicializarArrayNumerico(acumVentasPorTipo, TOPE_TIPOS);

    cargarProductos(pathProductos, productos, MAX_PRODUCTOS, cantidadDeProductos);
    cargarGrupos(pathGrupos, grupos, TOPE_GRUPOS);
    cargarTipos(pathTipos, tipos, TOPE_TIPOS);

    procesarVentas(pathMovimientos, pathErrores, productos, MAX_PRODUCTOS, grupos, TOPE_GRUPOS, tipos, 
        tablaTiposGrupos, acumGrupoConDescuento, acumVentasPorTipo, cantidadDeVentas);

    mostrarRecaudacionPorTipoYGrupo(tipos, grupos, tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);
    mostrarComprasPorGrupo(tipos, grupos, tablaTiposGrupos, TOPE_TIPOS, TOPE_GRUPOS);
    mostrarGrupoDeMayorVentaConDescuento(grupos, acumGrupoConDescuento, TOPE_GRUPOS);
    mostrarPorcentajesDeVentasPorTipo(tipos, acumVentasPorTipo, TOPE_TIPOS, cantidadDeVentas);

	return EXIT_SUCCESS;
}

void procesarVentas(char archivo[], char errores[], tyProducto productos[], int topeProd, tyGrupo grupos[], int topeGrupo, tyTipoProd tipos[], 
    tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int acumGrupoConDescuento[], int acumVentasPorTipo[], int &totalVentas) {

    tyVenta venta;
    FILE *fichero = NULL, *ficheroE = NULL;
    int posProd, posGrupo, posTipo, size = sizeof(venta);
    float precio;
    bool result, resultE, finDeArchivo;
    char op[] = "rb", opE[] = "wb";

    abrirArchivo(archivo, op, fichero, result);
    abrirArchivo(errores, opE, ficheroE, resultE);
    if (result and resultE) {
        leerArchivo(fichero, &venta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
            if (validarVenta(productos, topeProd, venta, posProd)) {
                posGrupo = buscarGrupo(grupos, topeGrupo, venta.edad);
                posTipo = productos[posProd].tipo - 1; // Para coincidir con posicion en vector
                precio = calcularPrecio(venta.descuento, productos, tipos, posProd, posTipo);
                contarVentas(totalVentas);
                acumularRecYCantPorTipoYGrupo(tablaTiposGrupos, posGrupo, posTipo, precio);
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

bool validarVenta(tyProducto productos[], int topeProd, tyVenta venta, int &posProd) {
    posProd = buscarProducto(productos, topeProd, venta.codigo);
    return (posProd != EXIT_ERROR and validarEdad(venta.edad) and validarOpcionDescuento(venta.descuento));
}

bool validarEdad(int edad) {
    return (edad >= EDAD_MINIMA and edad <= EDAD_MAXIMA);
}

bool validarOpcionDescuento(char d) {
    return (d == 'S' or d == 'N');
}

void cargarProductos(char archivo[], tyProducto productos[], int topeProd, int &topeReal) {
    tyProducto producto;
    int size = sizeof(producto);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

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

void cargarGrupos(char archivo[], tyGrupo grupos[], int tope) {
    tyGrupo grupo;
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

void cargarTipos(char archivo[], tyTipoProd tipos[], int tope) {
    tyTipoProd tipo;
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

int buscarProducto(tyProducto productos[], int tope, char codigo[]) {
    int i = 0;
    while (i < tope and strcmp(productos[i].codigo, codigo) != 0) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

int buscarGrupo(tyGrupo grupo[], int tope, int buscado) {
    int i = 0;
    while (i < tope and buscado < grupo[i].edadDesde or buscado > grupo[i].edadHasta) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void inicializarTablaTiposGrupos(tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablaTiposGrupos[i][j].cantidad = 0;
            tablaTiposGrupos[i][j].importe = 0;
        }
    }
}

void contarVentas(int &totalVentas) {
    totalVentas++;
}

float calcularPrecio(char descontar, tyProducto productos[], tyTipoProd tipos[], int posProd, int posTipo) {
    float precio;
    if (descontar == 'S') {
        precio = productos[posProd].precio - (productos[posProd].precio * tipos[posTipo].descuento);
    } else {
        precio = productos[posProd].precio;
    }
    return precio;
}

void acumularRecYCantPorTipoYGrupo(tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int posGrupo, int posTipo, float precio) {
    tablaTiposGrupos[posTipo][posGrupo].cantidad++;
    tablaTiposGrupos[posTipo][posGrupo].importe += precio;
}

void acumularVentasConDescuento(int acumulador[], int posGrupo) {
    acumulador[posGrupo]++;
}

void acumularVentasPorTipo(int acumVentasPorTipo[], int posTipo) {
    acumVentasPorTipo[posTipo]++;
}

void mostrarRecaudacionPorTipoYGrupo(tyTipoProd tipos[], tyGrupo grupos[], tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    mostrarTitulo("Por cada Tipo de Producto: Nombre del Tipo de Producto y Recaudacion por cada Grupo de Edad.");

    for (int i = 0; i < filas; i++) {
        cout << tipos[i].nombre << endl << endl;
        for (int j = 0; j < columnas; j++) {
            cout << "Grupo [" << grupos[j].edadDesde << "-" << grupos[j].edadHasta << "]\tRecaudacion: $ " << tablaTiposGrupos[i][j].importe << endl;
        }
        cout << endl;
    }
}

void mostrarComprasPorGrupo(tyTipoProd tipos[], tyGrupo grupos[], tyAcumulador tablaTiposGrupos[][TOPE_GRUPOS], int filas, int columnas) {
    mostrarTitulo("Por cada Grupo de Edad: Nombre del Tipo de Producto y Cantidad de Compras.");
    for (int i = 0; i < columnas; i++) {
        cout << "Grupo [" << grupos[i].edadDesde << "-" << grupos[i].edadHasta << "]"<< endl << endl;
        for (int j = 0; j < filas; j++) {
            cout << "Tipo de producto '" << tipos[j].nombre << "'\tCantidad de compras: " << tablaTiposGrupos[i][j].cantidad << endl;
        }
        cout << endl;
    }
}

void mostrarGrupoDeMayorVentaConDescuento(tyGrupo grupos[], int acumulador[], int tope) {
    mostrarTitulo("Grupo de Edad en que se vendio mayor cantidad de productos con descuento.");

    int posMax;
    buscarPosMaxEnArrayNumerico(acumulador, tope, posMax);
    cout << "El grupo " << posMax << " [" << grupos[posMax].edadDesde << "-" << grupos[posMax].edadHasta << "] vendio " << acumulador[posMax] << " productos con descuento" << endl;
}

void mostrarPorcentajesDeVentasPorTipo(tyTipoProd tipos[], int acumVentasPorTipo[], int tope, int totalVentas) {
    mostrarTitulo("Por cada Tipo de Producto: Nombre del Tipo y Porcentaje de productos vendidos.");
    float porcentaje;
    for (int i = 0; i < tope; i++) {
        porcentaje = acumVentasPorTipo[i] * 100 / (float)totalVentas; // Hago casteo para mostrar decimales
        cout << "El tipo '" << tipos[i].nombre << "' represento el " << std::fixed << std::setprecision(2) << porcentaje << " % de las ventas" <<endl;
    }
}