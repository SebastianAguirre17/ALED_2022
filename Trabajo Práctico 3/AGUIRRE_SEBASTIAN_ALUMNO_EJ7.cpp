#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define SALIDA 99
#define TOPE_COCHERA 10
#define APERTURA 7
#define CIERRE 21

struct tyVehiculo {
    string patente;
    int hora;
};

void aperturaDeEstacionamiento(string menu, tyVehiculo vehiculos[], int topeCochera);

void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &topeActual); 
int  buscarVehiculoPorPatente(tyVehiculo vehiculos[], int tope, string patente);
void agregarVehiculo(tyVehiculo vehiculos[], int &topeActual, string patente);
int  pedirHoraEnRango(int desde, int hasta);

void salidaDeVehiculo(tyVehiculo vehiculos[], int &topeActual);
void verificarVehiculo(tyVehiculo vehiculos[], int &topeActual);
void quitarVehiculo(tyVehiculo vehiculos[], int &topeActual, int pos);

void listadoDeVehiculos(tyVehiculo vehiculos[], int topeActual);
void mostrarVehiculos(tyVehiculo vehiculos[], int topeActual);

void finalizarPrograma(tyVehiculo vehiculos[], int topeActual, int &opcion);

void pausarPrograma();

int main(){
    string menu = "1) Ingreso de Vehiculo\n2) Salida de Vehiculo\n3) Listado de Vehiculos\n4) Fin de Programa\n\nOpcion: ";
    tyVehiculo vehiculos[TOPE_COCHERA];
    
    aperturaDeEstacionamiento(menu, vehiculos, TOPE_COCHERA);
    mostrarTitulo("Gracias por usar este programa.");

	return EXIT_SUCCESS;
}

void aperturaDeEstacionamiento(string menu, tyVehiculo vehiculos[], int topeCochera) {
    int opcion = 0, topeActual = 0;

    while (opcion != SALIDA) {
        system("CLS");
        mostrarTitulo("Ejercicio 7 - Estacionamiento");

        opcion = pedirEntero(menu);
        switch(opcion) {
            case 1:
                ingresoDeVehiculo(vehiculos, topeCochera, topeActual);
                break;
            case 2:
                salidaDeVehiculo(vehiculos, topeActual);
                break;
            case 3:
                listadoDeVehiculos(vehiculos, topeActual);
                break;
            case 4:
                finalizarPrograma(vehiculos, topeActual, opcion);
                break;
        }
    }
}

void ingresoDeVehiculo(tyVehiculo vehiculos[], int topeCochera, int &topeActual) {
    mostrarTitulo("Ingreso de Vehiculo");

    cout << "Cocheras libres: " << topeCochera - topeActual << " de " << topeCochera << endl << endl;
    if (topeActual < topeCochera) {
        string patente = retornarString("Ingrese la patente: ");
        if (buscarVehiculoPorPatente(vehiculos, topeActual, patente) == EXIT_ERROR)
            agregarVehiculo(vehiculos, topeActual, patente);
        else 
            mostrarMensaje("\nEl vehiculo se encuentra estacionado.\n");
    } else {
        mostrarMensaje("No hay lugares para estacionar.\n");
    }
    pausarPrograma();
}

int buscarVehiculoPorPatente(tyVehiculo vehiculos[], int tope, string patente) {
    int i = 0;
    bool encontrado = false;

    while (i < tope and not encontrado) {
        if (vehiculos[i].patente == patente) {
            encontrado = true;
            i--;
        }
        i++;
    }
    return encontrado ? i : EXIT_ERROR;
}

void agregarVehiculo(tyVehiculo vehiculos[], int &topeActual, string patente) {
    tyVehiculo auxVehiculo;
    auxVehiculo.patente = patente;
    auxVehiculo.hora = pedirHoraEnRango(APERTURA, CIERRE);
    vehiculos[topeActual] = auxVehiculo;
    topeActual++;
    mostrarMensaje("\nVehiculo guardado.\n");
}

int pedirHoraEnRango(int desde, int hasta) {
    int valor;
    do {
        cout << "Ingrese la hora (" << desde << " a " << hasta << "): ";
        cin >> valor;
    } while (valor < desde or valor > hasta);
    return valor;
}

void listadoDeVehiculos(tyVehiculo vehiculos[], int topeActual) {
    mostrarTitulo("Listado de Vehiculos");
    
    if (topeActual == 0)
        mostrarMensaje("No hay Vehiculos estacionados.\n");
    else 
        mostrarVehiculos(vehiculos, topeActual);

    pausarPrograma();
}

void mostrarVehiculos(tyVehiculo vehiculos[], int topeActual) {
    int i;
    for(i = 0; i < topeActual; i++) {
        cout << "Patente: " << vehiculos[i].patente << " - Hora de ingreso: " << vehiculos[i].hora << endl; 
    } 
}

void salidaDeVehiculo(tyVehiculo vehiculos[], int &topeActual) {
    mostrarTitulo("Salida de Vehiculo");

    if (topeActual == 0)
        mostrarMensaje("No hay vehiculos estacionados.\n");
    else 
        verificarVehiculo(vehiculos, topeActual);

    pausarPrograma();
}

void verificarVehiculo(tyVehiculo vehiculos[], int &topeActual) {
    string patente = retornarString("Ingrese la patente: ");
    int pos = buscarVehiculoPorPatente(vehiculos, topeActual, patente);

    if (pos != EXIT_ERROR) 
        quitarVehiculo(vehiculos, topeActual, pos);
    else
        mostrarMensaje("\nEl vehiculo no se encuentra estacionado.\n");
}

void quitarVehiculo(tyVehiculo vehiculos[], int &topeActual, int pos) {
    int i;
    cout << "\nEl vehiculo entro a las: " << vehiculos[pos].hora << endl;
    for (i = pos; i < topeActual; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    topeActual--;
}


void finalizarPrograma(tyVehiculo vehiculos[], int topeActual, int &opcion) {
    if (topeActual != 0) 
        mostrarMensaje("\nNo se puede cerrar, aun quedan vehiculos.\n");
    else 
        opcion = SALIDA;
    pausarPrograma();
}

void pausarPrograma() {
    cout << endl;
    system("PAUSE");
}