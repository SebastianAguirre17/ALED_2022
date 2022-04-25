#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 
using namespace std;

#define MAYORISTA 500
#define MINORISTA 750
#define TOPE_MINO 100

void mostrarOpcionesDePago(int cant, int p_mayo, int p_mino, int tope_mino);
void mostrarPagoEfectivo(int cant, int p_mayo, int p_mino, int tope_mino); 
void mostrarPagoConTarjeta(int cant, int p_mayo, int p_mino, int tope_mino); 
void mostrarTresCuotas(int cant, int p_mayo, int p_mino, int tope_mino); 
void mostrarMasCuotas(int cant, int p_mayo, int p_mino, int tope_mino); 

int main(){
    mostrarTitulo("Ejercicio 2");

    int cantidad = pedirEnteroMayorA("Ingrese la cantidad de mascaras a comprar: ", 0);
    mostrarOpcionesDePago(cantidad, MAYORISTA, MINORISTA, TOPE_MINO);

	return EXIT_SUCCESS;
}

void mostrarOpcionesDePago(int cant, int p_mayo, int p_mino, int tope_mino) {
    mostrarPagoEfectivo(cant, p_mayo, p_mino, tope_mino);
    mostrarPagoConTarjeta(cant, p_mayo, p_mino, tope_mino);
}

void mostrarPagoEfectivo(int cant, int p_mayo, int p_mino, int tope_mino) {
    mostrarTitulo("Pago en Efectivo");

    float total = (cant >= TOPE_MINO) ? cant * p_mayo : cant * p_mino;
    cout << "Pago total en efectivo con 0% de interes: $" << total << endl;
}

void mostrarPagoConTarjeta(int cant, int p_mayo, int p_mino, int tope_mino) {
    mostrarTitulo("Pago con Tarjeta");
    mostrarTresCuotas(cant, p_mayo, p_mino, tope_mino);
    mostrarMasCuotas(cant, p_mayo, p_mino, tope_mino);
}

void mostrarTresCuotas(int cant, int p_mayo, int p_mino, int tope_mino) {
    float total = (cant >= TOPE_MINO) ? cant * p_mayo * 1.1 : cant * p_mino * 1.1;
    cout << "Con 10% de Interes" << endl << endl;
    for (int i = 1; i <= 3; i++) {
        cout << i << " cuota/s de: $" << total / i << endl;
    }
}

void mostrarMasCuotas(int cant, int p_mayo, int p_mino, int tope_mino) { 
    float total = (cant >= TOPE_MINO) ? cant * p_mayo * 1.3 : cant * p_mino * 1.3;
    cout << endl << "Con 30% de Interes" << endl << endl;
    for (int i = 4; i <= 12; i++) {
        cout << i << " cuota/s de: $" << total / i << endl;
    }
}