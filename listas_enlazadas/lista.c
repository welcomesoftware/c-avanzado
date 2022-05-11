// Estructuras de Datos
// lista.c

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

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
    // si la cabeza esta vacía devuelve 1, en caso contrario devuelve 0
    return lista->cabeza == NULL;
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
    lista->longitud++;
}

// Insertar elementos al final de la lista.
void InsertarFinal(Lista *lista, Libro *libro) {
    Nodo *nodo = CrearNodo(libro);

    if (ListaVacia(lista)) { 
        lista->cabeza = nodo;
    } else {
        Nodo *apuntador = lista->cabeza;

        while (apuntador->siguiente) {
            apuntador = apuntador->siguiente;
        }
        apuntador->siguiente = nodo;
    }
    lista->longitud++;
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
    lista->longitud++;
}

// Obtener elementos en determinada posición de la lista.
Libro *Obtener(Lista *lista, int posicion) {
    if (ListaVacia(lista)) 
        return NULL;
    else {
        Nodo *apuntador = lista->cabeza;
        int indice = 0;

        while (indice < posicion && apuntador->siguiente) {
            apuntador = apuntador->siguiente;
            indice++;
        }
        if (indice == posicion)
            return &apuntador->libro;
        else
            return NULL;
    }
}

// Desplegar Lista de Libros completa
void DesplegarLista(Lista *lista) {
    Libro *ap_libro;
    for (int i = 0; i < lista->longitud; i++) {
        ap_libro = Obtener(lista, i);
        printf("Libro: %s\tAuthor: %s\tISBN:%s\n", 
                ap_libro->titulo, ap_libro->autor, ap_libro->isbn);
    }
}

// TODO: Revisar porque esta función no esta arrojando el resultado correcto
// Devuelve la longitud de una lista determinada
int ListaLongitud(Lista *lista) {
    return lista->longitud;
}

// Eliminar el primer elemetno de la lista
void EliminarPrimero(Lista *lista) {
    if (!ListaVacia(lista)) {
        Nodo *temporal = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(temporal);
        lista->longitud--;
    }
}

// Eliminar el ultimo elemetno de una lista determinada.
void EliminarUltimo(Lista *lista) {
    // Valída si la lista no esta vacia
    if (!ListaVacia(lista)) {
        // Valída si la lista contiene más de un elemento
        if (lista->cabeza->siguiente) {
            Nodo *temporal;
            Nodo *apuntador = lista->cabeza;

            while (apuntador->siguiente->siguiente) {
                apuntador = apuntador->siguiente;
            }
                                                      
            temporal = apuntador->siguiente;
            apuntador->siguiente = NULL;
            DestruirNodo(temporal);
            lista->longitud--;
        } else {
            Nodo *temporal = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(temporal);
            lista->longitud--;
        }
    }
}

// Eliminar un elemento especifico de la lista
void EliminarElemento(Lista *lista, int posicion) {
    // Valída si la lista no está vacía
    if (!ListaVacia(lista)) {
        // Valída si el elemento a eliminar es el primero
        if (posicion == 0) {
            Nodo *temporal = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(temporal);
            lista->longitud--;
        }
        // Valída si el elemento a eliminar no es mayor que la longitud
        // de elementos de la lista.
        else if (posicion < lista->longitud) {
            Nodo *temporal;
            Nodo *apuntador = lista->cabeza;
            int indice = 0;

            while (indice < (posicion - 1)) {
                apuntador = apuntador->siguiente;
                indice++;
            }

            temporal = apuntador->siguiente;
            apuntador->siguiente = apuntador->siguiente->siguiente;
            DestruirNodo(temporal);
            lista->longitud--;
        }
    }
}

