#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

class Novela : public Libro{
    private:
        string genero; 
        bool es_saga;
    public:
            Novela();
            Novela(string t, string a, bool d, string g, bool e);
            //:Libro(t,a,p),genero(g),es_saga(e){};
            //Se puede definir desde aquí pero es mejor abajo
            
            string getGenero();
            bool getEs_saga();

            void setGenero(string gender);
            void setEs_saga(bool saga);

};

Novela::Novela() : Libro(){
    genero = "Desconocido";
    es_saga = false;
}

Novela::Novela(string t, string a, bool d, string g, bool e): Libro(t,a,d){
    genero = g;
    es_saga = e;
}

string Novela::getGenero(){
    return genero;
}

bool Novela::getEs_saga(){
    return es_saga;
}

void Novela::setGenero(string gender){
    genero = gender;
}

void Novela::setEs_saga(bool saga){
    es_saga = saga;
}
