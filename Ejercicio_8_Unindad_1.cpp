#include <iostream>

using namespace std;

void IngresoRepeticiones(int &repeticiones);

void IngresoComercio(string &dato);
void IngresoProducto(string &producto);
void IngresoTipoLlamada(char &tipo);
void IngresoDuracion(int &duracion);

bool ValidoTipo(char tipo);
bool ValidoDuracion(int duracion);

void CantidadConsulta(char tipo, int &cantidadC, int &cantidadR);
void LlamadaMasLarga(int duracion,string producto,string &codigoConsulta,int &maximoValor);

void Mostrar(int cantidadC, int cantidadR, int maximoValor, string codigoConsulta);

int main(){
    char tipo = '.';
    string dato = "0";
    string producto = "0";
    string codigoConsulta = "0";
    int maximoValor = 0;
    int duracion = 0;
    int cantidadC = 0;
    int cantidadR = 0;
    int llamadaLargaConsulta = 0;
    int repeticiones = 0;
    int indice;

    IngresoRepeticiones(repeticiones);

    for(indice = 0 ; indice < repeticiones ; indice++){
        IngresoComercio(dato);
        IngresoProducto(producto);
        IngresoTipoLlamada(tipo);
        IngresoDuracion(duracion);
        CantidadConsulta(tipo, cantidadC, cantidadR);

    }

    if(tipo == 'C' || tipo == 'c'){
        LlamadaMasLarga(duracion,producto,codigoConsulta,maximoValor);
    }


    Mostrar(cantidadC,cantidadR,maximoValor,codigoConsulta);


    return 0;
}

void IngresoRepeticiones(int &repeticiones){
    cout << "Ingrese la cantidad de consultas que quiere realizar: ";
    cin >> repeticiones;
    while(!(repeticiones > 0)){
        cout << "Ingrese un valor mayor a 0: ";
        cin >> repeticiones;
    }
}


void IngresoComercio(string &dato){
    cout << "Ingrese el comercio donde adquirio el producto: ";
    cin >> dato;

}

void IngresoProducto(string &producto){
    cout << "Ingrese el producto por el cual esta llamando: ";
    cin >> producto;
}

void IngresoTipoLlamada(char &tipo){
    cout << "Ingrese TIPO de llamada (C o R): ";
    cin >> tipo;
    while(!ValidoTipo(tipo)){
        cout << "Ingrese nuevamente el tipo de llamada (C o R): ";
        cin >> tipo;
    }
}

bool ValidoTipo(char tipo){
    return tipo == 'c' || tipo == 'C' || tipo == 'R' || tipo == 'r';
}



void IngresoDuracion(int &duracion){
    cout << "Ingrese la duracion en minutos de la consulta: ";
    cin>> duracion;
    while(!ValidoDuracion(duracion)){
        cout << "Por favor ingrese nuevamente la duracion de su consulta: ";
        cin>> duracion;
    }
}

bool ValidoDuracion(int duracion){
    return duracion > 0;
}

void CantidadConsulta(char tipo, int &cantidadC, int &cantidadR){
    switch(tipo){
    case 'C':
        cantidadC++;
        break;
    case 'c':
        cantidadC++;
        break;
    case 'r':
        cantidadR++;
        break;
    case 'R':
        cantidadR++;
        break;
    }
}

void LlamadaMasLarga(int duracion,string producto, string &codigoConsulta, int &maximoValor){
    if( duracion > maximoValor){
        maximoValor = duracion;
        codigoConsulta = producto;
    }
}


void Mostrar(int cantidadC, int cantidadR, int maximoValor, string codigoConsulta){
    cout << "CONSULTA: " << cantidadC;
    cout << " ";
    cout << "RECLAMOS: " << cantidadR;
    cout << endl;
    cout << "Codigo: "<< codigoConsulta << " duracion de la llamada: " << maximoValor;
}
