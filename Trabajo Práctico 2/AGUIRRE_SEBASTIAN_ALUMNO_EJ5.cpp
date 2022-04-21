/* Ej5. Realizar una función que dado un arreglo de 45 elementos de tipo carácter que 
contiene una palabra, devuelva otro arreglo de 5 elementos enteros donde cada uno 
representa la cantidad de veces que se repite cada vocal en la palabra. 
Para 
entregar*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h"

#define TOPE_CADENA 65
#define TOPE_VOCALES 5

void contarVocales(char cadena[], int topeChar, int contVocales[], int topeVocales);

int main() {
    mostrarTitulo("TP 2 - Ejercicio 5");
    
    char cadena[TOPE_CADENA] = "Frase que vamos a usar para contar vocales en una cadena de char";
    int contVocales[TOPE_VOCALES];

    inicializarArrayNumerico(contVocales, TOPE_VOCALES);
    contarVocales(cadena, TOPE_CADENA, contVocales, TOPE_VOCALES);

    mostrarArrayNumerico(contVocales, TOPE_VOCALES);
    return R_OK;
}

void contarVocales(char cadena[], int topeChar, int contVocales[], int topeVocales) {
    char vocales[] = "aeiou";
    int i, aux, largoCadena = contarCaracteresDeCadenaChar(cadena, topeChar);

    for (i = 0; i < largoCadena; i++) {
        aux = buscarCaracterEnCadenaChar(vocales, TOPE_VOCALES, cadena[i]);
        if (aux != R_ERROR) 
            contVocales[aux]++;
    }
}
