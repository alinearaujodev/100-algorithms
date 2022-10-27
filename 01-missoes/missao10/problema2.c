#include <stdio.h>
#include <string.h>

int main() {
   
    char nome[3][20], aux[20];
    int i, j;

    for (i = 0; i < 2; i++) {
        printf("Nome %i: ", i+1);
        scanf("%s", nome[i]);
    }


    for (i = 1; i < 2; i++) { /* 3 = qtde de palavras */
        for (j = 1; j < 2; j++) {
            // verifica se tem que ser depois, se for troca de posição
            if (strcmp(nome[j - 1], nome[j]) > 0) {
                strcpy(aux, nome[j - 1]);
                strcpy(nome[j - 1], nome[j]);
                strcpy(nome[j], aux);
            }
        }
    }

    // só mostrar a matriz
    for (i = 0; i < 2; i++){
        printf("\n%s", nome[i]);
    }
    
    return 0;
}