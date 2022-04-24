// Estructuras de Datos
// lista.c

// Librerías
#include "lista.h"
#include <stdlib.h>
#include <string.h>

// Crea un nodo a partir de los datos de un libro que le demos
Nodo *CrearNodo(Libro *libro) {
    // Crea un nodo y reserva espacion en memoria 
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));

    // Asigna los valores a los elementos en el nodo
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    strncpy(nodo->libro.autor, libro->autor, 50);
    strncpy(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;

    // Devuelve el nodo
    return nodo;
}

// Destruye un nodo que pasemos a la función
void DestruirNodo(Nodo *nodo) {
    free(nodo);
}

// Valída si una lista que le pasemos esta vacia o tiene elementos
int ListaVacia(Lista *lista) {
    if (lista->cabeza == NULL)
        return 1;
    else
        return 0;
}

// Inserta elementos al principio de la lista. 
void InsertarPrincipio(Lista *lista, Libro *libro) {

    Nodo *nodo = CrearNodo(libro);

    if (ListaVacia(lista)) {
        lista->cabeza = nodo;    
    } 
    else {
        nodo->siguiente = lista->cabeza;
        lista->cabeza = nodo;
    }
}

// Insertar elementos al final de la lista.
void InsertarFinal(Lista *lista, Libro *libro) {

    Nodo *nodo = CrearNodo(libro);

    if (ListaVacia(lista)) { 
        lista->cabeza = nodo;
    }
    else {
        Nodo *apuntador = lista->cabeza;

        while (apuntador->siguiente) {
            apuntador = apuntador->siguiente;
        }
        apuntador->siguiente = nodo;
    }
}

// Insertar elementos despues de otro elemento en  la lista.
void InsertarDespues(Lista *lista, Libro *libro, int posicion) {
    Nodo *nodo = CrearNodo(libro);

    if (ListaVacia(lista)) {
        lista->cabeza = nodo;
    } else {
        Nodo *apuntador = lista->cabeza;
        int indice = 0;

        // Mientras indice sea menor que la posición y apuntador.siguiente
        // contenga algun valor se recorrerá la lista.
        while (indice < posicion && apuntador->siguiente) {
            apuntador = apuntador->siguiente;
            indice++;
        }

        nodo->siguiente = apuntador->siguiente;
        apuntador->siguiente = nodo;
    }
}
