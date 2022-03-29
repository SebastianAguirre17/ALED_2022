#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*	
	Ejercicio 2: 
	De una lista de personas se ingresa su edad. 
	La carga termina cuando en la edad se ingresa el valor -1
	Se pide indicar:
	Cuál de todos ellos es el mayor (suponer único).
	Cuántos de ellos son menores de edad (17 años o menos).
	Cuántos de ellos están en edad laboral activa (hasta 65 años, inclusive).
	Mostrar las edades de quiénes están por jubilarse (única para ambos	sexos)
*/

int main(){
	
	int edad, mayor, menores, edadLaborar, porJubilarse;
	
	cout << "Ingrese la edad: ";
	cin >> edad;
	
	if (edad > -1 and edad < 100) {
		mayor = edad;
	}
	
	while(edad != -1) {
		if (edad < -1 or edad > 100) {
			cout << "Edad incorrecta!\n";
		} 
		else {
			cout << "Edad correcta";
		}	
		
		
		cout << "\nIngrese la edad: ";
		cin >> edad;
	}


	return 0;
}
