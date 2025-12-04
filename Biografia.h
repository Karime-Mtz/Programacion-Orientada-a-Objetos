/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 03/12/2025
 */

 /*
 * Clase Biografia que hereda de clase Libro. Contiene los métodos
 * genéricos para manejar sus atributos especiales.
 *
 */

#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

// Declaracion de la clase Biografia que hereda de clase Libro
class Biografia: public Libro {

    private:
        // Declaracion de variables de instancia
        string personaje;

    public:
        // Declaracion de los metodos del objeto
        Biografia();
        Biografia(string t, string a, bool d, string e);

        string get_personaje();
        void set_personaje(string persona);


};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Biografia
 */
Biografia::Biografia(): Libro(){
    personaje = "Desconocido";
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 * de este objeto, además de las variables heredadas
 *
 * @param string string t: titulo del libro, string a: autor, 
 * bool d: disponibilidad, string e: personaje principal
 * @return objeto Biografia
 */
Biografia::Biografia(string t, string a, bool d,
                     string e)
    : Libro(t, a, d)
{
    personaje = e;
}


/**
 * getter personaje
 *
 * @param
 * @return string: personaje principal
*/
string Biografia::get_personaje(){
    return personaje;
}

/**
 * setter personaje
 *
 * @param string persona: personaje de la biografia
 * @return 
*/
void Biografia::set_personaje(string persona){
    personaje = persona;
}
