// Aplicacion de ejemplo del uso de listas enlazadas

#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[]) {
    // variables
    Lista lista;
    Libro libro;

    int opcion;

    // inicialización
    lista.cabeza = NULL;

    // Menú
    puts("===================================================");
    puts("      SISTEMA DE ADMINISTRACION DE BIBLIOTECA      ");
    puts("===================================================");
    do {
        puts("(1) Ingresar libros, (2) Lista de libros, (3) Salir");
        puts("---------------------------------------------------");
        printf("¿Que desea hacer?: ");
        scanf("%d", &opcion);
        puts("===================================================");
        switch (opcion) {
            case 1:
                puts("DATOS DEL LIBRO:");
                puts("---------------------------------------------------");
                libro = LlenarLibro(libro);
                InsertarFinal(&lista, &libro);
                puts("===================================================");
                break;
            case 2:
                puts("LISTA DE LIBROS:");
                puts("---------------------------------------------------");
                DesplegarLista(&lista);
                puts("---------------------------------------------------");
                break;
            case 3:
                puts("              ¡Adiós, Vuelve pronto!               ");
                puts("===================================================");
                break;
            default:
                puts("¡Opción inválida! ingrese una Opción válida");
                puts("---------------------------------------------------");
                break;
        }

    } while (opcion != 3);


    // fin del programa
    return 0;
}
