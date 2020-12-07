#include <stdio.h>
#include <string.h>

    struct horario
    {
        int dia;
        int mes;
        int ano;
    };

int main(){
    struct horario data (struct horario x);
    
    struct horario agora;
    agora.dia = 06;
    agora.mes = 12;
    agora.ano = 2020;

    struct horario proxima;
    proxima = data(agora);

    printf("%d:%d:%d\n", proxima.dia, proxima.mes, proxima.ano);
    return 0;
}

struct horario data (struct horario x){
    printf("%d:%d:%d\n", x.dia, x.mes, x.ano);
    x.dia = 15;
    x.mes = 11;
    x.ano = 1999;
    return x;
}
