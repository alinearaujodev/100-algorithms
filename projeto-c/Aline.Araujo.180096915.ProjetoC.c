#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASSINATURA DE FUNCOES 
void menu();
void sair();

// PROGRAMA PRINCIPAL
int main(){
    int opcao;

    printf("Seja Bem Vindo(a) ao Sistema de Gerência de Clube Esportivo");
    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch (opcao){
            case 1:
            
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:

            break;
            case 6:

            break;
            case 7:
                sair();
            break;
            default:
                printf("Comando Inválido! Digite um número válido.\n");
            break;
        }
    }while (opcao != 7);
    return 0;
}

// FUNCOES
void menu(){
    printf("-------------------------\n");
    printf("1. Cadastrar associado\n");
    printf("2. Cadastrar dependente\n");
    printf("3. Listar associados\n");
    printf("4. Listar associados por modalidade\n");
    printf("5. Pesquisar associados\n");
    printf("6. Gerar relatório de associados\n");
    printf("7. Finalizar Programa\n");
}

void sair(){
    printf("Obrigado por ter usado o sistema, até mais!\n");
}