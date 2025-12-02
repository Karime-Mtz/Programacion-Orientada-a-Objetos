#ifndef VALORACION_H
#define VALORACION_H

#include <string>
#include <iostream>
using namespace std;

class Valoracion {
    private:
        string comentario;
        int calificacion;
    
    public:
        Valoracion();
        Valoracion(string comment, int cali);

        string mostrar_valoracion();

        string getComentario();
        int getCalificacion();

        void setCalificacion(int n);

        string agregar_comentario(string &comment);
};

Valoracion::Valoracion(){
    comentario = "";
    calificacion = 0;
}


Valoracion::Valoracion(string comment, int cali){
    comentario = comment;
    calificacion = cali;
}

string Valoracion::mostrar_valoracion(){
    stringstream info_review;

    if (comentario.length() == 0){
        info_review << "No hay comentarios" << "\n";
    } else {
        info_review << "Comentarios: " << comentario << "\n";
    }
    info_review << "Puntuacion: " << calificacion << "\n";
    
    return info_review.str();
}


int Valoracion::getCalificacion(){
    return calificacion;
}

void Valoracion::setCalificacion(int c){
    calificacion = c;
}


//Checar si si se ocupa &
string Valoracion::agregar_comentario(string &comment){
    comentario = comentario + "\n" + comment;
    return comentario;
}


#endif
