#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#define TOPE 15
#define TOPE2 5

void mostrarVector (int MV_V[], int MV_t){
	int i;
	for (i=0; i<MV_t;i++){
		cout<< "Posicion "<<i<<" : "<<MV_V[i]<<endl;
		
	}
}
int sumaVec (int SV_vec[], int SV_t){
	int sumaV=0, k;
	for (k=0; k<SV_t;k++){
		sumaV+=SV_vec[k];
	}
	return sumaV;
}
void iniVec(int IV_V[], int IV_t){
	int k;
	for (k=0; k<IV_t;k++){
		IV_V[k]=0;
	}
}
int main(){
	int suma, vecnum [TOPE]={23,1,6,34,0,45,8,4,56,7,0,123,-5,1,7};
	int vec2 [TOPE2]={323,2111,60,134,0};
	mostrarVector(vecnum, TOPE);
	mostrarVector(vec2, TOPE2);
	system("PAUSE");
	iniVec(vecnum, TOPE);
	cout<<endl<<"Muestra el vector despues de la inicializacion"<<endl;
	mostrarVector(vecnum, TOPE);
	suma=sumaVec(vec2, TOPE2);
	cout<<"La suma de los elementos del vector es: "<<suma; 

}

