#include <stdio.h>

int main() {
    int n, i , cod, maior, menor;
    float vendas, aux1=0, aux2=10000000000;
    
    printf("Total de vendedores: ");
    scanf("%d", &n);
    
    for(i=1; i<=n; i++){
        printf("Código do %d vendedor: ", i );
        scanf("%d", &cod);
        printf("Vendas do %d vendedor: ", i );
        scanf("%f", &vendas);
        
        if (vendas <= 5000){
            printf("Comissão do %d vendedor: %.2f\n", i, (vendas*1.5)/100);
        } else
            if (vendas > 5000 && vendas < 15000){
                printf("Comissão do %d vendedor: %.2f\n", i, (vendas*3.5)/100);
            } else 
                if (vendas >= 15000){
                printf("Comissão do %d vendedor: %.2f\n", i, (vendas*4.7)/100);
            }
        printf("-----------------\n");
        
        if()
    }
    return 0;
}
  