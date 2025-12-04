/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 03/12/2025
 */

 /*
 * Clase Novela que hereda de clase Libro. Contiene los métodos
 * genéricos para manejar sus atributos especiales.
 *
 */

#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

// Declaracion de clase Novela que hereda de clase Libro
class Novela : public Libro{

    private:
        // Declaracion de variables de instancia
        string genero; 
        bool es_saga;

    public:
            // Declaracion de los metodos del objeto
            Novela();
            Novela(string t, string a, bool d, string g, bool e);
            
            string get_genero();
            bool get_es_saga();

            void set_genero(string gender);
            void set_es_saga(bool saga);

};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Novela
 */
Novela::Novela() : Libro(){
    genero = "Desconocido";
    es_saga = false;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 * de este objeto, además de las variables heredadas
 *
 * @param string string t: titulo del libro, string a: autor, 
 * bool d: disponibilidad, string g: genero del libro, 
 * bool e: indica si es parte de una saga o no
 * @return objeto Novela
 */
Novela::Novela(string t, string a, bool d,
               string g, bool e)
    : Libro(t, a, d)
{
    genero = g;
    es_saga = e;
}


/**
 * getter genero
 *
 * @param
 * @return string: genero de la novela 
*/
string Novela::get_genero(){
    return genero;
}

/**
 * getter es saga
 *
 * @param
 * @return bool: true: es parte de una saga, false: no lo es
*/
bool Novela::get_es_saga(){
    return es_saga;
}

/**
 * setter genero
 *
 * @param string gender: genero de la novela
 * @return 
*/
void Novela::set_genero(string gender){
    genero = gender;
}

/**
 * setter es saga
 *
 * @param bool saga: true or false dependiendo si sea parte de una
 * saga o no
 * @return 
*/
void Novela::set_es_saga(bool saga){
    es_saga = saga;
}
