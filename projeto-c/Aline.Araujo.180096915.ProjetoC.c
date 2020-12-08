#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ASSINATURA DE FUNCOES 
void menu();
struct Associado cad_associado (struct Associado *x, int i);
struct Associado cad_depedente (struct Associado *x, int j);
void listarAssociado (struct Associado *x, int j);
void listarModalidade (struct Associado *x, int j);
void pesquisarAssociado (struct Associado *x, int j);
void sair();

// STRUCT PARA DEPEDENTE
struct Depedente{
    char nome[20];
    int idade;
};
    
// STRUCT PARA ASSOCIADO
typedef struct Associado{
    int id;
    char nome[20];
    int idade;
    int qtdDep;
    struct Depedente dep[3];
    bool natacao;
    bool futsal;
    bool tenis;
}new_associado, copia;

// PROGRAMA PRINCIPAL
int main(){
    // DECLARAÇÃO DE VARIAVEIS
    int opcao, i=0;

    // vetor para associado
    new_associado novo [25];
    copia copiado [25];

    printf("Seja Bem Vindo(a) ao Sistema de Gerência de Clube Esportivo\n");
    do {
        menu();
        scanf("%d", &opcao);
        system("clear || cls");
        switch (opcao){
            case 1:    
                i++;   
                copiado[i] = cad_associado(novo, i);
            break;
            case 2:
                cad_depedente(copiado, i);
            break;
            case 3:
                listarAssociado(copiado, i);
            break;
            case 4:
                listarModalidade(copiado, i);
            break;
            case 5:
                pesquisarAssociado(copiado, i);
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
struct Associado cad_associado (struct Associado *x, int i) {
    int nat_num, fut_num, ten_num;

    printf("--- Cadastrando Associado ---\n");
    printf("ID: "); // SABER ID DO ASSOCIADO
    scanf("%d", &x[i].id);

    printf("Nome do Associado: "); // SABER NOME DO ASSOCIADO
    getchar();
    scanf("%[^\n]s", x[i].nome);
    
    do {
        printf("Idade: ");
        scanf("%d", &x[i].idade);
        if(x[i].idade <=0){ // NAO VALIDAR IDADE NEGATIVA
            printf("-------------------------\n");
            printf("Idade não ser menor ou igual a 0, por favor insira uma idade válida.\n");
        }
    } while (x[i].idade <= 0);

    // Saber atividades esportivas
    printf("Qual atividade esportiva você realiza:\n");
    printf("[Sim = 1] ou [Não = 0]\n");

    // Não validar numero diferente de 1 ou 0
    // Natacao
    do { 
        printf("Natação: ");
        scanf("%d", &nat_num);
        if ((nat_num != 1) && (nat_num != 0)){
            printf("Número inválido! Por favor insira 1 para Sim ou 0 para Não\n");
            printf("-------------------------\n");
        } 

        if(nat_num == 1){
            x[i].natacao = true;
        }
    }while ((nat_num != 1) && (nat_num != 0));

    // Futsal
    do {
        printf("Futsal: ");
        scanf("%d", &fut_num);
        if ((fut_num != 1) && (fut_num != 0)){
            printf("Número inválido! Por favor insira 1 para Sim ou 0 para Não\n");
            printf("-------------------------\n");
        }

        if(fut_num == 1){
            x[i].futsal = true;
        }
    } while ((fut_num != 1) && (fut_num != 0));

    // Tenis
    do { 
        printf("Tênis: ");
        scanf("%d", &ten_num);
        if ((ten_num != 1) && (ten_num != 0)){
            printf("Número inválido! Por favor insira 1 para Sim ou 0 para Não\n");
            printf("-------------------------\n");
        } 

         if(ten_num == 1){
            x[i].tenis = true;
        }
    } while ((ten_num != 1) && (ten_num != 0));
    
    // Bug listagem de associado
    x[i].qtdDep = 0;
    return x[i];
}

// FUNCAO CADASTRAR DEPEDENTE
struct Associado cad_depedente (struct Associado *x, int j){
    int i, id_associado;
    printf("--- Cadastrando Depedente ---\n");
    do{
        printf("ID: "); // INFORMAR ID DO ASSOCIADO
        scanf("%d", &id_associado);
        if (id_associado != x[j].id){ // Não validar id diferente
            printf("ID não encontrado\n");
        }
    } while (id_associado != x[j].id);
    
    do { // SABER NUMERO DE DEPEDENTE
        printf("Quantos Depedentes: ");
        scanf("%d", &x[j].qtdDep);
        if (x[j].qtdDep > 3 || x[j].qtdDep < 0){
            printf("Número inválido! Quantidade maxima de depedente é até 3\n");
        }
    } while (x[j].qtdDep > 3 || x[j].qtdDep < 0);
    
    for (i=0; i<x[j].qtdDep; i++){
        printf("-------------------------\n");
        printf("Nome do %dº Depedente: ", i+1); // SABER NOME DO DEPEDENTE
        getchar();
        fgets(x[j].dep[i].nome, 20, stdin);    
        do {
            printf("Idade do %dº Depedente: ", i+1); // SABER IDADE DO DEPEDENTE
            scanf("%d", &x[j].dep[i].idade);
            if(x[j].dep[i].idade <=0){ // NAO VALIDAR IDADE NEGATIVA
                printf("-------------------------\n");
                printf("Idade não ser menor ou igual a 0, por favor insira uma idade válida.\n");
            }
        } while (x[j].dep[i].idade <= 0);    
    }

    system("clear || cls");
    //  LISTAR DEPEDENTES
    printf("Lista dos Depedentes do Associado ID: %d\n", x[j].id);
    for (i=0; i<x[j].qtdDep; i++){
        printf("-------------------------\n");
        printf("Nome do Depedente %d: %s", i+1, x[j].dep[i].nome);
        printf("Idade do Depedente %d: %d\n", i+1, x[j].dep[i].idade);
    }
    return x[j];
}

// FUNCAO PARA LISTAR ASSOCIADO
void listarAssociado (struct Associado *x, int j){
    int i;
    char nat[20];
    char fut [20];
    char ten[20];

    printf("--- Lista de Associados ---\n");
    for (i=0; i<j; i++){
        
        // Printar se faz ou não natacao
        if (x[i+1].natacao == true){
            strcpy(nat, "Faz Natação");
        } else {
            strcpy(nat, "Não Faz Natação");
        }
        // Printar se faz ou não futsal
        if (x[i+1].futsal == true){
            strcpy(fut, "Faz Futsal");
        } else {
            strcpy(fut, "Não Faz Futsal");
        }
        // Printar se faz ou não tenis
        if (x[i+1].tenis == true){
            strcpy(ten, "Faz Tenis");
        } else {
            strcpy(ten, "Não Faz Tenis");
        }
        printf("%d - %s - %d - %s - %s - %s\n", i+1, x[i+1].nome, x[i+1].qtdDep, nat, fut, ten);
    }
}

// FUNCAO PARA LISTAR ASSOCIADOS POR MODALIDADE 
void listarModalidade (struct Associado *x, int j){
    int modalidade, i;
    printf("--- Lista de Associados por modalidade ---\n");
    do {
        printf("Qual modalidade deseja selecionar: \n");
        printf("1 - Natação\n");
        printf("2 - Futsal\n");
        printf("3 - Tenis\n");
        scanf("%d", &modalidade);
        system("clear || cls");
        switch (modalidade){
            case 1:
                printf("--- Lista de Associados de Natação ---\n");
                // SABER A LISTA DE ASSOCIADOS DE NATACAO
                for (i=0; i<j; i++){
                    if (x[i+1].natacao == true){
                        printf("%d - %s\n", x[i+1].id, x[i+1].nome);
                    }
                } 
                break;
            case 2:
                printf("--- Lista de Associados de Futsal ---\n");
                // SABER A LISTA DE ASSOCIADOS DE FUTSAL
                for (i=0; i<j; i++){
                    if (x[i+1].futsal == true){
                        printf("%d - %s\n", x[i+1].id, x[i+1].nome);
                    }
                } 
                break;
            case 3: 
                printf("--- Lista de Associados de Tenis ---\n");
                // SABER A LISTA DE ASSOCIADOS DE TENIS
                for (i=0; i<j; i++){
                    if (x[i+1].tenis == true){
                        printf("%d - %s\n", x[i+1].id, x[i+1].nome);
                    }
                } 
                break;
            default:
                printf("Comando inválido! Tente Novamente\n");
                break;
        }
    } while (modalidade != 1 && modalidade != 2 && modalidade != 3);
}

// funcao para pesquisar o associado
void pesquisarAssociado (struct Associado *x, int j){
    char nome_pesquisa[20];
    int i, c=0;
    float mensalidade;
    bool achei = false;

    printf("--- Pesquisando Associado ---\n");
    printf("Nome do Associado a ser pesquisado: ");
    getchar();
    scanf("%[^\n]s", nome_pesquisa);

    // FAZER PESQUISA
    for (i=0; i<j; i++){
        if (strcmp(nome_pesquisa, x[i+1].nome) == 0){
            achei = true;
            c=0;
            // Contar as aulas
            if (x[i+1].natacao == true){
                c++;
            }
            if (x[i+1].futsal == true){
                c++;
            }
            if (x[i+1].tenis == true){
                c++;
            }

            // Saber valor da mensalidade
            mensalidade = 100 + (x[i+1].qtdDep*50) + (c*30);

            // Imprimir informações
            printf("Informações de %s\n", x[i+1].nome);
            printf("%d - %s - %d - %d - %d - R$%.2f\n", x[i+1].id, x[i+1].nome, x[i+1].idade, x[i+1].qtdDep, c, mensalidade);
        }
    }

    // Mostrar associado não encontrado
    if (achei == false){
        printf("Associado não encontado!\n");
    }
}

// funcao para sair do programa
void sair(){
    printf("Obrigado por ter usado o sistema, até mais!\n");
}