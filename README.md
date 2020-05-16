# Informe TP2: Recolectores y Productores

**Martín Andrés Suarez**

**Padrón: 101.540**

**Repositorio: `https://github.com/martinsuarezz/taller-tp1`**

--------------

## Modelo general

El programa se basa en un hilo principal que se encarga de leer los archivos entrada (mapa y distribución de trabajadores) mediante el uso de los objetos MapParser y WorkerParser. Este hilo principal luego crea los trabajadores y les pasa referencias a las colas de recursos, el inventario y el almacenamiento de puntos de beneficio.

Luego de esto, el hilo principal espera y organiza la finalización de los trabajadores y procede a imprimir por pantalla los resultados obtenidos.

