#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Juego {
    int numero;
    int suma;
    float promedio;
};

void printMensaje(string mensaje);
int getIntNumber(string mensaje);

void inicializarValores(Juego &jugada);
void iniciarJuego(int cantDeManos, Juego &juegoPrincipal);
void ingresarValores(int cantDeValores, Juego &jugada, int nroDeJuego);
void mostrarResultados(Juego &jugada);
void actualizarValoresDelJuego(Juego &jugada, Juego &juegoPrincipal);     


int main(){
    Juego juegoPrincipal;
    int nroDeManos = getIntNumber("Ingrese la cantidad de manos a jugar (N): ");
    
    inicializarValores(juegoPrincipal);
    iniciarJuego(nroDeManos, juegoPrincipal);
    mostrarResultados(juegoPrincipal);

	return 0;
}

void printString(string mensaje) {
    cout << mensaje;
}

int getIntNumber(string mensaje) {
    int numero;
    printString(mensaje);
    cin >> numero;
    return numero;
}

void iniciarJuego(int cantDeManos, Juego &juegoPrincipal) {
    int cantDeValores;
    Juego jugada;

    for (int i = 1; i <= cantDeManos; i++) {
        inicializarValores(jugada);
        cantDeValores = getIntNumber("Ingrese la cantidad de valores a tipear (N1): ");
        ingresarValores(cantDeValores, jugada, i); 
        actualizarValoresDelJuego(jugada, juegoPrincipal);     
    }
}

void inicializarValores(Juego &jugada) {
    jugada.numero = 0;
    jugada.promedio = 0;
    jugada.suma = 0;
}

void ingresarValores(int cantDeValores, Juego &jugada, int nroDeJuego) {
    int valor;
    for (int i = 1; i <= cantDeValores; i++) {
        valor = getIntNumber("Ingrese un valor: ");
        jugada.suma += valor;
    }
    jugada.promedio = jugada.suma / cantDeValores;
    jugada.numero = nroDeJuego;
}

void mostrarResultados(Juego &jugada) {
    cout << "EL promedio mas alto es " << jugada.promedio << " y ocurrio en el juego numero " << jugada.numero << endl;
    cout << "La suma total es " << jugada.suma << endl;
}

void actualizarValoresDelJuego(Juego &jugada, Juego &juegoPrincipal) {
    juegoPrincipal.suma += jugada.suma;
    if (juegoPrincipal.promedio < jugada.promedio) {
        juegoPrincipal.promedio = jugada.promedio;
        juegoPrincipal.numero = jugada.numero;
    }
} 
