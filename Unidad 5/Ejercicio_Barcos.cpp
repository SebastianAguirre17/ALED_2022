#include <iostream>
#include <cstdlib>
#include <cstring>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_BARCOS 	5
#define TOPE_CAT    	4
#define TOPE_PAISES 	6
#define TOPE_PRECIOS 	4
#define TOPE_NOMBRES	31

struct tyIngreso {
	char nombre[TOPE_NOMBRES];
	int permanencia;
};

struct tyBarco{
	string nombre;
	int tonelaje;
	int pais;
	char habilitado;
};
struct tyCat{
	string tipoBarco;
	int tonMin;
	int tonMax;
};

struct tyPais{
	string nombre;
	int sobretasa;
};

void escribirArchivoIngresos();
void procesarInformeDeBarcos();

int main(){
	tyBarco barcos[TOPE_BARCOS] = {
        "NO SE NADAR", 15500, 0, 'S',
		"APENAS FLOTO", 10000, 1, 'S',
		"SALVAVIDAS DE PATITO", 6000,2,'N',
		"PATAS DE RANA", 2100,3,'S',
		"NO SE COMO ME LLAMO", 7520, 4, 'S'
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
	int precios[TOPE_PRECIOS] = {
        1000, 1250, 1500, 2000
    };

	// escribirArchivoIngresos();
	procesarInformeDeBarcos();

}

void escribirArchivoIngresos() {
	tyIngreso fruta[] = {
		"NO SE NADAR", 0,
		"APENAS FLOTO", 8,
		"SALVAVIDAS DE PATITO", 6,
		"COSME FULANITO", 4,
		"PATAS DE RANA", 3,
		"NO SE COMO ME LLAMO", 8
	};

	bool result;
    char op[] = "wb";
    char path[] = "barcos_ingresados.dat"; 
    FILE *fichero = NULL;
    int i, size = sizeof(fruta[0]);

    abrirArchivo(path, op, fichero, result);
    if (result) {
        for (i = 0; i < 6; i++) {
            escribirArchivo(&fruta[i], size, fichero, result);
        }  
        cerrarArchivo(fichero, result);
        cout << "Archivo '" << path << "' generado." << endl << endl; 
    } 
}

void procesarInformeDeBarcos() {
	tyIngreso fruta;
    FILE *fichero = NULL;
    int size = sizeof(fruta);
    bool result, finDeArchivo;
    char op[] = "rb";
	char archivo[] = "barcos_ingresados.dat"; 

    abrirArchivo(archivo, op, fichero, result);
    if (result) {
        leerArchivo(fichero, &fruta, size, finDeArchivo, result);
        while (result and not finDeArchivo) {
			cout << fruta.nombre << endl;
            leerArchivo(fichero, &fruta, size, finDeArchivo, result);
        }
        cerrarArchivo(fichero, result);
    } 
}