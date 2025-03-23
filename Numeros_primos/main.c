#include <stdio.h>

int main() {
	int numero_usuario, es_primo;
		printf("Ingrese la cantidad de números primos que desea visualizar: ");
		scanf("%d", &numero_usuario);
		for(int i = 2; i<numero_usuario ; i++){
		    es_primo = 1;
			for (int c = 2; c * c <= i; c++) {
            if (i % c == 0) {
                es_primo = 0;
                break;
            }
        }
		    if (es_primo == 1){
		        printf("%d\n", i);
		    }
		}
	return 0;
}