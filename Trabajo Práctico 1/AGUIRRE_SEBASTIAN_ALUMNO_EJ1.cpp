#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*	
	Ejercicio 1: 
	A partir de un valor ingresado por el usuario (el cual deberá estar
	comprendido entre 2 y 9, inclusive), generar y mostrar todos los múltiplos del
	mismo menores a 100, primero en forma ascendente y luego en sentido inverso
	dentro del mismo programa. 
*/

int main(){
	
	int number = 0;
	
	while (number < 2 or number > 9) {
		cout << "Ingrese un numero entre 2 y 9: ";
		cin >> number;
		system("cls");
	}
	
	cout << "Multiplos de " << number;
	cout << " menores a 100 de forma Ascendente" << endl;
	
	int i;
	for (i = 2; i <= 100 ; i++) {
		if (i % number == 0) {
			cout << i << endl;
		}
	}
	
	cout << "\nMultiplos de " << number;
	cout << " menores a 100 de forma Descendente" << endl;
	
	for (i = 100; i >= 2 ; i--) {
		if (i % number == 0) {
			cout << i << endl;
		}
	}
	
	return 0;
}



