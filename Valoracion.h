#include <string>
#include <iostream>
using namespace std;

class Valoracion {
    private:
        string autor_valoracion;
        string book;
        string comentario;
        int calificacion;
    
    public:
        
        Valoracion();
        Valoracion(string autor, string title, string comment, int cali);

        void mostrar_valoracion();

        void set_autor_valoracion(string autor);
        string agregar_comentario(string comment);
        string borrar_comentarios();
        void set_calificacion(int cali);
};

Valoracion::Valoracion(){
    autor_valoracion = "Desconocido";
    comentario = "No hay comentarios";
    calificacion = 0;
}

Valoracion::Valoracion(string autor, string title, string comment, int cali){
    autor_valoracion = autor;
    book = title;
    comentario = comment;
    calificacion = cali;
}

void Valoracion::mostrar_valoracion(){
    cout << autor_valoracion << " - ";
    cout << book << endl;
    if (comentario.length() == 0){
        cout << "No hay comentarios" << endl;
    } else {
        cout << "Comentarios: " << comentario << endl;
    }
    cout << "Puntuacion: " << calificacion << endl;
}

void Valoracion::set_autor_valoracion(string autor){
    autor_valoracion = autor;
}

string Valoracion::agregar_comentario(string comment){
    comentario = comentario + "\n" + comment;
    return comentario;
}

string Valoracion::borrar_comentarios(){
    comentario = "";
    return "No hay comentarios";
}

void Valoracion::set_calificacion(int cali){
    calificacion = cali;
}
