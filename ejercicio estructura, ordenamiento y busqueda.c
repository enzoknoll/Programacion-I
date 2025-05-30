#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct productos {
    int numero_producto;
    char nombre_producto[50];
    int cantidad_stock;
};

void cargar_productos(struct productos *producto, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el NÚMERO del %d° producto: ", i + 1);
        scanf("%d", &producto[i].numero_producto);
        printf("Ingrese el NOMBRE del %d° producto: ", i + 1);
        scanf(" %49[^\n]", producto[i].nombre_producto);
        printf("Ingrese la CANTIDAD en stock del %d° producto: ", i + 1);
        scanf("%d", &producto[i].cantidad_stock);
    }
}

void ordenar_productos(struct productos *producto, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (producto[j].numero_producto > producto[j + 1].numero_producto) {
                struct productos temp = producto[j];
                producto[j] = producto[j + 1];
                producto[j + 1] = temp;
            }
        }
    }
}

void buscar_producto(struct productos *producto, int n, int numero_buscar) {
    int bajo = 0;
    int alto = n - 1;
    int encontrado = 0;
    while (bajo <= alto) {
        int medio = (bajo + alto) / 2;
        if (producto[medio].numero_producto == numero_buscar) {
            encontrado = 1;
            printf("Producto encontrado: %d - %s - Cantidad en stock: %d\n", producto[medio].numero_producto, producto[medio].nombre_producto, producto[medio].cantidad_stock);
            break;
        } else if (producto[medio].numero_producto < numero_buscar) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void mostrar_productos(struct productos *producto, int n) {
    printf("Contenido del arreglo de productos:\n");
    printf("--------------------------------------------------\n");
    printf("|%-10s |%-20s|%-10s|\n", "N°", "Nombre Producto", "Stock");
    for (int i = 0; i < n; i++) {
        printf("|%-10d|%-20s|%-10d|\n", producto[i].numero_producto, producto[i].nombre_producto, producto[i].cantidad_stock);
    }
}

void generar_cadena_productos(struct productos *producto, int n) {
    char cadena[100] = "";
    for (int i = 0; i < n; i++) {
        strcat(cadena, producto[i].nombre_producto);
        if (i < n - 1) {
            strcat(cadena, "*");
        }
    }
    strcat(cadena, ".");
    printf("Cadena de productos: %s\n", cadena);
}

int main() {
    struct productos producto[10];
    int n, numero_buscar;
    // Ingresar el número de productos
    printf("Ingrese el número de productos: ");
    scanf("%d", &n);

    // cargar el arreglo de estructuras
    cargar_productos(producto, n);

    // Ordenar el arreglo por número de producto
    ordenar_productos(producto, n);

    // Ingresar un número de producto a buscar
    printf("\nIngrese el número de producto a buscar: ");
    scanf("%d", &numero_buscar);
    buscar_producto(producto, n, numero_buscar);
    printf("\n");

    // Mostrar el contenido del arreglo de estructuras
    mostrar_productos(producto, n);

    // Generar una cadena de caracteres con los nombres de los productos
    generar_cadena_productos(producto, n);
    
    return 0;
}
    
/*
dado un arreglo de estructuras que tiene los siguiente elementos, numero de producto, nombre del producto, cantidad de productos en stock, se pide:
A- cargar el arreglo de estructura.
B- ordenar el arreglo o número de producto.
C- ingresar un número de producto por teclado e indicar si esta en arreglo.
D- mostrar el contenido de arreglo de estructura.
E- generar una cadena de caracteres que indique el nombre del producto separados por un asterisco y finalizando con un ".".
*/
