#include <stdio.h>

int calculo (int a, int b);

int main() {
    int n, d;
    printf("Vezes: %d", calculo(n, d));
    return 0;
}

int calculo (int a, int b){
    int x=0;
    do {
        printf("Numero 1: ");
        scanf("%d", &a);
        printf("Numero 2: ");
        scanf("%d", &b);
        if (b == a){
            x++;
        } 
    }while(b >=0 && b<=9);
   
    return x;
}
