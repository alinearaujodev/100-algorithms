#include <stdio.h>
#include <math.h>

int x1 (int a, int b, int c);
int x2 (int a, int b, int c);

int main() {
    int a, b, c;
    
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);
    printf("C: ");
    scanf("%d", &c);
    printf("X1 = %d\n", x1(a,b,c));
    printf("X2 = %d\n", x2(a,b,c));
    return 0;
}

int x1 (int a, int b, int c){
    int x1, delta;
    delta = pow(b,2)-(4*a*(c));
    if (delta >=0){
        x1 = (-b+sqrt(delta))/2*a;
        
    }
    return x1;
}

int x2 (int a, int b, int c){
    int x2, delta;
    delta = pow(b,2)-(4*a*(c));
    if (delta >=0){
        x2 = (-b-sqrt(delta))/2*a;
    }
    return x2;
}
  