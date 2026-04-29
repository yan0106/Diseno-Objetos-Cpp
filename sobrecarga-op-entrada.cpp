//entrada.cpp
//sobrecarga del operador de entrada
//

#include<iostream>
#include<string>
using namespace std;

class Tipo{
    string tipo;
    string color;
public:
    Tipo(){};

    string get_tipo(){return tipo;}
    string get_color(){return color;}
    friend istream& operator>>(istream&, Tipo&);

};

class Impresora{
    string marca;
    string modelo;
    Tipo tipo;
public:
    Impresora(){};

    string get_marca(){return marca;}
    string get_modelo(){return modelo;}
    Tipo get_tipo(){return tipo;}

    friend istream& operator>>(istream&, Impresora&);

};

istream& operator>>(istream& is, Tipo& t){
    cout << "Ingrese el tipo de impresora: laser/tinta ";
    is >> t.tipo;
    
    cout << "Ingrese si es color o B/N: ";
    is >> t.color;

    return is;

}

istream& operator>>(istream& is, Impresora& i){
    cout<< "Ingresará los datos de la impresora:" << endl;
    cout<< "Ingrese la marca: ";
    is >> i.marca;
    cout<< "Ingrese el modelo: ";
    is >> i.modelo;
    is >> i.tipo;

    return is;
}

int main (){

    Impresora I;
    cin >> I;

    cout << "la impresora ingresada es: " << endl;
    cout << I.get_marca();

    return 0;
}

///~

/* EJERCICIO:

Teniendo en cuenta los ejemplos de los archivos
entrada.cpp y salida.cpp realice:

- En el archivo entrada.cpp sobrecargue los operadores de salida para poder mostrar correctamente 
al objeto creado.
- En el archivo salida.cpp sobrecargue los operadores de entrada, sobrecargue los constructores para que
no reciban parámetros de entrada y poder usar los objetos en forma directa en cin.

*/