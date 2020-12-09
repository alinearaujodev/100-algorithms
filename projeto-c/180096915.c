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
void relatorio (struct Associado *x, int j);
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
                relatorio(copiado, i);
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
    bool achei = false;
    printf("--- Cadastrando Depedente ---\n");
    do {
        printf("ID: "); // INFORMAR ID DO ASSOCIADO
        scanf("%d", &id_associado);
        for(i=0; i<j; i++){
            if (id_associado == x[i+1].id){
                achei = true;
                do { // SABER NUMERO DE DEPEDENTE
                    printf("Quantos Depedentes: ");
                    scanf("%d", &x[i+1].qtdDep);
                    if (x[i+1].qtdDep < 0 || x[i+1].qtdDep > 3){
                        printf("Número inválido! Quantidade maxima de depedente é até 3\n");
                    }
                } while (x[i+1].qtdDep < 0 || x[i+1].qtdDep > 3);

                
                for (i=0; i<x[i+1].qtdDep; i++){
                    printf("-------------------------\n");
                    printf("Nome do %dº Depedente: ", i+1); // SABER NOME DO DEPEDENTE
                    getchar();
                    fgets(x[i+1].dep[i].nome, 20, stdin);    
                    do {
                        printf("Idade do %dº Depedente: ", i+1); // SABER IDADE DO DEPEDENTE
                        scanf("%d", &x[i+1].dep[i].idade);
                        if(x[i+1].dep[i].idade <=0){ // NAO VALIDAR IDADE NEGATIVA
                            printf("-------------------------\n");
                            printf("Idade não ser menor ou igual a 0, por favor insira uma idade válida.\n");
                        }
                    } while (x[i+1].dep[i].idade <= 0);    
                }

                system("clear || cls");
                //  LISTAR DEPEDENTES       
                for (i=0; i<x[i+1].qtdDep; i++){
                    printf("Lista dos Depedentes do Associado ID: %d\n", x[i+1].id);
                    printf("-------------------------\n");
                    printf("Nome do Depedente %d: %s", i+1, x[i+1].dep[i].nome);
                    printf("Idade do Depedente %d: %d\n", i+1, x[i+1].dep[i].idade);
                }
            }
        }
        if (achei == false){
            printf("ID não encontrado!\n");
        }
    }while (achei == false);
    
    return x[i+1];
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

// funcao para relatorio de associados
void relatorio (struct Associado *x, int j){
    int i, c, num_dep=0, num_nat=0, num_fut=0, num_ten=0, maior_aulas[25], aux=0;
    float mensalidade, tot_mensal=0, maior=0;
    char aux_nome[20];

    printf("--- Relatorio de Associados ---\n");
    // Numero de asscociados
    printf("Número total de associados cadastrados: %d\n", j);

    // Numero de Depedentes
    for(i=0; i<j; i++){
        if (x[i+1].qtdDep > 0){
            num_dep = num_dep + x[i+1].qtdDep;
        }
    }
    printf("Número total de dependentes cadastrados: %d\n", num_dep);

    // Número de associados que fazem aula de Natação
    for(i=0; i<j; i++){
        if (x[i+1].natacao == true){
            num_nat++;
        }
    }
    printf("Número de associados que fazem aula de Natação: %d\n", num_nat);

    // Número de associados que fazem aula de futsal
    for(i=0; i<j; i++){
        if (x[i+1].futsal == true){
            num_fut++;
        }
    }
    printf("Número de associados que fazem aula de Futsal: %d\n", num_fut);

    // Número de associados que fazem aula de tenis
    for(i=0; i<j; i++){
        if (x[i+1].tenis == true){
            num_ten++;
        }
    }
    printf("Número de associados que fazem aula de Tenis: %d\n", num_ten);

    for(i=0; i<j; i++){
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
        maior_aulas[i+1] = c;
    }

    // valor total de todas as mensalidades
    for (i=0; i<j; i++){
        mensalidade = 0;
        mensalidade = 100 + (x[i+1].qtdDep*50) + (maior_aulas[i+1]*30);
        tot_mensal = tot_mensal + mensalidade;
        // Saber o maior valor de mensalidade
        if (mensalidade > maior){
            maior = mensalidade;
        }
    }
    printf("Valor total de todas as mensalidades dos associados: %.2f\n", tot_mensal);

    // Media das Mensalidades
    printf("Valor médio das mensalidades dos associados: %.2f\n", tot_mensal/j);

    // Valor mais alto de mensalidade
    printf("Valor de mensalidade mais alto pago por um associado: %.2f\n", maior);

    // Nome que quem faz mais aulas
    printf("Nome do(s) associado(s) que fazem mais aulas:\n");
    for (i=0; i<j; i++){
        if (maior_aulas[i+1] > aux){
            aux = maior_aulas[i+1];
            strcpy(aux_nome, x[i+1].nome);
        }
    }
    printf("%s\n", aux_nome);
}

// funcao para sair do programa
void sair(){
    printf("Obrigado por ter usado o sistema, até mais!\n");
}