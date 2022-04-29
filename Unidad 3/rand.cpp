#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 10

int main(){
    int vec[TOPE];
    long long tini;
    srand(time(NULL)); // Semilla
    tini = clock();

    cargarVecRandom(vec, TOPE, 250);
    cout << "Total clock(): " << clock() - tini << endl;
    cout << "Unidades clock() por segundo: " << CLOCKS_PER_SEC << endl;

	return EXIT_SUCCESS;
}

