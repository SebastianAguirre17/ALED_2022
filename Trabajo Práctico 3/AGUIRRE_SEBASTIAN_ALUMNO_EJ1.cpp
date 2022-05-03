#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 20
#define MOD 100

void mostrarValorMaximoArrNumerico(int vec[], int pos);

int main(){
    mostrarTitulo("Ejercicio 1");

    int vec[TOPE], posMin, posMax;
    cargarVecRandom(vec, TOPE, MOD);
    mostrarArrayNumericoConIndice(vec, TOPE);

    buscarPosMinYMaxEnArrayNumerico(vec, TOPE, posMin, posMax);
    mostrarTitulo("Punto C");
    cout << "El Maximo se encuentra el la posicion: " << posMax << endl;
    cout << "El Minimo se encuentra el la posicion: " << posMin << endl << endl;
    mostrarTitulo("Punto D");
    mostrarValorMaximoArrNumerico(vec, posMax);

	return EXIT_SUCCESS;
}

void mostrarValorMaximoArrNumerico(int vec[], int pos) {
    cout << "El valor maximo es: " << vec[pos] << " y se encuentra en el indice: " << pos << endl;
}