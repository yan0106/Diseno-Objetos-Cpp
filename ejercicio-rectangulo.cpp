/*Ejercicio:

==== PUNTO ====
--- Atributos --- 
- cor_x: int
- cord_y: int
--- Métodos ---
+ punto(void): void
+ set(int, int): bool
+ print(void): void
+ valida(int): bool

=== RECTANGULO ===
--- Atributos ---
- tope_izq: Punto
- tope_der: Punto
--- Métodos ---
+ rectangulo(int, int, int, int): void
+ print(void): void

Un rectángulo se compone de dos puntos.

Cuando se instancia el rectángulo, recibe las coordenadas x,y de cada uno de los puntos. Se instancian y setean.
Deben utilizarse solamente los métodos definidos en las clases.
print(), muestra en pantalla los valores de los atributos.
valida(int), verifica que el entero sea positivo
No es necesario que se realice un ingreso por teclado. Simplemente en el main se fijan los valores.
Ejemplo:

int main (){
    Rectangulo R(5, 4, 9, 2);
    R.print();
}

*/

#include <iostream>

using namespace std;

class Punto {

    // Atributos:
    int cord_x;
    int cord_y;

    // Métodos:
public:
    Punto(){};
    bool set_p(int, int);
    void print_p();
    bool valida_p(int);

};

class Rectangulo {

    // Atributos
    Punto tope_iz;
    Punto inf_der;

    // Métodos
public: 
    Rectangulo(int x, int y, int z, int w){
        if (x > 0 && y > 0){
            tope_iz.set_p(x, y);
        }
        if (z > 0 && w > 0) {
            inf_der.set_p(z, w);
        }
        else {
            cout << "Coordenada inválida" << endl;
        }
    };
    void print_r();

};

// --- Implementación de los Métodos ---

bool Punto::valida_p(int x) {
    if (x > 0) {
        return true;
    } else {
        return false;
    }
};

bool Punto::set_p(int x, int y) {
    if (valida_p(x) && valida_p(y)) {
        cord_x = x;
        cord_y = y;
        return true
    } else { 
        cout << "Coordenadas inválidas" << endl;
        return false;
    }
};

void Punto::print_p() {
    cout << "Las coordenadas ingresadas son: " <<"(" << cord_x <<", " << cord_y << ")" << endl;
};