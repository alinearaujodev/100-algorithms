/*
	Name: Distancia entre dois pontos
	Author: Aline 
	Date: 07/10/19 13:44
	Description: Leia dois pontos x e y. calcule com base na formula 
*/

#include <stdio.h>
#include <math.h>

int main(){
	
	float x1, x2, y1, y2;
	float distancia;
	float raiz = 0.0;
	
	scanf("%f", &x1);
	getchar();
	scanf("%f", &y1);
	getchar();
	scanf("%f", &x2);
	getchar();
	scanf("%f", &y2);
	getchar();
	
	distancia = ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1));
	
	raiz = sqrt(distancia);
	
	printf("%.4f\n", raiz);
	
	return 0;
}
