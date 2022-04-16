#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MONTH 31

void input(char *nomeDoFicheiro);

void
output(char nome[MAX], float kwDia, float irradiancia, float kwGasto, float area, int mes, int ano, char *resposta);

void menu();

int monthDays(int mes, int ano);

int findBissexto(int ano);

int main(void) {
    char nomeDoFicheiro[9];
    scanf(" %s", &nomeDoFicheiro);
    input(nomeDoFicheiro);
    //Variáveis

    puts("OK, ficheiro acedido sem problemas");
    //Imprimir o menu
    //menu();

    return 0;
}

//region Input
void input(char *nomeDoFicheiro) {
    FILE *ptr;
    char ch;

    // Opening file in reading mode
    ptr = fopen(nomeDoFicheiro, "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    char nome[8], opcao;
    float kwdia, inradiancia, kwgasto, area;
    int mes, ano;
    if (NULL != ptr) {
        printf("file can't be open1ed \n");
    }
    while (fscanf(ptr, " %s %c %f %f %f %f %d %d", &nome, &opcao, &kwdia, &inradiancia, &kwgasto, &area, &mes, &ano) ==
           3) {
        printf("%s %c %f %f %f %f\n", nome, opcao, kwdia, inradiancia, kwgasto, area, mes, ano);
    }
    fclose(ptr);
}

void
output(char nome[MAX], float kwDia, float irradiancia, float kwGasto, float area, int mes, int ano, char *resposta) {

}

void menu() {
    puts(" =====SIMULADOR DE PRODUCAO FOTOVOLTAICA===== ");
    puts(" |                                          | ");
    puts(" |_Registos_________________________________| ");
    puts(" |  a Adicionar consumo                     | ");
    puts(" |  m Modificar consumo                     | ");
    puts(" |  r Remover consumo                       | ");
    puts(" |                                          | ");
    puts(" |_Calculos_________________________________| ");
    puts(" |  g Média de consumo anual                | ");
    puts(" |  v Variancia de consumo verao vs inverno | ");
    puts(" |                                          | ");
    puts(" |_Simulacao________________________________| ");
    puts(" |  p Numero de paineis a instalar          | ");
    puts(" |  s Poupanca anual estimada               | ");
    puts(" |  t Tempo de retorno do investimento      | ");
    puts(" |                                          | ");
    puts(" |_Diversos_________________________________| ");
    puts(" |  d Imprimir este menu                    | ");
    puts(" |  h Solicitar assistencia                 | ");
    puts(" |  q Sair                                  | ");
    puts(" |                                          | ");
    puts(" ============================================ ");
}

/*int monthDays(int mes, int ano)
{
    if (findBissexto(ano) == 2 && mes == 2){
        return 29;
    }

    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        case 2: return 28;
    }

    return -1;
}

int findBissexto(int ano)
{
    if (ano % 4 == 0 && ano % 100 != 0)
        return 2;
    else if (ano % 400 == 0)
        return 2;
    else
        return 1;
}*/
