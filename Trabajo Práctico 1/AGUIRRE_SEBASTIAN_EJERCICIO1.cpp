#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 
using namespace std;

void pedirNumeros(int &min, int &max, int &cant);
void mostrarRangoYValorCentral(int min, int max);
void pedirCapicua();
void pedirNumerosAmigos();

int main(){
    mostrarTitulo("Ejercicio 1");

    int min, max, cant;

    pedirNumeros(min, max, cant);
    pedirCapicua();
    pedirNumerosAmigos();

	return EXIT_SUCCESS;
}

void pedirNumeros(int &min, int &max, int &cant) {
    mostrarTitulo("Rango y Valor Central");
    int numIngresado, i = 0;

    cant = pedirEnteroPositivo("Cuantos numeros desea ingresar? ");
    while (i < cant) {
        numIngresado = pedirEnteroPositivo("Ingrese un numero positivo: ");
        if (i == 0)
            min = max = numIngresado;
        if (numIngresado < min)
            min = numIngresado;
        if (numIngresado > max) 
            max = numIngresado;
        i++;
    }
    mostrarRangoYValorCentral(min, max);
}
void mostrarRangoYValorCentral(int min, int max) {
    float central = (max - min) / 2;
    cout << "\nEl Rango es: [" << min << "," << max << "]" << endl;
    cout << "El Valor Central es: " << central << endl;
}

void pedirCapicua() {
    mostrarTitulo("Numero Capicua");
    int num, desde = 100, hasta = 999; 
    pedirEnteroEnRango(num, desde, hasta);
    
    esNumeroCapicua(num) ? 
        cout << endl << num << " Es un numero Capicua" << endl : 
        cout << endl << num << " No es un numero Capicua" << endl;
}

void pedirNumerosAmigos() {
    mostrarTitulo("Numeros Amigos");

    int num1, num2;
    num1 = pedirEnteroPositivo("Ingrese un numero positivo: ");
    num2 = pedirEnteroPositivo("Ingrese otro numero positivo: ");

    sonNumerosAmigos(num1, num2) ? 
        cout << endl << num1 << " y " << num2 << " Son numeros amigos." << endl : 
        cout << endl << num1 << " y " << num2 << " NO son numeros amigos." << endl;
}