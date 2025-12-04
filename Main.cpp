/*
 * Proyecto Biblioteca Digital
 * Karime Martínez López
 * A01709690
 * 04/12/2025
 */

/**
 * Este es un programa que simula una biblioteca digital. Gestiona 
 * libros, usuarios y valoraciones mediante un sistema interactivo, a
 * través del cual se pueden realizar las tareas más comunes.
*/

// Bibliotecas
// Para imprimir
#include <iostream>
// Tipos de objetos que utiliza mi proyecto
#include "Libro.h"
#include "Novela.h"
#include "Biografia.h"
#include "Comic.h"
#include "Usuario.h"
#include "Valoracion.h"

using namespace std;

// Procedimiento menu
char menu(){

    // Imprime las opciones que se pueden realizar en el programa
    cout << "\nElige una de las siguientes opciones "
        "(a/b/c/d/e/f/g):" 
     << endl;
    cout << "a) Agregar libro a la biblioteca" << endl;
    cout << "b) Buscar libro" << endl;
    cout << "c) Pedir libro prestado" << endl;
    cout << "d) Devolver libro" << endl;
    cout << "e) Calificar libro" << endl;
    cout << "f) Ver mi informacion" << endl;
    cout << "g) Mostrar libros de la biblioteca" << endl;
    cout << "h) Ver resenia de un libro" << endl;
    cout << "i) Salir\n" << endl;

    char opcion;
    // Lee la opcion que ha sido seleccionada
    cin >> opcion;
    cin.ignore();    
    return opcion;
}

/**
 * Función que recorre cada caracter del string 
 * y lo convierte a minusculas
 *
 * @param string s: texto que quiere ser pasado a minusculas
 * @return string s: texto en minusculas
 */
