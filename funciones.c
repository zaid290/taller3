#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarProductos(char nombres[10][50], float precios[10], int cantidades[10], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);
        do{
        printf("Precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
        if (precios[i] < 0){
            printf("solo ingrese precios positivos\n");
        }
        }while (precios[i] < 0);
        do{
        printf("Cantidad del producto %d: ", i + 1);
        scanf("%d", &cantidades[i]);
        if (cantidades[i] < 0){
            printf("solo ingrese inventario positivo\n");
        }
        }while (cantidades[i] < 0);
    }
    return n;
}

float calcularTotal(float precios[10], int cantidades[10], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i] * cantidades[i];
    }
    return total;
}

int indiceMasCaro(float precios[10], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int indiceMasBarato(float precios[10], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] < precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

float calcularPromedio(float precios[10], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total / n;
}

int buscarProducto(char nombres[10][50], float precios[10], int cantidades[10], int n, char nombreBuscado[50]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto: %s\nPrecio: %.2f\nCantidad: %d\n", nombres[i], precios[i], cantidades[i]);
            return i;
        }
    }
    printf("Producto no encontrado.\n");
    return -1;
}
