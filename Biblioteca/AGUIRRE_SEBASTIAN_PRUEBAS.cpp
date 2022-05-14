#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "AGUIRRE_SEBASTIAN.h" 

int main(){

	int vec[] = { 0, 15, 6, 4 ,5, 9, 3, 9, 10, 2, 17, 1, 12, 22 };

	ordenamientoPorSeleccionV2(vec, 14);
	mostrarArrayNumericoConIndice(vec, 14);

	

	return EXIT_SUCCESS;
}

