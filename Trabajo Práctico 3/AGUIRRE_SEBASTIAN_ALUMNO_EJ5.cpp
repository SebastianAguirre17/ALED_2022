#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "../AGUIRRE_SEBASTIAN_BIBLIOTECA.h" 

#define TOPE 100

struct tyAlumno {
    int legajo;
    string nombre;
};

int main(){
    mostrarTitulo("Ejercicio 5");

    tyAlumno alumnos[] = {1,"Ross",2,"Luci",3,"Crissie",4,"Sherri",5,"Waiter",6,"Dasi",7,"Grenville",8,"Harley",9,"Lucina",10,"Neila",11,"Rhodie",12,"Leesa",13,"Karrah",14,"Marlee",15,"Cherlyn",16,"Niccolo",17,"Danella",18,"Karilynn",19,"Keene",20,"Carlo",21,"Catlee",22,"Valentin",23,"Kristel",24,"Rahal",25,"Justus",26,"Iosep",27,"Hallie",28,"Gradey",29,"Farlay",30,"Debbie",31,"Archie",32,"Winifred",33,"Rolph",34,"Glori",35,"Berni",36,"Chadd",37,"Marietta",38,"Dominic",39,"Grayce",40,"Catlin",41,"Carce",42,"Jillayne",43,"Ali",44,"Mic",45,"Vannie",46,"Cathee",47,"Goldina",48,"Nikkie",49,"Donelle",50,"Mayer",51,"Cullen",52,"Wheeler",53,"Ernaline",54,"Nathanial",55,"Oran",56,"Marion",57,"Terrence",58,"Cullie",59,"Ulises",60,"Alasdair",61,"Risa",62,"Gayle",63,"Cassaundra",64,"Adore",65,"Eddie",66,"Jeniece",67,"Hedvig",68,"Reba",69,"Yolanthe",70,"Jewell",71,"Marga",72,"Dani",73,"Sammy",74,"Augustina",75,"Trixi",76,"Misty",77,"Aleksandr",78,"Anthea",79,"Rosemonde",80,"Althea",81,"Sibylla",82,"Rafferty",83,"Audrie",84,"Neel",85,"Ewart",86,"Aura",87,"Elvyn",88,"Herrick",89,"Warner",90,"Giacomo",91,"Susannah",92,"Marcelo",93,"Heath",94,"Jarrett",95,"Rowen",96,"Bucky",97,"Marena",98,"Brigit",99,"Sarajane",100,"Janene"};


    cout << alumnos[25].nombre << endl;

	return EXIT_SUCCESS;
}

/*Ejercicio 5: 
Realizar  una  función  que  reciba  como  primer  parámetro  un  arreglo  de  100 
elementos donde cada elemento es una estructura que contiene el número de 
legajo y el nombre de una persona (string) 
Como segundo parámetro recibe un número de legajo.  
La función debe mostrar el nombre correspondiente al legajo recibido o, en su 
defecto, un mensaje indicando que no lo encontró.*/



