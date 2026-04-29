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
    friend istream& operator>>(istream&, Tipo&); // sobrecarga del op de entrada
    // friend: para darle permiso especial a la función para que pueda acceder a los atributos.
    // istream: se refiere a un "flujo de entrada" (input stream), como es el caso de cin.
    // el símbolo &: significa que lo pasamos por referencia se usa para que los datos se guarden 
    // directamente en el objeto original y no en una copia, que se borre al terminar la función
    // operator>>: es el nombre la función:
    // quiero definir qué tiene que pasar cuando use el símbolo >> con este objeto
    // el primer parámetro es un istream&, porque cin es un istream (clase de C++)
    friend ostream& operator<<(ostream&, Tipo&); // sobrecarga del op de salida
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

    friend istream& operator>>(istream&, Impresora&); // sobrecarga del op de entrada
    friend ostream& operator<<(ostream&, Impresora&); // sobrecarga del op de salida
    // friend: permiso para acceder a marca, modelo y tipo (privados).
    // ostream&: flujo de salida por referencia (el "caño" por donde sale la info, ej. cout).
    // Impresora&: el objeto que queremos mostrar (pasado por referencia para no copiarlo).

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