/* Ejercicio: lista de Vectores de cuatro elementos 

Estructura básica: 

class vec4{ 

private: 
    float v1, v2, v3, v4; 

public: 	
    Dos constructores, uno inicializando en 0.0 los componentes otro que recibe cuatro floats

    metodos gets y sets para cada uno de los componentes 

    una funcion mostrar() que imprime por pantalla el vector 
};

class nodo{ 
    vec4 vect; 
	nodo* sig;

public: 
    nodo(){sig=NULL;} 
	void set_nodo(vec4); 
	void set_sig(nodo a); 
    bool si_esta(vec4); 
	void mostrar();
};
*/