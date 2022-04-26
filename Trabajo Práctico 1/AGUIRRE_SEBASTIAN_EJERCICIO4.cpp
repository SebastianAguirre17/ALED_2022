#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 
using namespace std;

struct tyEstudiante {
    string apellido;
    string nombre;
    int anioIngreso;
    int anioCursada;
    int cantMaterias;
    float promedio;
};

struct tyRecibido {
    string apellido;
    string nombre;
    int anioEgreso;
    int cantMaterias;
    float promedio;
};

struct tyPromedio {
    tyRecibido recibido;
    tyEstudiante estudiante;
};

void ingresarEstudiante(tyEstudiante &estudiante);
void ingresarRecibido(tyRecibido &recibido);
void pedirtexto(string msg, string &dest); 
void pedirAnioCursada(int anio);
void pedirAnio(string msg, int anio);

int main(){
    mostrarTitulo("Ejercicio 4");

    char opc;
    tyEstudiante alumno;
    tyRecibido graduado;
    tyPromedio promedio;

    do {
        pedirCaracterValido(opc, "eERr", 5, "'E' - Ingresar Estudiante - 'R' - Ingresar Recibido: ");
        (opc == 'e' or opc == 'E') ? ingresarEstudiante(alumno) : ingresarRecibido(graduado);

        pedirCaracterValido(opc, "sSnN", 5, "\n\nDesea continuar? (S / N)");
    } while (opc == 'S' or opc == 's');


	return EXIT_SUCCESS;
}

void ingresarEstudiante(tyEstudiante &estudiante) {
    mostrarTitulo("Ingreso Estidiante");
    pedirtexto("Ingrese el nombre: ", estudiante.nombre);
    pedirtexto("Ingrese el apellido: ", estudiante.nombre);
    pedirAnio("Ingrese el anio de Ingreso: ", estudiante.anioIngreso);
    pedirAnioCursada(estudiante.anioCursada);
}

void ingresarRecibido(tyRecibido &recibido) {
    mostrarTitulo("Ingreso Graduado");
    
}

void pedirtexto(string msg, string &dest) {
    do {
        dest = retornarString(msg);
    } while (dest.length() == 0);
}

void pedirAnioCursada(int anio) {
    do {
        anio = pedirEntero("Ingrese el anio de cursada: ");
    } while (anio > 5 or anio < 1);
}

void pedirAnio(string msg, int anio) {
    do {
        anio = pedirEntero(msg);
    } while (anio < 2011 or anio > 2022);
}