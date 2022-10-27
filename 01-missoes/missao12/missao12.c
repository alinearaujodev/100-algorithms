#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct Estudantes{
        char nome [20];
        int idade;
        float nota;
    } x[5][5];

    int linhas, colunas, i, j, linha_maior, linha_menor, coluna_maior, coluna_menor, pior_media, melhor_media;
    float maior_n=0, menor_n=10, media[25], aux1=0, aux2=10;

    // Saber linhas e colunas
    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);

    struct Estudantes;

    // Cadastro dos estudantes
    for (i=0; i<linhas; i++){
        media[i] = 0;
        for (j=0; j<colunas; j++){
            printf("Nome do Aluno [Linha %d] [Coluna %d]: ", i, j);
            getchar();
            fgets(x[i][j].nome, 20, stdin);

            printf("Idade do Aluno [Linha %d] [Coluna %d]: ", i, j);
            scanf("%d", &x[i][j].idade);

            do {
                printf("Nota do Aluno [Linha %d] [Coluna %d]: ", i, j);
                getchar();
                scanf("%f", &x[i][j].nota);
            } while (x[i][j].nota > 10 || x[i][j].nota < 0);

            // Saber menor e maior nota geral
            if (x[i][j].nota > maior_n){
                maior_n = x[i][j].nota;
                // Linha e Coluna da melhor nota
                linha_maior = i;
                coluna_maior = j;
            }
            if (x[i][j].nota < menor_n){
                menor_n = x[i][j].nota;
                // Linha e Coluna da pior nota
                linha_menor = i;
                coluna_menor = j;
            }
            // Soma das notas
            media[i] = media[i] + x[i][j].nota;
            printf("----------------------\n");
        }
        
        // Saber a linha com pior e melhor media das notas
        if (media[i]/colunas > aux1){
            aux1 = media[i]/colunas;
            melhor_media = i;
        }
        if (media[i]/colunas < aux2){
            aux2 = media[i]/colunas ;
            pior_media = i;
        }
    }

    // Apresentando informações
    printf("Maior Nota: %.2f\n", maior_n);
    printf("Linha e coluna do Estudante com a maior nota: [%d] [%d]\n", linha_maior, coluna_maior);
    printf("Menor Nota: %.2f\n", menor_n);
    printf("Linha e coluna do Estudante com a menor nota: [%d] [%d]\n", linha_menor, coluna_menor);
    printf("Linha com a maior média: [%d]\n", melhor_media);
    printf("Linha com a menor média: [%d]\n", pior_media);

    // Printando a matriz com as notas dos alunos
    printf("\nMatriz Geral das notas dos Alunos\n");
    for(i=0; i<linhas; i++){
        for (j=0; j<colunas; j++){        
            printf("Nota do Aluno [Linha %d] [Coluna %d]: %.2f\n", i, j, x[i][j].nota);
            printf("----------------------\n");
        }
    }
    return 0;
}