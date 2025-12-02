#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;

class Comic: public Libro{
    private:
        string universo; 
    public:
            Comic();
            Comic(string t, string a, bool d, string u);
            
            string getUniverso();
            void setUniverso(string u);
};

Comic::Comic() : Libro(){
    universo = "Desconocido";
}

Comic::Comic(string t, string a, bool d, string u) : Libro(t,a,d){
    universo = u;
}

string Comic::getUniverso(){
    return universo;
}

void Comic::setUniverso(string u){
    universo = u;
}

