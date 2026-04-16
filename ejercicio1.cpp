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

class Dispositivo{

	string dir_ip;
	string nombre;
	string mascara;

public:
	Dispositivo(dir_ip, nombre, mascara){
        dir_ip = " ";
        nombre = " ";
        mascara = " ";
        cout << "Dispositivo inicializado" << endl;
    }
	void enviar_datos(Paquete, Dispositivo);
	void recibir_datos(Paquete, Dispositivo);

};

void enviar_datos(Paquete, Dispositivo) {
    cout << Dispositivo << " " << Paquete << endl;
}

void recibir_datos(Paquete, Dispositivo){
    cout << Paquete << " " << Dispositivo << endl;
}

class Paquete{

	Dispositivo origen;
	Dispositivo destino;
	string mensaje;

public:

	Paquete(Dispositivo, Dispositivo, string mensaje) {
        // Dispositivo
        // Dispositivo
        mensaje = " ";
    }
	void mostrar();


}

using namespace std;

int main () {

Dispositivo A;

vector <Dispositivo> red;

for (int i = 0; i < Dispositivo.size(); i++) {
    cout << Dispositivo[i] << endl;
}

return 0;
}
