#include <string>
#include <iostream>
#include <list>
using namespace std;

class Usuario {
    private:
        string nombre;
        int edad;
        Libro libros_prestados[10];
        int cantidad_prestados;

    public:
        Usuario(string name, int age, int prestados);

        void infoUsuario();

        string getNombre();
        int getEdad();
        int getCantidad_prestados();
        void mostrarLibros_prestados();

        void setNombre(string name);
        void setEdad(int age);
        void agregar_libro_prestado(Libro b);
        void setCantidad_prestados(int n);
};


Usuario::Usuario(string name, int age, int prestados){
    nombre = name;
    edad = age;
    cantidad_prestados = prestados;
}

void Usuario::infoUsuario(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Libros prestados:" << endl;
    for(int i = 0; i < cantidad_prestados; ++i) {
        cout << libros_prestados[i].getTitulo() << endl;
    }
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

void Usuario::mostrarLibros_prestados(){
    cout << "Libros prestados:" << endl;
    for(int i = 0; i < cantidad_prestados; ++i) {
        cout << libros_prestados[i].getTitulo() << endl;
    }
}

void Usuario::setNombre(string name){
    nombre = name;
}

void Usuario::setEdad(int age){
    edad = age;
}

void Usuario::agregar_libro_prestado(Libro b){

    if(cantidad_prestados<10){
        for(int i = 0; i < cantidad_prestados; i++){
            libros_prestados[cantidad_prestados] = b;
            cantidad_prestados = cantidad_prestados + 1;
        }
    }
}

void Usuario::setCantidad_prestados(int n){
    cantidad_prestados = n;
}
