#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SALIDA          999
#define APERTURA        7
#define CIERRE          21
#define TOPE_COCHERA    10

struct tyVehiculo {
    string patente;
    int hora;
};

string menu();
void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &topeActual);
bool hayEspacioEnCohcera(int topeCochera, int topeActual);
int  buscarVehiculoPorPatente(tyVehiculo vehiculos[], int topeActual, string patente);
void agregarVehiculo(tyVehiculo vehiculos[], int &topeActual);
void salidaDeVehiculo(tyVehiculo vehiculos[], int &topeActual);
void quitarVehiculo(tyVehiculo vehiculos[], int &topeActual, int pos);
void listadoDeVehiculos(tyVehiculo vehiculos[], int topeActual);
void mostrarVehiculos(tyVehiculo vehiculos[], int topeActual);
void finalizarPrograma(tyVehiculo vehiculos[], int topeActual, int &opcion);

int main(){
    string menuDeOPciones = menu();
    tyVehiculo cochera[TOPE_COCHERA];
    int opcion, topeActual = 0;

    do {
        system("CLS");
        ingresarEntero(opcion, menuDeOPciones);
        switch (opcion) {
            case 1:
                ingresoDeVehiculo(cochera, TOPE_COCHERA, topeActual);
                break;
            case 2:
                salidaDeVehiculo(cochera, topeActual);
                break;
            case 3:
                listadoDeVehiculos(cochera, topeActual);
                break;
            case 4:
                finalizarPrograma(cochera, topeActual, opcion);
                break;
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

// INGRESO
void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &topeActual) {
    mostrarTitulo("Ingreso de Vehiculo");

    if (hayEspacioEnCohcera(topeCochera, topeActual)) {
        agregarVehiculo(vehiculos, topeActual);
    } else {
        cout << "No hay cocheras libres.\n\n";
    }

    system("PAUSE");
}

bool hayEspacioEnCohcera(int topeCochera, int topeActual) {
    return topeActual < topeCochera;
}

void agregarVehiculo(tyVehiculo vehiculos[], int &topeActual) {
    tyVehiculo auxVehiculo;
    cin.ignore(); // Limpiar buffer cin para usar getline
    ingresarString(auxVehiculo.patente, "Ingrese la patente: ");
    if (buscarVehiculoPorPatente(vehiculos, topeActual, auxVehiculo.patente) == EXIT_ERROR) {
        ingresarEnteroEnRango(auxVehiculo.hora, APERTURA, CIERRE, "Ingrese hora de ingreso (7 a 21): ");
        vehiculos[topeActual] = auxVehiculo;
        topeActual++;
        cout << "\nVehiculo guardado.\n\n";
    } else {
        cout << "\nEl vehiculo ya se encuentra estacionado.\n\n";
    }
}

int buscarVehiculoPorPatente(tyVehiculo vehiculos[], int topeActual, string patente) {
    int i = 0;
    while (i < topeActual and vehiculos[i].patente != patente) {
        i++;
    }
    if (i == topeActual)
        i = EXIT_ERROR;
    return i;
}

// SALIDA
void salidaDeVehiculo(tyVehiculo vehiculos[], int &topeActual) {
    mostrarTitulo("Salida de Vehiculo");
    
    if (topeActual > 0) {
        string patente;
        cin.ignore(); // Limpiar buffer cin para usar getline
        ingresarString(patente, "Ingrese la patente: ");
        int pos = buscarVehiculoPorPatente(vehiculos, topeActual, patente);
        if (pos != EXIT_ERROR) {
            cout << "\nEl vehiculo entro a las: " << vehiculos[pos].hora << endl << endl;
            quitarVehiculo(vehiculos, topeActual, pos);
        } else {
            cout << "\nEl vehiculo no se encuentra estacionado.\n\n";
        }
    } else {
        cout << "No hay vehiculos estacionados.\n\n";
    } 

    system("PAUSE");
}

void quitarVehiculo(tyVehiculo vehiculos[], int &topeActual, int pos) {
    int i;
    for (i = pos; i < topeActual; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    topeActual--;
}

// LISTADO
void listadoDeVehiculos(tyVehiculo vehiculos[], int topeActual) {
    mostrarTitulo("Listado de Vehiculos");
    
    if (topeActual == 0) {
        cout << "No hay Vehiculos estacionados.\n\n";
    } else {
        mostrarVehiculos(vehiculos, topeActual);
    }

    system("PAUSE");   
}

void mostrarVehiculos(tyVehiculo vehiculos[], int topeActual) {
    int i;
    for(i = 0; i < topeActual; i++) {
        cout << "Patente: " << vehiculos[i].patente << " - Hora de ingreso: " << vehiculos[i].hora << endl; 
    } 
    cout << endl;
}

// FIN
void finalizarPrograma(tyVehiculo vehiculos[], int topeActual, int &opcion) {
    if (topeActual != 0) {
        cout << "\nNo se puede cerrar, aun quedan vehiculos.\n\n";
        system("PAUSE");
    } else {
        opcion = SALIDA;
    }
}
