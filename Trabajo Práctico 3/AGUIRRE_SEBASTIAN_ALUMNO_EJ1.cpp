#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 20
#define MOD 100

void buscarPosMinYMaxEnArrayNumerico(int vec[], int tope, int &minPos, int &maxPos);
void mostrarValorMaximoArrNumerico(int vec[], int tope);

int main(){
    mostrarTitulo("Ejercicio 1");
    
    int vec[TOPE], posMin, posMax;

    mostrarTitulo("Vector de 20 elementos Random");
    cargarVecRandom(vec, TOPE, MOD);
    mostrarArrayNumericoConIndice(vec, TOPE);

    mostrarTitulo("Punto C");
    buscarPosMinYMaxEnArrayNumerico(vec, TOPE, posMin, posMax);
    cout << "El Maximo se encuentra el la posicion: " << posMax << endl;
    cout << "El Minimo se encuentra el la posicion: " << posMin << endl;

    mostrarTitulo("Punto D");
    mostrarValorMaximoArrNumerico(vec, TOPE);

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