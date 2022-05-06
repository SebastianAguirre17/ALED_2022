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

void inicializarContRubros(tyContRubros &cont);
void incrementarContRubros(tyContRubros &cont, char rubro);

void cargarProducto(tyProducto &prod);
void mostrarFactura(tyProducto &prod);

int main() {
    mostrarTitulo("Aguirre Sebastian - Ejercicio 1 Primer Parcial");

    tyProducto producto;
    tyContRubros contador;

    inicializarContRubros(contador);
    
    do {
        cargarProducto(producto);
        mostrarFactura(producto);
        incrementarContRubros(contador, producto.rubro);
        cin.ignore();

    } while (producto.descripcion != "fin");


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