#include <stdio.h>
#include <string.h>  // Para strlen() y strchr()

#define DIM 500  // Tamaño máximo de la cadena

// Función que verifica si una letra es vocal (A/a o E/e)
int esVocal(char letra) {
    return (letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e');
}

// Función para contar cuántas vocales (A/a o E/e) hay en total
int contarVocales(const char* cadena) {
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (esVocal(cadena[i])) {
            contador++;
        }
    }
    return contador;
}

int main() {
    char texto[DIM] = "Hola-A-todos*Esto-es-una-prueba*Vamos-A-ver*Como-funciona-Este-programa";

    // Mostrar longitud de la cadena
    int longitud = strlen(texto);
    printf("Longitud de la cadena: %d\n\n", longitud);

    // Mostrar cada oración en una línea, separadas por una línea en blanco
    printf("Texto separado por oraciones:\n\n");

    char copiaTexto[DIM];
    strcpy(copiaTexto, texto);  // Copiamos el texto porque strtok modifica la original

    char* oracion = strtok(copiaTexto, "*");
    while (oracion != NULL) {
        // Reemplazar '-' por espacio para mostrar palabras
        for (int i = 0; oracion[i] != '\0'; i++) {
            if (oracion[i] == '-') {
                oracion[i] = ' ';
            }
        }
        printf("%s\n\n", oracion);
        oracion = strtok(NULL, "*");
    }

    // Contar vocales A/a y E/e
    int totalVocales = contarVocales(texto);
    printf("Cantidad total de vocales A/a y E/e en el texto: %d\n\n", totalVocales);

    // Solicitar letra y verificar si es vocal y está en el texto
    char letra;
    printf("Ingrese una letra para verificar si es una vocal presente en la cadena: ");
    scanf(" %c", &letra);

    if (esVocal(letra)) {
        if (strchr(texto, letra) != NULL) {
            printf("La letra '%c' es una vocal (A/a o E/e) y está presente en el texto.\n", letra);
        } else {
            printf("La letra '%c' es una vocal pero NO está presente en el texto.\n", letra);
        }
    } else {
        printf("La letra '%c' no es una vocal válida (solo A/a o E/e).\n", letra);
    }

    return 0;
}
