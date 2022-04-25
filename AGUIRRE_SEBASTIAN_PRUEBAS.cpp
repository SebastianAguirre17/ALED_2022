#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 20

void stringToChar(string str, char cad[]) {
    int i, largo = str.length();
    for (i = 0; i < largo; i++) {
        cad[i] = str[i]; 
    }
    cad[largo] = '\0';
}

int main(){
    string str = "Esto es una prueba";
    char cad[TOPE];

    stringToChar(str, cad);

    cout << cad << endl;

	return EXIT_SUCCESS;
}

