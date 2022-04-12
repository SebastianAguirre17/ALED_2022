#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct tyJuego {
    int numero;
    int suma;
    float promedio;
};

void mostrarMensaje(string mensaje);
void mostrarResultados(tyJuego &jugada);
void mostrarTitulo(string titulo);
int pedirNumeroEntero(string mensaje);
void inicializarValores(tyJuego &jugada);
void iniciarJuego(int cantDeManos, tyJuego &juegoPrincipal);
void ingresarValores(int cantDeValores, tyJuego &jugada, int nroDeJuego);
void actualizarValoresDelJuego(tyJuego &jugada, tyJuego &juegoPrincipal);     

int main(){
    mostrarTitulo("Ejercicio 5");

    tyJuego juegoPrincipal;
    int nroDeManos = pedirNumeroEntero("Ingrese la cantidad de manos a jugar: ");

    if (nroDeManos <= 0) {
        mostrarMensaje("\nGracias por usar este simple programa.\n");
    } else {
        inicializarValores(juegoPrincipal);
        iniciarJuego(nroDeManos, juegoPrincipal);
        mostrarResultados(juegoPrincipal);
    }
    
	return 0;
}

void mostrarMensaje(string mensaje) {
    cout << mensaje;
}

int pedirNumeroEntero(string mensaje) {
    int numero;
    mostrarMensaje(mensaje);
    cin >> numero;
    return numero;
}

void iniciarJuego(int cantDeManos, tyJuego &juegoPrincipal) {
    int cantDeValores, nroDeJuego;
    tyJuego jugada;

    for (int nroDeJuego = 1; nroDeJuego <= cantDeManos; nroDeJuego++) {
        inicializarValores(jugada);
        cantDeValores = pedirNumeroEntero("\nIngrese la cantidad de valores a tipear: ");
        ingresarValores(cantDeValores, jugada, nroDeJuego); 
        actualizarValoresDelJuego(jugada, juegoPrincipal);     
    }
}

void inicializarValores(tyJuego &jugada) {
    jugada.numero = 0;
    jugada.promedio = 0;
    jugada.suma = 0;
}

void ingresarValores(int cantDeValores, tyJuego &jugada, int nroDeJuego) {
    int valor;
    for (int i = 1; i <= cantDeValores; i++) {
        valor = pedirNumeroEntero("Ingrese un valor: ");
        jugada.suma += valor;
    }
    jugada.promedio = jugada.suma / cantDeValores;
    jugada.numero = nroDeJuego;
}

void mostrarResultados(tyJuego &jugada) {
    mostrarMensaje("\n****************************\n");
    cout << "EL promedio mas alto es " << jugada.promedio << endl;
    cout << "Se dio en el juego " << jugada.numero << endl;
    cout << "La suma total es " << jugada.suma << endl;
    mostrarMensaje("****************************\n");
}

void actualizarValoresDelJuego(tyJuego &jugada, tyJuego &juegoPrincipal) {
    juegoPrincipal.suma += jugada.suma;
    if (juegoPrincipal.promedio < jugada.promedio) {
        juegoPrincipal.promedio = jugada.promedio;
        juegoPrincipal.numero = jugada.numero;
    }
} 

void mostrarTitulo(string titulo) {
    mostrarMensaje("****************************\n");
    cout << "\t" << titulo << endl;
    mostrarMensaje("****************************\n\n");
}
