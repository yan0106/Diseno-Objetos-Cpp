/* 2.- Semaforos
Simularemos el comportamiento y sincronia de semáforos, simplificaremos un poco el diseño, teniendo 
en cuenta, que el semáforo posee tres luces, las cuales pueden estar encendidas o apagadas, solo
pueden estar de a dos en el mismo estado, o sea, rojo/amarillo, o verde/amarillo, que sera utilizada 
para la transición entre el rojo y verde.
En cada esquina hay dos semáforos, en determinado lapso de tiempo, ambos cambiaran de estado pero siempre
en contraposición, ejemplo:
  Semaforo A 			  Semaforo B

	Rojo					Verde
	Rojo 					Verde/amarillo
	Rojo/amarillo			Rojo
	Verde					Rojo

Se debe determinar los objetos que participan, sus atributos, constructores, y los métodos necesarios en
cada uno.
Obviamente, no habrá una función timer autónoma, simplemente alcanzará con un método cambiar_estado, que
cada vez que se ejecute establezca a los semaforos en los estados arriba expuestos.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Luz {

	string color;
	bool onoff;

public:
	Luz(string color_recibido, bool onoff_recibido){ 
		color = color_recibido;
		onoff = onoff_recibido;
	};
	void encender();
	void apagar();
	bool esta_encendida(){return onoff;}; // getter, para que el semáforo sepa qué está pasando con sus luces
};

class Semaforo {
	Luz luz_roja;
	Luz luz_amarilla;
	Luz luz_verde;
	enum estado {Est_Rojo, Est_Rojo_Amarillo, Est_Verde, Est_Verde_Amarillo};
	estado estado_actual; // este atributo, guarda uno de los estados declarados arriba

public:
    // : lista de inicialización en el constructor semáforo
 	Semaforo(): luz_roja("Rojo", true),
				luz_amarilla("Amarillo", false),
				luz_verde("Verde", false),
				estado_actual(Est_Rojo){}; 
	void cambiar_estado();

};

// -- Implementación de los Métodos --

void Luz::encender(){
	onoff = true;
}

void Luz::apagar(){
	onoff = false;
}

