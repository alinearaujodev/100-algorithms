#include <stdio.h>
#include <string.h>


int main (){
    char nome[30];
    int tam, c; 

    printf("Nome: ");
    fgets(nome, 30, stdin);
    tam = strlen(nome);

    for (c = tam; c >= 0; x--){
        printf("%c",nome[c]);
    }

    return 0;
}