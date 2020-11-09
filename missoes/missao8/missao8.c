#include <stdio.h>
#include <stdlib.h>

void menu();
void sair();
int validar (int x, int n);

int main() {
    int opcao, n, i, x, valido=0;
    
    printf("Numero de vezes: ");
    scanf("%d", &n);
    printf("------------------\n");
    for (i=1; i<=n; i++){
        do {
            valido = 0;
            printf("Numero %d: ", i);
            scanf("%d", &x);
            validar(x, n);
            if (validar(x,n == 1)){
               valido ++; 
            }
        }while (valido == 0);
    }
    
    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch(opcao){
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
                printf("Comando inválido! Digite um comando válido\n");
        }
        
    }while (opcao != 7);
    return 0;
}

void menu(){
    printf("------------------\n");
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
    int a, i, val=0;
    
    for (i=1; i<=x; i++){
        if (x % i == 0){
            val++;
        }
	}
    
    if ((x >= 0) && (x < (n*3)) && (val != 2)){
        a=1;
    }
    return a;
}
