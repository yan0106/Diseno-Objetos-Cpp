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
	string nombre;
	Luz luz_roja;
	Luz luz_amarilla;
	Luz luz_verde;
	enum estado {Est_Rojo, Est_Rojo_Amarillo, Est_Verde, Est_Verde_Amarillo};
	estado estado_actual; // este atributo, guarda uno de los estados declarados arriba

public:
    // : lista de inicialización en el constructor semáforo
 	Semaforo(string nombre_recibido): luz_roja("Rojo", true),
				luz_amarilla("Amarillo", false),
				luz_verde("Verde", false),
				estado_actual(Est_Rojo),
				nombre(nombre_recibido){};
	void cambiar_estado();
	void mostrar_estado();

};

// -- Implementación de los Métodos --

void Luz::encender(){
	onoff = true;
}

void Luz::apagar(){
	onoff = false;
}

void Semaforo::cambiar_estado(){
	switch (estado_actual) {
    case Est_Rojo:
		luz_amarilla.encender();
        estado_actual = Est_Rojo_Amarillo;
        break; // para que no siga de largo al siguiente caso

    case Est_Rojo_Amarillo:
        luz_roja.apagar();
		luz_amarilla.apagar();
		luz_verde.encender();
		estado_actual = Est_Verde;
        break;
	
	case Est_Verde:
		luz_amarilla.encender();
		estado_actual = Est_Verde_Amarillo;
		break;

	case Est_Verde_Amarillo:
		luz_verde.apagar();
		luz_amarilla.apagar();
		luz_roja.encender();
		estado_actual = Est_Rojo;
		break;

    default:
        luz_roja.encender();
		luz_verde.apagar();
		luz_amarilla.apagar();
		estado_actual = Est_Rojo;
        break;
	}
}

void Semaforo::mostrar_estado() {
	cout << "Semáforo: " << nombre << endl;
	cout << "Rojo: " << (luz_roja.esta_encendida() ? "ENCENDIDO" : "---") << " | ";
	cout << "Amarillo: " << (luz_amarilla.esta_encendida() ? "ENCENDIDO" : "---") << " | ";
	cout << "Verde: " << (luz_verde.esta_encendida() ? "ENCENDIDO" : "---") << endl;
    cout << "------------------------------------------------" << endl; 
}
// "Semáforo [Nombre]: Roja [ON/OFF] | Amarilla [ON/OFF] | Verde [ON/OFF]".

// --- Main ---

int main () {





return 0;	
}