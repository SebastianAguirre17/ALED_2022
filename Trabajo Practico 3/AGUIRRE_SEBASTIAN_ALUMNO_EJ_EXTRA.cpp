#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../Biblioteca/AGUIRRE_SEBASTIAN.h" 

#define CANT_MODELOS    10
#define CANT_PROMOTORES 40
#define CANT_DIAS       31
#define INI_MES         1
#define FIN_MES         31   
#define PORCENTAJE      100  
#define MIN_LEN         2  
#define MAX_LEN         30  
#define FIN             "fin"

struct tyPromotor {
    string nombre;
    float comision;
};

struct tyTelefono {
    string descripcion;
    float precio;
};

void cargarPromotores(tyPromotor promotores[], int tope);
void cargarTelefonos(tyTelefono telefonos[], int tope);
void ingresarVenta(tyPromotor promotores[], int topeProm, tyTelefono telefonos[], int topeTel, int &posProm, int &posTel, int &cantidad, int &dia);
int buscarPromotor(tyPromotor promotores[], int tope, string nombre);
int buscarTelefono(tyTelefono telefonos[], int tope, string descripcion); 
void ingresarPromotor(tyPromotor promotores[], int topeProm, int &posProm);
void ingresarTeleono(tyTelefono telefonos[], int topeTel, int &posTel);
void incrementarAcumuladorFacturasPorDia(int contFactPorDia[], int dia);
void incrementarContTelefonosVendidos(int contTelefonosVendidos[], int posTel, int cantidad);
void incrementarAcumuladorComisiones(float acumComisiones[], int posProm, float comision);
void calcularImporteYComision(tyPromotor promotores[], tyTelefono telefonos[], int posProm, int posTel, int cantidad, float &importeTotal, float &comision);
void mostrarFacturaYComision(tyPromotor promotores[], tyTelefono telefonos[], int posProm, int posTel, int cantidad, float importeTotal, float comision);
void mostrarTelefonoMasVendido(int contTelefonosVendidos[], tyTelefono telefonos[], int topeTel);
void mostrarComisionesPorPromotor(float acumComisiones[], tyPromotor promotores[], int topeProm);
void mostrarCantFacturasPorDia(int contFactPorDia[], int topeDias);

int main(){
    tyPromotor promotores[CANT_PROMOTORES];
    tyTelefono telefonos[CANT_MODELOS];
    int contFactPorDia[CANT_DIAS];
    float acumComisiones[CANT_PROMOTORES];
    int contTelefonosVendidos[CANT_MODELOS];
    int posProm, posTel, cantidad, dia;
    float importeTotal, comision;

    cargarPromotores(promotores, CANT_PROMOTORES);
    cargarTelefonos(telefonos, CANT_MODELOS);
    inicializarArrayNumerico(contFactPorDia, CANT_DIAS);
    inicializarArrayNumerico(contTelefonosVendidos, CANT_MODELOS);
    inicializarArrayFlotante(acumComisiones, CANT_PROMOTORES);

    ingresarVenta(promotores, CANT_PROMOTORES, telefonos, CANT_MODELOS, posProm, posTel, cantidad, dia);
    while (posProm != EXIT_ERROR and promotores[posProm].nombre != FIN) {
        calcularImporteYComision(promotores, telefonos, posProm, posTel, cantidad, importeTotal, comision);
        incrementarAcumuladorFacturasPorDia(contFactPorDia, dia);
        incrementarContTelefonosVendidos(contTelefonosVendidos, posTel, cantidad);
        incrementarAcumuladorComisiones(acumComisiones, posProm, comision);
        mostrarFacturaYComision(promotores, telefonos, posProm, posTel, cantidad, importeTotal, comision);

        system("CLS");
        ingresarVenta(promotores, CANT_PROMOTORES, telefonos, CANT_MODELOS, posProm, posTel, cantidad, dia);
    }

    mostrarComisionesPorPromotor(acumComisiones, promotores, CANT_PROMOTORES);
    mostrarTelefonoMasVendido(contTelefonosVendidos, telefonos, CANT_MODELOS);
    mostrarCantFacturasPorDia(contFactPorDia, CANT_DIAS);

	return EXIT_SUCCESS;
}

void cargarPromotores(tyPromotor promotores[], int tope) {
    string nombres[tope] = { 
        "Juan", "Pablo", "Maria", "Victoria", "Romina", "Jose", "Milena", "Javier", "Sebastian", "Carlos"
        "Mario", "Ruben", "Raul", "Pia", "Sergio", "Juan Manuel", "Agustin", "Marcos", "Horacio", "Francisco"
        "Diego", "Florencia", "Micaela", "Gonzalo", "Cristian", "Adrian", "Lucia", "Manuel", "Alejo", "Alejandro"
        "Marcelo", "Alicia", "Gaston", "Estefania", "Pilar", "Emiliano", "Carlos", "Pedro", "Matias", "Simon"
    };
    float comisiones[tope] = { 
        2.10, 3.50, 3.20, 4.20, 2.80, 5.00, 4.90, 3.60, 4.50, 2.40, 
        4.70, 2.20, 4.80, 2.70, 3.20, 2.60, 3.00, 5.00, 4.50, 3.00, 
        4.80, 3.90, 3.30, 2.40, 3.80, 3.20, 4.90, 2.40, 4.30, 2.60, 
        4.80, 3.10, 4.80, 4.50, 4.90, 5.00, 4.00, 5.00, 4.20, 2.40 
    };

    int i;
    for (i = 0; i < tope; i++) {
        promotores[i].nombre = nombres[i];
        promotores[i].comision = comisiones[i];
    }
}

