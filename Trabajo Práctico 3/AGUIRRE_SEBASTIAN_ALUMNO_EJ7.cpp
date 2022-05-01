#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 5
#define SALIDA 5

struct tyVehiculo {
    string patente;
    int hora;
};

void mostrarMenu(string menu, tyVehiculo vehiculos[], int tope, int &topeReal, tyVehiculo &vehiculo);

void ingresoDeVehiculo(tyVehiculo vehiculos[], int tope, int &topeReal, tyVehiculo &vehiculo);
int buscarPatente(tyVehiculo vehiculos[], int tope, string patente); 
void pedirHoraEnRango(int &valor, int desde, int hasta);
void agregarVehiculo(tyVehiculo vehiculos[], tyVehiculo vehiculo, int &pos);

void salidaDeVehiculo(tyVehiculo vehiculos[], int &topeReal);
void quitarVehiculo(tyVehiculo vehiculos[], int &topeReal, int pos); 

void listadoDeVehiculos(tyVehiculo vehiculos[], int tope);
void mostrarVehiculo(tyVehiculo vehiculo); 

void verificarSalida(tyVehiculo vehiculos[], int topeReal, int &opcion);
void pausarPrograma();

int main(){
    tyVehiculo cochera[TOPE];
    tyVehiculo vehiculo;
    int topeReal = 0;
    
    mostrarMenu("1) Ingreso de Vehiculo\n2) Salida de Vehiculo\n3) Listado de Vehiculos\n4) Fin\n\nOpcion: ", cochera, TOPE, topeReal, vehiculo);
    mostrarTitulo("Gracias por usar este programa.");
    pausarPrograma();
	return EXIT_SUCCESS;
}

void mostrarMenu(string menu, tyVehiculo vehiculos[], int tope, int &topeReal, tyVehiculo &vehiculo) {
    int opcion = 0;

    while(opcion != SALIDA) {
        system("CLS");
        mostrarTitulo("Ejercicio 7 - Estacionamiento");

        opcion = pedirEntero(menu);

        switch(opcion) {
            case 1:
                ingresoDeVehiculo(vehiculos, tope, topeReal, vehiculo);
                break;
            case 2:
                salidaDeVehiculo(vehiculos, topeReal);
                break;
            case 3:
                listadoDeVehiculos(vehiculos, topeReal);
                break;
            case 4:
                verificarSalida(vehiculos, topeReal, opcion);
                break;
        }
    }
}

void ingresoDeVehiculo(tyVehiculo vehiculos[], int tope, int &topeReal, tyVehiculo &vehiculo) {
    mostrarTitulo("Ingreso de Vehiculo");

    if (topeReal == tope) {
        cout << "No lugares para estacionar" << endl;
    } else {
        vehiculo.patente = retornarString("Ingrese la patente: ");
        if (buscarPatente(vehiculos, topeReal, vehiculo.patente) == EXIT_ERROR) {
            pedirHoraEnRango(vehiculo.hora, 7, 21);
            agregarVehiculo(vehiculos, vehiculo, topeReal);
        }
        else
            cout << endl << "El vehiculo se encuentra estacionado" << endl;
    }  
    pausarPrograma();
}

void agregarVehiculo(tyVehiculo vehiculos[], tyVehiculo vehiculo, int &pos) {
    vehiculos[pos] = vehiculo;
    pos++;
    cout << endl << "Vehiculo guardado" << endl;
}

int buscarPatente(tyVehiculo vehiculos[], int tope, string patente) {
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

void pedirHoraEnRango(int &valor, int desde, int hasta) {
    do {
        cout << "Ingrese la hora (7 a 21): ";
        cin >> valor;
    } while (valor < desde or valor > hasta);
}

void salidaDeVehiculo(tyVehiculo vehiculos[], int &topeReal) {
    mostrarTitulo("Salida de Vehiculo");

    if (topeReal == 0) {
        cout << "No hay vehiculos estacionados" << endl;
    }
    else {
        string patente = retornarString("Ingrese la patente: ");
        int pos = buscarPatente(vehiculos, topeReal, patente);

        if (pos != EXIT_ERROR) {
            cout << "El vehiculo entro a las: " << vehiculos[pos].hora << endl;
            quitarVehiculo(vehiculos, topeReal, pos);
        } else {
            cout << endl << "El vehiculo no se encuentra estacionado." << endl;
        }
    }
    pausarPrograma();
}

void quitarVehiculo(tyVehiculo vehiculos[], int &topeReal, int pos) {
    int i;
    for (i = pos; i < topeReal; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    topeReal--;
}

void listadoDeVehiculos(tyVehiculo vehiculos[], int tope) {
    mostrarTitulo("Listado de Vehiculos");
    
    int i;
    for(i = 0; i < tope; i++) {
        mostrarVehiculo(vehiculos[i]);
    } 
    if (tope == 0)
        cout << "No hay Vehiculos estacionados." << endl;
    pausarPrograma();
}

void mostrarVehiculo(tyVehiculo vehiculo) {
    cout << "Patente: " << vehiculo.patente << " - Hora de ingreso: " << vehiculo.hora << endl; 
}   

void verificarSalida(tyVehiculo vehiculos[], int topeReal, int &opcion) {
    if (topeReal != 0) {
        cout << endl << "No se puede cerrar, aun quedan vehiculos" << endl;
        listadoDeVehiculos(vehiculos, topeReal);
    } else {
        opcion = 5;
    }
}

void pausarPrograma() {
    cout << endl;
    system("PAUSE");
}
