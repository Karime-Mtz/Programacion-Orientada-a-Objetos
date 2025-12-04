/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 03/12/2025
 */

 /*
 * Clase Valoracion contiene los métodos genéricos
 * para el manejo de sus atributos.
 *
 */

#ifndef VALORACION_H
#define VALORACION_H

#include <string>
#include <iostream>
using namespace std;

// Declaracion de clase Valoracion
class Valoracion {

    private:
        // Declaracion de variables de instancia
        string comentario;
        int calificacion;
    
    public:
        // Declaracion de los metodos del objeto
        Valoracion();
        Valoracion(string comment, int cali);

        int get_calificacion();
        void set_calificacion(int n);

        string agregar_comentario(string comment);
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Valoracion
 */
Valoracion::Valoracion(){
    comentario = "";
    calificacion = 0;
}

/**
 * Constructor que recibe valores para llenar las variables de instancia
 *
 * @param string comment: comentarios acerca del libro leido, 
 * int cali: calificacion que se le da un libro
 * @return objeto Valoracion
 */
Valoracion::Valoracion(string comment, int cali){
    comentario = comment;
    calificacion = cali;
}

/**
 * getter calificacion
 *
 * @param
 * @return int: numero que representa la calificacion 
*/
int Valoracion::get_calificacion(){
    return calificacion;
}

/**
 * setter calificacion
 *
 * @param int c: calificacion asignada
 * @return 
*/
void Valoracion::set_calificacion(int c){
    calificacion = c;
}


#endif
