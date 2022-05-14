#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 20
#define MOD 100

void mostrarValorMaximoArrNumerico(int vec[], int tope);

int main(){
    mostrarTitulo("Ejercicio 1");
    
    int vec[TOPE], posMin, posMax;

    mostrarTitulo("Vector de 20 elementos Random");
    cargarVecRandom(vec, TOPE, MOD);
    mostrarArrayNumericoConIndice(vec, TOPE);

    mostrarTitulo("Punto C");
    buscarPosMinYMaxEnArrayNumerico(vec, 0, TOPE, posMin, posMax);
    cout << "El Maximo se encuentra el la posicion: " << posMax << endl;
    cout << "El Minimo se encuentra el la posicion: " << posMin << endl;

    mostrarTitulo("Punto D");
    mostrarValorMaximoArrNumerico(vec, TOPE);

	return EXIT_SUCCESS;
}

void mostrarValorMaximoArrNumerico(int vec[], int tope) {
    int i, vMax = vec[0], pos = 0;

    for (i = 0; i < tope; i++) {
        if (vec[i] > vMax) {
            pos = i;
            vMax = vec[i];
        }
    }
    cout << "El valor maximo es: " << vMax << " y se encuentra en el indice: " << pos << endl;
}