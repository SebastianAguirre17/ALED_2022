#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 
using namespace std;

#define TOPE_RUBROS 4

struct tyProducto {
    string descripcion;
    char rubro;
    float precio;
    int cantidad;
};

struct tyContRubros {
    int a;
    int d;
    int l;
};

struct tyAcumuladores {
    float acumAlcoholes;
    float mayorLavandina;
    string descMayorLavandina;
};

void inicializarContRubros(tyContRubros &cont);
void incrementarContRubros(tyContRubros &cont, char rubro);
void inicializarAcumulador(tyAcumuladores &acum);
void incrementarAcumuladores(tyProducto &prod, tyAcumuladores &acum);
void ingresarProductos(tyProducto &prod, tyContRubros &cont, tyAcumuladores &acum);
void cargarProducto(tyProducto &prod, string desc, tyContRubros &cont, tyAcumuladores &acum);
void mostrarFactura(tyProducto &prod);
void mostrarResultados(tyAcumuladores &acum, tyContRubros &cont);

int main() {
    mostrarTitulo("Aguirre Sebastian - Ejercicio 1 Primer Parcial");
    
    tyProducto producto;
    tyContRubros contRubros;
    tyAcumuladores acumulador;

    inicializarContRubros(contRubros);
    inicializarAcumulador(acumulador);

    ingresarProductos(producto, contRubros, acumulador);

    if (contRubros.a == 0 and contRubros.d == 0 and contRubros.l == 0)
        mostrarTitulo("Gracias por usar este programa :D");
    else
        mostrarResultados(acumulador, contRubros);

	return EXIT_SUCCESS;
}

void inicializarContRubros(tyContRubros &cont) {
    cont.a = 0;
    cont.d = 0;
    cont.l = 0;
}

void incrementarContRubros(tyContRubros &cont, char rubro) {
    switch (rubro) {
        case 'A':
            cont.a++;
            break;
        case 'D':
            cont.d++;
            break;
        case 'L':
            cont.l++;
            break;
    }
}

void inicializarAcumulador(tyAcumuladores &acum) {
    acum.acumAlcoholes = 0;
    acum.mayorLavandina = 0;
}

void ingresarProductos(tyProducto &prod, tyContRubros &cont, tyAcumuladores &acum) {
    string desc = retornarString("Ingrese Descripcion ('fin' para sailr): ");
    while (desc != "fin") {
        cargarProducto(prod, desc, cont, acum);
        mostrarFactura(prod);
        desc = retornarString("Ingrese Descripcion ('fin' para sailr): ");
    }
}

void cargarProducto(tyProducto &prod, string desc, tyContRubros &cont, tyAcumuladores &acum) {
    char validos[TOPE_RUBROS] = "DAL";

    prod.descripcion = desc;
    pedirCaracterValido(prod.rubro, validos, TOPE_RUBROS, "Ingrese el Rubro (D - A - L): ");
    prod.precio = pedirFlotanteMayorA("Ingrese el precio: ", 0);
    prod.cantidad = pedirEnteroMayorA("Ingrese la cantidad: ", 0);
    incrementarAcumuladores(prod, acum);
    incrementarContRubros(cont, prod.rubro);
}

void mostrarFactura(tyProducto &prod) {
    mostrarTitulo("Factura SomosLimpitos");
    cout << "Descripcion    : " << prod.descripcion << endl;
    cout << "Precio unitario: " << prod.precio << endl;
    cout << "Importe total  : " << prod.cantidad * prod.precio << endl << endl;
}

void incrementarAcumuladores(tyProducto &prod, tyAcumuladores &acum) {
    float precioFinal = prod.cantidad * prod.precio;

    if (prod.rubro == 'A') {
        acum.acumAlcoholes += precioFinal;
    }
    if (prod.rubro == 'L' and precioFinal > acum.mayorLavandina) {
        acum.mayorLavandina = precioFinal;
        acum.descMayorLavandina = prod.descripcion;
    }
}

void mostrarResultados(tyAcumuladores &acum, tyContRubros &cont) {
    mostrarTitulo("Resultados");
    mostrarMensaje("Total de Facturas por Rubro\n\n");
    if (cont.l > 0)
        cout << "Lavandinas     : " << cont.l << endl;
    else
        cout << "No hubo ventas del Rubro Lavandinas" << endl;

    if (cont.a > 0)
        cout << "Alcoholes      : " << cont.a << endl;
    else
        cout << "No hubo ventas del Rubro Alcoholes" << endl;
    if (cont.d > 0)
        cout << "Desinfectantes : " << cont.d << endl;
    else
        cout << "No hubo ventas del Rubro Desinfectantes" << endl;

    if (cont.a > 0)
        cout << endl << "Promedio Factura de Alcoholes: $" << acum.acumAlcoholes / cont.a << endl;

    if (acum.mayorLavandina > 0)
        cout << endl << "Producto de mayor factura de Lavandinas: " << acum.descMayorLavandina << endl << endl;
}