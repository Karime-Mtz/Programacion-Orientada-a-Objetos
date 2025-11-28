#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

class Comic: public Libro{
    private:
        string universo; 
        string ilustrador;
    public:
            Comic();
            Comic(string t, string a, int p, string u, string i);
            
            string getUniverso();
            string getIlustrador();

            void setUniverso(string u);
            void setIlustrador(string drawer);

};

Comic::Comic() : Libro(){
    universo = "Desconocido";
    ilustrador = "Desconocido;";
}

Comic::Comic(string t, string a, int p, string u, string i) : Libro(t,a,p){
    universo = u;
    ilustrador = i;
}

string Comic::getUniverso(){
    return universo;
}

string Comic::getIlustrador(){
    return ilustrador;
}

void Comic::setUniverso(string u){
    universo = u;
}

void Comic::setIlustrador(string drawer){
    ilustrador = drawer;
}
