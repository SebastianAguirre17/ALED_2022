#include <iostream>
#include <cstdlib>
#include <cstdio>

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

void mostrarMensaje(string mensaje);
string pedirTexto(string mensaje);
char pedirCaracter(string mensaje);
int pedirNumeroEntero(string mensaje);
void mostrarTitulo(string titulo);
void inicializarContadores(tyContFiestas &contFiestas, tyContTipoMenu &contTipoMenu);
void incrementarContadorTipos(tyContFiestas &contador, char tipo);
void ingresarFiesta(tyFiesta &fiesta, string fecha);
void verificarMaximosPorMenu(tyContTipoMenu &contTipoMenu, tyFiesta fiesta);
void realizarInforme(tyContFiestas &contFiestas, tyContTipoMenu &contTipoMenu, int contInvitados);

int main() {
    mostrarTitulo("Ejercicio 9");

    string auxFecha;
    int contInvitados = 0;
    tyFiesta fiesta;
    tyContFiestas contFiestas;
    tyContTipoMenu contTipoMenu;
    
    inicializarContadores(contFiestas, contTipoMenu);

    auxFecha = pedirTexto("Ingresar fecha de la fiesta (* para salir): ");
    while (auxFecha != "*") {
        ingresarFiesta(fiesta, auxFecha);
        incrementarContadorTipos(contFiestas, fiesta.tipo);
        verificarMaximosPorMenu(contTipoMenu, fiesta);
        contInvitados += fiesta.cantidad;
        auxFecha = pedirTexto("\n\nIngresar fecha de la fiesta (* para salir): ");
    }
    
    realizarInforme(contFiestas, contTipoMenu, contInvitados);

	return 0;
}

void mostrarMensaje(string mensaje) {
    cout << mensaje;
}

string pedirTexto(string mensaje){
    string texto;
    mostrarMensaje(mensaje);
    cin >> texto;
    return texto;
}

int pedirNumeroEntero(string mensaje){
    int numero;
    mostrarMensaje(mensaje);
    cin >> numero;
    return numero;
}

char pedirCaracter(string mensaje) {
    char caracter;
    mostrarMensaje(mensaje);
    cin >> caracter;
    return caracter;
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
    fiesta.tipo = pedirCaracter("Ingrese el tipo de fiesta (C - S - O): ");
    fiesta.cantidad = pedirNumeroEntero("Ingrese la cantidad de personas: ");
    fiesta.menu = pedirNumeroEntero("Ingrese el menu (1 - 2): ");
}

void verificarMaximosPorMenu(tyContTipoMenu &contTipoMenu, tyFiesta fiesta) {
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
        mostrarMensaje("\n****************************************************************************\n");
        cout << "Se realizaron " << contFiestas.qC << " fiestas del tipo C" << endl;
        cout << "Se realizaron " << contFiestas.qS << " fiestas del tipo S" << endl;
        cout << "Se realizaron " << contFiestas.qO << " fiestas del tipo O" << endl;
        if (contTipoMenu.maxPersonasUno > 0) {
            cout << "La Fiesta con mayor cantidad de invitados que eligieron el menu 1 fue el " << contTipoMenu.fechaMayorUno << endl;
        } else {
            cout << "No se eligio el menu 1" << endl;
        }
        if (contTipoMenu.maxPersonasDos > 0) {
            cout << "La Fiesta con mayor cantidad de invitados que eligieron el menu 2 fue el " << contTipoMenu.fechaMayorDos << endl;
        } else {
            cout << "No se eligio el menu 2" << endl;
        }
        cout << "El promedio de personas de todas las fiestas es de " << promedio << endl;
        mostrarMensaje("\n****************************************************************************\n");

    } else {
        mostrarMensaje("\nGracias por usar este simple programa.\n\n");
    }
}

void mostrarTitulo(string titulo) {
    mostrarMensaje("****************************\n");
    cout << "\t" << titulo << endl;
    mostrarMensaje("****************************\n\n");
}
