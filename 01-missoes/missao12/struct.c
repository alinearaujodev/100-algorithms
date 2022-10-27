#include <stdio.h>
#include <string.h>

typedef struct pessoa {
    int idade;
    char nome[30];
}Pessoa;

int main() {
    Pessoa aluno;
    aluno.idade = 21;
    strcpy(aluno.nome, "Aline");
    printf("Nome: %s, Idade: %d", aluno.nome, aluno.idade);
    
    return 0;
}
  
