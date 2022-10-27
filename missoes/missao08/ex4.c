#include <stdio.h>
#include <stdlib.h>

void menu();
void sair();
int somar (int x, int y);
int subtrair (int x, int y);
int multiplicar (int x, int y);
int dividir (int x, int y);

int main()
{
    int opcao, num1, num2;
    
    do {
        printf("Numero 1: ");
        scanf("%d", &num1);
        printf("Numero 2: ");
        scanf("%d", &num2);
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch(opcao){
            case 1:
                printf("Soma: %d\n", somar(num1, num2));
            break;
            case 2:
                printf("Subtração: %d\n", subtrair(num1, num2));
            break;
            case 3:
                printf("Multiplicação: %d\n", multiplicar(num1, num2));
            break;
            case 4:
                printf("Divisão: %d\n", dividir(num1, num2));
            break;
            case 5:
                sair();
            break;
            default:
                printf("Comando Invalido!\n");
        }
    }while(opcao != 5);

    return 0;
}

void menu(){
    printf("----------------\n");
    printf("1- Soma\n");
    printf("2- Subtração\n");
    printf("3- Multiplicação\n");
    printf("4- Divisão\n");
    printf("5- Sair\n");
}

void sair(){
    printf("Tchau!");
}

int somar (int x, int y){
    return x+y;
}

int subtrair (int x, int y){
    return x-y;
}

int multiplicar (int x, int y){

    return x*y;
}

int dividir (int x, int y){
    return x/y;
}