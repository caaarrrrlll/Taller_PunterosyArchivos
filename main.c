#include <stdio.h>
#include "funciones.h"

#define MAX_OPCION 2

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    int numProductos = 0;
    char opcion_str[MAX_OPCION];
    char opcion;

    do {
        mostrarMenu();
        printf("Ingrese su opcion: ");
        if (scanf("%s", opcion_str) != 1) {
            printf("Error al leer la opcion. Inténtelo de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer de entrada
            continue;
        }

        opcion = opcion_str[0];

        switch (opcion) {
            case '1':
                mostrarProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '2':
                agregarProducto(nombres, precios, cantidades, &numProductos);
                break;
            case '3':
                editarProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '4':
                eliminarProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '5':
                venderProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '6':
                guardarEnArchivo(nombres, precios, cantidades, numProductos);
                break;
            case '7':
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intentelo de nuevo.\n");
        }

    } while (opcion != '7');

    return 0;
}

