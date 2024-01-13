#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu() {
    printf("==== Menu ====\n");
    printf("1. Mostrar productos\n");
    printf("2. Agregar producto\n");
    printf("3. Editar producto\n");
    printf("4. Eliminar producto\n");
    printf("5. Vender producto\n");
    printf("6. Guardar en archivo\n");
    printf("7. Salir\n");
    printf("Ingrese su opcion: ");
}

void mostrarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos) {
    printf("\n*** Lista de productos ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    for (int i = 0; i < *numProductos; i++) {
        printf("%d. %s - Precio: %.2f - Cantidad: %d\n", i + 1, nombres[i], precios[i], cantidades[i]);
    }
}

void guardarEnArchivo(const char nombres[MAX_PRODUCTOS][MAX_NOMBRE], const float precios[MAX_PRODUCTOS], const int cantidades[MAX_PRODUCTOS], const int numProductos) {
    FILE *archivo = fopen("Inventario.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%s %.2f %d\n", nombres[i], precios[i], cantidades[i]);
    }

    fclose(archivo);
}

void agregarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos) {
    if (*numProductos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombres[*numProductos]);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &precios[*numProductos]);
        printf("Ingrese la cantidad en inventario: ");
        scanf("%d", &cantidades[*numProductos]);

        (*numProductos)++;
        printf("Producto agregado con exito.\n");
    } else {
        printf("El inventario está lleno. No se puede agregar mas productos.\n");
    }
}

void editarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos) {
    printf("\n*** Editar producto ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    mostrarProductos(nombres, precios, cantidades, numProductos);

    int seleccion;
    printf("Seleccione el número del producto que desea editar: ");
    scanf("%d", &seleccion);

    if (seleccion >= 1 && seleccion <= *numProductos) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", nombres[seleccion - 1]);
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &precios[seleccion - 1]);
        printf("Ingrese la nueva cantidad en inventario: ");
        scanf("%d", &cantidades[seleccion - 1]);
        printf("Producto editado con éxito.\n");
    } else {
        printf("Número de producto no válido.\n");
    }
}

void eliminarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos) {
    printf("\n*** Eliminar producto ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    mostrarProductos(nombres, precios, cantidades, numProductos);

    int seleccion;
    printf("Seleccione el número del producto que desea eliminar: ");
    scanf("%d", &seleccion);

    if (seleccion >= 1 && seleccion <= *numProductos) {
        for (int i = seleccion - 1; i < *numProductos - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            precios[i] = precios[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        (*numProductos)--;

        printf("Producto eliminado con exito.\n");
    } else {
        printf("Número de producto no valido.\n");
    }
}

void venderProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos){
    printf("\n*** Vender productos ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    mostrarProductos(nombres, precios, cantidades, numProductos);

    int seleccion;
    printf("Seleccione el número del producto que desea vender: ");
    scanf("%d", &seleccion);

    if (seleccion >= 1 && seleccion <= *numProductos) {
        int cantidadVender;
        printf("Ingrese la cantidad que desea vender: ");
        scanf("%d", &cantidadVender);

        if (cantidadVender > 0 && cantidadVender <= cantidades[seleccion - 1]) {
            cantidades[seleccion - 1] -= cantidadVender;
            printf("Venta realizada con éxito. Total a pagar: %.2f\n", precios[seleccion - 1] * cantidadVender);
        } else {
            printf("Cantidad no válida o insuficiente en inventario.\n");
        }
    } else {
        printf("Número de producto no válido.\n");
    }
}
