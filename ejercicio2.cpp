/* 2.- Semaforos
Simularemos el comportamiento y sincronia de semáforos, simplificaremos un poco el diseño, teniendo 
en cuenta, que el semáforo posee tres luces, las cuales pueden estar encendidas o apagadas, solo
pueden estar de a dos en el mismo estado, o sea, rojo/amarillo, o verde/amarillo, que sera utilizada 
para la transición entre el rojo y verde.
En cada esquina hay dos semáforos, en determinado lapso de tiempo, ambos cambiaran de estado pero siempre
en contraposición, ejemplo:
Semaforo 				Semaforo B

	Rojo					Verde
	Rojo 					Verde/amarillo
	Rojo/amarillo			Rojo
	Verde					Rojo

Se debe determinar los objetos que participan, sus atributos, constructores, y los métodos necesarios en
cada uno.
Obviamente, no habrá una función timer autónoma, simplemente alcanzará con un método cambiar_estado, que
cada vez que se ejecute establezca a los semaforos en los estados arriba expuestos.
*/