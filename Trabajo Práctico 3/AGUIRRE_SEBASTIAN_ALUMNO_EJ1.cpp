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

    buscarPosMinYMaxEnArrayNumerico(vec, TOPE, posMin, posMax);
    mostrarArrayNumericoConIndice(vec, TOPE);
    mostrarValorMaximoArrNumerico(vec, posMax);

	return EXIT_SUCCESS;
}

void mostrarValorMaximoArrNumerico(int vec[], int pos) {
    cout << endl << "El valor maximo es: " << vec[pos] << " y se encuentra en el indice: " << pos << endl;
}