#include <stdio.h>

int main(){
	
	int num1, num2, num3, menor;
	
	printf("Numero 1: ");
	scanf("%d", &num1);
 	 menor=num1;

	printf("Numero 2: ");
	scanf("%d", &num2);

	printf("Numero 3: ");
	scanf("%d", &num3);   

	  if(num2 < menor){
	    menor = num2;
	  } else if(num3 < menor){
	    menor = num3;
	  }

	  printf("Menor numero: %d", menor);
	  return 0;
} 
