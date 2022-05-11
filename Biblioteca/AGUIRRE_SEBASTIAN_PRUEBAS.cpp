#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "AGUIRRE_SEBASTIAN.h" 

int main(){

	int vec[] = { 12, 5, 4, 5, 9, 11, 5, 4, 13, 7 };

	//ordenamientoPorSeleccion(vec, 10);
	cout << endl << endl;
	ordenamientoPorSeleccionV2(vec, 10);
	mostrarArrayNumericoConIndice(vec, 10);

	

	return EXIT_SUCCESS;
}

