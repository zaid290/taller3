#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char nombres[10][50];
    float precios[10];
    int cantidades[10];
    int n, opcion;
    char nombreBuscado[50];

    do {
        printf("Cuantos productos desea ingresar (maximo 10)?\n");
        printf(">>");
        scanf("%d", &n);
        if (n < 1 || n > 10) {
            printf("Ingrese un numero entre 1 y 10.solo del 1 al 10.\n");
        }
    } while (n < 1 || n > 10);

    ingresarProductos(nombres, precios, cantidades, n);

    do {
        printf("\n      MENU      \n");
        printf("1. Mostrar total del inventario\n");
        printf("2. Mostrar producto mas caro\n");
        printf("3. Mostrar producto mas barato\n");
        printf("4. Mostrar precio promedio\n");
        printf("5. Buscar producto por nombre\n");
        printf("0. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Total del inventario: %.2f\n", calcularTotal(precios, cantidades, n));
                break;
            case 2: {
                int i = indiceMasCaro(precios, n);
                printf("Producto mas caro: %s (%.2f)\n", nombres[i], precios[i]);
                break;
            }
            case 3: {
                int i = indiceMasBarato(precios, n);
                printf("Producto mas barato: %s (%.2f)\n", nombres[i], precios[i]);
                break;
            }
            case 4:
                printf("Precio promedio: %.2f\n", calcularPromedio(precios, n));
                break;
            case 5:
                printf("Ingrese el nombre del producto: ");
                scanf("%s", nombreBuscado);
                buscarProducto(nombres, precios, cantidades, n, nombreBuscado);
                break;
            case 0:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opcion no encontrada.\n");
        }
    } while (opcion != 0);

    return 0;
}
//primero ctr + ñ
//gcc main.c funciones.c -o inventario.exe
//./inventario.exe
