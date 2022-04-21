#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int pedirNumeroEntero(string mensaje) {
    int num;
    cout << mensaje;
    cin >> num;
    return num;
}

int main() {

    int numeroIngresado, acumNumeros = 0, contNumeros = 0;
    float promedio = 0;

    while (promedio < 20) {
        numeroIngresado = pedirNumeroEntero("Ingrese un numero: ");
        contNumeros ++;
        acumNumeros += numeroIngresado;
        promedio = acumNumeros / contNumeros;
    }
    
    return EXIT_SUCCESS;
}
