#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, i, j, num, tot=0, opcao, menor=100,maior=0, erro=0;
    float media=0;

    printf("Número: ");
    scanf("%d", &x);

    for(i=1; i<=x; i++){
        do {
            printf("%dº Numero: ", i);
            scanf("%d", &num);

            if(num < 0){
                printf("Erro, número negativo! Por favor, insira um número válido\n ");
            }

            if (num > 100){
                printf("Erro, número maior que 100! Por favor, insira um número válido\n ");
            }

            if (num % 3 == 0){
                printf("Erro, número multiplo de 3! Por favor, insira um número válido\n ");
            
            }
            if (num < 0 || num > 100 || num % 3 == 0){
                erro++;
            }
    
        }while(num < 0 || num > 100 || num % 3 == 0); 

        tot++;
        media = media + num;

        if (num > maior){
            maior = num;
        }

        if (num < menor){
            menor = num;
        }
    }
    do{
        printf("---MENU---\n");
        printf("1 - Total\n");
        printf("2 - Média\n");
        printf("3 - Maior\n");
        printf("4 - Menor\n");
        printf("5 - Número de regras quebradas\n");
        printf("6 - Sair\n");
        scanf("%d", &opcao);     
        system("clear||cls");

        switch (opcao){
            case 1:
                printf("Total dos números inseridos: %d\n", tot);
            break;
            case 2:
                printf("Média dos números inseridos: %.2f\n", media/tot);
            break;
            case 3:
                printf("Maior número inserido: %d\n", maior);
            break;
            case 4:
                printf("Menor número inserido: %d\n", menor);
            break;
            case 5:
                printf("Vezes que o usuário digitou um número inválido: %d\n", erro);
            break;
            case 6:
                printf("Tchau!\n");
            break;
            default:
                printf("Comando Inválido, insira um comando válido!\n");
        }
    }while (opcao != 6);
    return 0;
}