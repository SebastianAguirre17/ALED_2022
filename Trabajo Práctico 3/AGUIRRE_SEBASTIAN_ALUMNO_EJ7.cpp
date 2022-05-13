#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SALIDA          4
#define TOPE_COCHERA    10
#define MIN_LEN_PATENTE 6
#define MAX_LEN_PATENTE 10
#define MIN_LEN_HORA    4
#define MAX_LEN_HORA    5
#define LIBRE           "LIBRE"
#define VACIO           ""


struct tyVehiculo {
    string patente;
    string hora;
};

string menu();

void inicializarEstacionamiento(tyVehiculo vehiculos[], int topeCochera);

void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados);
int buscarCochera(tyVehiculo vehiculos[], int topeCochera, string patente);
void agregarVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados, int pos);

void salidaDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados);
void quitarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados, int pos); 

void listadoDeVehiculos(tyVehiculo vehiculos[], int topeCochera, int cantVehiculosEstacionados);
void mostrarVehiculos(tyVehiculo vehiculos[], int topeCochera);
void mostrarVehiculo(tyVehiculo vehiculo);

void finalizarPrograma(int cantVehiculosEstacionados);
void mostrarMensajeDeError();

int main(){
    string menuDeOpciones = menu();
    int cantVehiculosEstacionados, opcion;
    tyVehiculo cochera[TOPE_COCHERA];

    inicializarEstacionamiento(cochera, TOPE_COCHERA);
    cantVehiculosEstacionados = 0;
    
    do {
        system("CLS");
        ingresarEntero(opcion, menuDeOpciones);
        switch (opcion) {
            case 1:
                ingresoDeVehiculo(cochera, TOPE_COCHERA, cantVehiculosEstacionados);
                break;
            case 2:
                salidaDeVehiculo(cochera, TOPE_COCHERA, cantVehiculosEstacionados);
                break;
            case 3:
                listadoDeVehiculos(cochera, TOPE_COCHERA, cantVehiculosEstacionados);
                break;
            case 4:
                finalizarPrograma(cantVehiculosEstacionados);
                break;
            default:
                mostrarMensajeDeError();
        }
    } while (opcion != SALIDA or cantVehiculosEstacionados != 0);

    mostrarTitulo("Gracias por usar este programa");
	return EXIT_SUCCESS;
}

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

void inicializarEstacionamiento(tyVehiculo vehiculos[], int topeCochera) {
    int i;
    for (i = 0; i < topeCochera; i++) {
        vehiculos[i].patente = LIBRE;
    }
}

void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados) {
    mostrarTitulo("Ingreso de Vehiculo");

    if (cantVehiculosEstacionados < topeCochera) {
        int pos = buscarCochera(vehiculos, topeCochera, LIBRE);
        agregarVehiculo(vehiculos, topeCochera, cantVehiculosEstacionados, pos);
    } else {
        mostrarString("No hay cocheras libres.\n\n");
    }

    system("PAUSE");
}

int buscarCochera(tyVehiculo vehiculos[], int topeCochera, string patente) {
    int i = 0;
    while (i < topeCochera and vehiculos[i].patente != patente) {
        i++;
    }
    if (i == topeCochera)
        i = EXIT_ERROR;
    return i;
}

void agregarVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados, int pos) {
    tyVehiculo auxVehiculo;

    ingresarStringValido(auxVehiculo.patente, MIN_LEN_PATENTE, MAX_LEN_PATENTE, "Ingrese la patente: ");
    if (buscarCochera(vehiculos, topeCochera, auxVehiculo.patente) == EXIT_ERROR) {
        ingresarStringValido(auxVehiculo.hora, MIN_LEN_HORA, MAX_LEN_HORA, "Ingrese hora (HH:MM): ");
        vehiculos[pos] = auxVehiculo;
        cantVehiculosEstacionados++;
        mostrarString("\nVehiculo guardado.\n\n");
    } else {
        mostrarString("\nEl vehiculo ya se encuentra estacionado.\n\n");
    }
}

void salidaDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados) {
    mostrarTitulo("Salida de Vehiculo");
    
    if (cantVehiculosEstacionados > 0) {
        string patente;

        ingresarStringValido(patente, MIN_LEN_PATENTE, MAX_LEN_PATENTE, "Ingrese la patente: ");
        int pos = buscarCochera(vehiculos, topeCochera, patente);
        if (pos != EXIT_ERROR) {
            cout << "\nEl vehiculo entro a las " << vehiculos[pos].hora << " Hs." << endl << endl;
            quitarVehiculo(vehiculos, cantVehiculosEstacionados, pos);
        } else {
            mostrarString("\nEl vehiculo no se encuentra estacionado.\n\n");
        }
    } else {
        mostrarString("No hay vehiculos estacionados.\n\n");
    } 

    system("PAUSE");
}

void quitarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados, int pos) {
    vehiculos[pos].patente = LIBRE;
    vehiculos[pos].hora = VACIO;
    cantVehiculosEstacionados--;
}

void listadoDeVehiculos(tyVehiculo vehiculos[], int topeCochera, int cantVehiculosEstacionados) {
    mostrarTitulo("Listado de Vehiculos");

    if (cantVehiculosEstacionados > 0)
        mostrarVehiculos(vehiculos, topeCochera); 
    else
        mostrarString("No hay vehiculos estacionados.\n\n");  
    
    system("PAUSE");   
}

void mostrarVehiculos(tyVehiculo vehiculos[], int topeCochera) {
    int i;
    for(i = 0; i < topeCochera; i++) {
        if (vehiculos[i].patente != LIBRE) {
            mostrarVehiculo(vehiculos[i]);
        }
    } 
    cout << endl;
}

void mostrarVehiculo(tyVehiculo vehiculo) {
    cout << "Patente: " << vehiculo.patente << " - Hora de ingreso: " << vehiculo.hora << " Hs." << endl;
}

void finalizarPrograma(int cantVehiculosEstacionados) {
    if (cantVehiculosEstacionados != 0) {
        mostrarString("\nNo se puede cerrar, aun quedan vehiculos.\n\n");
        system("PAUSE");
    } 
}

void mostrarMensajeDeError() {
    mostrarString("\nLa opcion ingresada es incorrecta.\n\n");
    system("PAUSE");
}