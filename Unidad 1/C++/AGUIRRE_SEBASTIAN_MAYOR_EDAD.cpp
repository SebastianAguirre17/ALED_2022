#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void printDebug (string palabra) {
	cout << "-- DEBUG -- : " << palabra << endl;
}

void getString(string mensaje, string &palabra) {
	cout << mensaje;
	cin >> palabra;
}

int getInt(string mensaje, int &numero) {
	cout << mensaje;
	cin >> numero;
}

void ingresoDatosPersona(string &nombre, int &edad) {
	getInt("Ingrese la edad: ", edad);
	if (edad != -1) {
		getString("Ingrese el nombre: ", nombre);
	}
}

int main(){

	int orden, edad, maxEdad = 0, maxOrden, acumEdad = 0;
	string nombre, maxNombre;
	
	ingresoDatosPersona(nombre, edad);
	printDebug(nombre);
	while (edad != -1) {
		orden++;
		
		// acumularEdad(acumEdad);
		ingresoDatosPersona(nombre, edad);
	}

	// mostrarDatos();

	return 0;
}


