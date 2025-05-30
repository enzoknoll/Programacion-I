#include <stdio.h>
#include <string.h>  // Para strlen()

#define TAM 4
#define MAX_ARRAY 50
#define MAX_CADENA 100

// Función: Determina si un número es divisible por 4
int esDivisiblePor4(int num) {
    return num % 4 == 0;
}

// Procedimiento: Ordenamiento burbuja del arreglo
void ordenarArreglo(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Procedimiento: Mostrar matriz
void mostrarMatriz(int mat[TAM][TAM]) {
    printf("Matriz:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Procedimiento: Mostrar arreglo
void mostrarArreglo(int arr[], int n) {
    printf("Arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

// Procedimiento: Verifica si la cadena es un palíndromo
void verificarPalindromo(char* cadena) {
    int len = strlen(cadena);
    int esPalindromo = 1;

    for (int i = 0; i < len / 2; i++) {
        if (cadena[i] != cadena[len - 1 - i]) {
            esPalindromo = 0;
            break;
        }
    }

    if (esPalindromo) {
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena NO es un palíndromo.\n");
    }
}

int main() {
    int matriz[TAM][TAM];
    int arreglo[MAX_ARRAY];
    int cantidad = 0;
    char cadena[MAX_CADENA] = "";

    // a) Cargar la matriz con números positivos
    printf("Ingrese valores para la matriz 4x4:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            do {
                printf("matriz[%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
            } while (matriz[i][j] <= 0);  // Solo positivos
        }
    }

    mostrarMatriz(matriz);

    // b) Cargar los números divisibles por 4 en un arreglo
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (esDivisiblePor4(matriz[i][j])) {
                arreglo[cantidad++] = matriz[i][j];
            }
        }
    }

    // c) Mostrar cantidad de elementos en arreglo
    printf("Cantidad de números divisibles por 4: %d\n\n", cantidad);
    mostrarArreglo(arreglo, cantidad);

    // d) Ordenar arreglo de menor a mayor
    ordenarArreglo(arreglo, cantidad);
    printf("Arreglo ordenado:\n");
    mostrarArreglo(arreglo, cantidad);

    // e) Crear cadena con vocales según regla
    for (int i = 0; i < cantidad; i++) {
        switch (arreglo[i]) {
            case 1:
                strcat(cadena, "A");
                break;
            case 4:
                strcat(cadena, "E");
                break;
            case 8:
                strcat(cadena, "I");
                break;
            case 12:
                strcat(cadena, "O");
                break;
            case 16:
                strcat(cadena, "U");
                break;
            default:
                break;
        }
    }

    // Mostrar cadena y verificar palíndromo
    if (strlen(cadena) > 0) {
        printf("Cadena generada: %s\n", cadena);
        printf("Longitud de la cadena: %lu\n", strlen(cadena));
        verificarPalindromo(cadena);
    } else {
        printf("No se generó ninguna cadena con vocales.\n");
    }

    return 0;
}
