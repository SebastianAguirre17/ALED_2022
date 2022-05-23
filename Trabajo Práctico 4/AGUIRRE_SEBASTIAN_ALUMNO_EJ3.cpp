#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "PROMOTORES_Y_TELEFONOS.h"

int main(){
    mostrarTitulo("Ejercicio 3");

    tyTelefono telefonos[CANT_TEL];
    tyPromotor promotores[CANT_PROM];
    char rutaTelefonos[] = "telefonos.dat";
    char rutaPromotores[] = "promotores.dat";

    cargarTelefonos(telefonos, CANT_TEL, rutaTelefonos);
    cargarPromotores(promotores, CANT_PROM, rutaPromotores);


	return EXIT_SUCCESS;
}
