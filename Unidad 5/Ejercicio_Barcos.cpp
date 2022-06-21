#include <iostream>
#include <cstdlib>
#include <cstring>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_BARCOS 	5
#define TOPE_CAT    	4
#define TOPE_PAISES 	6
#define TOPE_PRECIOS 	4
#define TOPE_NOMBRES	31
#define TOPE_TIPO	    11

struct tyIngreso {
	char nombre[TOPE_NOMBRES];
	int permanencia;
};

struct tyBarco{
	char nombre[TOPE_NOMBRES];
	int tonelaje;
	int pais;
	char habilitado;
};

struct tyCat{
	char tipoBarco[TOPE_TIPO];
	int tonMin;
	int tonMax;
};

struct tyPais{
	string nombre;
	int sobretasa;
};

void escribirArchivoIngresos();
void procesarInformeDeBarcos(tyBarco barcos[], int topeBarcos, tyCat categorias[], int topeCat, int acumBarcosPorPais[][TOPE_CAT]);

int buscarBarco(tyBarco barcos[], int tope, char buscado[]);
int buscarCategoria(tyCat categorias[], int tope, int tonelaje); 

void inicializarMatrizDeBarcosPorPais(int matriz[][TOPE_CAT], int filas, int columnas);
void acumularBarcosPorPais(int acumBarcosPorPais[][TOPE_CAT], int posPais, int posCat);
void mostrarTipoYCantDeBarcosPorPais(tyPais paises[], int tope, tyCat categorias[], int topeCat, int acumBarcosPorPais[][TOPE_CAT]);

int main(){
	tyBarco barcos[TOPE_BARCOS] = {
        "NO SE NADAR", 15500, 4, 'S',
		"APENAS FLOTO", 10000, 0, 'S',
		"SALVAVIDAS DE PATITO", 6000, 2,'N',
		"PATAS DE RANA", 2100, 2,'S',
		"NO SE COMO ME LLAMO", 10500, 3, 'S'
    };
	tyCat categorias[TOPE_CAT] = {
        "PESQUERO", 0, 3000,
		"CATAMARAN", 3001, 8000,
		"ARENERO", 8001, 15000,
		"CARGUERO", 15001, 30000
    };
	tyPais paises[TOPE_PAISES] = {
        "URUGUAY", 90,
		"CHINA", 70,
		"CHILE", 100,
		"ARGENTINA", 80,
		"FRANCIA", 120,
		"BRASIL", 110
    };
	// int precios[TOPE_PRECIOS] = {
    //     1000, 1250, 1500, 2000
    // };

	int acumBarcosPorPais[TOPE_PAISES][TOPE_CAT];
    inicializarMatrizDeBarcosPorPais(acumBarcosPorPais, TOPE_PAISES, TOPE_CAT);

	// escribirArchivoIngresos();
	procesarInformeDeBarcos(barcos, TOPE_BARCOS, categorias, TOPE_CAT, acumBarcosPorPais);

    mostrarTipoYCantDeBarcosPorPais(paises, TOPE_PAISES, categorias, TOPE_CAT, acumBarcosPorPais);
}

void procesarInformeDeBarcos(tyBarco barcos[], int topeBarcos, tyCat categorias[], int topeCat, int acumBarcosPorPais[][TOPE_CAT]) {
	tyIngreso ingreso;
    FILE *fichero = NULL;
    int size = sizeof(ingreso), posBarco, posCat;
    bool result, finDeArchivo;
    char op[] = "rb";
	char archivo[] = "barcos_ingresados.dat"; 

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &ingreso, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
			posBarco = buscarBarco(barcos, topeBarcos, ingreso.nombre);
			if (posBarco != EXIT_ERROR) { //and and ingreso.permanencia > 0
                posCat = buscarCategoria(categorias, topeCat, barcos[posBarco].tonelaje);
                acumularBarcosPorPais(acumBarcosPorPais, barcos[posBarco].pais, posCat);

                if (ingreso.permanencia > 0) {

                }
			}
            leerArchivo(fichero, &ingreso, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}

void escribirArchivoIngresos() {
	tyIngreso ingresos[] = {
		"PATAS DE RANA", 3,
		"APENAS FLOTO", 8,
		"SALVAVIDAS DE PATITO", 6,
		"NO SE COMO ME LLAMO", 8,
		"NO SE NADAR", 0,
		"COSME FULANITO", 4
	};

	bool result;
    char op[] = "wb";
    char path[] = "barcos_ingresados.dat"; 
    FILE *fichero = NULL;
    int i, size = sizeof(ingresos[0]);

    abrirArchivo(path, op, fichero, result);
    if (result) {
        for (i = 0; i < 6; i++) {
            escribirArchivo(&ingresos[i], size, fichero, result);
        }  
        cerrarArchivo(fichero, result);
        cout << "Archivo '" << path << "' generado." << endl << endl; 
    } 
}

int buscarBarco(tyBarco barcos[], int tope, char buscado[]) {
    int i = 0;
    while (i < tope and strcmp(barcos[i].nombre, buscado) != 0) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

int buscarCategoria(tyCat categorias[], int tope, int tonelaje) {
	int i = 0;
    while (i < tope and (tonelaje < categorias[i].tonMin or tonelaje > categorias[i].tonMax)) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void inicializarMatrizDeBarcosPorPais(int matriz[][TOPE_CAT], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }
}

void acumularBarcosPorPais(int acumBarcosPorPais[][TOPE_CAT], int posPais, int posCat) {
    acumBarcosPorPais[posPais][posCat]++;
}

void mostrarTipoYCantDeBarcosPorPais(tyPais paises[], int tope, tyCat categorias[], int topeCat, int acumBarcosPorPais[][TOPE_CAT]) {
    mostrarTitulo("Por cada pais: Nombre de cada tipo de barco (categoria) y cantidad de barcos.");
    int cant = 0;
    for (int i = 0; i < tope; i++) {
        mostrarTitulo(paises[i].nombre);
        for (int j = 0; j < topeCat; j++) {
            if ( acumBarcosPorPais[i][j] > 0) {
                cout << categorias[j].tipoBarco << endl;
                cant += acumBarcosPorPais[i][j];
            }
        }
        cout << "Cantidad de Barcos: " << cant << endl;
        cant = 0;
    }
}