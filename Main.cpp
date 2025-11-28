//Lo voy a hacer interactivo, con un menú, pero todavía me falta esa parte.


#include <iostream>
#include "Libro.h"
#include "Novela.h"
#include "Biografia.h"
#include "Comic.h"
#include "Usuario.h"
#include "Valoracion.h"
using namespace std;

int main() {

 
    // Crear libros:

    Libro Principito("El Principito", "Antoine de Saint-Exupéry", 120);
    Novela Mujercitas("Mujercitas", "Louisa May", 600, "Romance", true);
    Biografia Steve_Jobs("Steve Jobs", "Walter Isaacson", 600, "Steve Jobs");
    Comic Batman("Batman: Año Uno", "Frank Miller", 140, "DC", "David Mazzucchelli");


    // Crear reseñas
    Valoracion review1("Muy bonito y reflexivo", 5);
    Valoracion review2("Me encantó la historia", 4);
    Valoracion review3("Excelente libro", 5);

    Principito.agregar_review(review1);
    Principito.agregar_review(review3);
    Mujercitas.agregar_review(review2);

    // Crear usuarios
    Usuario Carlos("Carlos", 21, 0);
    Usuario Marta("Marta", 36, 0);


    Carlos.agregar_libro_prestado(Steve_Jobs);
    Carlos.agregar_libro_prestado(Batman);
    Marta.agregar_libro_prestado(Principito);

    
    
    cout << "\nInformación del libro\n";
    Principito.mostrar_info_libro();
    cout << "Promedio de calificación: " << Principito.getPromedio_calificacion() << endl;

    cout << "\nInformación del comic\n";
    Batman.mostrar_info_libro();
    cout << "Universo: " << Batman.getUniverso() << endl;
    cout << "Ilustrador: " << Batman.getIlustrador() << endl;

    cout << "\nInformación del Usuario\n";
    Carlos.infoUsuario();


    return 0;
}
