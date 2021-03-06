#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define MIN 1
#define MAX 99
#define MENOR_EDAD 18
#define MAYOR_EDAD 65

struct tyContEdad {
    int menores;
    int laborales;
};

void inicilizarContador(tyContEdad &cont);
void mostrarResultados(int mayor, tyContEdad contador);

int main(){
    mostrarTitulo("Ejercicio 2");

    tyContEdad contador;
    int edad, mayor = 0;

    inicilizarContador(contador);
    ingresarEntero(edad, "Ingrese la edad: ");
    while (edad != EXIT_ERROR) {
        if (not validarNumeroEnRangoExcluyente(edad, MIN, MAX)) {
            cout << "La edad ingresada es incorrecta" << endl;
        } else {
            if (edad > mayor)
                mayor = edad;

            if (edad < MENOR_EDAD)
                contador.menores++;
            else if (validarNumeroEnRango(edad, MENOR_EDAD, MAYOR_EDAD))
                contador.laborales++;
        }

        ingresarEntero(edad, "Ingrese la edad: ");
    }
    
    mostrarResultados(mayor, contador);

	return EXIT_SUCCESS;
}

void inicilizarContador(tyContEdad &cont) {
    cont.laborales = 0;
    cont.menores = 0;
}

void mostrarResultados(int mayor, tyContEdad contador) {
    cout << endl << "El de mayor tiene " << mayor << " anios." << endl; 
    cout << contador.menores << " son menores." << endl;
    cout << contador.laborales << " estan en edad laboral." << endl;
}