void cargarTelefonos(tyTelefono telefonos[], int tope) {
    string descripciones[tope] = { "Galaxy A03", "Galaxy A53", "Galaxy S22", "Galaxy A22", "Galaxy S21", "Galaxy Z", "Galaxy M12", "Galaxy A52", "Galaxy S20", "Galaxy A32" };
    float precios[tope] = { 20999.00, 84999.00, 149999.00, 45899.00, 110499.00, 135999.00, 45999.00, 79199.00, 80799.00, 55999.00 };

    int i;
    for (i = 0; i < tope; i++) {
        telefonos[i].descripcion = descripciones[i];
        telefonos[i].precio = precios[i];
    }
}

void ingresarVenta(tyPromotor promotores[], int topeProm, tyTelefono telefonos[], int topeTel, int &posProm, int &posTel, int &cantidad, int &dia) {
    mostrarTitulo("Ingresar Venta");

    ingresarPromotor(promotores, topeProm, posProm);
    if (posProm != EXIT_ERROR and promotores[posProm].nombre != FIN) {
        ingresarTeleono(telefonos, CANT_MODELOS, posTel);
        ingresarEnteroPositivo(cantidad, "Ingrese la cantidad: ");
        ingresarEnteroEnRango(dia, INI_MES, FIN_MES, "Ingrese el dia: ");
    }
}

void ingresarPromotor(tyPromotor promotores[], int topeProm, int &posProm) {
    string nombre;
    do {
        ingresarStringValido(nombre, MIN_LEN, MAX_LEN, "Ingrese nombre ('fin' para salir): ");
        posProm = buscarPromotor(promotores, topeProm, nombre);
    } while (nombre != FIN and posProm == EXIT_ERROR);
}

void ingresarTeleono(tyTelefono telefonos[], int topeTel, int &posTel) {
    string descripcion;
    do {
        ingresarString(descripcion, "Ingrese modelo de telefono: ");
        posTel = buscarTelefono(telefonos, topeTel, descripcion);
    } while (posTel == EXIT_ERROR);
}

int buscarPromotor(tyPromotor promotores[], int tope, string nombre) {
    int i = 0;
    while (i < tope and promotores[i].nombre != nombre) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

int buscarTelefono(tyTelefono telefonos[], int tope, string descripcion) {
    int i = 0;
    while (i < tope and telefonos[i].descripcion != descripcion) {
        i++;
    }
    if (i == tope)
        i = EXIT_ERROR;
    return i;
}

void incrementarAcumuladorFacturasPorDia(int contFactPorDia[], int dia) {
    contFactPorDia[dia - 1]++;
}

void incrementarAcumuladorComisiones(float acumComisiones[], int posProm, float comision) {
    acumComisiones[posProm] += comision;
}

void incrementarContTelefonosVendidos(int contTelefonosVendidos[], int posTel, int cantidad) {
    contTelefonosVendidos[posTel] += cantidad;
}

void calcularImporteYComision(tyPromotor promotores[], tyTelefono telefonos[], int posProm, int posTel, int cantidad, float &importeTotal, float &comision) {
    importeTotal = telefonos[posTel].precio * cantidad;
    comision = promotores[posProm].comision * importeTotal / PORCENTAJE;
}

void mostrarFacturaYComision(tyPromotor promotores[], tyTelefono telefonos[], int posProm, int posTel, int cantidad, float importeTotal, float comision) {
    mostrarTitulo("Factura");

    cout << "Nombre del promotor     : " << promotores[posProm].nombre << endl;
    cout << "Descripcion del telefono: " << telefonos[posTel].descripcion << endl;
    cout << "Cantidad Vendida        : " << cantidad << endl;
    cout << "Precio unitario         : $ " << telefonos[posTel].precio << endl << endl; 

    cout << "Importe total           : $ " <<  importeTotal << endl;
    cout << "Comision promotor       : $ " << comision << endl << endl;

    system("PAUSE");
}

void mostrarTelefonoMasVendido(int contTelefonosVendidos[], tyTelefono telefonos[], int topeTel) {
    int posMax;
    buscarPosMaxEnArrayNumerico(contTelefonosVendidos, topeTel, posMax);

    mostrarTitulo("Telefono mas vedido");
    if (contTelefonosVendidos[posMax] > 0) {
        cout << "Se vendieron " << contTelefonosVendidos[posMax] << " unidades del: " << telefonos[posMax].descripcion << endl;
    } else {
        cout << "No se realizaron ventas" << endl;
    }
}

void mostrarComisionesPorPromotor(float acumComisiones[], tyPromotor promotores[], int topeProm) {
    mostrarTitulo("Comisiones por promotor");

    bool hayResultados = false;
    int i;
    for (i = 0; i < topeProm; i++) {
        if (acumComisiones[i] > 0) {
            cout << promotores[i].nombre << " gano $ " << acumComisiones[i] << " en comisiones" << endl;
            hayResultados = true;
        }
    }
    if (not hayResultados) {
        cout << "No se realizaron ventas";
    }
}

void mostrarCantFacturasPorDia(int contFactPorDia[], int topeDias) {
    mostrarTitulo("Cantidad de facturas por dia");
    bool hayResultados = false;
    int i;
    for (i = 0; i < topeDias; i++) {
        if (contFactPorDia[i] > 0) {
            cout << "El dia " << i + 1 << " se realizaron " << contFactPorDia[i] << " facturas." << endl;
            hayResultados = true;
        }
    }
    if (not hayResultados) {
        cout << "No se realizaron ventas";
    }
    cout << endl;
}