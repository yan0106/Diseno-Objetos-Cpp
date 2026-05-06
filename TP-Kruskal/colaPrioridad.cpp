#include<iostream>
#include<queue>
using namespace std;

/**
 * Esta solución la he encontrado al tratar de buscar información sobre el diseño
 * de la cola de prioridad. La respuesta mas cercada que encontré es que el 
 * contenedor no posee punteros inicio y fin ya que el recorrerla y manipularla
 * de forma no secuencial pone en riesgo la integridad de los datos guardados
 * o sea, se podrían quitar y agregar datos sin respetar la prioridad que se 
 * haya establecido.
 * 
 * Sin embargo encontré esta posible forma hecho por un programador. Solo la
 * presento como medio posible, pero por lo dicho antes no sería correcto su
 * implementación
 * */

/**
 * Se declara una estructura, la cual hereda de priority_queue, dentro, agrega
 * los iteradores begin y end que retorna el inicio y el final de la estructura
 **/

template<class T, class C = vector<T>, class P = less<typename C::value_type> >
struct heapq :std::priority_queue<T,C,P> {
    using priority_queue<T,C,P>::priority_queue;
    typename C::iterator begin() { return std::priority_queue<T, C, P>::c.begin(); }
    typename C::iterator end() { return std::priority_queue<T, C, P>::c.end(); }
};

/**
 * Luego, se puede utilizar en el for 
 **/

int main(){
    heapq<int> q;
    q.push(100);
    q.push(80);
    q.push(60);
    for(auto e:q) 
        cout<<e<<endl;
}