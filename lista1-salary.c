/*
	Name: Salary
	Author: Aline
	Date: 07/10/19 11:11
	Description: leia num do funcionario, horas trabalhadas e valor da hora e calcule e imprima o salario e num.
*/

#include <stdio.h>

int main(){
	int num, horas_t;	
	float salary=0, val_t;
	
	scanf("%d", &num);
	getchar();
	scanf("%d", &horas_t);
	getchar();
	scanf("%f", &val_t);
	getchar();
	
	salary = horas_t * val_t;

	
	printf("NUMBER = %d\n", num);
	printf("SALARY = U$ %.2f\n", salary);

	return 0;
}
