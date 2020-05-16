# Informe TP2: Recolectores y Productores

**Martín Andrés Suarez**

**Padrón: 101.540**

**Repositorio: `https://github.com/martinsuarezz/taller-tp1`**

--------------

## Modelo general

El programa se basa en un hilo principal que se encarga de leer los archivos
entrada (mapa y distribución de trabajadores) mediante el uso de los objetos
MapParser y WorkerParser. Este hilo principal luego crea los trabajadores y
les pasa referencias a las colas de recursos, el inventario y el
almacenamiento de puntos de beneficio.

Luego de esto, el hilo principal espera y organiza la finalización de los
trabajadores y procede a imprimir por pantalla los resultados obtenidos.

## Modelado de los hilos de ejecución

Para implementar la ejecución multihilo desarrollé una clase abstracta
Thread que funciona de wrapper para los threads de C++. Posee las
funcionalidades basicas que permiten crearlo, ejecutarlo y esperar a su
finalización. El metodo Thread::start() comienza la ejecución del hilo
llamando al método Thread::run(). Este método es virtual puro, toda clase
que hereda de Thread debe implementarlo, colocando allí el código que se
desea ejecutar al correr el hilo.

Hice que hereden de esta clase Thread las siguientes clases:

* MainThread: ejecuta las funcionalidades ya descriptas en la sección de
_Modelo general_. Básicamente coordina toda la ejecución del programa.
* Gatherer: clase que modela a los recolectores. Reciben un puntero a una
cola bloqueante donde estarán los recursos que debe recolectar y una
referencia al inventario donde deben colocar los recursos recolectados.
* Producer: clase abstracta que modela a los productores. Al construirse
recibe una referencia al inventario y una referencia al contenedor de puntos
de beneficio (PointsStorage). Esta clase se encarga de obtener recursos
del inventario y agregar los correspondientes puntos de beneficio.
Polimórficamente las clases que heredan de Producer (Cooker, Carpenter y
Armourer) implementan este comportamiento.

## La lógica detrás de la finalización de la ejecución

Uno de los principales desafíos del trabajo práctico fue coordinar
la ordenada finalización de la ejecucción de todos los hilos.

Para que las clases (especialmente Producers y Gatherers) sepan cuando
finalizar la ejecución implementé que tanto las colas bloqueantes como
el inventario se puedan cerrar cuando no se le vayan a agregar más
recursos. Al cerrar estas estructuras los trabajadores
pueden seguir quitando recursos de las mismas. Sin embargo, si estas
están vacías saben que no vendrán nuevos recursos, dando el pie para que
detengan su ejecución.

El MapParser, la clase que se encarga de leer el mapa y agregar los
recursos a las colas bloqueantes se encarga de cerrarlas cuando finaliza.

Con respecto a cerrar el inventario, inicialmente había implementado la
siguiente solución: cuando, por ejemplo, un recolector veía que su cola
estaba cerrada y vacía, notificaba al inventario que no iba a recibir
más de ese tipo de recurso. Para lograr esto, implementé las clases
Farmer, Woodcutter y Miner. De esta manera, cada tipo de recolector
sabía que recurso del inventario cerrar. El Farmer notificaría que no
habría más trigo, el Woodcutter madera, mientras que el Miner avisaría
que no habría mas carbón o hierro.

Esta solución, sin embargo, tenía un problema debido a la ejecución
multihilo. Supongamos que existen dos Farmer, Farmer A y Farmer B.
Farmer A saca el último recurso de una cola cerrada de trigo. Luego
de esto, se le dá chance de ejecutarse al Farmer B. Este, al ver que
no hay mas trigo, y que la cola esta cerrada, le notifica al inventario
que no vendrá más trigo. Con esta información, productores como el
Cooker, pueden decidir cerrar su ejecución antes de tiempo.
El Farmer A todavía tiene su trigo que debe depositar en algún momento
en el inventario.

Debido a este problema debí ir a una solución más simple, y quizás,
menos elegante. Es el hilo principal el que espera que terminen todos
los recolectores para luego avisarle al inventario que no vendrá
más de ningún tipo de recurso. Al no necesitar ya las clases Farmer,
Woodcutter y Miner, las eliminé de mi modelo.
