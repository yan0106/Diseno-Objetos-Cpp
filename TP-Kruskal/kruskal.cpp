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

void grafo::combina(const char& grupoA, const char& grupoB){ // combina las aristas que se encuentran formando el árbol    
    
    // variables para conocer qué grupo es más grande y unirlos (al grupo más grande le suma el más chico)
    char g_grande;
    char g_chico;    
    if (CE.encabezados[grupoA].first > CE.encabezados[grupoB].first) { // comparo las cant. de v de los grupos (los int)
        g_grande = grupoA;
        g_chico = grupoB;
    } else {
        g_grande = grupoB;
        g_chico = grupoA;
    }
     // recorre los vértices:
    char vertice = CE.encabezados[g_grande].second; // guarda el vértice actual desde donde empieza  
    while (CE.nombres[vertice].second != ' ') { // camina por los vértices, mientras que no llegue a ' ';
        vertice = CE.nombres[vertice].second; // actualiza el vertice actual
    }

    // actualiza el último v de g_grande:
    char primer_v_chico = CE.encabezados[g_chico].second; // guarda en una variable, el 1er. v del g_chico
    CE.nombres[vertice].second = primer_v_chico; // al último v de g_grande, le asigna el 1er. v del g_chico

    // actualiza el v anterior:
    CE.nombres[primer_v_chico].first = vertice;

    // atualiza la cantidad del grupo:
    CE.encabezados[g_grande].first += CE.encabezados[g_chico].first;

    // anula el g_chico:
    CE.encabezados[g_chico].first = 0; // cantidad 0
    CE.encabezados[g_chico].second = ' '; // primer v como ' '
} 