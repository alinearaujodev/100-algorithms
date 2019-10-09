/*
	Name: Divisão de x por y
	Author: aline
	Date: 07/10/19 15:00
	Description: divida x por y. OBS: preste atenção na formula pois usa um cast
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int N, X, Y, i;
	float divisao;
	
	scanf("%d", &N);
	getchar();
	
	for (i=1;i<=N;i++){
	    scanf("%d %d", &X, &Y);
	    getchar();
	    	if(Y==0){
			printf("divisao impossivel\n");
		} else {
	    	divisao = (float) X/Y;
	    	printf("%.1f\n", divisao);
		}
	}
	
	return 0;
}
