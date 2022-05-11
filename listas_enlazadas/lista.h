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
    int longitud;
} Lista;

// Prototipos
Nodo *CrearNodo(Libro *libro);
void DestruirNodo(Nodo *nodo);

int ListaVacia(Lista *lista);
int ListaLongitud(Lista *lista);

void InsertarPrincipio(Lista *lista, Libro *libro);
void InsertarFinal(Lista *lista, Libro *libro);
void InsertarDespues(Lista *lista, Libro *libro, int posicion);
void EliminarPrimero(Lista *lista);
void EliminarUltimo(Lista *lista);
void EliminarElemento(Lista *lista, int posicion);
void DesplegarLista(Lista *lista);

Libro *Obtener(Lista *lista, int posicion);

#endif
