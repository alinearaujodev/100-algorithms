#include <stdio.h>

int main()
{
    float nota1, nota2, nota3, peso1, peso2, peso3, mp;

    printf("Nota 1: ");
    scanf("%f", &nota1);
    printf("Peso 1: ");
    scanf("%f", &peso1);
    printf("Nota 2: ");
    scanf("%f", &nota2);
    printf("Peso 2: ");
    scanf("%f", &peso2);
    printf("Nota 3: ");
    scanf("%f", &nota3);
    printf("Peso 3: ");
    scanf("%f", &peso3);
    
    if ((peso1+peso2+peso3) == 10 && (nota1 && nota2 && nota3 > 0)){
        mp = (nota1*peso1) + (nota2*peso2) + (nota3*peso3); 
        printf("Média Ponderada: %.1f", mp/(peso1+peso2+peso3));
    } else{
        printf("ERRO!");
    }
    
    return 0;
}