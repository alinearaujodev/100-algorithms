#include <stdio.h>

int main() {
    int n, i, j;
    int matriz[3][3];
    
    printf("N: ");
    scanf("%d", &n);
    
    for (i=0; i<=n; i++){
        for (j=0; j<=n; j++){
            printf("[%d] [%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    return 0;
}
  
