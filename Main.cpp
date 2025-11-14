#include "Libro.h"
#include "Usuario.h"
#include "Valoracion.h"

#include <string>
#include <iostream>
using namespace std;

int main(){
    // Crear objetos
    Libro book2("Heartless", "Romance", "Marissa Meyer", 416);
    Libro book3("Momo", "Novela", "Michael Ende", 320);

    Usuario user2("Marta", 42, "Romance", 2);
    Usuario user3("Carlos", 19, "Terror", 1);

    Valoracion review2("Marta", "Heartless", "Top libros que he leido", 5);
    Valoracion review3("Clara", "Momo", "Excelente", 5);

    book2.mostrar_info_libro();
    user3.infoUsuario();
    review2.mostrar_valoracion();

    user3.setEdad(21);
    user3.infoUsuario();

    review2.borrar_comentarios();
    review2.mostrar_valoracion();
    
    return 0;
}
