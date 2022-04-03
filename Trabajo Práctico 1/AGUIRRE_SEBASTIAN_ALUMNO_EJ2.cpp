#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void printNumber(int num);
void printString(string mensaje);
void getNumber(string mensaje, int &numero);

int main(){

	int edad, mayor, menores, edadLaborar, porJubilarse;

    
	return 0;
}

void printNumber(int num) {
    cout << num << endl;
}

void printString(string mensaje) {
    cout << mensaje;
}

void getNumber(string mensaje, int &numero) {
    printString(mensaje);
    cin >> numero;
}