#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "AGUIRRE_SEBASTIAN.h" 

#define TOPE_SECTORES   8
#define TOPE_PROYECTOS  9
#define TOPE_NOMBRE     31
#define TOPE_TIPOS      4
#define TOPE_ONG        26
#define MIN_LEN         1
#define MAX_LEN         30  
#define MIN_PROYECTO    1  
#define MAX_PROYECTO    9 
#define PORCENTAJE      0.15
#define MAXIMO          99999999
#define FIN             "*"

struct tySector {
	string nombre;
	int empleados;
};

struct tyAporte {
    string sector;
    int proyecto;
    float importe;
};

struct tyProyecto {
    char nombre[TOPE_NOMBRE];
    int tipo;
    char ong[TOPE_ONG];
};

void cargarProyectos(char archivo[], tyProyecto proyectos[], int tope);
void mostrarProyectos(tyProyecto proyectos[], int tope);

void ingresarAporte(tySector sectores[], int topeSector, tyAporte &aporte, int &posSector);
void ingresarSector(tySector sectores[], int topeSector, int &posSector, tyAporte &aporte);
int buscarSector(tySector sectores[], int tope, string nombre); 
float calcularImporteAdicionalEmpresa(float importe, float porcentaje);
void mostrarAdicionalEmpresa(float porcentaje);
void acumularImportePorProyecto(float acumImportePorProyecto[], int posProyecto, float importe);
void mostrarImportePorProyecto (tyProyecto proyectos[], int topeProyecto, float acumImportePorProyecto[]);

void acumularPorTipoYsector(float acumImporteTipoSector[][TOPE_PROYECTOS], int posTipo, int posSector, float importe);
void inicializarTablaTipoSector(float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas);
void mostrarRecaudacionPorTipoYSector(tySector sectores[], float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas);
void mostrarTipoDeMenorRecPorSector(tySector sectores[], float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas);
void mostrarTipoDeMenorRecPorSector(tySector sectores[], float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas);

int main() {
    mostrarTitulo("Aguirre Sebastian - Segudo Parcial");

    tySector sectores[TOPE_SECTORES] = {
        "Contaduria", 14, "Deposito", 9, "Ventas", 11, "Administracion", 12, 
        "Despacho", 7, "Sistemas", 10, "Atencion al Cliente", 12, "Compras", 6 
    };
    tyProyecto proyectos[TOPE_PROYECTOS];
    tyAporte aporte;

    float acumImporteTipoSector[TOPE_TIPOS][TOPE_PROYECTOS];
    float acumImportePorProyecto[TOPE_PROYECTOS];
    char archivoProyectos[] = "proyectos.dat";
    float porcentaje, importeTotal;
    int posSector, posTipo;

    inicializarArrayFlotante(acumImportePorProyecto, TOPE_PROYECTOS);
    inicializarTablaTipoSector(acumImporteTipoSector, TOPE_TIPOS, TOPE_PROYECTOS);
    cargarProyectos(archivoProyectos, proyectos, TOPE_PROYECTOS);

    ingresarAporte(sectores, TOPE_SECTORES, aporte, posSector);
    while (aporte.sector != FIN) {
        porcentaje = calcularImporteAdicionalEmpresa(aporte.importe, PORCENTAJE);
        mostrarAdicionalEmpresa(porcentaje);

        importeTotal = aporte.importe + porcentaje;
        acumularImportePorProyecto(acumImportePorProyecto, aporte.proyecto, importeTotal);

        posTipo = proyectos[aporte.proyecto - 1].tipo;
        acumularPorTipoYsector(acumImporteTipoSector, posTipo, posSector, importeTotal);

        ingresarAporte(sectores, TOPE_SECTORES, aporte, posSector);
    }

    mostrarRecaudacionPorTipoYSector(sectores, acumImporteTipoSector, TOPE_TIPOS, TOPE_PROYECTOS);
    mostrarTipoDeMenorRecPorSector(sectores, acumImporteTipoSector, TOPE_TIPOS, TOPE_PROYECTOS);
    mostrarImportePorProyecto(proyectos, TOPE_PROYECTOS, acumImportePorProyecto);


	return EXIT_SUCCESS;
}

