#include <stdio.h>
#include <stdlib.h>

void menu();
void sair();
float calquadrado (float x);
float calretangulo (float x, float y);
float calcirculo (float x);
float caltriangulo (float x, float y);

int main()
{
    int opcao;
    float base, alt, raio, lado;
    
    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch(opcao){
            case 1:
                printf("Area do Quadrado: %.2f\n", calquadrado(lado));
            break;
            case 2:
                printf("Area do Retângulo: %.2f\n", calretangulo(base, alt));
            break;
            case 3:
                printf("Area do Circulo: %.2f\n", calcirculo(raio));
            break;
            case 4:
                printf("Area do Triangulo: %.2f\n", caltriangulo(base, alt));
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
    printf("1- Quadrado\n");
    printf("2- Retângulo\n");
    printf("3- Circulo\n");
    printf("4- Triangulo\n");
    printf("5- Sair\n");
}

void sair(){
    printf("Tchau!");
}

float calquadrado (float x){
    printf("Lado: ");
    scanf("%f", &x);
    return x*x;
}

float calretangulo (float x, float y){
    printf("Base: ");
    scanf("%f", &x);
    printf("Altura: ");
    scanf("%f", &y);
    return y*x;
}

float calcirculo (float x){
    printf("Raio: ");
    scanf("%f", &x);
    return (3.14*(x*x));
}

float caltriangulo (float x, float y){
    printf("Base: ");
    scanf("%f", &x);
    printf("Altura: ");
    scanf("%f", &y);
    return (x*y)/2;
}
  