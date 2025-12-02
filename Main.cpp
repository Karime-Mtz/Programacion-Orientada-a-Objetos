#include <iostream>
#include "Libro.h"
#include "Novela.h"
#include "Biografia.h"
#include "Comic.h"
#include "Usuario.h"
#include "Valoracion.h"
using namespace std;

string a_minusculas(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}


int buscar_libro(Libro lista[], int cantidad, string titulo) {
    for (int i = 0; i < cantidad; i++) {
        if (a_minusculas(lista[i].getTitulo()) == a_minusculas(titulo)) {
            return i;
        }
    }
    return -1;
}

int validar_numero(string mensaje) {
    int n;
    cout << mensaje;

    while (!(cin >> n)) {
        cout << "Entrada inválida. Debes escribir un número: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    return n;
}


int main() {

// Agregar libros iniciales a la biblioteca:

    Libro Principito("El Principito", "Antoine de Saint-Exupéry", true);
    Novela Mujercitas("Mujercitas", "Louisa May", true, "Romance", true);
    Biografia Steve_Jobs("Steve Jobs", "Walter Isaacson", true, "Steve Jobs");
    Comic Batman("Batman: Año Uno", "Frank Miller", true, "DC");
    Libro Momo("Momo", "Michael Ende", true);
    Novela Frankenstein("Frankenstein", "Mary Shelley", true, "Horror", false);
    Comic Sandman("The Sandman", "Neil Gaiman", true, "DC");

    Libro lista_libros[100];
    int cantidad_libros = 7;

    lista_libros[0] = Principito;
    lista_libros[1] = Mujercitas;
    lista_libros[2] = Steve_Jobs;
    lista_libros[3] = Batman;
    lista_libros[4] = Momo;
    lista_libros[5] = Frankenstein;
    lista_libros[6] = Sandman;

    string nombre_usuario;
    int age;

    cout<< "Bienvenido a tu biblioteca digital:"<<endl;
    cout << "¿Cuál es tu nombre?" << endl;
    cin >> nombre_usuario;
    cout << "¿Cuál es tu edad?" << endl;
    while (!(cin >> age) || age <= 0) {
        cout << "Respues no válida. Vuelve a intentarlo: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Usuario user1(nombre_usuario, age, 0);

    while (true) {
        cout << "\nElige una de las siguientes opciones (a/b/c/d/e/f/g):" << endl;
        cout << "a) Agregar libro" << endl;
        cout << "b) Buscar libro" << endl;
        cout << "c) Pedir libro prestado" << endl;
        cout << "d) Devolver libro" << endl;
        cout << "e) Calificar libro" << endl;
        cout << "f) Ver mi informacion" << endl;
        cout << "g) Salir\n" << endl;

        char opcion;
        cin >> opcion;
        cin.ignore();


        switch (opcion) {
            case 'a': {
                int tipo;
                string title, escritor, genero, univers, character;
                bool es_saga;

                while (!(cin >> tipo) || tipo < 1 || tipo > 4) {
                    cout << "Rspuesta no válida. Elige un número del 1 al 4\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "¿Cuál deseas agregar? (1/2/3/4)\n"
                    "1.- Libro\n2.- Novela\n3.- Comic\n4.- Biografia\n";
                }
                cin.ignore();
            
                cout << "¿Cuál es el título?" << endl;
                getline(cin, title);
                cout << "Quién es el autor?" << endl;
                getline(cin, escritor);

                if (tipo == 1){
                    lista_libros[cantidad_libros++] = Libro(title, escritor, true);
                } 
                else if (tipo == 2){
                    cout << "¿Cuál es su genero?" << endl;
                    getline(cin, genero);
                    cout << "¿Es una saga? (1 = si, 0 = no)" << endl;
                    cin >> es_saga;

                    lista_libros[cantidad_libros] = Novela(title, escritor, true, genero, es_saga);
                    cantidad_libros ++;
                } 
                else if (tipo == 3){
                    cout << "¿Cuál es su universo?" << endl;
                    getline(cin, univers);
                    lista_libros[cantidad_libros] = Comic(title, escritor, true, univers);
                    cantidad_libros ++;
                } 
                else if (tipo == 4) {
                    cout << "¿De quién es la biografía?" << endl;
                    getline(cin, character);
                    lista_libros[cantidad_libros] = Biografia(title, escritor, true, character);
                    cantidad_libros ++;
                }

                break;
            }
 
            //Buscar libro

            case 'b': {
                string titulo;
                cout << "¿Cuál es el título?" << endl;
                getline(cin, titulo);

                int position = buscar_libro(lista_libros, cantidad_libros, titulo);

                if (position == -1) {
                    cout << "No se encontró el libro" << endl;
                } else {
                    cout << lista_libros[position].mostrar_info_libro();
                }
                break;
            }
        
            // Prestar libro

            case 'c': {
                if (user1.getCantidad_prestados() < 10){
                    string titulo;
                    cout << "¿Cuál es el título del libro a prestar?" << endl;
                    getline(cin, titulo);

                    int pos = buscar_libro(lista_libros, cantidad_libros, titulo);

                    if (pos == -1) {
                        cout << "Libro no encontrado" << endl;
                    } else if (!lista_libros[pos].get_disponible()) {
                        cout << "El libro no está disponible" << endl;
                    } else {
                        user1.agregar_libro_prestado(lista_libros[pos]);
                        cout << "El libro ha sido prestado exitosamente" << endl;
                    }
                } else {
                    cout << "Has alcanzado el límite de prestamos";
                }
                break;
            }
        
            // Devolver libro

            case 'd': {
                string titulo;
                cout << "¿Qué libro te gustaría devolver?" << endl;
                getline(cin, titulo);

                if(user1.devolver_libro(titulo)){
                    cout << "El libro ha sido devuelto" << endl;;
                } else {
                    cout << "No tienes este libro prestado";
                }
                break;
            }
        
            // Calificar

            case 'e':{
                string libro;
                int estrellas;
                string answer;
                string comment;

                cout << "¿Qué libro deseas calificar?" << endl;
                getline(cin, libro);

                int posicion = buscar_libro(lista_libros, cantidad_libros, libro);
                while (posicion == -1){
                    cout << "Libro no encontrado. Inténtalo de nuevo" << endl;
                    getline(cin, libro);
                    posicion = buscar_libro(lista_libros, cantidad_libros, libro);
                }   
            
            
                cout << "¿Qué calificación le das? (1-5)" << endl;
                cin >> estrellas;
                while(estrellas < 1 || estrellas > 5){
                    cout << "Calificación no válida. Vuélvelo a intentar (1-5) " << endl;
                    cin >> estrellas;
                }
                cin.ignore();

                cout << "¿Deseas agregar algún comentario? (si/no)" << endl;
                cin >> answer;
                cin.ignore();

                if (answer == "si"){
                    cout << "Escribe tu comentario" << endl;
                    getline(cin, comment);
                } else {
                    comment = "";
                }

                lista_libros[posicion].agregar_review(comment, estrellas);
                cout << "Tu reseña fue agregada exitosamente" << endl; 
                break;    
            }

            // Informacion

            case 'f': {
                cout << user1.infoUsuario() << endl;
                break;
            }

            case 'g': {
                cout << "¡Hasta luego!" << endl;
                return 0;
            }

            default:
                cout << "Opción inválida" << endl;
        }

    }
    return 0;
}
