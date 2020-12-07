#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ASSINATURA DE FUNCOES 
void menu();
struct Associado cad_associado (struct Associado x);
struct Associado cad_depedente (struct Associado x);

void sair();

// STRUCT PARA DEPEDENTE
struct Depedente{
    char nome[20];
    int idade;
};
    
// STRUCT PARA ASSOCIADO
struct Associado{
    int id;
    char nome[20];
    int idade;
    int qtdDep;
    struct Depedente dep[3];
    bool natacao;
    bool futsal;
    bool tenis;
}new_associado, teste;

// PROGRAMA PRINCIPAL
int main(){
    // DECLARAÇÃO DE VARIAVEIS
    int opcao, i;

    printf("Seja Bem Vindo(a) ao Sistema de Gerência de Clube Esportivo\n");
    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch (opcao){
            case 1:       
                teste = cad_associado(new_associado);
            break;
            case 2:
                cad_depedente(teste);
            break;
            case 3:

            break;
            case 4:

            break;
            case 5:

            break;
            case 6:

            break;
            case 7:
                sair();
            break;
            default:
                printf("Comando Inválido! Digite um número válido.\n");
            break;
        }
    }while (opcao != 7);
    return 0;
}

// FUNCOES
void menu(){
    printf("-------------------------\n");
    printf("1. Cadastrar associado\n");
    printf("2. Cadastrar dependente\n");
    printf("3. Listar associados\n");
    printf("4. Listar associados por modalidade\n");
    printf("5. Pesquisar associados\n");
    printf("6. Gerar relatório de associados\n");
    printf("7. Finalizar Programa\n");
}

// FUNCAO CADASTRAR ASSOCIADO
struct Associado cad_associado (struct Associado x) {
    int nat_num, fut_num, ten_num;

    printf("--- Cadastrando Associado ---\n");
    printf("ID: "); // SABER ID DO ASSOCIADO
    scanf("%d", &x.id);

    printf("Nome do Associado: "); // SABER NOME DO ASSOCIADO
    getchar();
    fgets(x.nome, 20, stdin);
    
    do {
        printf("Idade: ");
        scanf("%d", &x.idade);
        if(x.idade <=0){ // NAO VALIDAR IDADE NEGATIVA
            printf("-------------------------\n");
            printf("Idade não ser menor ou igual a 0, por favor insira uma idade válida.\n");
        }
    } while (x.idade <= 0);

    // Saber atividades esportivas
    printf("Qual atividade esportiva você realiza:\n");
    printf("[Sim = 1] ou [Não = 0]\n");

    // Não validar numero diferente de 1 ou 0
    do { 
        printf("Natação: ");
        scanf("%d", &nat_num);
        if ((nat_num != 1) && (nat_num != 0)){
            printf("Número inválido! Por favor insira 1 para Sim ou 0 para Não\n");
            printf("-------------------------\n");
        }
    }while ((nat_num != 1) && (nat_num != 0));
    do {
        printf("Futsal: ");
        scanf("%d", &fut_num);
        if ((fut_num != 1) && (fut_num != 0)){
            printf("Número inválido! Por favor insira 1 para Sim ou 0 para Não\n");
            printf("-------------------------\n");
        }
    } while ((fut_num != 1) && (fut_num != 0));
    do { 
        printf("Tênis: ");
        scanf("%d", &ten_num);
        if ((ten_num != 1) && (ten_num != 0)){
            printf("Número inválido! Por favor insira 1 para Sim ou 0 para Não\n");
            printf("-------------------------\n");
        }
    } while ((ten_num != 1) && (ten_num != 0));
    
    return x;
}

// FUNCAO CADASTRAR DEPEDENTE
struct Associado cad_depedente (struct Associado x){
    int i, id_associado;
    printf("--- Cadastrando Depedente ---\n");
    do{
        printf("ID: "); // INFORMAR ID DO ASSOCIADO
        scanf("%d", &id_associado);
        if (id_associado != x.id){ // Não validar id diferente
            printf("ID não encontrado\n");
        }
    } while (id_associado != x.id);
    
    do { // SABER NUMERO DE DEPEDENTE
        printf("Quantos Depedentes: ");
        scanf("%d", &x.qtdDep);
        if (x.qtdDep > 3 || x.qtdDep < 0){
            printf("Número inválido! Quantidade maxima de depedente é até 3\n");
        }
    } while (x.qtdDep > 3 || x.qtdDep < 0);
    
    for (i=0; i<x.qtdDep; i++){
        printf("-------------------------\n");
        printf("Nome do %dº Depedente: ", i+1); // SABER NOME DO DEPEDENTE
        getchar();
        fgets(x.dep[i].nome, 20, stdin);    
        do {
            printf("Idade do %dº Depedente: ", i+1); // SABER IDADE DO DEPEDENTE
            scanf("%d", &x.dep[i].idade);
            if(x.dep[i].idade <=0){ // NAO VALIDAR IDADE NEGATIVA
                printf("-------------------------\n");
                printf("Idade não ser menor ou igual a 0, por favor insira uma idade válida.\n");
            }
        } while (x.dep[i].idade <= 0);    
    }

    system("clear || cls");
    //  LISTAR DEPEDENTES
    printf("Lista dos Depedentes do Associado ID: %d\n", x.id);
    for (i=0; i<x.qtdDep; i++){
        printf("-------------------------\n");
        printf("Nome do Depedente %d: %s", i+1, x.dep[i].nome);
        printf("Idade do Depedente %d: %d\n", i+1, x.dep[i].idade);
    }
    return x;
}

void sair(){
    printf("Obrigado por ter usado o sistema, até mais!\n");
}