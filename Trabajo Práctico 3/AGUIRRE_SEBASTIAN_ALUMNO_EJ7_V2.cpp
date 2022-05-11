#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SALIDA          4
#define TOPE_COCHERA    2
#define LIBRE           "LIBRE"

struct tyVehiculo {
    string patente;
    string hora;
};

string menu() {
    string menu = "";
    menu += "---------------------------------------\n";
    menu += "     Ejercicio 7 - Estacionamiento\n";
    menu += "---------------------------------------\n\n";
    menu += "1) Ingreso de Vehiculo\n";
    menu += "2) Salida de Vehiculo\n";
    menu += "3) Listado de Vehiculos\n";
    menu += "4) Fin de Programa\n\n";
    menu += "Opcion: ";
    return menu;
}

void inicializarEstacionamiento(tyVehiculo vehiculos[], int tope) {
    int i;
    for (i = 0; i < tope; i++) {
        vehiculos[i].patente = "LIBRE";
    }
}

int buscarCochera(tyVehiculo vehiculos[], int tope, string patente) {
    int i = 0;
    while (i < tope and vehiculos[i].patente != patente) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void agregarVehiculo(tyVehiculo vehiculos[], int tope, int pos) {
    tyVehiculo auxVehiculo;
    ingresarStringValido(auxVehiculo.patente, 6, 10, "Ingrese la patente: ");
    if (buscarCochera(vehiculos, tope, auxVehiculo.patente) == EXIT_ERROR) {
        ingresarStringValido(auxVehiculo.hora, 4, 5, "Ingrese hora (HH:MM): ");
        vehiculos[pos] = auxVehiculo;
        mostrarString("\nVehiculo guardado.\n\n");
    } else {
        mostrarString("\nEl vehiculo ya se encuentra estacionado.\n\n");
    }
}

void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados) {
    mostrarTitulo("Ingreso de Vehiculo");

    int pos = buscarCochera(vehiculos, topeCochera, LIBRE);
    if (pos != EXIT_ERROR) {
        agregarVehiculo(vehiculos, topeCochera, pos);
        cantVehiculosEstacionados++;
    } else {
        mostrarString("No hay cocheras libres.\n\n");
    }

    system("PAUSE");
}

void mostrarVehiculo(tyVehiculo vehiculo) {
    if (vehiculo.patente != LIBRE)
        cout << "Patente: " << vehiculo.patente << " - Hora de ingreso: " << vehiculo.hora << " Hs." << endl;
}

void mostrarVehiculos(tyVehiculo vehiculos[], int topeCochera) {
    int i;
    for(i = 0; i < topeCochera; i++) {
        mostrarVehiculo(vehiculos[i]);
    } 
    cout << endl;
}


void listadoDeVehiculos(tyVehiculo vehiculos[], int topeCochera, int cantVehiculosEstacionados) {
    mostrarTitulo("Listado de Vehiculos");
    if (cantVehiculosEstacionados > 0)
        mostrarVehiculos(vehiculos, topeCochera); 
    else
        mostrarString("No hay vehiculos estacionados.\n\n");  
    system("PAUSE");   
}


int main(){
    string menuDeOpciones = menu();
    int cantVehiculosEstacionados = 0, opcion;

    tyVehiculo cochera[TOPE_COCHERA];
    inicializarEstacionamiento(cochera, TOPE_COCHERA);
    
    do {
        system("CLS");
        ingresarEntero(opcion, menuDeOpciones);
        switch (opcion) {
            case 1:
                ingresoDeVehiculo(cochera, TOPE_COCHERA, cantVehiculosEstacionados);
                break;
            case 2:
                //salidaDeVehiculo(cochera, cantVehiculosEstacionados);
                break;
            case 3:
                listadoDeVehiculos(cochera, TOPE_COCHERA, cantVehiculosEstacionados);
                break;
            case 4:
                //finalizarPrograma(cantVehiculosEstacionados);
                break;
            //default:
                //mostrarMensajeDeError();
        }
    } while (opcion != SALIDA or cantVehiculosEstacionados != 0);

    mostrarTitulo("Gracias por usar este programa");
	return EXIT_SUCCESS;
}
