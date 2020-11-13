#include <stdio.h>
#include <stdlib.h>

//Assisnatura de Funcoes
void menu();
void sair();
int validar (int x, int n);
void num_validar(int t_valido);
void num_invalidar(int t_invalido);
void calcular_media(float media, int t_valido);
void maior_num(int maior);
void menor_num(int menor);
void regra_critica(int regra);

int main() {
    int opcao, n, i, x, valido=0, t_valido=0, t_invalido=0, maior=0, menor=10000, problema, regra, aux=0;
    float media=0;
    
    printf("Numero de vezes: ");
    scanf("%d", &n);
    printf("------------------\n");

    for (i=1; i<=n; i++){
        problema=0;
        do {
            valido = 0;
            printf("Numero %d: ", i);
            scanf("%d", &x);
            if (validar(x, n) == 1){ // Validar numero
                valido ++; 
                t_valido++; // Contar as vezes valido
                if (x > maior){ // Maior e Menor número 
                    maior = x;
                }

                if (x < menor){
                    menor = x;
                }

                media = media + x;  // Media    
                printf("------------------\n");
            } else if (validar(x, n) == 2){
                printf("Erro! %d é um número negativo\n", x);
                t_invalido++;
                problema++;
            } else if (validar(x, n) == 3){
                printf("Erro! %d é um número igual ou maior que o triplo de %d\n", x, n);
                t_invalido++;
                problema++;
            } else if (validar(x, n) == 4){
                printf("Erro! %d é um número primo\n", x);
                t_invalido++;
                problema++;
            }

            if (problema > aux){ // Regra mais critica
                aux = problema;
                regra = i;
            }
        }while (valido == 0);
    }
    
    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch(opcao){
            case 1:
                num_validar(t_valido);
            break;
            case 2:
                num_invalidar(t_invalido);
            break;
            case 3:
                calcular_media(media, t_valido);
            break;
            case 4:
                maior_num(maior);
            break;
            case 5:
               menor_num(menor);
            break;
            case 6:
                regra_critica(regra);
            break;
            case 7:
                sair();
            break;
            default:
                printf("Comando inválido! Digite um comando válido\n");
        }
        
    }while (opcao != 7);
    return 0;
}

void menu(){
    printf("MENU\n");
    printf("1 - Total de número válidos\n");
    printf("2 - Total de tentativas inválidas\n");
    printf("3 - Média\n");
    printf("4 - Maior\n");
    printf("5 - Menor\n");
    printf("6 - Regra mais crítica\n");
    printf("7 - Sair\n");
}

void sair(){
    printf("Até Mais!");
}

int validar (int x, int n){
    int a=0, i, val=0;
  
    for (i=1; i<=x; i++){
        if (x % i == 0){
            val++;
        }
	}
    
    if ((x >= 0) && (x < (n*3)) && (val != 2)){
        a=1;
    } else if (x < 0){
        a=2;
    } else if (x >= (n*3)){
        a=3;
    } else if (val == 2){
        a=4;
    }
    return a;
}

void num_validar(int t_valido){
    printf("Você selecionou a opcao 1 - Total de número válidos\n");
    printf("Digitado %d tentativa(s) válida(s)\n", t_valido);
}

void num_invalidar(int t_invalido){
    printf("Você selecionou a opcao 2 - Total de tentativas inválidas\n");
    printf("Digitado %d tentativa(s) inválida(s)\n", t_invalido);
}

void calcular_media(float media, int t_valido){
    printf("Você selecionou a opcao 3 - Média\n");
    printf("A média dos números: %.2f\n", (media/t_valido));
}

void maior_num(int maior){
    printf("Você selecionou a opcao 4 - Maior número\n");
    printf("O maior numero digitado: %d\n", maior);
}

void menor_num(int menor){
    printf("Você selecionou a opcao 5 - Menor número\n");
    printf("O menor numero digitado: %d\n", menor);
}

void regra_critica(int regra){
    printf("Você selecionou a opcao 6 - Regra mais crítica\n");
    printf("O numero(indice) que causou o maior problema: %d\n", regra);
}