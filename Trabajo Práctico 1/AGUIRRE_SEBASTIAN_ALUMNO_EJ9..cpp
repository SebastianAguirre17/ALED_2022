#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

using namespace std;

struct tyFiesta {
    string fecha;
    char tipo;
    int cantidad;
    int menu;
};

struct tyContFiestas {
    int qC;
    int qS;
    int qO;
};

struct tyContTipoMenu {
    string fechaMayorUno;
    string fechaMayorDos;
    int maxPersonasUno;
    int maxPersonasDos;
};

void inicializarContadores(tyContFiestas &contFiestas, tyContTipoMenu &contTipoMenu);
void incrementarContadorTipos(tyContFiestas &contador, char tipo);
void ingresarFiesta(tyFiesta &fiesta, string fecha);
void verificarMaximosPorMenu(tyContTipoMenu &contTipoMenu, tyFiesta &fiesta);
void realizarInforme(tyContFiestas &contFiestas, tyContTipoMenu &contTipoMenu, int contInvitados);

int main() {
    mostrarTitulo("Ejercicio 9");

    string auxFecha;
    int contInvitados = 0;
    tyFiesta fiesta;
    tyContFiestas contFiestas;
    tyContTipoMenu contTipoMenu;
    
    inicializarContadores(contFiestas, contTipoMenu);

    ingresarString(auxFecha, "Ingresar fecha de la fiesta (* para salir): ");
    while (auxFecha != "*") {
        ingresarFiesta(fiesta, auxFecha);
        incrementarContadorTipos(contFiestas, fiesta.tipo);
        verificarMaximosPorMenu(contTipoMenu, fiesta);
        contInvitados += fiesta.cantidad;
        ingresarString(auxFecha, "Ingresar fecha de la fiesta (* para salir): ");
    }
    
    realizarInforme(contFiestas, contTipoMenu, contInvitados);

	return EXIT_SUCCESS;
}

void inicializarContadores(tyContFiestas &contFiestas, tyContTipoMenu &contTipoMenu){
    contFiestas.qC = 0;
    contFiestas.qS = 0;
    contFiestas.qO = 0;
    contTipoMenu.maxPersonasUno = 0;
    contTipoMenu.maxPersonasDos = 0;
}

void incrementarContadorTipos(tyContFiestas &contFiestas, char tipo){
    switch (tipo) {
        case 'C':
        case 'c':
            contFiestas.qC++;
            break;
        case 'S':
        case 's':
            contFiestas.qS++;
            break;
        case 'O':
        case 'o':
            contFiestas.qO++;
            break;
    }
}

void ingresarFiesta(tyFiesta &fiesta, string fecha){
    fiesta.fecha = fecha;
    ingresarCaracter(fiesta.tipo, "Ingrese el tipo de fiesta (C - S - O): ");
    ingresarEntero(fiesta.cantidad, "Ingrese la cantidad de personas: ");
    ingresarEntero(fiesta.menu, "Ingrese el menu (1 - 2): ");
}

void verificarMaximosPorMenu(tyContTipoMenu &contTipoMenu, tyFiesta &fiesta) {
    if (fiesta.menu == 1 and fiesta.cantidad > contTipoMenu.maxPersonasUno) {
        contTipoMenu.maxPersonasUno = fiesta.cantidad;
        contTipoMenu.fechaMayorUno = fiesta.fecha;
        
    } else if (fiesta.cantidad > contTipoMenu.maxPersonasDos) {
        contTipoMenu.maxPersonasDos = fiesta.cantidad;
        contTipoMenu.fechaMayorDos = fiesta.fecha;
    }
}

void realizarInforme(tyContFiestas &contFiestas, tyContTipoMenu &contTipoMenu, int contInvitados) { 
    int cantFiestas = contFiestas.qC + contFiestas.qS + contFiestas.qO;

    if (cantFiestas > 0) {
        float promedio = contInvitados/cantFiestas; 

        mostrarTitulo("Informar cuantas fiestas hay de cada tipo");
        cout << "Se realizaron " << contFiestas.qC << " fiestas del tipo C" << endl;
        cout << "Se realizaron " << contFiestas.qS << " fiestas del tipo S" << endl;
        cout << "Se realizaron " << contFiestas.qO << " fiestas del tipo O" << endl;

        mostrarTitulo("Fecha de la fiesta con mayor cantidad de personas");
        contTipoMenu.maxPersonasUno > 0 ?
            cout << "La Fiesta con mayor cantidad de invitados que eligieron el menu 1 fue el " << contTipoMenu.fechaMayorUno << endl :
            cout << "No se eligio el menu 1" << endl;
        contTipoMenu.maxPersonasDos > 0 ?
            cout << "La Fiesta con mayor cantidad de invitados que eligieron el menu 2 fue el " << contTipoMenu.fechaMayorDos << endl :
            cout << "No se eligio el menu 2" << endl;
        
        mostrarTitulo("El promedio de personas de todas las fiestas");
        cout << "El promedio de personas de todas las fiestas es de " << promedio << endl;

    } else {
        cout << endl << "Gracias por usar este simple programa." << endl << endl;
    }
}


