/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 03/12/2025
 */

 /*
 * Clase Usuario lleva un registro de los libros que
 * se piden prestados y se devuelven. También contiene
 * los métodos genéricos para el manejo de los atributos
 * del usuario.
 *
 */

#include <string>
#include <iostream>
#include <list>
#include "Libro.h"
using namespace std;

// Declaracion de clase Usuario
class Usuario {

    private:
        // Declaracion de variables de instancia
        string nombre;
        int edad;
        Libro libros_prestados[10];
        int cantidad_prestados;

    public:
        // Declaracion de los métodos del objeto
        Usuario();
        Usuario(string name, int age, int prestados);

        string info_usuario();

        string get_nombre();
        int get_edad();
        int get_cantidad_prestados();
        string mostrar_libros_prestados();

        void set_nombre(string name);
        void set_edad(int age);
        void agregar_libro_prestado(Libro &b);
        bool devolver_libro(string titulo);
        void set_cantidad_prestados(int n);
};

/**
 * Constructor por default
 *
 * @param
 * @return Objeto Usuario
 */
Usuario::Usuario(){
    nombre = "Desconocido";
    edad = 0;
    cantidad_prestados = 0;
}

/**
 * Constructor recibe valores para llenar las variables de instancia
 *
 * @param string name: nombre del usuario, int age: edad de la persona, 
 * int prestados: cantidad de libros que ha pedido prestados
 * @return objeto Usuario
 */
Usuario::Usuario(string name, int age, int prestados){
    nombre = name;
    edad = age;
    cantidad_prestados = prestados;
}

/**
 * Almacena los valores de las variables de instancia en una cadena de
 * texto, así como el titulo de los libros que han sido prestados.
 *
 * @param
 * @return string con los atributos del usuario y los libros que ha 
 * pedido prestados
*/
string Usuario::info_usuario(){
    stringstream datos_usuario;

    datos_usuario << "\nNombre: " << nombre << "\n";
    datos_usuario << "Edad: " << edad << "\n";
    datos_usuario << "Libros prestados: " << "\n";
    for(int i = 0; i < cantidad_prestados; ++i) {
        datos_usuario << libros_prestados[i].get_titulo() << "\n";
    }
    return datos_usuario.str();
}

/**
 * getter nombre
 *
 * @param
 * @return string: nombre del usuario
*/
string Usuario::get_nombre(){
    return nombre;
}

/**
 * getter edad
 *
 * @param
 * @return int: edad del usuario
*/
int Usuario::get_edad(){
    return edad;
}

/**
 * getter cantidad de libros prestados
 *
 * @param
 * @return int cantidad de elementos de la lista
*/
int Usuario::get_cantidad_prestados(){
    return cantidad_prestados;
}

/**
 * setter nombre
 *
 * @param string: nombre del usuario
 * @return 
*/
void Usuario::set_nombre(string name){
    nombre = name;
}

/**
 * setter edad
 *
 * @param int: edad del usuario
 * @return 
*/
void Usuario::set_edad(int age){
    edad = age;
}

/**
 * Lleva un registro de los libros que son pedidos prestados
 * por el usuario. Agrega un objeto libro a la lista tipo libro
 * y actualiza la disponiblidad del libro.
 *
 * @param Libro: objeto libro por referencia
 * @return 
*/
void Usuario::agregar_libro_prestado(Libro &b){
    if(cantidad_prestados < 10){
        libros_prestados[cantidad_prestados] = b;
        cantidad_prestados++;
        b.set_disponible(false);
    }
}

/**
 * Devuelve un libro previamente prestado. Busca el titulo del libro
 * dentro de la lista de libros prestados, comparando en minúsculas y 
 * lo elimina. Tambien actualiza la disponibilidad del libro.
 *
 * @param string: titulo del libro que se quiere devolver
 * @return true: si el libro fue encontrado y devuelto, 
 * false: no se encontró el libro
*/

bool Usuario::devolver_libro(string titulo){
    // Convertir el titulo ingresado a minúsculas
    for (char &c : titulo) {
        c = tolower(c);
    }

    for(int i = 0; i < cantidad_prestados; i++){

        // Obtener el título del libro y convertirlo a minúsculas
        string titulo_libro = libros_prestados[i].get_titulo();
        for (char &c : titulo_libro) {
            c = tolower(c);
        }

        if (titulo_libro == titulo){
            for(int j = i; j < cantidad_prestados - 1; j++){
                libros_prestados[j] = libros_prestados[j + 1];
            }

            cantidad_prestados -= 1;
            return true;
        }
    }

    return false; // no se encontró el libro
}

/**
 * setter cantidad de libros prestados
 *
 * @param int: cantidad de libros prestados
 * @return 
*/
void Usuario::set_cantidad_prestados(int n){
    cantidad_prestados = n;
}
