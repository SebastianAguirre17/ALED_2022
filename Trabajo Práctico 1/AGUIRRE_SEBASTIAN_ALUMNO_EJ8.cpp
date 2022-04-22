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

void inicializarLlamada(tyLlamada &llamada);
void cargarLlamadas(tyContador cont, string prod, int masLarga);
void mostrarResultados(tyLlamada &llamada);
void ingresarLlamada(tyLlamada &llamada, string comercio);
void incrementarContador(tyContador cont, char tipo);

int main(){
    mostrarTitulo("Ejercicio 8");
    
    int llamadaMasLarga = 0;
    string producto;
    tyContador contador;

    cargarLlamadas(contador, producto, llamadaMasLarga);
    
    
	return EXIT_SUCCESS;
}

void cargarLlamadas(tyContador cont, string prod, int masLarga) {
    tyLlamada llamada;
    string auxComercio;

    pedirString("Ingrese el Comercio (* para salir): ", auxComercio);
    while (auxComercio != "*") {
        ingresarLlamada(llamada, auxComercio);
        incrementarContador(cont, llamada.tipo);
        auxComercio = retornarString("\nIngrese el Comercio (* para salir): ");
    }

}

void inicializarContador(tyContador &cont) {
    cont.consultas = 0;
    cont.reclamos = 0;
}

void inicializarLlamada(tyLlamada &llamada) {
    llamada.duracion = 0;
    llamada.comercio = "";
    llamada.codigo = "";
}

void ingresarLlamada(tyLlamada &llamada, string comercio) {
    char validos[TOPE_TIPO_LLAMADO] = "cCrR";

    inicializarLlamada(llamada);
    llamada.comercio = comercio;
    llamada.codigo = retornarString("Ingrese el Codigo de Producto: ");
    pedirCaracterValido(llamada.tipo, validos, TOPE_TIPO_LLAMADO, "Ingrese el Tipo de Llamada (C - R): ");
    llamada.duracion = pedirEntero("Ingrese la Duracion: ");
}

void incrementarContador(tyContador cont, char tipo) {
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