// Estructuras de Datos
// libro.h

// Defines
#ifndef _STDIO_H
#define _STDIO_H	1
#include <stdio.h>
#endif /* _STDIO_H */


#ifndef _LIBRO_H
#define _LIBRO_H    

typedef struct Libro {
    char titulo[50];
    char autor[50];
    char isbn[13];
} Libro;

#endif /* _LIBRO_H */
