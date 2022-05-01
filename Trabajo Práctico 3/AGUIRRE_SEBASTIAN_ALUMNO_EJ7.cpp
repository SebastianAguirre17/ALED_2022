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

void mostrarMenu(string menu, tyVehiculo vehiculos[], int tope, int &topeReal);
void ingresoDeVehiculo(tyVehiculo vehiculos[], int tope, int &topeReal);
void agregarVehiculo(tyVehiculo vehiculos[], tyVehiculo vehiculo, int &pos);
void mostrarVehiculo(tyVehiculo vehiculo); 
void pedirHoraEnRango(int &valor, int desde, int hasta);
void salidaDeVehiculo();
void listadoDeVehiculos(tyVehiculo vehiculos[], int tope);
int buscarPatente(tyVehiculo vehiculos[], int tope, string patente); 
void pausarPrograma();

int main(){
    tyVehiculo cochera[TOPE];
    int topeReal = 0;
    
    mostrarMenu("1) Ingreso Vehiculo\n2) Salida Vehiculo\n3) Listado\n4) Fin\n\nOpcion: ", cochera, TOPE, topeReal);
    mostrarTitulo("Gracias por usar este programa.");
    pausarPrograma();
	return EXIT_SUCCESS;
}

void mostrarMenu(string menu, tyVehiculo vehiculos[], int tope, int &topeReal) {
    int opcion = 0;

    while(opcion != SALIDA) {
        system("CLS");
        mostrarTitulo("Ejercicio 7 - Estacionamiento");

        opcion = pedirEntero(menu);

        switch(opcion) {
            case 1:
                ingresoDeVehiculo(vehiculos, tope, topeReal);
                break;
            case 2:
                salidaDeVehiculo();
                break;
            case 3:
                listadoDeVehiculos(vehiculos, topeReal);
                break;
            case 4:
                cout << "Salida" << endl;
                pausarPrograma();
                break;
        }
    }
}

void ingresoDeVehiculo(tyVehiculo vehiculos[], int tope, int &topeReal) {
    mostrarTitulo("Ingreso de Vehiculo");

    tyVehiculo auxVehiculo;

    if (topeReal == tope) {
        cout << "No lugares para estacionar" << endl;
    } else {
        auxVehiculo.patente = retornarString("Ingrese la patente: ");
        if (buscarPatente(vehiculos, topeReal, auxVehiculo.patente) == EXIT_ERROR) {
            pedirHoraEnRango(auxVehiculo.hora, 7, 21);
            agregarVehiculo(vehiculos, auxVehiculo, topeReal);
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

void quitarVehiculo() {

}

void pedirHoraEnRango(int &valor, int desde, int hasta) {
    do {
        cout << "Ingrese la hora (7 a 21): ";
        cin >> valor;
    } while (valor < desde or valor > hasta);
}

void salidaDeVehiculo() {
    mostrarTitulo("Salida de Vehiculo");
    
    pausarPrograma();
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

void pausarPrograma() {
    cout << endl;
    system("PAUSE");
}