void cargarProyectos(char archivo[], tyProyecto proyectos[], int tope) {
    tyProyecto proyecto;
    int i = 0, size = sizeof(proyecto);
    FILE *fichero = NULL;
    bool result, finDeArchivo;
    char op[] = "rb";

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &proyecto, size, finDeArchivo, result);
        while (result and not finDeArchivo and i < tope) {
            proyectos[i++] = proyecto;
            leerArchivo(fichero, &proyecto, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void mostrarProyectos(tyProyecto proyectos[], int tope) {
    mostrarTitulo("Proyectos");
    int i = 0;
    for (i = 0; i < tope; i++) {
        cout << "Nombre: " << proyectos[i].nombre << endl;
        cout << "Tipo: " << proyectos[i].tipo << endl;
        cout << "ONG: " << proyectos[i].ong << endl;
        cout << "---------------------------" << endl;
    }
}

void ingresarAporte(tySector sectores[], int topeSector, tyAporte &aporte, int &posSector) {
    mostrarTitulo("Ingresar Aporte");
    
    ingresarSector(sectores, topeSector, posSector, aporte);
    if (posSector != EXIT_ERROR and aporte.sector != FIN) {
        ingresarEnteroEnRango(aporte.proyecto, MIN_PROYECTO, MAX_PROYECTO, "Ingrese el proyecto: ");
        ingresarFlotantePositivo(aporte.importe, "Ingrese el importe: ");
    }
}

void ingresarSector(tySector sectores[], int topeSector, int &posSector, tyAporte &aporte) {
    do {
        ingresarStringValido(aporte.sector, MIN_LEN, MAX_LEN, "Ingrese sector ('*' para salir): ");
        posSector = buscarSector(sectores, topeSector, aporte.sector);
    } while (aporte.sector != FIN and posSector == EXIT_ERROR);
}

int buscarSector(tySector sectores[], int tope, string nombre) {
    int i = 0;
    while (i < tope and sectores[i].nombre != nombre) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

float calcularImporteAdicionalEmpresa(float importe, float porcentaje) {
    return importe * porcentaje;
}

void mostrarAdicionalEmpresa(float porcentaje) {
    cout << endl << "Importe Adicional de la Empresa: $" << std::fixed << std::setprecision(2) << porcentaje << endl;
}

void acumularImportePorProyecto(float acumImportePorProyecto[], int posProyecto, float importe) {
    acumImportePorProyecto[posProyecto - 1] += importe;
}

void mostrarImportePorProyecto (tyProyecto proyectos[], int topeProyecto, float acumImportePorProyecto[]) {
    mostrarTitulo("Importes por Proyectos");
    for (int i = 0; i < topeProyecto; i++) {
        if (acumImportePorProyecto[i] > 0) {
            cout << proyectos[i].nombre << ": $" << std::fixed << std::setprecision(2) << acumImportePorProyecto[i] << endl; 
        }
    }
}

void acumularPorTipoYsector(float acumImporteTipoSector[][TOPE_PROYECTOS], int posTipo, int posSector, float importe) {
    acumImporteTipoSector[posTipo][posSector] += importe;
}

void inicializarTablaTipoSector(float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            acumImporteTipoSector[i][j] = 0;
        }
    }
}

void mostrarRecaudacionPorTipoYSector(tySector sectores[], float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas) {
    mostrarTitulo("Recaudacion Por Tipo de Proyecto y Sector");

    for (int i = 0; i < filas; i++) {
        cout << "Tipo " << i << endl << endl;
        for (int j = 0; j < columnas; j++) {
            if (acumImporteTipoSector[i][j] > 0) {
                cout << "Sector: " << sectores[j].nombre << " - Recaudacion: $ " << acumImporteTipoSector[i][j] << endl;
            }
        }
        cout << "---------------------------------------------------" << endl;
    }
}

void mostrarTipoDeMenorRecPorSector(tySector sectores[], float acumImporteTipoSector[][TOPE_PROYECTOS], int filas, int columnas) {
    mostrarTitulo("Tipo de Proyecto que recaudo menos por Sector");

    float menor = MAXIMO;
    int pos;
    for (int i = 0; i < columnas; i++) {
        cout << "Sector: " << sectores[i].nombre << endl << endl;
        for (int j = 0; j < filas; j++) {
            if (acumImporteTipoSector[j][i] > 0 and acumImporteTipoSector[j][i] < menor) {
                menor = acumImporteTipoSector[j][i];
                pos = j;
            }
        }
        if (menor > 0 and menor != MAXIMO) {
            cout << "Tipo de Proyecto: " << pos << endl;
        }
        menor = MAXIMO;
        cout << "---------------------------------------------------" << endl;
    }
}
