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
}

void grafo::inicial(const char& vertice, const char& nombre_grupo){ // inicializa a las estructuras del conjunto Combina-Encuentra
    CE.nombres[vertice] = make_pair(' ', ' '); // como el vértice al ppio. está solo, no tiene anterior ni siguiente
    CE.encabezados[nombre_grupo] = make_pair(1, vertice); // cada vértice es su propio conjunto de 1 elemento
}

// Estructura Combina-Encuentra
typedef struct combina_encuentra {
	map <char, pair<char, char>> nombres; // vértice y vértice sig.
	map <char, pair<int, char>> encabezados; // resumen de cada vértice: cuenta los vértices y da el primer elemento
}conjunto_CE;