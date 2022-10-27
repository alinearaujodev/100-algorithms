#include <stdio.h>
#include <math.h>

int main()
{
    int num, quad, cubo;
    float rq;
    
    printf("Número: ");
    scanf("%d", &num);
    
    if (num > 0){
        quad = pow(num,2);
        cubo = pow(num,3);
        rq = sqrt(num);
    
        printf("%d, %d, %d, %.2f",num, quad, cubo, rq);
    } else {
        printf("%d, 0, 0, 0", num);
    }

    return 0;
}