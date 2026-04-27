/* 1.-

Teniendo estas definiciones de objetos:

class Dispositivo{

	string dir_ip;
	string nombre;
	string mascara;

public:
	Dispositivo(){}

	void enviar_datos(Paquete, Dispositivo);
	void recibir_datos(Paquete, Dispositivo);

}

class Paquete{

	Dispositivo origen;
	Dispositivo destino;
	string mensaje;

public:

	Paquete(Dispositivo, Dispositivo, string);
	void mostrar();


}

a) Modificar el constructor de la clase Dispositivo para que pueda recibir los datos necesarios e
inicializar los atributos.
b) Implementar los métodos enviar_datos y recibir_datos para que ambos muestren por pantalla los
parametros que recibieron.
c) Implementar el constructor de la clase Paquete
d) Implementar el método mostrar();
e) En la función main, declarar los objetos y probarlos.

OPCIONAL IMPORTANTE

En la función main, declarar:

vector<Dispositivo> red;

- utilizarlo como contenedor de dispositivos, y luego, recorrerlo, mostrando los dispositivos que
componen a esa red.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paquete; 

class Dispositivo{ // En las clases de C++, todo lo que está arriba de public: es private por defecto
	// Atributos:
	string dir_ip;
	string nombre;
	string mascara;

public: // Métodos:
	// Constructor vacío, por defecto. Para cuando necesito un objeto "en blanco"
	Dispositivo(){};
	// Constructor con parámetros: el constructor tiene que "mapear" lo que viene de afuera hacia adentro
	Dispositivo(string ip_recibida, string nombre_recibido, string mascara_recibida){
        dir_ip = ip_recibida;
        nombre = nombre_recibido;
        mascara = mascara_recibida;
        cout << "Dispositivo inicializado" << endl;
    }
	void enviar_datos(Paquete p, Dispositivo d);
	void recibir_datos(Paquete p, Dispositivo d);
	string getNombre(){ // método para obtener el nombre del Dispositivo
		return nombre;
	}
};

class Paquete{
	// Atributos:
	Dispositivo origen;
	Dispositivo destino;
	string mensaje;

public: // Métodos:
	Paquete (){};
	// Mapeo en el Constructor, los parámetros con los atributos
	Paquete(Dispositivo ori_recibido, Dispositivo dest_recibido, string msje_recibido) {
        origen = ori_recibido;
		destino = dest_recibido;
        mensaje = msje_recibido;
    }
	string getMensaje(){ // método para obtener el mensaje
		return mensaje;
	}
	void mostrar();
};

// Implementación de los Métodos:

void Dispositivo::enviar_datos(Paquete p, Dispositivo d){
	cout << "Enviando: " << p.getMensaje() << " para: " << d.getNombre() << endl;
}

void Dispositivo::recibir_datos(Paquete p, Dispositivo d){
	cout << "Recibiendo: " << p.getMensaje () << "de: " << d.getNombre() << endl;
}

void Paquete::mostrar() {
	cout << "--- INFO DEL PAQUETE ---" << endl;
    cout << "Contenido: " << mensaje << endl; 
    // como origen es un Dispositivo, usamos el getter:
    cout << "Desde: " << origen.getNombre() << endl;
    cout << "Hacia: " << destino.getNombre() << endl;
    cout << "------------------------" << endl;	
}

// --- Main ---

int main () {

	
return 0;
}
