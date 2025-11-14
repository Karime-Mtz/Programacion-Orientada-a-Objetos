#include <string>
#include <iostream>
using namespace std;

class Usuario {
    private:
        string nombre;
        int edad;
        string genero_fav;
        string libros_prestados[10];
        int cantidad_prestados;

    public:
        Usuario();
        Usuario(string name, int age, string fav, int prestados);

        void infoUsuario();

        void setNombre(string name);
        void setEdad(int age);
        void setGeneroFavorito(string fav);
        void agregar_libro_prestado(string book);
        //void devolver_libro(string book);
};

Usuario::Usuario(){
    nombre = "Desconocido";
    edad = 0;
    genero_fav = "Desconocido";
    cantidad_prestados = 0;
}

Usuario::Usuario(string name, int age, string fav, int prestados){
    nombre = name;
    edad = age;
    genero_fav = fav;
    cantidad_prestados = prestados;
}

void Usuario::infoUsuario(){
    cout << nombre << " - ";
    cout << edad << " - ";
    cout << genero_fav<< endl;
    cout << "Libros prestados:" << endl;
    for(int i = 0; i < cantidad_prestados; ++i) {
        cout << " - " << libros_prestados[i] << endl;
    }
    cout << cantidad_prestados <<endl;
}

void Usuario::setNombre(string name){
    nombre = name;
}

void Usuario::setEdad(int age){
    edad = age;
}

void Usuario::setGeneroFavorito(string fav){
    genero_fav = fav;
}

void Usuario::agregar_libro_prestado(string book){
    cantidad_prestados = cantidad_prestados + 1;
    libros_prestados[10].append(book);
    cout << "Cantidad de libros prestados" << cantidad_prestados<< endl;
    cout << libros_prestados << endl;
}
