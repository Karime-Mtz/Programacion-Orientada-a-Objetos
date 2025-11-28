#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

class Biografia: public Libro {
    private:
        string personaje;
    public:
            Biografia();
            Biografia(string t, string a, int p, string e);

            string getPersonaje();
            void setPersonaje(string persona);


};

Biografia::Biografia(): Libro(){
    personaje = "Desconocido";
}

Biografia:: Biografia(string t, string a, int p, string e) : Libro(t,a,p){
    personaje = e;
}

string Biografia::getPersonaje(){
    return personaje;
}

void Biografia::setPersonaje(string persona){
    personaje = persona;
}
