#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define SALIDA          999
#define TOPE_CICLISTAS  10


/*Ejercicio 2:
El próximo mes se realizará una competencia de ciclismo en Buenos Aires, con la
participación de 30 ciclistas de toda la provincia. Previamente cada ciclista debe solicitar
su inscripción con los siguientes datos: DNI, apellido, nombre, localidad, edad.
Se requiere un programa que permita al organizador de la competencia:
a) Registrar cada ciclista con todos los datos indicados anteriormente.
b) Buscar un ciclista ingresando su DNI. En caso de encontrarlo deberán mostrarse
todos sus datos, o sino indicar: “Ciclista no encontrado”
c) Borrar un ciclista ingresando su DNI.
d) Mostrar el total de ciclistas inscriptos.*/

struct tyCiclista {
    string dni;
    string apellido;
    string nombre;
    string localidad;
    int edad;
};

string menu();
void ingresaoDeCiclista(tyCiclista ciclistas[], int topeCiclistas, int &topeActual);
bool hayEspaciosDisponibles(int topeCiclistas, int topeActual);
void agregarCiclista(tyCiclista ciclistas[], int &topeActual);
int buscarCiclistaPorDni(tyCiclista ciclistas[], int topeActual, string dni);
int buscarYMostrarCiclista(tyCiclista ciclistas[], int topeActual);
void mostrarCiclista(tyCiclista ciclista);
void mostrarTotalCiclistas(int cantidad);

int main(){
    string menuDeOPciones = menu();
    tyCiclista ciclistas[TOPE_CICLISTAS] = { "35000428", "Aguirre", "Sebastian", "Lanus", 32, "37200785", "Salega", "Micaela", "Lanus", 29, "11941885", "Chamorro", "Agustina", "Lomas", 64, "11324028", "Aguirre", "Feliciano", "Lomas", 68 };

    int opcion, contCiclistas = 4; 

    do {
        system("CLS");
        ingresarEntero(opcion, menuDeOPciones);
        switch (opcion) {
            case 1:
                ingresaoDeCiclista(ciclistas, TOPE_CICLISTAS, contCiclistas);
                break;
            case 2:
                buscarYMostrarCiclista(ciclistas, contCiclistas);
                break;
            case 3:
                //listadoDeciclistas(cochera, contCiclistas);
                break;
            case 4:
                mostrarTotalCiclistas(contCiclistas);
                break;
        }
    } while (opcion != SALIDA);

    mostrarTitulo("Gracias por usar este programa");
	return EXIT_SUCCESS;
}

string menu() {
    string menu = "";
    menu += "---------------------------------------\n";
    menu += "     Ejercicio 2 - Ciclistas\n";
    menu += "---------------------------------------\n\n";
    menu += "1) Registrar Ciclista\n";
    menu += "2) Buscar Ciclista\n";
    menu += "3) Borrar Cilista\n";
    menu += "4) Total Ciclistas\n\n";
    menu += "Opcion: ";
    return menu;
}

void ingresaoDeCiclista(tyCiclista ciclistas[], int topeCiclistas, int &topeActual) {
    mostrarTitulo("Ingreso de Ciclistas");
    if (hayEspaciosDisponibles(topeCiclistas, topeActual)) {
        agregarCiclista(ciclistas, topeActual);
    } else {
        cout << "No hay cocheras libres.\n\n";
    }
    system("PAUSE");
}

bool hayEspaciosDisponibles(int topeCiclistas, int topeActual) {
    return topeActual < topeCiclistas;
}

void agregarCiclista(tyCiclista ciclistas[], int &topeActual) {
    tyCiclista auxCiclista;
    ingresarStringValido(auxCiclista.dni, 7, 8, "Ingrese el dni: ");
    if (buscarCiclistaPorDni(ciclistas, topeActual, auxCiclista.dni) == EXIT_ERROR) {
        ingresarStringValido(auxCiclista.apellido, 2, 30, "Ingrese el apellido: ");
        ingresarStringValido(auxCiclista.nombre, 2, 30, "Ingrese el nombre: ");
        ingresarStringValido(auxCiclista.localidad, 2, 30, "Ingrese localidad: ");
        ingresarEnteroEnRango(auxCiclista.edad, 18, 65, "Ingrese edad: (18 a 65): ");
        ciclistas[topeActual] = auxCiclista;
        topeActual++;
        cout << "\nCiclista guardado.\n\n";
    } else {
        cout << "\nEl ciclista ya se encuentra en la lista.\n\n";
    }
}

int buscarCiclistaPorDni(tyCiclista ciclistas[], int topeActual, string dni) {
    int i = 0;
    while (i < topeActual and ciclistas[i].dni != dni) {
        i++;
    }
    if (i == topeActual)
        i = EXIT_ERROR;
    return i;
}

int buscarYMostrarCiclista(tyCiclista ciclistas[], int topeActual) {
    tyCiclista auxCiclista;
    ingresarStringValido(auxCiclista.dni, 7, 8, "Ingrese el dni: ");
    int pos = buscarCiclistaPorDni(ciclistas, topeActual, auxCiclista.dni);  
    if (pos != EXIT_ERROR) {
        mostrarCiclista(ciclistas[pos]);
    } else {
        cout << "\nCiclista no encontrado.\n\n";
    }
}

void mostrarTotalCiclistas(int cantidad) {
    mostrarTitulo("Cantidad de Ciclistas");
    cout << "Se registraron " << cantidad << " ciclistas.\n\n";
    system("PAUSE");
}

void mostrarCiclista(tyCiclista ciclista) {
    
}
