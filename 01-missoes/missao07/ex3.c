#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade, c, cont_j=0;
    float peso, alt, m_idade=0,cont_a=0;
    
    for (c=1; c<=11; c++){
        printf("Altura do %d jogador: ", c);
        scanf("%f", &alt);
        printf("Peso do %d jogador: ", c);
        scanf("%f", &peso);
        printf("Idade do %d jogador: ", c);
        scanf("%d", &idade);
        
        m_idade = m_idade + idade;
        
        if(idade < 18){
            cont_j++;
        }
        
        if(alt < 1.70){
            cont_a++;
        }
        system("clear||cls");
    }
    
    
    printf("Quantidade de jogadores menores de 18 anos: %d\n", cont_j);
    printf("Média de idade dos jogadores: %.2f\n", (m_idade/11));
    printf("Percentual de jogadores menores de 1,70 de altura: %.1f", 100-(((11-cont_a)/11))*100);

    return 0;
}
