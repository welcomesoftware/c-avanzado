// Estructuras de Datos
// lista.h

// Definiciones
#ifndef _STDIO_H
#define _STDIO_H    
#include <stdio.h>
#endif 

#ifndef _LISTA_H
#define _LISTA_H   

#include "libro.h"

// Estructura del Nodo
typedef struct Nodo {
    Libro libro;
    struct Nodo *siguiente;
} Nodo;

// Estructura de la lista
typedef struct Lista {
    Nodo *cabeza;
} Lista;

#endif
