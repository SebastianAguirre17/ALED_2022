#include <iostream>
#include <cstdlib>
#include <cstring>
#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define TOPE_BARCOS 5
#define TOPE_CAT    4
#define TOPE_PAISES 6
#define TOPE_PREC   4

//Registros
struct tyIngreso{
	string nombre;
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

int main(){
	tyBarco barcos[TOPE_BARCOS]= {
        "NO SE NADAR", 15500, 0, 'S',
		"APENAS FLOTO", 10000, 1, 'S',
		"SALVAVIDAS DE PATITO", 6000,2,'N',
		"PATAS DE RANA", 2100,3,'S',
		"NO SE COMO ME LLAMO", 7520, 4, 'S'
    };
	tyCat cate[TOPE_CAT]= {
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
	int precio[TOPE_PREC] = {
        1000, 1250, 1500, 2000
    };
}
