/*
	Name: Conversor de horas, minutos e segundos
	Author: Aline
	Date: 07/10/19 18:29
	Description: leia um numero n que será os segundos e convertar para horas, minutos e segundos
*/

#include <stdio.h>

int main(){
	int n;
	int hora, min, seg;
	
	scanf("%d", &n);
	
	seg = n%60;
	n = n/60;
	min = n%60;
	n = n/60;
	hora = n;
		
	printf("%d:%d:%d\n", hora, min, seg);
	
	return 0;
}
