#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MONTH 31

void input(char *nomeDoFicheiro);

void output(char nome[MAX], float kwDia, float irradiancia, float kwGasto, float area, int mes, int ano, char *resposta);

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

void output(char nome[MAX], float kwDia, float irradiancia, float kwGasto, float area, int mes, int ano, char *resposta) { }

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
void assistencia() {
    puts("A nossa linha telefonica de assistencia funciona nos dias uteis entre as 8 e as 18 horas.");
    puts("Se desejar desloque-se 'as nossas instalacoes.");
    puts("Contacto telefonico: 212345667");
    puts("Endereco eletronico: mundo.melhor@gmail.com");
    puts("Loja fisica perto de si: Rua poluida, lote 3");
}

int monthDays(int mes, int ano) {
    if (findBissexto(ano) == 2 && mes == 2) {
        return 29;
    }

    switch (mes) {
        case 'a':
            break;
        case 'm':
            break;
        case 'r':
            break;
        case 'g':
            break;
        case 'v':
            break;
        case 'p':
            break;
        case 's':
            break;
        case 't':
            break;
        case 'd':
            menu();
            break;
        case 'h':
            assistencia();
            break;
        case 'q':
            printf("Simulador encerrado");
            return 0;
        default:
            break;
    }

    return -1;
}
