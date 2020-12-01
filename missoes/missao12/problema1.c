#include <stdio.h>
#include <string.h>

typedef struct person {
    char name[20];
    int age;
    int mat;
}Person;

int main() {
    int i;
    Person aluno;
    
    for (i=0; i<3; i++){
        printf("Nome do aluno %d: ", i+1);
        fgets(aluno.name[i], 20,stdin);
        printf("Idade do aluno %d: ", i+1);
        scanf("%d", &aluno.age[i]);
        printf("Matricula do aluno %d: ", i+1);
        scanf("%d", &aluno.mat[i]);
    }
    
    for(i=0; i<3; i++){
        printf("Nome do aluno %d: %s", i+1, aluno.name[i]);
        printf("Idade do aluno %d: %d\n", i+1, aluno.age[i]);
        printf("Matricula do aluno %d: %d\n", i+1, aluno.mat[i]);

    }

    return 0;
}
  
