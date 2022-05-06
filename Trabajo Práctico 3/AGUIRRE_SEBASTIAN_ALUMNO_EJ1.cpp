#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 20
#define MOD 100

void buscarPosMinYMaxEnArrayNumerico(int vec[], int tope, int &minPos, int &maxPos);
void mostrarValorMaximoArrNumerico(int vec[], int pos);

int main(){
    mostrarTitulo("Ejercicio 1");

    int vec[TOPE], posMin, posMax;
    cargarVecRandom(vec, TOPE, MOD);
    mostrarArrayNumericoConIndice(vec, TOPE);

    buscarPosMinYMaxEnArrayNumerico(vec, TOPE, posMin, posMax);
    mostrarTitulo("Punto C");
    cout << "El Maximo se encuentra el la posicion: " << posMax << endl;
    cout << "El Minimo se encuentra el la posicion: " << posMin << endl;
    mostrarTitulo("Punto D");
    mostrarValorMaximoArrNumerico(vec, posMax);

	return EXIT_SUCCESS;
}

void buscarPosMinYMaxEnArrayNumerico(int vec[], int tope, int &minPos, int &maxPos) {
    int i, vMin, vMax;
    minPos = maxPos = 0;
    vMax = vMin = vec[0];
    for (i = 0; i < tope; i++) {
        if (vec[i] < vMin) {
            minPos = i;
            vMin = vec[i];
        }
        if (vec[i] > vMax) {
            maxPos = i;
            vMax = vec[i];
        }
    }
}

void mostrarValorMaximoArrNumerico(int vec[], int pos) {
    cout << "El valor maximo es: " << vec[pos] << " y se encuentra en el indice: " << pos << endl;
}