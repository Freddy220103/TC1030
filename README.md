# TC1030 RAMPAGE
El proyecto tiene como objetivo demostrar el uso de clases, apuntadores, herencia, composición, sobreescritura, sobrecarga, polimorfismo y agregación mediante un videojuego kaiju.

El videojuego es un juego de turnos tipo Pokemón. El juego tiene una idea simple, hay una ciudad con un porcentaje de destrucción, siendo que este porcentaje de destrucción irá aumentando cada vez que un monstruo lo ataque. El jugador (ósease el que use el código) tendrá que llegar al porcentaje de destrucción de la ciudad al 100%. Cuando se llegue a este porcentaje, el juego termina. Sin embargo, no será tan sencillo, ya que la ciudad puede generar defensas de dos diferentes tipos que atacan a los monstruos para evitar la destrucción total de todo el lugar. 

## Funcionalidad
El programa hace uso de clases para poder crear los objetos requeridos para el juego. El código contiene tres clases padres o principales y una clase llamada Ataque para hacer funcional el sistema de ataques y de vida. Las demás clases son ciudad, defensa y monstruo. Cada uno cuenta con atributos y métodos únicos para poder cumplir su función. 

Defensa:
 Tiene vida, nombre y fuerza de ataque . El método disparar() y activar_escudo() en la clase Defensa sólo sirven para comunicarse con el usuario en el juego. Siendo que saca a la consola strings mediante couts.  También existe el método herirse(fuerza), el cúal es llamado cuando un monstruo ataca, o en este caso la función de ataque de la clase Ataque es llamado (más adelante se explica). Este método también decrementa la vida de la defensa dependiendo de la fueza del monstruo que ataca.

Ciudad:
 Tiene un porcentaje de destruccion y defensas. El porcentaje de destrucción de la ciudad indica si el juego se termina en caso que este porcentaje llegue a 100. El array de defensas guardará las defensas, debido a que los objetos defensa son parte de la ciudad (uso de composición).  Respecto a los métodos, solamente tenemos crear defensas, que será el método que cree objetos del tipo defensas para luego ser guardadas en el array de defensas. Este método es privado ya que solamente se llama cuando se crea la ciudad mediante un constructor.
 
Monstruo:
 Tiene vida, fuerza de ataque, nombre. Respecto a los métodos, el primero que es ataque() comunica al usuario que su monstruo ha atacado a una defensa. El método destruir() comunica que el monstruo ha atacado la ciudad. Estos métodos son llamados por la clase ataque. Siendo que la funcionalidad de lo anterior esta definido por la clase ataque.
 
 Ataque:
 Esta clase fue hecha para evitar una dependencia circular entre Monstruo, Ciudad y Defensa. Tiene los métodos de ataque(Ciudad ciudad, Monstruo monstruo), ataque_especial(Ciudad ciudad, Monstruo monstruo), disparar(Ciudad ciudad, Monstruo monstruo) y destruir_ciudad(Ciudad ciudad, Monstruo monstruo). Cada parámetro debe ser un apuntador, para que modifique a su objeto original respectivo. Disparar, ataque_especial y ataque son método que cuando son llamados, mandan a llamar a la funcion herirse de cada clase a la cual se le quiera bajar la vida. Mientras que destruir_ciudad(), modifica el porcentaje de destrucción de la ciudad, tomando la fuerza del monstruo y restandosela al porcentaje de destrucción.

Cada uno de estas clases cuentan con sus accesor methods para poder funcionar.

La clase Defensa como Monstruo cuentan con clases hijas, siendo que cada una de ellas cuenta con una habiilidad especial.

La torre de hielo tiene como habilidad especial o métodos únicos el de congelar a un monstruo, siendo que la congelación haga que el movimiento ataque del monstruo pueda fallar.

El transporte cuenta con un método especial, siendo que es la única defensa que puede lanzar un misil especial que hace un gran daño a la vida de los monstruos. Este movimiento tiene un cooldown, así que no siempre puede ser usado.


El monstruo tanque tiene el método de proteger() y de ataque_destructor(). Proteger() hace que todas las defensas sólo lo puedan atacar a él durante un turno (mediante la modificación de atributo vida), mientras que ataque_destructor() consta de hacer un daño masivo a la estructura más cercana.

Por último el asesino sobreescribe el método ataque (Defensa) para multiplicar el daño  que tiene por el número de defensas a las cuales les ha bajado el atributo vida a 0 de un objeto defensa. Mientras que mareo(Defensa), puede hacer que el ataque de un objeto defensa fallé con una probabilidad del 40%. 

El cambio o modificación de un atributo es hecho mediante el uso de apuntadores y accesor methods.

## Consideraciones
El programa solo corre en la consola y esta hecho con c++  por lo que corre en todos los sistemas operativos. Muchos atributos y objetos ya estarán declarados propiamente por el código y no por el jugador.
