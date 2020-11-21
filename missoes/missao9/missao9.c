    #include <stdio.h>
    #include <stdlib.h>

    void menu();

    int main (){
        int opcao, num[200], i=0, j, c=0, ed_i, ed_n, ex_i, soma=0;
        float media;
        do {
            menu();
            scanf("%d", &opcao);
            system("clear || cls");
            switch (opcao){
                case 1:
                    printf("--- Inserir Número ---\n");
                    printf("Número %d: ", i);
                    scanf("%d", &num[i]);
                    soma = soma + num[i];
                    i++;
                    c++;            
                break;
                case 2:
                    printf("--- Lista dos Números ---\n");
                    for (i=0; i<c; i++){
                        printf("Número %d: %d\n", i, num[i]);
                    }
                break;
                case 3:
                    printf("--- Editar Número ---\n");
                    printf("Nova Posição no número: ");
                    scanf("%d", &ed_i);
                    printf("Novo número: ");
                    scanf("%d", &ed_n);
                    for (i=0; i<c; i++){
                        if (i == ed_i){
                            num[i] = ed_n;
                        }
                    }
                break;
                case 4:
                    printf("--- Excluir Número ---\n");
                    printf("Posição do número: ");
                    scanf("%d", &ex_i);
                    for (i=ex_i; i<c; i++){
                        num[i] = num[i+1]; 
                    }
                    c--;
                    for (i=0; i<c; i++){
                        printf("Número %d: %d\n", i, num[i]);
                    }
                break;
                case 5:
                    printf("--- Lista dos números maiores que a média ---\n");
                    media = soma/c;
                    for (i=0; i<c; i++){
                        if (media < num[i]){
                            printf("%d\n", num[i]);
                        }
                    }
                break;
                case 6:
                    printf("Até mais!\n");
                break;
                default:
                    printf("Erro! Comando Inválido, por favor digite um número válido\n");
                break;
            }

        }while (opcao != 6);

        return 0;
    }

    void menu(){
        printf("--------------------\n");
        printf("1 - Inserir número\n");
        printf("2 - Listar números\n");
        printf("3 - Editar posição\n");
        printf("4 - Excluir posição\n");
        printf("5 - Listar números maiores que a média\n");
        printf("6 - Sair\n");
    }