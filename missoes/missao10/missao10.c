#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASSINATURA DE FUNCOES
void menu();


// PROGRAMA PRINCIPAL
int main() {
    int opcao;
    char string [101];

    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch(opcao){
            case 1:
                printf("String: ");
                fgets(string, 101, stdin);
            break;
            case 2:
                printf("Número de Caracteres: %lu\n", strlen(string)); // MOSTAR NUMEROS DE CARACTERES DA STRING
                printf("String: %s\n", string); // IMPRIMIR STRING
            break;
            case 3:

            break;
            case 4:

            break;
            case 5:

            break;
            case 6:

            break;
            default:
                printf("Comando, Inválido, tente novamente\n");
            break;
        }


    }while(opcao != 6);

    return 0;
}

// FUNCAO DO MENU
void menu(){
    printf("----------------------\n");
    printf("1 - Testar string\n");
    printf("2 - Imprimir string\n");
    printf("3 - Imprimir de tras pra frente\n");
    printf("4 - Validar string\n");
    printf("5 - Modificar string\n");
    printf("6 - Sair\n");
}