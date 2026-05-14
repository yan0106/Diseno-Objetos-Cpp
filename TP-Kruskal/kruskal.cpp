#include <iostream>
#include "grafo.h"
using namespace std;

// Implementación de los métodos:

void grafo::insertar_arista(){ // guarda las aristas en el conjunto E pidiendolas ingresar por teclado
    char v1; // v origen 
    char v2; // v destino
    int costo;
    cout << "Ingrese vertice origen: "; 
    cin >> v1;
    cout << "Ingrese vertice destino: "; 
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

void grafo::combina(const char& grupoA, const char& grupoB){ // recibe el nombre de los grupos, combina las aristas 
// que se encuentran formando el árbol    
    
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

void grafo::inserta() {
    // recorre cada x dentro del vector de aristas E
    for (auto const& x : E) {
        // mete x en la cola de prioridad grafo_ordenado:
        grafo_ordenado.push(x);
    }
}

void grafo::kruskal() {
    
    int comp_n = V.size(); // cantidad actual de componentes (vértices)
    arista a;
    int costo_total = 0;

    // llama al método inserta para que meta las aristas en la cola de prioridad
    inserta();

    // inicializa los conjuntos
    for (auto const& x : V) {
        inicial (x, x);
    }

    while (comp_n > 1 && !grafo_ordenado.empty()) // mientras haya vertices para comparar y la cola de prioridad
    // no esté vacía
    {
        a = grafo_ordenado.top(); // saca la primera arista de la cola (menor costo) y la guarda en a
        grafo_ordenado.pop(); // la elimina de la cola

        char grupoA = encuentra (a.first.first); // recibe el 1er. vértice de la arista a, devuelve el grupo y lo guarda en grupoA
        char grupoB = encuentra (a.first.second); // recibe el 2do. vértice de la arista a, devuelve el grupo y lo guarda en grupoB

        if (grupoA != grupoB) {
            arbol_minimo.push_back(a);
            costo_total = costo_total + a.second;
            combina(grupoA, grupoB);
            comp_n = comp_n - 1;
        }
    }

    cout << "Las aristas elegidas son: " << endl;
    for (auto const& x : arbol_minimo) {
        cout << x.first.first << " - " << x.first.second << " | Costo: " << x.second << endl;
    }
    
    cout << "El costo total es: " << costo_total << endl;
}


int main () {

    grafo G;

/* // 1. Gestión del Grafo (prueba)
    G.insertar_vertice('A');
    G.insertar_vertice('B');
    G.insertar_vertice('C');
    G.insertar_vertice('D');

	G.insertar_arista('A', 'B', 10);
    G.insertar_arista('B', 'C', 5);
    G.insertar_arista('A', 'D', 2);
    G.insertar_arista('A', 'C', 7);
*/
    G.insertar_vertice('1');
    G.insertar_vertice('2');
    G.insertar_vertice('3');
    G.insertar_vertice('4');
    G.insertar_vertice('5');
    G.insertar_vertice('6');

    G.insertar_arista('1', '2', 6);
    G.insertar_arista('1', '3', 1);
    G.insertar_arista('1', '4', 5);
    G.insertar_arista('2', '3', 5);
    G.insertar_arista('2', '5', 3);
    G.insertar_arista('3', '5', 6);
    G.insertar_arista('3', '6', 4);
    G.insertar_arista('4', '3', 5);
    G.insertar_arista('4', '6', 2);
    G.insertar_arista('5', '6', 7);

    cout << G;

/*  // 2. Lógica Combina-Encuentra (prueba)
    G.inicial('A', 'A');
    G.inicial('B', 'B');
    G.inicial('C', 'C');
    G.inicial('D', 'D');

    cout << "--- Metodo encuentra: ---" << endl;
    cout << "El vertice A pertenece al grupo: " << G.encuentra('A') << endl;
    cout << "El vertice B pertenece al grupo: " << G.encuentra('B') << endl;
    cout << "El vertice C pertenece al grupo: " << G.encuentra('C') << endl;

    cout << "--- Luego de combinar los vertices: ---" << endl;
    G.combina('A', 'B');
    cout << "El vertice A ahora pertenece al grupo: " << G.encuentra('A') << endl;
    cout << "El vertice B ahora pertenece al grupo: " << G.encuentra('B') << endl;
    G.combina('B', 'C');
    cout << "El vertice C ahora pertenece al grupo: " << G.encuentra('C') << endl;
    cout << "El vertice A ahora pertenece al grupo: " << G.encuentra('A') << endl;

*/

    // 3. Kruskal: 
    G.kruskal();

return 0;
}
