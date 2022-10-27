#include <stdio.h>

int main(){
    float pe, polegada, jarda, milha;
    
    printf("Pé: ");
    scanf("%f", &pe);
    
    polegada = pe * 12;
    jarda = pe/3;
    milha = jarda/1760;
    
    printf("%.2f, %.2f, %f", polegada, jarda, milha);
    
    return 0;
}