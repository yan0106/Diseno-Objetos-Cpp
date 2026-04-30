/*Ejercicio:

==== PUNTO ====
--- Atributos --- 
- cor_x: int
- cord_y: int
--- Métodos ---
+ punto(void): void
+ set(int, int): bool
+ print(void): void
+ valida(int): bool

=== RECTANGULO ===
--- Atributos ---
- tope_izq: Punto
- tope_der: Punto
--- Métodos ---
+ rectangulo(int, int, int, int): void
+ print(void): void

Un rectángulo se compone de dos puntos.

Cuando se instancia el rectángulo, recibe las coordenadas x,y de cada uno de los puntos. Se instancian y setean.
Deben utilizarse solamente los métodos definidos en las clases.
print(), muestra en pantalla los valores de los atributos.
valida(int), verifica que el entero sea positivo
No es necesario que se realice un ingreso por teclado. Simplemente en el main se fijan los valores.
Ejemplo:

int main (){
    Rectangulo R(5, 4, 9, 2);
    R.print();
}

*/

