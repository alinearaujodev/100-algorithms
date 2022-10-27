    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // ASSINATURA DE FUNCOES
    void menu();

    // PROGRAMA PRINCIPAL
    int main() {
        int opcao, c, valida, tam, ok;
        char string [101], teste[101], caracter_antigo, caracter_novo;

        printf("String: ");
        fgets(string, 101, stdin);

        do {
            menu();
            scanf("%d", &opcao);
            system("clear || cls");
            switch(opcao){
                case 1:
                    printf("String Teste: "); // String de Teste
                    getchar();
                    fgets(teste, 101, stdin);       
                    strcpy(string, teste);      
                break;
                case 2:
                    printf("Número de Caracteres: %lu\n", strlen(string)-1); // MOSTAR NUMEROS DE CARACTERES DA STRING
                    printf("String: %s", string); // IMPRIMIR STRING
                break;
                case 3:
                    printf("String de trás pra frente: ");  
                    for (c = strlen(string)-1; c >= 0; c--){ // IMPRIMIR DE TRÁS PRA FRENTE
                        printf("%c",string[c]);
                    }
                    printf("\n");
                break;
                case 4:
                    valida = 0;
                    ok = 0;
                    tam = strlen(string);
                    if(tam-1 >= 10){ // SABER SE STRING TEM PELO MENOS 10 CARACTERES
                        valida++;
                    }

                    for(c=0; c<1; c++){ // SABER SE A STRING COMECA COM VOGAL
                        if(string[c] == 97 || string[c] == 101 || string[c] == 105 || string[c] == 111 || string[c] == 117){
                            valida++;                                
                        }
                    }

                    for (c=0; c<=tam-1; c++){ // SABER SE A STRING TEM SOMENTE LETRAS MINUSCULAS
                        if(string[c]>= 97 && string[c]<= 122){
                            ok++;
                        }
                    }

                    if (ok == tam-1){
                        valida++;
                    }

                    if (valida ==3){ // Saber se string é valida ou invalida
                        printf("A string é Válida!\n");
                    } else {
                        printf("A string é inválida\n");
                    }
                break;
                case 5:
                    strcpy(string, teste); // String escopo global
                    printf("String: %s", string);
                    printf("Antigo Caracter: ");
                    getchar();
                    scanf("%c", &caracter_antigo);
                    printf("Novo Caracter: ");
                    getchar();
                    scanf("%c", &caracter_novo);
                    for(c=0; c<= tam-1; c++){ // Modificar string
                        if (string[c] == caracter_antigo){
                            string[c] = caracter_novo;
                        }
                    }
                    getchar();
                    printf("String Nova: %s", string);
                break;
                case 6:
                    printf("Até mais!\n"); // SAIR DO PROGRAMA
                break;
                default:
                    printf("Comando Inválido, tente novamente\n");
                break;
            }


        }while(opcao != 6);

        return 0;
    }

    // FUNCAO DO MENU
    void menu(){
        printf("----------------------\n");
        printf("1 - Testar string\n");
        printf("2 - Imprimir string\n");
        printf("3 - Imprimir de tras pra frente\n");
        printf("4 - Validar string\n");
        printf("5 - Modificar string\n");
        printf("6 - Sair\n");
    }