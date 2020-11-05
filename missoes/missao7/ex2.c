#include <stdio.h>

int main() {
    int i, n, fem=0,masc=0;
    char sexo;
    float hora, media_f=0, media_m=0;
    
    printf("Número de professores: ");
    scanf("%d", &n);
    
    for (i=1; i<=n; i++){
        printf("Sexo do %d professor: ", i);
        getchar();
        scanf("%c", &sexo);
        printf("Hora/aula do %d professor: ", i);
        scanf("%f", &hora);
        
        if (sexo == 'm' || sexo == 'M'){
            masc++;
            media_m = media_m + hora;
        } else
            if(sexo == 'f' || sexo == 'F'){
                fem++;
                media_f = media_f + hora;
            }
    }
    
    printf("Média das Professoras: %.2f \n", media_f/fem);
    printf("Média das Professoras: %.2f \n", media_m/masc);
    return 0;
}
  