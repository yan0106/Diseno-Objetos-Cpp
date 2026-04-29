//salida.cpp
//Sobrecarga del operador de salida
//

#include<iostream>
#include<string>
using namespace std;

class Persona{
    string nombre;
    string apellido;
public:
    Persona(string n, string a):nombre{n}, apellido{a}{};

    friend ostream& operator<<(ostream&, const Persona&);
};

class Grabacion{

    string titulo;
    string comentario;
    Persona autor;
    int fecha;

public:

    Grabacion(string t, Persona p, int f):
        titulo{t}, autor{p}, fecha{f}{};

    void set_comentario(string);

    friend ostream& operator<< (ostream&, const Grabacion&);
};



void Grabacion::set_comentario(string c){
    comentario = c;
}
ostream& operator<< (ostream& os, const Grabacion& g){
    os<< "La grabacion es:\n"
    << g.titulo << endl << "creada por "<< g.autor << endl
    << "Fecha: " << g.fecha << endl;
}
ostream& operator<<(ostream& os, const Persona& P){
    os << P.nombre << " " << P.apellido;
}

int main()
{
    Persona autor("Paul", "McCartney");
    Grabacion Disco("Band on the run", autor, 1974);

    cout << Disco;

    return 0;
}