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

char grafo::encuentra(const char& vertice){ // encuentra los vértices dentro del conjunto Combina-Encuentra
    // iterar en CE.encabezados[nombre_grupo] 
    for (auto const& i : CE.encabezados){ // recorre los grupos
        char nombre_grupo = i.first;
        char v = i.second.second;
        while (v != ' ') { // recorre los vértices
            if (v == vertice){ // si lo encuentra
                return nombre_grupo;
            }
            v = CE.nombres[v].second; // si no lo encuentra, actualiza al siguiente v
        }
    }
return ' '; // si sale del bucle for y no lo encontró, retorna vacío
}
// clave: nombre del grupo | valor: par de (cantidad, 1er. elem.)
// map <char, pair<int, char>> encabezados;