#include <string>
#include <iostream>
using namespace std;


class Libro {
    private:
        string titulo;
        string genero;
        string autor;
        int num_pags;

    public:
        Libro();
        Libro(string title, string gender, string aut, int pags);

        void mostrar_info_libro();

        void setTitulo(string title);
        void setGenero(string gender);
        void setAutor(string author);

};

Libro::Libro(){
    titulo = "Desconocido";
    genero = "Desconocido";
    autor = "Desconocido";
    num_pags = 0;
}

Libro::Libro(string title, string gender, string aut, int pags){
    titulo = title;
    genero = gender;
    autor = aut;
    num_pags = pags;
}

void Libro::mostrar_info_libro(){
    cout << titulo << " - ";
    cout << genero << " - ";
    cout << autor << " - ";
    cout << num_pags << endl;
}

void Libro::setTitulo(string title){
    titulo = title;
}

void Libro::setGenero(string gender){
    genero = gender;
}

void Libro::setAutor(string author){
    autor = author;
}

