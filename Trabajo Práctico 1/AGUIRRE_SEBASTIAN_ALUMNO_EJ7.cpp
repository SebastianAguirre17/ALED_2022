#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SEMANA 7
#define MES 4

struct tySemanal {
    int diasSinLluvia;
    int acumSemana;
};

struct tyMensual {
    float mayorPromedio;
    int semanaMayor;
    int acumMensual;
};

using namespace std;

void inicializarContSemanal(tySemanal &cont);
void inicializarContMensual(tyMensual &cont);
void mostrarInformeSemanal(int semana, tySemanal &cont);
void mostrarInformeMensual(tyMensual &cont);

int main(){
    mostrarTitulo("Ejercicio 7");
	
    int milPorDia, dia = 0, semana = 0; 
    float auxPromedio;
    tyMensual contMensual;
    tySemanal contSemanal;

    inicializarContMensual(contMensual);

    while (semana < MES) {
        inicializarContSemanal(contSemanal);
        semana++;

        while (dia < SEMANA) {
            dia++;
            ingresarEntero(milPorDia, "Ingrese la cantidad del dia (ml): ");

            contSemanal.acumSemana += milPorDia;
            if (milPorDia == 0)
                contSemanal.diasSinLluvia++;
        }
        contMensual.acumMensual += contSemanal.acumSemana;

        auxPromedio = contSemanal.acumSemana / SEMANA;
        if (auxPromedio > contMensual.mayorPromedio) {
            contMensual.mayorPromedio = auxPromedio;
            contMensual.semanaMayor = semana;
        }

        mostrarInformeSemanal(semana, contSemanal);
        dia = 0;
    }

    mostrarInformeMensual(contMensual);

	return EXIT_SUCCESS;
}

void inicializarContSemanal(tySemanal &cont) {
    cont.acumSemana = 0;
    cont.diasSinLluvia = 0;
}

void inicializarContMensual(tyMensual &cont) {
    cont.acumMensual = 0;
    cont.semanaMayor = 0;
    cont.mayorPromedio = 0;
}

void mostrarInformeSemanal(int semana, tySemanal &cont) {
    mostrarTitulo("Informe Semanal");
    cout << "Promedio de lluvia de la semana " << semana << ": " << cont.acumSemana / SEMANA << " ml." << endl;
    cout << "Porcentaje de de dias sin lluvia: " << cont.diasSinLluvia * 100 / SEMANA << "%." << endl << endl;
}

void mostrarInformeMensual(tyMensual &cont) {
    mostrarTitulo("Informe Mensual");
    cout << "Total de milimetros caidos: " << cont.acumMensual << endl;
    cout << "Semana de mayor promedio de lluvia: " << cont.semanaMayor << endl << endl;
}