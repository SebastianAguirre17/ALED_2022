#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SALIDA          4
#define TOPE_COCHERA    10
#define MIN_LEN_PATENTE 6
#define MAX_LEN_PATENTE 10
#define MAX_LEN_HORA    6
#define TOPE_PATENTE    10
#define TOPE_HORA       6
#define LIBRE           "LIBRE"

struct tyVehiculo {
    char patente[TOPE_PATENTE];
    char hora[TOPE_HORA];
};

string menu();

void inicializarEstacionamiento(tyVehiculo vehiculos[], int topeCochera, char nombreArchivo[], int &cantVehiculosEstacionados); 

void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados);
int buscarCochera(tyVehiculo vehiculos[], int topeCochera, string patente);
void agregarVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados, int pos);

void salidaDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &cantVehiculosEstacionados);
void quitarVehiculo(tyVehiculo vehiculos[], int &cantVehiculosEstacionados, int pos); 

void listadoDeVehiculos(tyVehiculo vehiculos[], int topeCochera, int cantVehiculosEstacionados);
void mostrarVehiculos(tyVehiculo vehiculos[], int topeCochera);
void mostrarVehiculo(tyVehiculo vehiculo);

void finalizarPrograma(tyVehiculo vehiculos[], int topeCochera, char nombreArchivo[]);
void mostrarMensajeDeError();

int main(){
    tyVehiculo cochera[TOPE_COCHERA];
    string menuDeOpciones = menu();
    int cantVehiculosEstacionados = 0, opcion;
    char path[] = "estacionamiento.dat";
    
    inicializarEstacionamiento(cochera, TOPE_COCHERA, path, cantVehiculosEstacionados);
    
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
                finalizarPrograma(cochera, TOPE_COCHERA, path);
                break;
            default:
                mostrarMensajeDeError();
        }
    } while (opcion != SALIDA);

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

void inicializarEstacionamiento(tyVehiculo vehiculos[], int topeCochera, char nombreArchivo[], int &cantVehiculosEstacionados) {
    tyVehiculo vehiculo;
    int i = 0, size = sizeof(vehiculo);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(nombreArchivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &vehiculo, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < topeCochera) {
            if (strcmp(vehiculo.patente, LIBRE) != 0) {
                cantVehiculosEstacionados++;
            }
            vehiculos[i++] = vehiculo;
            leerArchivo(fichero, &vehiculo, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } else {
        for (i = 0; i < topeCochera; i++) {
            strcpy(vehiculos[i].patente, LIBRE);
            strcpy(vehiculos[i].hora, LIBRE);
        }
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

    ingresarCadenaCharValida(auxVehiculo.patente, MAX_LEN_PATENTE, "Ingrese la patente: ");
    if (buscarCochera(vehiculos, topeCochera, auxVehiculo.patente) == EXIT_ERROR) {
        ingresarCadenaCharValida(auxVehiculo.hora, MAX_LEN_HORA, "Ingrese hora (HH:MM): ");
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
    strcpy(vehiculos[pos].patente, LIBRE);
    strcpy(vehiculos[pos].hora, LIBRE);
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
    if (strcmp(vehiculo.patente, LIBRE) != 0) {
        cout << "Patente: " << vehiculo.patente << " - Hora de ingreso: " << vehiculo.hora << " Hs." << endl;
    }
}

void finalizarPrograma(tyVehiculo vehiculos[], int topeCochera, char nombreArchivo[]) {
    FILE *fichero = NULL;
    char op[] = "wb";
    int i, size = sizeof(tyVehiculo);
    bool result;

    abrirArchivo(nombreArchivo, op, fichero, result);
    if (result) {
        for (i = 0; i < topeCochera; i++) {
            escribirArchivo(&vehiculos[i], size, fichero, result);
        }
        cerrarArchivo(fichero, result);
    }
}

void mostrarMensajeDeError() {
    mostrarString("\nLa opcion ingresada es incorrecta.\n\n");
    system("PAUSE");
}