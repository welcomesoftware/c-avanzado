# Estructuras de datos

Son las distintas estructuras que utilizamos para representar la información
en el ordenador, ya conocemos los arreglos pero estas no son los únicos tipos
de estructuras que existen. Existen estructuras propias para almacenar otros 
tipos de información más compleja.

## Listas enlazadas

Una lista enlazada es una estructura de datos que permite representar un grupo
de elementos como si fuere una secuencia. Existen algunas diferencias entre las
Listas enlazadas y los arreglos. En nuestra lista enlazada agregamos nuestro 
elemento dentro de una estructura llamada **Nodo**, estos a su vez, apuntan al
siguiente nodo dentro de la lista. Básicamente una lista es un grupo de nodos
apuntados entre sí. 

Tenemos un nodo principal que es al que llamamos **cabeza | HEAD**, es el unico
que debemos conocer para poder trabajar con una lista. Para acceder al resto de
nodos, solo tenemos que acceder a los apuntadores **siguiente** de cada uno de 
los nodos. En las Listas enlazadas, lo que no es **HEAD** se le denomina **cola
| QUEUE**, las colas tambien son listas que tienen su propia cabeza y su propia
cola.

### Ventajas de las lista enlazadas

1. Los nodos no tienen porque guardarse todos juntos en memoría, como con
los arreglos; lo único que importa es que cada nodo debe de apuntar al 
siguiente nodo a través de un apuntador.
2. Los nodos pueden tener longitud variable, esto no pasa con los arreglos 
ya que estos tienen una longitud fija.
3. Nada nos impide agregar y eliminar elementos.

### Desventajas de las listas enlazadas vs arreglos

1. Las listas no tienen noción de índice por lo cual no podremos hacer accesos
aleatorios.
2. Necesitan más espacio en memoria ya que se deben que almacenar los 
apuntadores.

### Ejemplos

Este Ejemplo funciona en lenguajes funcionales como **haskell, lisp**

**LIBRO**

```
ESTRUCTURA libro
    nombre : CADENA[50]
    autor  : CADENA[50]
    isbn   : CADENA[13]
FIN ESTRUCTURA
```

**LISTA**

```
ESTRUCTURA lista
    cabeza : libro
    cola   : APUNTADOR a la lista
FIN ESTRUCTURA
```

Existe una forma más sencilla de almacenar elementos de una lista, es utilizando
dos estructuras; una estructura **NODO** que contiene un apuntador al siguiente
nodo y una estructura llamada lista que contiene una **cabeza** que es un 
apuntador al primer nodo de la lista. 

```
ESTRUCTURA nodo
    elemento  : libro
    siguiente : APUNTADOR a nodo
FIN ESTRUCTURA

ESTRUCTURA lista
    cabeza : APUNTADOR a nodo
FIN ESTRUCTURA
```

### Lo que podemos hacer con las listas enlazadas

1. Crear un nodo.

```
FUNCIÓN CrearNodo(l: Libro): Nodo
    VARIABLE nuevoNodo: Nodo

    nuevoNodo.elemento = l
    nuevoNodo.siguiente = NULO
    DEVOLVER nuevoNodo
FIN FUNCIÓN
```

2. Recorrer una lista.

```
FUNCIÓN RecorrerLista(l: Lista)
    VARIABLE apuntador: Nodo
    
    apuntador = l.cabeza

    MIENTRAS (apuntador != NULO)
        ProcesarElemento(apuntador.elemento)
        apuntador = apuntador.siguiente
    FIN MIENTRAS

FIN FUNCIÓN
```

2. Insertar elementos en una lista vacía.

```
FUNCIÓN InsertarNodo(l: Lista, n: Nodo)

    SI (l == NULO)
        l.cabeza = NULO

        VARIABLE nuevoNodo: Nodo

        nuevoNodo.elemento = n
        nuevoNodo.siguiente = NULO
        l.cabeza = nuevoNodo
    FIN SI

FIN FUNCIÓN
```

3. Insertar elementos al principio de la lista.

```
FUNCIÓN InsertarPrincipio(l: Lista, n: Nodo)
    VARIABLE nuevoNodo: Nodo

    nuevoNodo.elementos = n
    nuevoNodo.siguiente = l.cabeza
    l.cabeza = nuevoNodo
FIN FUNCIÓN    
```

4. Insertar elementos al final de la lista.

```
FUNCIÓN InsertarFinal(l: Lista, n: Nodo)
    VARIABLE nuevoNodo: Nodo
    
    nuevoNodo.elemento = n
    nuevoNodo.siguiente = NULO

    SI (l.cabeza == NULO)
        l.cabeza = nuevoNodo
    SINO
        VARIABLE apuntador: Nodo

        apuntador = l.cabeza

        MIENTRAS (apuntador != NULO)
            apuntador = apuntador.siguiente
        FIN MIENTRAS

        apuntador.siguiente.siguiente = nuevoNodo

    FIN SI

FIN FUNCIÓN
```

5. Eliminar el primer elemento de una lista.

```
FUNCIÓN EliminarPrimero(l: Lista)
    VARIABLE temporal: Nodo

    temporal = l.cabeza
    l.cabeza = l.cabeza.siguiente

    ELIMINAR temporal
FIN FUNCIÓN
```

6. Eliminar el ultimo elemento de la lista.

```
FUNCIÓN EliminarUltimo(l: Lista)
    VARIABLE temporal: Nodo
    VARIABLE apuntador: Nodo

    apuntador = l.cabeza

    MIENTRAS (apuntador != NULO)
        apuntador = apuntador.siguiente
    FIN MIENTRAS

    temporal = apuntador.siguiente
    apuntador.siguiente = NULO
    ELIMINAR temporal 
FIN FUNCIÓN
```

7. Eliminar un elemento especifico de la lista.

```
FUNCIÓN EliminarElemento(l: Lista, e: elemento)
    VARIABLE temporal: Nodo
    VARIABLE apuntador: Nodo

    apuntador = l.cabeza

    MIENTRAS (apuntador.siguiente != e)
        apuntador = apuntador.siguiente
    FIN MIENTRAS

    temporal = apuntador.siguiente
    apuntador.siguiente = apuntador.siguiente.siguiente
    ELIMINAR temporal
FIN FUNCIÓN
```
