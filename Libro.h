#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>
#include <sstream>
#include "Valoracion.h"
using namespace std;


class Libro {
    private:
        string titulo;
        string autor;
        Valoracion lista_reviews[20];
        int num_reviews;
        bool disponible;

    public:
        Libro();
        Libro(string title, string aut, bool disponible);

        string mostrar_info_libro();

        float getPromedio_calificacion();
        string getTitulo();
        string getAutor();
        bool get_disponible();

        void setTitulo(string title);
        void setAutor(string autor);
        void set_disponible(bool disponible);

        void agregar_review(string comment, int cali);       
};

Libro::Libro(){
    titulo = "Desconocido";
    autor = "Desconocido";
    disponible = true;
    num_reviews = 0;
}

Libro::Libro(string title, string aut, bool d){
    titulo = title;
    autor = aut;
    disponible = d;
    num_reviews = 0;
}

string Libro::mostrar_info_libro() {
    stringstream datos_libro;

    datos_libro << "\nTítulo: " << titulo << "\n";
    datos_libro << "Autor: " << autor << "\n";
    datos_libro << "Disponible: " << disponible << "\n";

    return datos_libro.str();
}

string Libro::getTitulo(){
    return titulo;
}

string Libro::getAutor(){
    return autor;
}

bool Libro::get_disponible(){
    return disponible;
}

void Libro::setTitulo(string title){
    titulo = title;
}


void Libro::setAutor(string author){
    autor = author;
}

void Libro::set_disponible(bool d){
    disponible = d;
}

float Libro::getPromedio_calificacion(){
    float suma = 0.0;
    for (int i = 0; i < num_reviews; i++){
        suma = suma + lista_reviews[i].getCalificacion();
    }
    suma = suma / num_reviews;
    return suma;
}

void Libro::agregar_review(string comment, int cali){
    if (num_reviews < 20) {
        lista_reviews[num_reviews] = Valoracion(comment, cali);
        num_reviews += 1;
    }
}

#endif
