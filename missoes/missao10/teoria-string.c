#include <stdio.h>
#include <string.h>


int main() {
    char nome1 [20];
    char nome2 [20] = "aline de Araujo";
    
    printf("Nome 1: ");
    fgets (nome1, 100, stdin);
    printf("Tamanho do nome 1: %lu\n", strlen(nome1));
    printf("%d\n", strcmp(nome1, nome2)); // Comparar 
    printf("%s\n", strstr(nome1, nome2)); // Verfica se string2 aparece na 1
    printf("%s\n", strcat(nome2, nome1)); // Concatena
    printf("Novo nome 1: %s\n", strcpy(nome1, nome2)); // Copiei a String nome2 para a nome1
    return 0;
}