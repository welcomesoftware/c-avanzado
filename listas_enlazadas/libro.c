// Estructuras de Datos
// libro.c 

// Librerías
#include <stdio.h>
#include "libro.h"

// Pide al usuario la información de una cantidad determinada de libros
// y los llena.
Libro LlenarLibro(Libro libro) {
    printf("Ingrese el titulo del libro: ");
    scanf("%s", libro.titulo);
    printf("Ingrese el autor del libro: ");
    scanf("%s", libro.autor);
    printf("Ingrese el isbn del libro: ");
    scanf("%s", libro.isbn);
    return libro;
}
