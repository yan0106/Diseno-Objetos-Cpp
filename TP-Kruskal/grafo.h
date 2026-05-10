#include<iostream>
#include<vector>
#include<utility> // para usar pair
#include<map> // para la estructura Combina-Encuentra (asociar clave-valor)
#include<queue> // para la cola de prioridad (el árbol)
using namespace std;

// Estructura Arista
typedef pair<pair<char, char>, int> arista; // (v1, v2 y costo entre ellos)

// Estructura Combina-Encuentra
typedef struct combina_encuentra {
	// clave: vértice actual | valor: par de (v anterior, v sig.)
	map <char, pair<char, char>> nombres;
	// clave: nombre del grupo | valor: par de (cantidad, 1er. elem.)
	map <char, pair<int, char>> encabezados;
}conjunto_CE;

// Clase MenorValor
class MenorValor { // se genera una nueva clase para generar un nuevo criterio de comparación y que no sea por defecto
	public:
		// sobrecarga del operador () para comparar los pesos de las aristas
    	// retorna true si el peso de e1 es mayor al de e2 (para ordenar de menor a mayor)
		bool operator() (arista e1, arista e2) { // functor (objeto que se comporta como una función)
			return e1.second > e2.second;
		}
};

// Estructura Arbol (cola de prioridad de aristas)
typedef priority_queue<arista, vector<arista>, MenorValor> arbol;

/*
Sea un grafo G = (V, E)
*/
class grafo{
	
	vector<char> V;
	vector<arista> E;
	conjunto_CE CE; // estructura para evitar ciclos
	arbol grafo_ordenado; // cola de prioridad con los pesos de las aristas
	vector<arista> arbol_minimo; // donde guardo las aristas (de menor costo) del resultado final

public:
	grafo(){} // constructor
	~grafo(){} // destructor

	void insertar_vertice(const char&); // guarda los vértices en el conjunto V
	void insertar_arista(const char&, const char&, const int&); // guarda las aristas en el conjunto E
	
	// Nuevos métodos:
	void insertar_arista(); // guada las aristas en el conj. E pidiendolas ingresar por teclado
	void inicial(const char& vertice, const char& nombre_grupo); // inicializa a las estructuras del conjunto Combina-Encuentra
	char encuentra(const char& vertice); // encuentra los vértices dentro del conjunto Combina-Encuentra
	void combina(const char&, const char&); // combina las aristas que se encuentran formando el árbol
	void inserta(); // guarda al conjunto E dentro de la cola de prioridad teniendo en cuenta los costos
	void kruskal(); // algoritmo generador del árbol recubridor minimal
	

	friend ostream& operator <<(ostream&, grafo);
};

void grafo::insertar_vertice(const char& vertice){
	V.push_back(vertice);
}

void grafo::insertar_arista(const char& vertice1, const char& vertice2, const int& costo){	
	E.push_back(make_pair(make_pair(vertice1, vertice2), costo));
}

ostream& operator <<(ostream& os, grafo G){

	os << "El grafo es: \n";
	for(auto x: G.E)
		os << x.first.first << " - " << x.first.second << ": costo = " << x.second << endl;

	return os;
}
/*
int main(){
	grafo G;

	G.insertar_vertice('a');
	G.insertar_vertice('b');
	G.insertar_vertice('c');
	G.insertar_vertice('d');

	G.insertar_arista('a', 'b', 52 );
	G.insertar_arista('a', 'c', 15 );
	G.insertar_arista('a', 'd', 5 );
	G.insertar_arista('b', 'c', 40 );
	G.insertar_arista('a', 'd', 25 );
	G.insertar_arista('c', 'd', 1 );

	cout << G;
	return 0;
}*/