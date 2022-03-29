#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*	
	Ejercicio 4: Ingresar una serie de n�meros naturales que termina con -1 e
    indicar cu�ntas veces se interrumpe el orden ascendente y cuántos números
    hay en cada grupo ordenado
*/

getInt(string mensaje, int &numero) {
	cout << mensaje;
	cin >> numero;
}

printDebugInt (int numero) {
	cout << "-- DEBUG -- : " << numero << endl;
}

int main(){
	
	int numIngresado;

	do {
		getInt("Ingrese un numero: (-1 para finalizar)", numIngresado);
		printDebugInt(numIngresado);
		
	} while (numIngresado != -1);
	


	return 0;
}
