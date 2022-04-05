#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void printString(string mensaje);
void getNumber(string mensaje, int &numero);
void clearScreen();
void jugar(int nroDeJuegos, int &sumaTotal, float &promedioMasAlto); 
void cargarJuego(int &suma, float &promedio);
float calcularPromedio(int valor, int cantidad);
void mostrarTotal(int total);
void mostrarPromedio(float promedio);

int main(){

    int cantidadDeJuegos = 0, sumaTotal = 0;
    float promedioMasAlto;

    getNumber("Ingrese la cantidad de juegos (N): ", cantidadDeJuegos);
    jugar(cantidadDeJuegos, sumaTotal, promedioMasAlto);

    clearScreen();
    mostrarTotal(sumaTotal);
    mostrarPromedio(promedioMasAlto);

	return 0;
}

void printString(string mensaje) {
    cout << mensaje;
}

void getNumber(string mensaje, int &numero) {
    printString(mensaje);
    cin >> numero;
}

void clearScreen() {
    system("cls");
}

void jugar(int nroDeJuegos, int &sumaTotal, float &promedioMasAlto) {
    int i = 1, suma;
    float promedio;

    while (i <= nroDeJuegos) {
        suma = 0;
        cargarJuego(suma, promedio);
        sumaTotal += suma;
        if (promedio > promedioMasAlto) {
            promedioMasAlto = promedio;
        }
        i++;
    };
}

void cargarJuego(int &suma, float &promedio) {
    int nroDeManos, valorIngresado, i = 1;
    getNumber("Ingrese la cantidad de manos (N1): ", nroDeManos);

    while (i <= nroDeManos) {
        getNumber("Ingrese un valor: ", valorIngresado);
        suma += valorIngresado;
        i++;
    };

    promedio = calcularPromedio(suma, nroDeManos);
}

float calcularPromedio(int valor, int cantidad) {
    return valor / cantidad;
}

void mostrarTotal(int total) {
    cout << "La suma total es: " << total << endl;
}

void mostrarPromedio(float promedio) {
    cout << "El promedio mas alto es: " << promedio << endl;
}