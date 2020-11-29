#include <stdio.h>
#include <string.h>

int main() {
    char nome[20];
    char nome2[] = "A";
    int i, tam, c=0, k;

    printf("String: ");
    fgets(nome, 20, stdin);
    
    tam = strlen(nome);

    k = strcmp(nome,nome2);
    for (i=0; i <= tam; i++){
        if (k == 0){
            c++;         
        }
    }
    printf("Quantidades de vogais %d\n", c);
    return 0;
}