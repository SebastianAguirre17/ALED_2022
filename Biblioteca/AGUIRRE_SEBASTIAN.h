#ifndef _AGUIRRE_SEBASTIAN_H_
#define  _AGUIRRE_SEBASTIAN_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

#define EXIT_ERROR      -1
#define FIN_LINEA       '\0'
#define REPETICIONES    10
#define CANT_FICHEROS   1

using namespace std;

// PROTOTIPOS
void ingresarEntero(int &valor, string mensaje);
void ingresarEnteroPositivo(int &valor, string mensaje);
void ingresarEnteroEnRango(int &valor, int desde, int hasta, string mensaje);
void swapEntero(int &a, int &b);

void ingresarFlotante(float &valor, string mensaje);
void ingresarFlotantePositivo(float &valor, string mensaje);

void ingresarCaracter(char &dest, string msg);
void ingresarCaracterValido(char &dest, char validos[], int tope, string mensaje);
void repetirCaracter(char c, int cant);
void swapCaracter(char &a, char &b);
bool esCaracterValido(char c, char validos[], int tope);

int contarCaracteresDeCadenaChar(char cadChar[], int tope);
int buscarCaracterEnCadenaChar(char cadChar[], int tope, char c);
int buscarCaracteresEnCadenaChar(char cadChar[], int tope, char c1, char c2);
int buscarCaracterEnRango(char cadChar[], int desde, int hasta, char c);
void ingresarCadenaCharValida(char cadChar[], int tope, string mensaje);
void convertirStringACadenaChar(string source, char dest[]);
void copiarCadenaChar(char dest[], char source[], int tope);
bool existenDosCarNoConsecutivos(char cadChar[], int tope, char car1, char car2); 

void mostrarTitulo(string mensaje);
void invertirFrase(char cadChar[], int tope);
void mostrarString(string mensaje);
bool validarLongitudString(string str, int tope);
void ingresarString(string &dest, string mensaje);
void ingresarStringValido(string &dest, int min, int max, string mensaje);
void pedirStringConTope(string &dest, int tope);

void inicializarArrayNumerico(int numeros[], int tope);
void inicializarArrayFlotante(float numeros[], int tope);
void ordenamientoPorSeleccion(int numeros[], int tope);
void ordenamientoPorSeleccionV2(int numeros[], int tope);
void ordenamientoPorInsercion(int numeros[], int tope);
int busquedaSecuencial(int numeros[], int tope, int buscado);
void buscarPosMaxEnArrayNumerico(int vec[], int tope, int &maxPos);
void buscarPosMinYMaxEnArrayNumerico(int vec[], int desde, int hasta, int &minPos, int &maxPos);
void mostrarArrayNumerico(int numeros[], int tope);
void mostrarArrayNumericoConIndice(int numeros[], int tope);
void cargarVecRandom(int vec[], int tope, int mod);
int contarRepeticionesEnVecNumerico(int vec[], int tope, int buscado);

int sumarDivisores(int num);
int calcularNumeroInverso(int num);
bool esNumeroCapicua(int num);
bool sonNumerosAmigos(int num1, int num2);

// DESARROLLO DE FUNCIONES
void ingresarEntero(int &valor, string mensaje) {
    cout << mensaje;
    cin >> valor;
    cin.ignore(); // Limpiar buffer cin para usar getline
}

void ingresarEnteroPositivo(int &valor, string mensaje) {
    do {
        cout << mensaje;
        cin >> valor;
    } while (valor <= 0);
    cin.ignore(); // Limpiar buffer cin para usar getline
}

void ingresarEnteroEnRango(int &valor, int desde, int hasta, string mensaje) {
    do {
        cout << mensaje;
        cin >> valor;
    } while (valor < desde or valor > hasta);
    cin.ignore(); // Limpiar buffer cin para usar getline
}

bool validarNumeroEnRango(int valor, int min, int max) {
    return (valor >= min and valor <= max);
}

bool validarNumeroEnRangoExcluyente(int valor, int min, int max) {
    return (valor > min and valor < max);
}

