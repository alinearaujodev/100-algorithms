#include <stdio.h>

int main()
{
    float kw, consumo;
    
    printf("Quantidade de KW consumida: ");
    scanf("%f", &kw);
    
    if (kw <=50){
        consumo = kw * 0.1918;
    } else if (kw >50 && kw <=100){
        consumo = kw * 0.3877;
    } else if (kw >50 && kw <=100){
        consumo = kw * 0.3877;
    } else if (kw > 100 && kw <=200){
       consumo = kw * 0.5566;  
    } else if (kw > 200){
        consumo = kw * 0.7834;
    }
    
    printf("O cosumo em KW foi: %.2f",consumo );
    
    return 0;
}