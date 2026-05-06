#include <iostream>
#include <string>

using namespace std;

class Estudiante {
public:
    string nombre;
    
    void saludar() {
        cout << "Hola! Soy " << nombre << " y mi entorno de C++ funciona." << endl;
    }
};

int main() {
    // creo una instancia de la clase
    Estudiante yan;
    yan.nombre = "Yan";
    
    // llamo al método
    yan.saludar();

    return 0;
}