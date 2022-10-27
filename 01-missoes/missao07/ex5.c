#include <stdio.h>

int main(void) {
  int n, positivo=0, negativo=0, cont=0;
  float media=0, p_positivo, p_negativo;
  char opcao;

  do {
    printf("Digite um número: ");
    scanf("%d", &n);

    // Contar todos os numeros
    cont++;

    // Contar os numeros positivos e negativos
    if(n >= 0){
      positivo++;
    } else {
      negativo++;
    }

    // Saber a media
    media = media + n;

    printf("Deseja continuar [S/N]? ");
    getchar();
    scanf("%c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  // Percentual 
  p_negativo = ((100/cont)*negativo)-(((cont-negativo)/cont)*100);
  p_positivo = ((100/cont)*positivo)-(((cont-positivo)/cont)*100);

  if (positivo == 0){
    p_positivo = 0;
  }

  if (negativo == 0){
    p_negativo = 0;
  }

  // Resultados
  printf("Média: %.2f\n", media/cont);
  printf("Números positivos: %d\n", positivo);
  printf("Números negativos: %d\n", negativo);
  printf("Percentual dos números positivos: %.2f\n",p_positivo);
  printf("Percentual dos números negativos: %.2f\n",p_negativo);
  return 0;
}