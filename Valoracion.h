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

        void mostrar_valoracion();

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

void Valoracion::mostrar_valoracion(){

    if (comentario.length() == 0){
        cout << "No hay comentarios" << endl;
    } else {
        cout << "Comentarios: " << comentario << endl;
    }
    cout << "Puntuacion: " << calificacion << endl;
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
