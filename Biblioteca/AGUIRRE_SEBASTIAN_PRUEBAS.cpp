#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "AGUIRRE_SEBASTIAN.h" 

struct tyPersona
{
	int dni;
	char nombre[30];
};

void mostrarArch (char arch[]);

int main(){

	mostrarArch("prueba.dat");

	return EXIT_SUCCESS;
}

/*	Para implementaci�n local en el cpp*/

void mostrarArch (char arch[]) {
	tyPersona reg;
	bool pude, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(reg);
	abrirArchivo(arch, "rb", fichero);
	cout<<"El registro pesa: "<<sizeof(reg)<<" bytes"<<endl;
	if (pude){
		leerArchivo(fichero, &reg, largo, finArch, pude);
		while(pude && !finArch) {
			cout << "Nombre: "<<reg.nombre << endl;
			cout << "------------------";
			leerArchivo(fichero, &reg,sizeof(reg), finArch, pude);
		}
		cerrarArchivo(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
}




