#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>
#include "Valoracion.h"
using namespace std;


class Libro {
    private:
        string titulo;
        string autor;
        int num_pags;
        Valoracion lista_reviews[20];
        Valoracion review;
        int num_reviews;

    public:
        Libro();
        Libro(string title, string aut, int pags);

        void mostrar_info_libro();

        float getPromedio_calificacion();
        string getTitulo();
        string getAutor();
        int getNum_pags();

        void setTitulo(string title);
        void setAutor(string author);
        void setNum_pags(int pags);

        void agregar_review(string comment, int cali);
        

};

Libro::Libro(){
    titulo = "Desconocido";
    autor = "Desconocido";
    num_pags = 0;
    num_reviews = 0;
}

Libro::Libro(string title, string aut, int pags){
    titulo = title;
    autor = aut;
    num_pags = pags;
    num_reviews = 0;
}


void Libro::mostrar_info_libro(){
    cout << "Título: " << titulo << endl;
    cout << "Autor: " <<autor << endl;
    cout << "Número de páginas: " << num_pags << endl;
}

string Libro::getTitulo(){
    return titulo;
}

string Libro::getAutor(){
    return autor;
}

int Libro::getNum_pags(){
    return num_pags;
}

void Libro::setTitulo(string title){
    titulo = title;
}


void Libro::setAutor(string author){
    autor = author;
}

void Libro::setNum_pags(int pags){
    num_pags = pags;
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
        review = Valoracion(comment, cali);
        lista_reviews[num_reviews] = review;
        num_reviews += 1;
    }
}

#endif
