#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

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

struct tyLavandina {
    float precio;
    string descripcion;
};

void inicializarContRubros(tyContRubros &cont);
void inicializarContLavandina(tyLavandina &lava);
void incrementarContRubros(tyContRubros &cont, char rubro);
void cargarProducto(tyProducto &prod);
void mostrarFactura(tyProducto &prod);
void mostrarFacturasPorRubro(tyContRubros &cont);
void mostrarImportePromedioAlcoholes(tyContRubros cont, int acum);
void mostrarMayorFacturaLavandinas(tyContRubros cont, tyLavandina lava);

int main() {
    mostrarTitulo("Aguirre Sebastian - Ejercicio 1 Primer Parcial");

    tyProducto producto;
    tyContRubros contador;
    tyLavandina acumLavandina;
    float acumImporteAlcoholes = 0;

    inicializarContRubros(contador);
    inicializarContLavandina(acumLavandina);

    cargarProducto(producto);
    while (producto.descripcion != "fin") {
        mostrarFactura(producto);
        incrementarContRubros(contador, producto.rubro);
        if (producto.rubro == 'A'){
            acumImporteAlcoholes += (producto.precio * producto.cantidad);
        }
        else if (producto.rubro == 'L' and (producto.precio * producto.cantidad) > acumLavandina.precio) {
            acumLavandina.precio = (producto.precio * producto.cantidad);
            acumLavandina.descripcion = producto.descripcion;
        }
        cin.ignore();
        cargarProducto(producto);
    }

    mostrarFacturasPorRubro(contador);
    mostrarImportePromedioAlcoholes(contador, acumImporteAlcoholes);
    mostrarMayorFacturaLavandinas(contador, acumLavandina);

	return EXIT_SUCCESS;
}

void inicializarContRubros(tyContRubros &cont) {
    cont.a = 0;
    cont.d = 0;
    cont.l = 0;
}

void inicializarContLavandina(tyLavandina &lava) {
    lava.precio = 0;
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

void cargarProducto(tyProducto &prod) {
    char caracteresValidos[TOPE_RUBROS] = "DAL";

    ingresarString(prod.descripcion, "Ingrese Descripcion ('fin' para sailr): ");
    if (prod.descripcion != "fin") {
        ingresarCaracterValido(prod.rubro, caracteresValidos, TOPE_RUBROS, "Ingrese el Rubro (D - A - L): ");
        ingresarFlotantePositivo(prod.precio, "Ingrese el precio: $");
        ingresarEnteroPositivo(prod.cantidad, "Ingrese la cantidad: ");
    } 
}

void mostrarFactura(tyProducto &prod) {
    mostrarTitulo("Factura SomosLimpitos");
    cout << "Descripcion    : " << prod.descripcion << endl;
    cout << "Precio unitario: " << prod.precio << endl;
    cout << "Importe total  : " << prod.cantidad * prod.precio << endl << endl;
}

void mostrarFacturasPorRubro(tyContRubros &cont) {
    mostrarTitulo("Total de Facturas por Rubro");

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
}

void mostrarImportePromedioAlcoholes(tyContRubros cont, int acum) {
    mostrarTitulo("Importe Promedio por factura de alcoholes");

    if (cont.a > 0)
        cout << "\nPromedio Factura de Alcoholes: $" << acum / cont.a << endl;
    else
        cout << "No hubo ventas del Rubro Alcoholes.\n";
}

void mostrarMayorFacturaLavandinas(tyContRubros cont, tyLavandina lava) {
    mostrarTitulo("Producto de mayo importe Lavantinas");

    if (cont.l > 0)
        cout << endl << "Producto de mayor factura de Lavandinas: " << lava.descripcion << endl << endl;
    else
        cout << "No hubo ventas del Rubro Lavandinas" << endl;
}