void swapEntero(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void ingresarFlotante(float &valor, string mensaje) {
    cout << mensaje;
    cin >> valor;
}

void ingresarFlotantePositivo(float &valor, string mensaje) {
    do {
        cout << mensaje;
        cin >> valor;
    } while (valor <= 0);
}

void mostrarCaracter(char c) {
    cout << c;
}

void ingresarCaracter(char &dest, string msg) {
    cout << msg;
    cin >> dest;
}

void repetirCaracter(char c, int cant) {
    for (int i = 0; i < cant; i++) {
        cout << c;
    }
}

void swapCaracter(char &a, char &b) {
    char aux = a;
    a = b;
    b = aux;
}

int contarCaracteresDeCadenaChar(char cadChar[], int tope) {
    int i = 0;
    while (cadChar[i] != FIN_LINEA and i < tope) {
        i++;
    }
    return i;
}

int buscarCaracterEnCadenaChar(char cadChar[], int tope, char c) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);

    while (i < longitud and i < tope and cadChar[i] != c and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i >= longitud) 
        i = EXIT_ERROR;

    return i;
}

bool esCaracterValido(char c, char validos[], int tope) { 
    return (buscarCaracterEnCadenaChar(validos, tope, c) != EXIT_ERROR);
}

void ingresarCaracterValido(char &dest, char validos[], int tope, string mensaje) {
    bool charValido;
    do {
        ingresarCaracter(dest, mensaje);
        charValido = esCaracterValido(dest, validos, tope);
    } while (not charValido);
}

void invertirFrase(char cadChar[], int tope) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope), j = longitud - 1;

    while (cadChar[i] != FIN_LINEA and i < longitud / 2) {
        swapCaracter(cadChar[i], cadChar[j]);
        i++;
        j--;
    }
}

int buscarCaracteresEnCadenaChar(char cadChar[], int tope, char c1, char c2) {
    int i = 0, longitud = contarCaracteresDeCadenaChar(cadChar, tope);

    while (i < longitud and i < tope and cadChar[i] != c1 and cadChar[i] != c2 and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i >= longitud) 
        i = EXIT_ERROR;

    return i;
}

void mostrarString(string mensaje) {
    cout << mensaje;
}

bool validarLongitudString(string str, int tope) {
    return (str.length() < tope);
}

void ingresarString(string &dest, string mensaje) {
    cout << mensaje;
    getline(cin, dest);
}

void ingresarStringValido(string &dest, int min, int max, string mensaje) {
    do {
        cout << mensaje;
        getline(cin, dest);
    } while (dest.length() < min or dest.length() > max);
}

void mostrarTitulo(string mensaje) {
    int longitud = mensaje.length();
    cout << endl;
    repetirCaracter('-', longitud + REPETICIONES);
    cout << endl << "     " << mensaje << endl;
    repetirCaracter('-', longitud + REPETICIONES);
    cout << endl << endl;
}

void pedirStringConTope(string &dest, int tope) {
    cout << "Ingrese un texto de menos de " << tope << " caracteres: ";
    getline(cin, dest);
}

void convertirStringACadenaChar(string source, char dest[]) {
    int i = 0, longitud = source.length();
    while (i < longitud) {
        dest[i] = source[i];
        i++;
    }
    dest[longitud] = FIN_LINEA;
}

void copiarCadenaChar(char dest[], char source[], int tope) {
    int i = 0;
    while (i < tope and source[i] != FIN_LINEA) {
        dest[i] = source[i];
        i++;
    }
    dest[i] = FIN_LINEA;
}

void ingresarCadenaCharValida(char cadChar[], int tope, string mensaje) {
    string auxString;
    bool cadValida;
    do {
        cout << mensaje;
        getline(cin, auxString);
        cadValida = validarLongitudString(auxString, tope);
    } while (not cadValida);
    convertirStringACadenaChar(auxString, cadChar);
} 

void inicializarArrayNumerico(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        numeros[i] = 0;
    }
}

void inicializarArrayFlotante(float numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        numeros[i] = 0;
    }
}

