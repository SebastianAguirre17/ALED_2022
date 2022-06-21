#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SALIDA          4
#define APERTURA        7
#define CIERRE          21
#define TOPE_COCHERA    10

struct tyVehiculo {
    string patente;
    int hora;
    int minutos;
};

string menu();
void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados);
bool hayEspacioEnCohcera(int topeCochera, int cantVehiculosEstacionados);
int  buscarVehiculoPorPatente(tyVehiculo vehiculos[], int cantVehiculosEstacionados, string patente);
void agregarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados);
void salidaDeVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados);
void quitarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados, int pos);
void listadoDeVehiculos(tyVehiculo vehiculos[], int cantVehiculosEstacionados);
void mostrarVehiculos(tyVehiculo vehiculos[], int cantVehiculosEstacionados);
void mostrarVehiculo(tyVehiculo vehiculo);
void finalizarPrograma(int cantVehiculosEstacionados);
void mostrarMensajeDeError();

int main(){
    string menuDeOPciones = menu();
    tyVehiculo cochera[TOPE_COCHERA];
    int opcion, cantVehiculosEstacionados = 0;

    do {
        system("CLS");
        ingresarEntero(opcion, menuDeOPciones);
        switch (opcion) {
            case 1:
                ingresoDeVehiculo(cochera, TOPE_COCHERA, cantVehiculosEstacionados);
                break;
            case 2:
                salidaDeVehiculo(cochera, cantVehiculosEstacionados);
                break;
            case 3:
                listadoDeVehiculos(cochera, cantVehiculosEstacionados);
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

// INGRESO
void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados) {
    mostrarTitulo("Ingreso de Vehiculo");

    if (hayEspacioEnCohcera(topeCochera, cantVehiculosEstacionados)) {
        agregarVehiculo(vehiculos, cantVehiculosEstacionados);
    } else {
        cout << "No hay cocheras libres.\n\n";
    }

    system("PAUSE");
}

bool hayEspacioEnCohcera(int topeCochera, int cantVehiculosEstacionados) {
    return cantVehiculosEstacionados < topeCochera;
}

void agregarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados) {
    tyVehiculo auxVehiculo;
    ingresarStringValido(auxVehiculo.patente, 6, 10, "Ingrese la patente: "); // QWE123 - AS345AS
    if (buscarVehiculoPorPatente(vehiculos, cantVehiculosEstacionados, auxVehiculo.patente) == EXIT_ERROR) {
        ingresarEnteroEnRango(auxVehiculo.hora, APERTURA, CIERRE, "Ingrese hora de ingreso (7 a 21): ");
        ingresarEnteroEnRango(auxVehiculo.minutos, 0, 59, "Ingrese los minutos: ");
        vehiculos[cantVehiculosEstacionados] = auxVehiculo;
        cantVehiculosEstacionados++;
        cout << "\nVehiculo guardado.\n\n";
    } else {
        cout << "\nEl vehiculo ya se encuentra estacionado.\n\n";
    }
}

int buscarVehiculoPorPatente(tyVehiculo vehiculos[], int cantVehiculosEstacionados, string patente) {
    int i = 0;
    while (i < cantVehiculosEstacionados and vehiculos[i].patente != patente) {
        i++;
    }
    if (i == cantVehiculosEstacionados)
        i = EXIT_ERROR;
    return i;
}

// SALIDA
void salidaDeVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados) {
    mostrarTitulo("Salida de Vehiculo");
    
    if (cantVehiculosEstacionados > 0) {
        string patente;
        ingresarStringValido(patente, 6, 10, "Ingrese la patente: ");
        int pos = buscarVehiculoPorPatente(vehiculos, cantVehiculosEstacionados, patente);
        if (pos != EXIT_ERROR) {
            cout << "\nEl vehiculo entro a las: " << vehiculos[pos].hora << ":";
            if (vehiculos[pos].minutos < 10)
                cout << "0" << vehiculos[pos].minutos << " Hs." << endl << endl;
            else
                cout << vehiculos[pos].minutos << " Hs." << endl << endl;
            quitarVehiculo(vehiculos, cantVehiculosEstacionados, pos);
        } else {
            cout << "\nEl vehiculo no se encuentra estacionado.\n\n";
        }
    } else {
        cout << "No hay vehiculos estacionados.\n\n";
    } 

    system("PAUSE");
}

void quitarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados, int pos) {
    int i;
    for (i = pos; i < cantVehiculosEstacionados; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    cantVehiculosEstacionados--;
}

// LISTADO
void listadoDeVehiculos(tyVehiculo vehiculos[], int cantVehiculosEstacionados) {
    mostrarTitulo("Listado de Vehiculos");
    
    if (cantVehiculosEstacionados == 0) {
        cout << "No hay Vehiculos estacionados.\n\n";
    } else {
        mostrarVehiculos(vehiculos, cantVehiculosEstacionados);
    }
    system("PAUSE");   
}

void mostrarVehiculos(tyVehiculo vehiculos[], int cantVehiculosEstacionados) {
    int i;
    for(i = 0; i < cantVehiculosEstacionados; i++) {
        mostrarVehiculo(vehiculos[i]);
    } 
    cout << endl;
}

void mostrarVehiculo(tyVehiculo vehiculo) {
    cout << "Patente: " << vehiculo.patente;
    if (vehiculo.hora < 10)
        cout << " - Hora de ingreso: " << "0" << vehiculo.hora << ":"; 
    else
        cout << " - Hora de ingreso: " << vehiculo.hora << ":"; 
    if (vehiculo.minutos < 10)
        cout << "0" << vehiculo.minutos << " Hs." << endl;
    else
        cout << vehiculo.minutos << " Hs." << endl;
}

// FIN
void finalizarPrograma(int cantVehiculosEstacionados) {
    if (cantVehiculosEstacionados != 0) {
        cout << "\nNo se puede cerrar, aun quedan vehiculos.\n\n";
        system("PAUSE");
    } 
}

void mostrarMensajeDeError() {
    cout << "\nLa opcion ingresada es incorrecta.\n\n";
    system("PAUSE");
}