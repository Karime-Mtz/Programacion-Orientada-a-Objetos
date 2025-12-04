/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 03/12/2025
 */

 /*
 * Clase Libro contiene los métodos genéricos para el manejo de sus
    atributos y crea y registra las reseñas que recibe cada uno de sus
    objetos. Tiene 3 clases hijas que son tipos más específicos
    de libros:
 * Novela, Comic y Biografía
 *
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>
#include <sstream>
#include "Valoracion.h"
using namespace std;

// Declaracion de clase Libro
class Libro {

    private:
        // Declaracion de variables de instancia
        string titulo;
        string autor;
        Valoracion lista_reviews[20];
        int num_reviews;
        bool disponible;
        string comentarios[20];

    public:
        // Declaracion de los métodos del objeto
        Libro();
        Libro(string title, string aut, bool disponible);

        string mostrar_info_libro();

        string get_titulo();
        string get_autor();
        bool get_disponible();
        Valoracion get_review(int i);
        int get_num_reviews();

        void set_titulo(string title);  
        void set_autor(string aut);
        void set_disponible(bool disponible);

        float obtener_promedio();
        void agregar_review(string comment, int cali);
        string mostrar_comentarios();       
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Libro
 */
Libro::Libro(){
    titulo = "Desconocido";
    autor = "Desconocido";
    disponible = true;
    num_reviews = 0;
}

/**
 * Constructor que recibe valores para llenar las variables de instancia
 *
 * @param string title: titulo del libro, string aut: nombre del autor, 
 * bool d: muestra si el libro se puede pedir prestado o no
 * @return objeto Libro
 */
Libro::Libro(string title, string aut, bool d){
    titulo = title;
    autor = aut;
    disponible = d;
    num_reviews = 0;
}

/**
 * Almacena los valores de las variables de instancia en una cadena de
 * texto.
 *
 * @param
 * @return string con los atributos del libro
*/
string Libro::mostrar_info_libro() {
    stringstream datos_libro;

    datos_libro << "\nTitulo: " << titulo << "\n";
    datos_libro << "Autor: " << autor << "\n";
    datos_libro << "Disponible: " << disponible << "\n";

    return datos_libro.str();
}

/**
 * getter titulo
 *
 * @param
 * @return string: titulo del libro
*/
string Libro::get_titulo(){
    return titulo;
}

/**
 * getter autor
 *
 * @param
 * @return string: nombre del autor
*/
string Libro::get_autor(){
    return autor;
}

/**
 * getter disponible
 *
 * @param
 * @return bool: disponibilidad del libro
*/
bool Libro::get_disponible(){
    return disponible;
}

/**
 * setter titulo
 *
 * @param string: titulo del libro
 * @return 
*/
void Libro::set_titulo(string title){
    titulo = title;
}

/**
 * setter autor
 *
 * @param string: nombre del autor
 * @return 
*/
void Libro::set_autor(string aut){
    autor = aut;
}

/**
 * setter disponible
 *
 * @param bool: disponibilidad del libro
 * @return 
*/
void Libro::set_disponible(bool d){
    disponible = d;
}

/**
 * Obtiene el promedio de las calificaciones que 
 * se le da a cada objeto
 *
 * @param
 * @return float con el calculo
*/
float Libro::obtener_promedio(){
    if (num_reviews == 0){
        return 0;
    }

    float suma = 0.0;
    for (int i = 0; i < num_reviews; i++){
        suma = suma + lista_reviews[i].get_calificacion();
    }
    suma = suma / num_reviews;
    return suma;
}

/**
 * Guarda un registro de las resenias que se le dan a cada libro.
 * Crea un objeto Valoracion y lo agrega a una lista tipo Valoracion.
 *
 * @param string comment: comentario del libro, int cali: calificacion que 
 * se le da al libro
 * @return string con los atributos del libro
*/
void Libro::agregar_review(string comment, int cali){
    if (num_reviews < 20) {
        lista_reviews[num_reviews] = Valoracion(comment, cali);
        comentarios[num_reviews] = comment;
        num_reviews += 1;
    }
}

/**
 * Convierte los comentarios registrados en una cadena de
 * texto.
 * 
 * @param
 * @return string con los comentarios escritos sobre un libro
*/
string Libro::mostrar_comentarios(){
    stringstream comentario;
    if (num_reviews == 0) {
        return "No hay ningun comentario\n";
    }

    for (int i = 0; i < num_reviews; i++){
        comentario << comentarios[i] << "\n";
    }
    return comentario.str();
}

#endif