string a_minusculas(string s) {
    // c es una referencia del caracter actual de s
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

/**
 * Función que busca un libro dentro de una lista y regresa la posicion
 * donde se encuentra. 
 *
 * @param Libro lista[]: arreglo de libros donde se busca, 
 * int &cantidad: número de libros dentro de la lista,
 * string titulo: título del libro que se quiere buscar
 * @return int: posición del libro en la lista o -1 si no se encontro
 */
int posicion_libro(Libro lista[], int &cantidad, string titulo) {
    for (int i = 0; i < cantidad; i++) {

        // Compara los títulos ignorando mayúsculas
        if (a_minusculas(lista[i].get_titulo()) == a_minusculas(titulo)) {
            return i;
        }
    }
    return -1;
}

/**
 * Función que permite agregar un libro nuevo a la biblioteca.
 * Dependiendo del tipo elegido, crea un objeto Libro, Novela,
 * Comic o Biografía y lo agrega al arreglo principal.
 *
 * @param Libro lista_libros[]: arreglo donde se guardan los libros, 
 * int &cantidad_libros: cantidad actual de libros en la lista
 * @return
 */
void agregar_libro(Libro lista_libros[], int &cantidad_libros){
    int tipo;
    string title, escritor, genero, univers, character;
    bool es_saga;

    // Muestra un menu
    cout << "¿Cual deseas agregar? (1/2/3/4)\n"
    "1.- Libro\n2.- Novela\n3.- Comic\n4.- Biografia\n";

    // Asegura que el usuario siempre elija un numero del 1 al 4
    while (!(cin >> tipo) || tipo < 1 || tipo > 4) {
        cout << "Rspuesta no valida. Elige un numero del 1 al 4\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "¿Cual deseas agregar? (1/2/3/4)\n"
        "1.- Libro\n2.- Novela\n3.- Comic\n4.- Biografia\n";
    }
    cin.ignore();
    
    // Pregunta al usuario las variables heredadas a todos los objetos
    cout << "¿Cual es el titulo?" << endl;
    getline(cin, title);
    cout << "Quien es el autor?" << endl;
    getline(cin, escritor);

    // Creacion del libro según el tipo y sus atributos especiales
    if (tipo == 1){
        // Libro en general
        lista_libros[cantidad_libros++] = Libro(title, escritor, true);
    } 
    else if (tipo == 2){
        cout << "¿Cual es su genero?" << endl;
        getline(cin, genero);
        cout << "¿Es una saga? (1 = si, 0 = no)" << endl;
        cin >> es_saga;

        // Creacion de Novela
        lista_libros[cantidad_libros] =
            Novela(title, escritor, true, genero, es_saga);
        cantidad_libros ++;
    } 
    else if (tipo == 3){
        cout << "¿Cual es su universo?" << endl;
        getline(cin, univers);

        // Creacion de Comic
        lista_libros[cantidad_libros] =
            Comic(title, escritor, true, univers);
        cantidad_libros ++;
    } 
    else if (tipo == 4) {
        cout << "¿De quien es la biografia?" << endl;
        getline(cin, character);

        // Creacion de Biografia
        lista_libros[cantidad_libros] =
            Biografia(title, escritor, true, character);
        cantidad_libros ++;
    }
}

/**
 * Permite buscar un libro por título y muestra su información.
 *
 * @param Libro lista_libros[]: lista de libros, 
 * int& cantidad_libros: cantidad total de libros
 * @return
 */

void buscar_libro(Libro lista_libros[], int &cantidad_libros){
    string title;
    cout << "¿Cual es el titulo?" << endl;
    getline(cin, title);

    // Llama a la funcion posicion libro
    int pos = posicion_libro(lista_libros, cantidad_libros, title);

    if (pos == -1) {
        cout << "No se encontro el libro" << endl;
    } else {
        // Imprime los datos usando el método del objeto libro
        cout << lista_libros[pos].mostrar_info_libro();
    }
}

/**
 * Presta un libro al usuario si está disponible y actualiza el 
 * status del libro.
 *
 * @param Libro lista_libros[]: lista de libros,  int& cantidad_libros, 
 * Usuario& user1: usuario que pide el préstamo
 * @return 
 */
void prestar_libro(Libro lista_libros[], int &cantidad_libros, 
                   Usuario &user1){
    // Asegura que no se exceda el limite de libros prestados
    if (user1.get_cantidad_prestados() < 10){
        string title;
        cout << "¿Cual es el titulo del libro a prestar?" << endl;
        getline(cin, title);

        // Guarda la posicion del libro a prestar
        int pos = posicion_libro(lista_libros, cantidad_libros, title);

        if (pos == -1) {
            cout << "Libro no encontrado" << endl;
        } else if (!lista_libros[pos].get_disponible()) {
            // No se puede prestar si no está disponible
            cout << "El libro no esta disponible" << endl;
        } else {
            // Se presta el libro
            user1.agregar_libro_prestado(lista_libros[pos]);
            cout << "\nEl libro ha sido prestado exitosamente" << endl;
        }
    } else {
        cout << "Has alcanzado el limite de prestamos" << endl;
    }
}

/**
 * Devuelve un libro que ha sido previamente prestado.
 *
 * @param Libro lista_libros[]: lista de libros, int& cantidad_libros
 * Usuario& user1: usuario que devuelve el libro
 * @return
 */
void devolver_libro(Libro lista_libros[], int &cantidad_libros,    
                    Usuario &user1){
    string titulo;
    cout << "¿Que libro te gustaria devolver?" << endl;
    getline(cin, titulo);

    // Guarda la posicion del libro en la lista
    int i = posicion_libro(lista_libros, cantidad_libros, titulo);

    // Llama la funcion del objeto usuario para devolve el libro
    if(user1.devolver_libro(titulo)){
        if (i != -1){
            // Marca el libro como disponible dentro de la lista total
            lista_libros[i].set_disponible(true);
            cout << "El libro ha sido devuelto" << endl;
        }
    } else {
        cout << "No tienes este libro prestado" << endl;
    }
}

/**
 * Califica un libro con estrellas y agrega comentarios opcionales.
 *
 * @param Libro lista_libros[], int& cantidad_libros
 * @return 
 */
void calificar_libro(Libro lista_libros[], int &cantidad_libros){
    string libro;
    int estrellas;
    string answer;
    string comment;

    cout << "¿Que libro deseas calificar?" << endl;
    getline(cin, libro);

    // Busca y guarda la posicion del libro en la lista
    int pos = posicion_libro(lista_libros, cantidad_libros, libro);
    while (pos == -1){
        cout << "Libro no encontrado. Intentalo de nuevo" << endl;
        getline(cin, libro);
        pos = posicion_libro(lista_libros, cantidad_libros, libro);
    }   

    // Pide la calificacion al usuario         
    cout << "¿Que calificacion le das? (1-5)" << endl;
    cin >> estrellas;
    // Valida que no se salga del rango
    while(estrellas < 1 || estrellas > 5){
       cout << "Calificacion no valida. "
        "Vuelvelo a intentar (1-5) "<< endl;
        cin >> estrellas;
    }
    cin.ignore();

    // Pide un comentario opcional
    cout << "¿Deseas agregar algun comentario? (si/no)" << endl;
    cin >> answer;
    cin.ignore();

    // Verifica que la respuesta sea correcta
    while (answer != "si" && answer != "no") {
        cout << "Respuesta no válida. Escribe 'si' o 'no': " << endl;
        getline(cin, answer);
        answer = a_minusculas(answer);
    }

    if (answer == "si"){
        cout << "Escribe tu comentario" << endl;
        getline(cin, comment);
    } else {
        comment = "";
    }
    
    // Agrega el comentario a la lista de resenias
    lista_libros[pos].agregar_review(comment, estrellas);
    cout << "Tu resenia fue agregada exitosamente" << endl; 
}

/**
 * Muestra la información actual del usuario.
 *
 * @param Usuario& user1
 * @return
 */
void datos_usuario(Usuario &user1){
    cout << user1.info_usuario() << endl;
}

/**
 * Muestra todos los libros de la biblioteca y su disponibilidad.
 *
 * @param Libro lista_libros[], int& cantidad_libros
 * @return
 */
void libros_biblioteca(Libro lista_libros[], int &cantidad_libros){
    // Recorre la lista y muestra el titulo de cada libro y su status
    for (int i = 0; i < cantidad_libros; i ++){
        cout << "\n" << lista_libros[i].get_titulo()
        << "  --  Disponible: "
        << lista_libros[i].get_disponible() << endl;
    }
}

/**
 * Muestra las reseñas y el promedio de calificación de un libro.
 *
 * @param Libro lista_libros[], int& cantidad_libros
 * @return
 */
void ver_resenias(Libro lista_libros[], int &cantidad_libros){
    string titulo;
    float promedio;
    cout << "¿De que libro te gustaría leer una resenia?" << endl;
    getline(cin, titulo);

    // Registra la posicion del libro
    int pos = posicion_libro(lista_libros, cantidad_libros, titulo);

    if (pos == -1){
        cout << "El libro no ha sido encontrado" << endl;
        return;
    }

    cout << "Titulo :" << lista_libros[pos].get_titulo() << endl;
    
    // Checa si el libro ya tiene calificaciones o no
    promedio = lista_libros[pos].obtener_promedio();
    if (promedio == 0 && 
        lista_libros[pos].mostrar_comentarios() == 
            "No hay ningun comentario\n"){
        cout << "Estrellas: No hay calificaciones" << endl;
    } else {
            cout << "Estrellas: " << promedio << endl;
    }

    // Muestra los comentarios
    cout << "Comentarios:" << endl;
    cout << lista_libros[pos].mostrar_comentarios() << endl;
}


int main() {

    // Agregar libros iniciales a la biblioteca:
    Libro Principito("El Principito", "Antoine de Saint-Exupery", true);
    Novela Mujercitas("Mujercitas", "Louisa May", true, "Romance", true);
    Biografia Steve_Jobs("Steve Jobs", "Walter Isaacson", 
                        true, "Steve Jobs");
    Comic Batman("Batman: Anio Uno", "Frank Miller", true, "DC");
    Libro Momo("Momo", "Michael Ende", true);
    Novela Frankenstein("Frankenstein", "Mary Shelley", 
                        true, "Horror", false);
    Comic Sandman("The Sandman", "Neil Gaiman", true, "DC");

    // Arreglo donde se guardan todos los libros de la biblioteca
    Libro lista_libros[100];
    // Cantidad inicial de libros en la biblioteca
    int cantidad_libros = 7;

    // Asigna los libros dentro del arreglo
    lista_libros[0] = Principito;
    lista_libros[1] = Mujercitas;
    lista_libros[2] = Steve_Jobs;
    lista_libros[3] = Batman;
    lista_libros[4] = Momo;
    lista_libros[5] = Frankenstein;
    lista_libros[6] = Sandman;

    string nombre_usuario;
    int age;

    // Pregunta los datos al usuario
    cout<< "Bienvenido a tu biblioteca digital:"<<endl;
    cout << "¿Cual es tu nombre?" << endl;
    cin >> nombre_usuario;
    cout << "¿Cual es tu edad?" << endl;
    // Valida que la edad sea un numero
    while (!(cin >> age) || age <= 0) {
        cout << "Respues no valida. Vuelve a intentarlo: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Crea un Usuario con los datos brindados y cero libros prestados
    Usuario user1(nombre_usuario, age, 0);

    // Permite realizar varias acciones hasta que se salga del programa
    while (true) {
        // Muestra el menu principial y recibe la opcion elegida
        char choice = menu();

        // Ejecuta las funciones de acuerdo a la opcion elegida
        switch (choice) {
            case 'a': {
                // Agrega un nuevo libro a la biblioteca
                agregar_libro(lista_libros, cantidad_libros);
                break;
            }

            case 'b': {
                // Busca un libro por titulo
                buscar_libro(lista_libros, cantidad_libros);
                break;
            }

            case 'c': {
                // Presta un libro al usuario
                prestar_libro(lista_libros, cantidad_libros, user1);
                break;
            }

            case 'd': {
                // Devuelve un libro prestado
                devolver_libro(lista_libros, cantidad_libros, user1);
                break;
            }

            case 'e':{
                // Califica un libro y registra los comentarios
                calificar_libro(lista_libros, cantidad_libros);
                break;    
            }

            case 'f': {
                // Muestra los datos del usuario y los libros prestados
                datos_usuario(user1);
                break;
            }

            case 'g': {
                // Muestra todos los libros y su status
                libros_biblioteca(lista_libros, cantidad_libros);
                break;
            }

            case 'h': {
                // Muestra los comentarios y estrellas de un libro
                ver_resenias(lista_libros, cantidad_libros);
                break;
            }

            case 'i': {
                // Permite al usuario salir del programa
                cout << "¡Hasta luego!" << endl;
                return 0;
            }

            // En caso de que el usuario elija una opción no válida
            default:
                cout << "Opcion invalida" << endl;
        }
    }
    return 0;
}
