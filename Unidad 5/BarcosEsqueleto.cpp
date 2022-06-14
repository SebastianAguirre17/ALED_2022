#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define TOPEBARCOS 5
#define TOPECAT 4
#define TOPEPAISES 6
#define TOPEPREC 4

//Registros
struct tyingreso{
	string nombre;
	int permanencia;
};

struct tybarcos{
	string nombar;
	int tonelaje;
	int codpais;
	char habilitado;//S o N
};
struct tycat{
	string tipobarco;
	int tonmin;
	int tonmax;
};

struct typaises{
	string nompais;
	int sobretasa;//numero entero de porcentaje
};

void mayus(string &var){
	int i;
	for(i=0;i<var.length();i++){
		var[i]=toupper(var[i]);
	}
}

int main(){
	tybarcos barco[TOPEBARCOS]={"NO SE NADAR",15500,0,'S',
								"APENAS FLOTO",10000,1,'S',
								"SALVAVIDAS DE PATITO",6000,2,'N',
								"PATAS DE RANA",2100,3,'S',
								"NO SE COMO ME LLAMO",7520,4,'S'};
	tycat cate[TOPECAT]={"PESQUERO",0,3000,
					 	 "CATAMARAN",3001,8000,
						 "ARENERO",8001,15000,
						 "CARGUERO",15001,30000};
	typaises pais[TOPEPAISES]={"URUGUAY",90,
							   "CHINA",70,
						       "CHILE",100,
							   "ESPAÑA",80,
							   "FRANCIA",120,
							   "BRASIL",110};
	int precio[TOPEPREC]={1000,1250,1500,2000};
}
