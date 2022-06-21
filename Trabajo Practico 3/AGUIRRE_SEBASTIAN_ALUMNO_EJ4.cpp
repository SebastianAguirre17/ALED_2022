#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE 21

int main(){
    // mostrarTitulo("Ejercicio 4");

    char frase[TOPE] = "abeurp ed esarF";

    mostrarTitulo("Frase inicial");
    mostrarString(frase);
    cout << endl;

    invertirFrase(frase, TOPE);

    mostrarTitulo("Frase invertida");
    mostrarString(frase);
    cout << endl;

    mostrarTitulo("Nueva frase");
    ingresarCadenaCharValida(frase, TOPE, "Ingrese un texto de menos de 20 caracteres: ");
    
    invertirFrase(frase, TOPE);

    mostrarTitulo("Frase invertida");
    mostrarString(frase);
    cout << endl;

	return EXIT_SUCCESS;
}
