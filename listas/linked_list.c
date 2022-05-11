// Estructuras de datos
// Ejemplo practico y sencillo del manejo de las lista enlazadas vesión 2
// linked_list.c

// librerías
#include <stdio.h>
#include <stdlib.h>

// estructuras 
typedef struct dato {
    char nombre[10];
    struct dato *siguiente;
} Registro;


// principal
int main() {
    
    // variables
    Registro *lista = NULL;
    
    int i = 0, salir = 0;
    char continuar;

    while (salir == 0) {
        Registro *nuevoregistro, *auxiliar;
        nuevoregistro = (Registro *) malloc(sizeof(Registro));
        printf("Ingrese un nombre: ");
        scanf("%s", nuevoregistro->nombre);
        nuevoregistro->siguiente = NULL;

        if (lista == NULL) {
            lista = nuevoregistro;
        } else {
            auxiliar = lista;
            while (auxiliar->siguiente) {
                auxiliar = auxiliar->siguiente;
            }
            auxiliar->siguiente = nuevoregistro;
        }

    }

    while (lista->siguiente) {
        printf("Nombre: %s\n", lista->nombre);
        lista = lista->siguiente;
    }    
        

    return 0;
}
