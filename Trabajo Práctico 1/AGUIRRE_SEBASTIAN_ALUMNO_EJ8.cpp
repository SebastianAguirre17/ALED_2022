#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

using namespace std;

#define TOPE_TIPO_LLAMADO 5

struct tyLlamada {
    string comercio;
    string codigo;
    char tipo;
    int duracion;
};

struct tyContador {
    int consultas;
    int reclamos;
};

void inicializarContador(tyContador &cont);
void inicializarLlamada(tyLlamada &llamada);
void cargarLlamadas(tyContador &cont, string &prod, int &masLarga);
void ingresarLlamada(tyLlamada &llamada, string comercio);
void incrementarContador(tyContador &cont, char tipo);
void mostrarResultados(tyContador &cont, int masLarga, string producto);

int main(){
    mostrarTitulo("Ejercicio 8");
    
    int llamadaMasLarga = 0;
    string producto;
    tyContador contador;

    inicializarContador(contador);
    cargarLlamadas(contador, producto, llamadaMasLarga);
    mostrarResultados(contador, llamadaMasLarga, producto);
    
	return EXIT_SUCCESS;
}

void inicializarContador(tyContador &cont) {
    cont.consultas = 0;
    cont.reclamos = 0;
}

void cargarLlamadas(tyContador &cont, string &prod, int &masLarga) {
    tyLlamada llamada;
    string auxComercio;

    pedirString("Ingrese el Comercio (* para salir): ", auxComercio);
    while (auxComercio != "*") {
        ingresarLlamada(llamada, auxComercio);
        incrementarContador(cont, llamada.tipo);
        if (esCaracterValido(llamada.tipo, "cC", 3) and llamada.duracion > masLarga) {
            masLarga = llamada.duracion;
            prod = llamada.codigo;
        }
        auxComercio = retornarString("\nIngrese el Comercio (* para salir): ");
    }
}

void ingresarLlamada(tyLlamada &llamada, string comercio) {
    char validos[TOPE_TIPO_LLAMADO] = "cCrR";

    inicializarLlamada(llamada);
    llamada.comercio = comercio;
    llamada.codigo = retornarString("Ingrese el Codigo de Producto: ");
    pedirCaracterValido(llamada.tipo, validos, TOPE_TIPO_LLAMADO, "Ingrese el Tipo de Llamada (C - R): ");
    llamada.duracion = pedirEnteroPositivo("Ingrese la Duracion: ");
}


void inicializarLlamada(tyLlamada &llamada) {
    llamada.duracion = 0;
    llamada.comercio = "";
    llamada.codigo = "";
}

void incrementarContador(tyContador &cont, char tipo) {
        switch (tipo) {
        case 'C':
        case 'c':
            cont.consultas++;
            break;
        case 'R':
        case 'r':
            cont.reclamos++;
            break;
    }
}

void mostrarResultados(tyContador &cont, int masLarga, string producto) {
    mostrarTitulo("Cantidad de llamadas por consulta y cantidad por reclamos.");
    cont.reclamos == 0 ? 
        cout << "No se cargaron llamadas por reclamos." << endl :
        cout << "Se cargaron " << cont.reclamos << " llamadas por reclamos." << endl;
    cont.consultas == 0?
        cout << "No se cargaron llamadas por consultas." << endl :
        cout << "Se cargaron " << cont.consultas << " llamadas por consultas." << endl;

    mostrarTitulo("Codigo del producto correspondiente a la llamada más larga para consulta");
    cout << "La llamada mas larga fue de " << masLarga << " y corresponde al producto " << producto << endl;
}