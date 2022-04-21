#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define MIN 1
#define MAX 99
#define MENOR_EDAD 17
#define MAYOR_EDAD 66

struct tyContEdad {
    int menores;
    int laborales;
};

void inicilizarContador(tyContEdad &cont) {
    cont.laborales = 0;
    cont.menores = 0;
}

void mostrarResultados(int mayor, tyContEdad contador) {

        
        mostrarNumeroEntero(contador.laborales);
        mostrarNumeroEntero(contador.menores);
}

int main(){

    tyContEdad contador;
    int edad, mayor = 0;

    inicilizarContador(contador);

    edad = pedirEntero("Ingrese la edad: ");
    while (edad != -1) {
        if (not validarNumeroEnRago(edad, MIN, MAX)) {
            mostrarMensaje("La edad ingresada es incorrecta\n");
        } else {
            if (edad > mayor)
                mayor = edad;

            if (edad < MENOR_EDAD)
                contador.menores++;
            else if (validarNumeroEnRago(edad, MENOR_EDAD, MAYOR_EDAD))
                contador.laborales++;
        }

        edad = pedirEntero("Ingrese la edad: ");
    }
    
    mostrarResultados(mayor, contador);


	return R_OK;
}


/* 
Ejercicio  2:  De  una  lista  de  personas  se  ingresa  su  edad.  La  carga  termina 
cuando en la edad se ingresa el valor -1  
Se pide indicar: 
Cuál de todos ellos es el mayor (suponer único).  
Cuántos de ellos son menores de edad (17 años o menos). 
Cuántos de ellos están en edad laboral activa (hasta 65 años, inclusive). 
Mostrar  las  edades  de  quiénes  están  por  jubilarse  (única  para  ambos 
sexos).*/