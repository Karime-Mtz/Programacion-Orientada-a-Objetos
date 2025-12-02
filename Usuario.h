#include <string>
#include <iostream>
#include <list>
#include "Libro.h"
using namespace std;

class Usuario {
    private:
        string nombre;
        int edad;
        Libro libros_prestados[10];
        int cantidad_prestados;

    public:
        Usuario(string name, int age, int prestados);

        string infoUsuario();

        string getNombre();
        int getEdad();
        int getCantidad_prestados();
        string mostrarLibros_prestados();

        void setNombre(string name);
        void setEdad(int age);
        void agregar_libro_prestado(Libro &b);
        bool devolver_libro(string titulo);
        void setCantidad_prestados(int n);
};


Usuario::Usuario(string name, int age, int prestados){
    nombre = name;
    edad = age;
    cantidad_prestados = prestados;
}

string Usuario::infoUsuario(){
    stringstream datos_usuario;

    datos_usuario << "\nNombre: " << nombre << "\n";
    datos_usuario << "Edad: " << edad << "\n";
    datos_usuario << "Libros prestados: " << "\n";
    for(int i = 0; i < cantidad_prestados; ++i) {
        datos_usuario << libros_prestados[i].getTitulo() << "\n";
    }
    return datos_usuario.str();
}

string Usuario::getNombre(){
    return nombre;
}

int Usuario::getEdad(){
    return edad;
}

int Usuario::getCantidad_prestados(){
    return cantidad_prestados;
}

string Usuario::mostrarLibros_prestados(){
    stringstream libros;
    libros << "\nLibros prestados:" << "\n";
    for(int i = 0; i < cantidad_prestados; ++i) {
        libros << libros_prestados[i].getTitulo() << "\n";
    }
    return libros.str();
}

void Usuario::setNombre(string name){
    nombre = name;
}

void Usuario::setEdad(int age){
    edad = age;
}

void Usuario::agregar_libro_prestado(Libro &b){
    if(cantidad_prestados < 10){
        libros_prestados[cantidad_prestados] = b;
        cantidad_prestados++;
        b.set_disponible(false);
    }
}

bool Usuario::devolver_libro(string titulo){
    for(int i = 0; i < cantidad_prestados; i++){

        if(libros_prestados[i].getTitulo() == titulo){
            libros_prestados[i].set_disponible(true);
            for(int j = i; j < cantidad_prestados - 1; j++){
                libros_prestados[j] = libros_prestados[j + 1];
            }

            cantidad_prestados -= 1;
            return true;
        }
    }
    return false; // no se encontró el libro
}

void Usuario::setCantidad_prestados(int n){
    cantidad_prestados = n;
}
