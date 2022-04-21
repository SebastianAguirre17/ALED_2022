#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 5

void ingreso(string &texto) {
    cout << "Ingrese un texto ...: ";
    getline(cin, texto);
    while (texto.length() > TOPE) {
        cout << "Ingrese un texto ...: ";
        getline(cin, texto);
    }
}

int main(int argc, char const *argv[])
{
    char parrafo[TOPE];
    string auxParrafo;

    ingreso(auxParrafo);
    
    cout << auxParrafo;
    return 0;
}
