# Estructuras de datos

Son las distintas estructuras que utilizamos para representar la información
en el ordenador, ya conocemos los arreglos pero estas no son los únicos tipos
de estructuras que existen. Existen estructuras propias para almacenar otros 
tipos de información más compleja.

## Colas

Son estructuras de datos como en la vida real, funcionan igual como cuando 
hacemos cola en un banco, el primero en llegar es el primero en salir. Una cola
se puede componer a partir de una lista enlazada, unimos los nodos desde el 
principio hasta el final por medio de apuntadores. Sólo que las operaciones son
esencialmente distintas.

### Operaciones sobre una cola

1. Encolar: Introducir algo en la cola, los elementos se introducen en la cola 
por el final. Podemos encolar elementos agregándolos al final de nuestra lista.
2. Procesar: Es lo mismo a decir **Consultar** lo cuál significa obtener el 
siguiente elemento de la cola. En una cola el siguiente elemento siempre estará
al principio de la lista. 
3. Eliminar: Echar el siguiente elemento de la cola una vez que ha sido 
eliminado. Como los elementos avanzan hacia adelante, hay que quitar la cabeza.

### Optimizaciones

```
ESTRUCTURA cola
    cabeza : APUNTADOR a nodo
    final  : APUNTADOR a nodo
FIN ESTRUCTURA
```

### Resumen

1. Encolar: insertar al final.
2. Consultar: obtener la cabeza de la cola.
3. Eliminar: eliminar la cabeza de la cola.

4. Despachar: operación dual, extrae el primer elemento, lo elimina de la cola,
y luego lo devuelve para ser procesado por el programa que lo llamó.

```
FUNCIÓN Despachar(Cola: cola): Nodo
    VARIABLE n: Nodo
    n = ObtenerPrimero(cola)
    EliminarPrimero(cola)
    DEVOLVER n 
FIN FUNCIÓN
```

