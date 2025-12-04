/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 03/12/2025
 */

 /*
 * Clase Comic que hereda de clase Libro. Contiene los métodos
 * genéricos para manejar sus atributos especiales.
 *
 */

#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

// Declaracion de la clase Comic que hereda de clase Libro
class Comic: public Libro{

    private:
        // Declaracion de variables de instancia
        string universo; 

    public:
        // Declaracion de los metodos del objeto
        Comic();
        Comic(string t, string a, bool d, string u);
            
        string get_universo();
        void set_universo(string u);
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Comic
 */
Comic::Comic() : Libro(){
    universo = "Desconocido";
}

/**
 * Constructor que recibe valores para llenar las variables de instancia
 * de este objeto, además de las variables heredadas
 *
 * @param string string t: titulo del libro, string a: autor, bool d: disponibilidad
 * string u: universo del comic
 * @return objeto Comic
 */
Comic::Comic(string t, string a, bool d, string u) : Libro(t,a,d){
    universo = u;
}

/**
 * getter universo
 *
 * @param
 * @return string: universo del comic
*/
string Comic::get_universo(){
    return universo;
}

/**
 * setter universo
 *
 * @param string u: universo al que pertenece el comic
 * @return 
*/
void Comic::set_universo(string u){
    universo = u;
}

