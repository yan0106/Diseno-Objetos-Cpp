#include <iostream>
#include "grafo.cpp"
using namespace std;

// Implementación de los nuevos Métodos:

void grafo::insertar_arista(){ // guarda las aristas en el conjunto E pidiendolas ingresar por teclado
    char v1; // v origen 
    char v2; // v destino
    int costo;
    cout << "Ingrese vértice origen: "; 
    cin >> v1;
    cout << "Ingrese vértice destino: "; 
    cin >> v2;
    cout << "Ingrese costo: "; 
    cin >> costo;

    // se crea el par y guarda los datos en el vector E
    E.push_back(make_pair(make_pair(v1, v2), costo));
};


