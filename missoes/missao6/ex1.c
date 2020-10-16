#include <stdio.h>

int main()
{
    float num;
    
    printf("Temperatura em Celsius: ");
    scanf("%f", &num);

    printf("Temperatura em Fahrenheit: %.1f", (num * 9/5) + 32);
    return 0;
}