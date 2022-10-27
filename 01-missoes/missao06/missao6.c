#include <stdio.h>

int main(){
    int opcao, num, num2;
    float peso, altura, imc, n1, n2;
    
    printf("=== MENU ===\n");
    printf("1 - Informacoes\n");
    printf("2 - Calcular IMC\n");
    printf("3 - Par ou Impar \n");
    printf("4 - Multiplicação\n");
    printf("5 - Divisao\n");
    printf("6 - Sair\n");
    scanf("%d", &opcao);
    
    switch (opcao){
        case 1:
            printf("=== Informações ===\n");
			printf("Nome do Aluno: Aline de Araújo Diniz\n");
			printf("Matrícula do Aluno: 180096915\n");
			printf("Semestre do Aluno: 2019.2\n");
        break;
        case 2:
            printf("=== IMC ===\n");
			printf("Peso: ");
			scanf("%f", &peso);
			printf("Altura: ");
			scanf("%f", &altura);

			imc = peso / (altura * altura);

			printf("IMC: %2.f", imc);
        break;
        case 3:
            printf("=== Par ou Impar ===\n");
			printf("Digite um numero: ");
			scanf("%d", &num);

			if (num % 2 == 0) {
			    printf("%d é um numero par\n", num);
			} else {
			    printf("%d é um numero impar\n", num);
			}
        break;
        case 4:
            printf("=== Multiplicação ===\n");
			printf("Digite um numero: ");
			scanf("%d", &num);
			printf("Digite um numero: ");
			scanf("%d", &num2);
			printf("%d X %d = %d", num, num2, (num*num2));
        break;
        case 5:
            printf("=== Divisão ===\n");
			printf("Digite um numero: ");
			scanf("%f", &n1);
			printf("Digite um numero: ");
			scanf("%f", &n2);

			if ((n1 == 0 ) || (n2 == 0 )) {
			    printf("Número invalido !\n");
			} else {
			    printf("%.1f / %.1f = %.1f", n1, n2, (n1/n2));
			}
        break;
        case 6:
            printf("=== Saindo ===\n");
			printf("Tchau!\n");
        break;
        default:
            printf("Comando invalido !\n");
        break;
    }
    return 0;
}
