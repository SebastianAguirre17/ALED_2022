#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*	
	Ejercicio 4: Ingresar una serie de numeros naturales que termina con -1 e
    indicar cuantas veces se interrumpe el orden ascendente y cuantos numeros
    hay en cada grupo ordenado.
*/

void getInt(string mensaje, int &numero); 
void printInterrumpciones(int cantidad);
void printDebug(string debug, int numero);

int main(){
	
	int numIngresado, contGrupos = 0, acumPorGrupo = 0;
	int i = 0, anterior = -1;

	int lista[] = { 4, 7, 18, 5, 189, 204, 205, 7, 8, 12, 23, 35, 2, -1};

	do {
		// getInt("Ingrese un numero: ", numIngresado);
		numIngresado = lista[i]; // TODO: Solo para pruebas
		// printDebug("-- INGRESADO: ", numIngresado);

		
		if (numIngresado <= anterior) {
			contGrupos++;
			printDebug("-- ACUM: ", acumPorGrupo);
			acumPorGrupo = 1;
		} else {
			acumPorGrupo++;
		}
		anterior = numIngresado;

		i++; // TODO: Solo para pruebas
	} while (numIngresado != -1);
	
	printInterrumpciones(contGrupos);
	return 0;
}

/* FUNCIONES */

/**
 * @brief Muestra mensaje y captura valor numerico ingresado por teclado.
 * 
 * @param mensaje Mensaje a imprimir en pantalla.
 * @param numero Variable donde se almacenara el valor obtenido.
 */
void getInt(string mensaje, int &numero) {
	cout << mensaje;
	cin >> numero;
}

void printInterrumpciones(int cantidad) {
	cout << "El orden ascendente se interrumpe " << cantidad << " veces" << endl;
}

void printDebug(string debug, int numero) {
	cout << debug << numero << endl;
}
