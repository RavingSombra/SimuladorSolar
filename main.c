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
    puts("+-CALCULADORA DE POUPANCA ENERGETICA-+");
    puts("| a Quanto gasta mensalmente         |");
    puts("| b Quanto gasta anualmente          |");
    puts("| c Media Diaria                     |");
    puts("|  / <a> <b> - compute a / b         |");
    puts("|  % <a> <b> - compute a % b         |");
    puts("+-Conversions -----------------------+");
    puts("|  h <x>     - x from dec to hex     |");
    puts("|  H <x>     - x from hex to dec     |");
    puts("|  o <x>     - x from dec to oct     |");
    puts("|  O <x>     - x from oct to dec     |");
    puts("|  c <x>     - x from hex to oct     |");
    puts("|  C <x>     - x from oct to hex     |");
    puts("+-Advanced --------------------------+");
    puts("|  ! <n>     - factorial of n        |");
    puts("|  b <n>     - plays buzz up to n    |");
    puts("+-Interface -------------------------+");
    puts("|  h         - print this menu       |");
    puts("|  q         - end program           |");
    puts("+------------------------------------+");


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
