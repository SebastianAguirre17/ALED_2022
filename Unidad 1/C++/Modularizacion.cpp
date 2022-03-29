#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void IngresoNumero (int valor){
	cout<<"Ingrese un numero: ";
	cin>>valor;
	//cout<<"Valor en el modulo contiene: "<<valor<<endl;
	//system("PAUSE");
}
void VerExtremos(int &desde, int &hasta, int ext){
	desde+=ext;
	hasta=hasta-ext;
	ext=4;
}

int main(){

	int num1, num2=8, extremos=1;
	
	cout<<"El numero num1 contiene: "<<num1<<endl;
	IngresoNumero(num1);
	cout<<"El numero ingresado es: "<<num1<<endl;
	
	/*IngresoNumero(num2);
	comentario

	VerExtremos(num1,num2,extremos);
	cout<<"Desde: "<<num1<<endl;
	cout<<"Hasta: "<<num2<<endl;
	cout<<"Extremos?: "<<extremos<<endl;
	*/
	
}


