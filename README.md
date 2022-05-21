# TC1030 RAMPAGE
El proyecto tiene como objetivo demostrar el uso de clases, apuntadores, herencia, composición y agregación mediante un videojuego kaiju.

El videojuego es un juego de turnos tipo Pokemón. El juego iene una idea simple, hay una ciudad con un porcentaje de destrucción, siendo que este porcentaje de destrucción irá aumentando cada vez que un monstruo lo ataque. El jugador (ósease el que use el código) tendrá que llegar al porcentaje de destrucción de la ciudad al 100%. Cuando se llegue a este porcentaje, el juego termina. Sin embargo, no será tan sencillo, ya que la ciudad puede generar defensas de dos diferentes tipos que atacan a los monstruos para evitar la destrucción total de todo el lugar. 

## Funcionalidad
El programa hace uso de clases para poder crear los objetos requeridos para el juego. El código contiene tres clases padres o principales, las cúales son ciudad, defensa y monstruo. Cada uno cuenta con atributos y métodos únicos para poder cumplir su función. 

Defensa:
-Tiene vida, posición en la ciudad, fuerza de ataque  y un rango. El método disparar() ataca directamente a un objeto monstruo para hacer que el atributo vida del monstruo decremente. Mientras que el método activar_escudo() hace que el atributo vida del objeto Defensa no decremente a pesar de que sea atacado.

Ciudad:
-Tiene un porcentaje de destruccion, tamaño, defensas y un porcentaje de generación de defensas. Siendo que el tamaño sea un array de 2 valores, así formando un mapa en el cúal los otros objetos puedan estar ubicados. El porcentaje de generación de defensas consta en el porcentaje de que tantas unidades puede generar por turno o partida. Mientras que el array de defensas guardará las defensas, debido a que los objetos defensa son parte de la ciudad (uso de composición). 
Respecto a los métodos, sólo tenemos crear defensas, que será el método que cree objetos del tipo defensas para luego ser guardadas en el array de defensas.

Monstruo:
-Tiene vida, fuerza de ataque, posición (en dos ejes), nombre y un rango de ataque. Respecto a los métodos, el primero que es ataque(Defensa) hace que el atributo de un objeto defensa decremente. Moverse() es un método para que el monstruo pueda cambiar de posición en el mapa. Por último, este cuenta con el método destruir(Ciudad) para subir el porcentaje de destrucción del objeto ciudad.

Cada uno de estos objetos cuentan con sus accesor methods para poder funcionar.

La clase Defensa como Monstruo cuentan con clases hijas, siendo que cada una de ellas cuenta con una habiilidad especial.

La torre de hielo tiene como habilidad especial o métodos únicos el de congelar a un monstruo por un tiempo especificado, siendo que la congelación haga que el movimiento del monstruo en la ciudad sea menor. Mientras que el retroceso(), hace que la posición del monstruo cambie al azar.

El transporte cuenta con dos métodos especiales, siendo que es la única defensa que se puede mover y que puede lanzar un misil especial que hace un gran daño a la vida de los monstruos en el mapa. Este ataque que modifica la vida puede alcanzar cualquier posición de la ciudad.

El monstruo volador tiene tres métodos únicos, siendo que volar_y_huir() permite que el monstruo se aleje lo más posible de la defensa más cercana para proceder a recuperar toda su salud. Cuando el objeto monstruo usa este método, no puede usar otros métodos o funciones durante un set de turnos determinado. Con el uso del método curar(), puede modificar minimamente los atributos de vida de los otros monstruos. Con el método curarse(), puede aumentar una unidad al valor de su atributo vida-

El monstruo tanque tiene el método de proteger() y de ataque_destructor(). Proteger() hace que todas las defensas sólo lo puedan atacar a él durante un turno (mediante la modificación de atributo vida), mientras que ataque_destructor() consta de hacer un daño masivo a la estructura más cercana.

Por último el asesino puede usar el método extra_ataque (Defensa) para multiplicar el daño  que tiene por el número de defensas a las cuales les ha bajado el atributo vida a 0 de un objeto defensa. Mientras que mareo(Defensa), puede hacer que el ataque de un objeto defensa fallé con una probabilidad del 40%. 

El cambio o modificación de un atributo es hecho mediante el uso de apuntadores y accesor methods.

## Consideraciones
El programa solo corre en la consola y esta hecho con c++  por lo que corre en todos los sistemas operativos. Muchos atributos y objetos ya estarán declarados propiamente por el código y no por el jugador.