void ordenamientoPorSeleccion(int numeros[], int tope) {
    int i, j, aux, min;
    for (i = 0; i < tope - 1; i++) {
        min = i;
        for (j = i + 1; j < tope ; j++) {
            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        swapEntero(numeros[i], numeros[min]);
    }
}

void ordenamientoPorInsercion(int numeros[], int tope) {
    int i, pos, aux;
    for (i = 0; i < tope; i++) {
        pos = i;
        aux = numeros[i];
        while (pos > 0 and numeros[pos -1] > aux) {
            numeros[pos] = numeros[pos - 1];
            pos--; 
        }
        numeros[pos] = aux;
    }
}

int busquedaSecuencial(int numeros[], int tope, int buscado) {
    int i = 0;
    while (i < tope and numeros[i] != buscado) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void buscarPosMaxEnArrayNumerico(int vec[], int tope, int &maxPos) {
    int i, vMax;
    maxPos = 0;
    vMax = vec[0];
    for (i = 0; i < tope; i++) {
        if (vec[i] > vMax) {
            maxPos = i;
            vMax = vec[i];
        }
    }
}

void buscarPosMinYMaxEnArrayNumerico(int vec[], int desde, int hasta, int &minPos, int &maxPos) {
    int i, vMin, vMax;
    minPos = maxPos = desde;
    vMax = vMin = vec[desde];
    for (i = desde; i < hasta; i++) {
        if (vec[i] < vMin) {
            minPos = i;
            vMin = vec[i];
        }
        if (vec[i] > vMax) {
            maxPos = i;
            vMax = vec[i];
        }
    }
}

void ordenamientoPorSeleccionV2(int numeros[], int tope) {
    /* INCOMPLETO */
    int i, aux, min, max;
    for (i = 0; i < tope; i++) {
        cout << "Vuelta: " << i << endl;
        buscarPosMinYMaxEnArrayNumerico(numeros, i, tope, min, max);
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
        tope--;
        aux = numeros[tope];
        numeros[tope] = numeros[max];
        numeros[max] = aux;
    }
}

void mostrarArrayNumerico(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        cout << numeros[i] << endl;
    }
}

void mostrarArrayNumericoConIndice(int numeros[], int tope) {
    for (int i = 0; i < tope; i++) {
        cout << "Indice: " << i << " - Valor: " << numeros[i] << endl;
    }
}

void cargarVecRandom(int vec[], int tope, int mod) {
    int i;
    for (i = 0; i < tope; i++) {
        vec[i] = rand() % (mod);
    }
}

int contarRepeticionesEnVecNumerico(int vec[], int tope, int buscado) {
    int i, q = 0;
    for (i = 0; i < tope; i++) {
        if (vec[i] == buscado)
            q++;
    }
    return q;
}

int sumarDivisores(int num) {
    int div = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            div += i;
    }
    return div;
}   

int calcularNumeroInverso(int num) {
    int inv = 0;
    while (num > 0) {
        inv = num % 10 + inv * 10;
        num = num / 10;
    }
    return inv;
}

bool esNumeroCapicua(int num) {
    return (num == calcularNumeroInverso(num));
}

bool sonNumerosAmigos(int num1, int num2) {
    int div1 = sumarDivisores(num1);
    int div2 = sumarDivisores(num2);

    return (num1 == div2 and num2 == div1);
}

bool esNumeroPar(int num) {
    return (num % 2 == 0);
}

int buscarCaracterEnRango(char cadChar[], int desde, int hasta, char c) {
    int i = desde;

    while (i < hasta and cadChar[i] != c and cadChar[i] != FIN_LINEA ) {
        i++;
    }
    if (i == hasta) 
        i = EXIT_ERROR;
    return i;
}

bool existenDosCarNoConsecutivos(char cadChar[], int tope, char car1, char car2) {
    int i, longitud = contarCaracteresDeCadenaChar(cadChar, tope);
    bool ret;
    i = buscarCaracterEnRango(cadChar, 0, longitud, car1);  
    if (i != EXIT_ERROR) {
        i = buscarCaracterEnRango(cadChar, i, longitud, car2);
        ret = i != EXIT_ERROR;   
    }
    return ret;
}

void abrirArchivo(char ruta[], char op[], FILE *&fichero, bool &result) {
	fichero = NULL;
	if ((op[0] == 'w' or op[0] == 'r' or op[0] == 'a') and op[1] == 'b') {
		fichero = fopen(ruta, op);
	} else {
        cout << "ERROR - No se reconoce el modo de acceso." << endl;
    }
    result = (fichero != NULL);
    if (not result) {
        cout << "ERROR - No se pudo abrir archivo: " << ruta << endl;
    }
}

void cerrarArchivo(FILE *fichero, bool &result) {
	result = false;
	if (fichero != NULL) {
		result = fclose(fichero) == 0;	
        if (not result) {
            cout << "ERROR - No se pudo cerrar el archivo";
        }
	}
}

void escribirArchivo(void *reg, int size, FILE *fichero, bool &result) {
	result = false;
	if (fichero != NULL) {
		result = fwrite(reg, size, CANT_FICHEROS, fichero) == 1;
        if (not result) {
            cout << "ERROR - No se pudo escribir el archivo";
        }
	}
}

void leerArchivo(FILE *fichero, void *reg, int size, bool &fin, bool &pude){
	fin = true;
	if (fichero != NULL) {
		if (fread(reg, size, CANT_FICHEROS, fichero) == 0) {
			pude = false;
		} else {
			pude = true;
			fin = feof(fichero);
		}
	}	
}


#endif
