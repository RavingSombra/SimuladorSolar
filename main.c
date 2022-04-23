#include <stdio.h>
#include <string.h>
#include <math.h>

//region constantes
//Inteiros
#define YEAR 12
#define PANEL_COST 400
#define DEFAULT_VALUE (-1)

const char distrito[][17] = { "VianaDoCastelo", "Braga", "VilaReal", "Braganca", "Porto", "Aveiro", "Viseu", "Guarda", "Coimbra", "CasteloBranco", "Leiria", "Lisboa", "Santarem", "Portalegre", "Evora", "Setubal", "Beja", "Faro" };
//Strings
const char distritoInvalido[] = {"O distrito indicado nao existe. A fechar...\n"};
const char arrayNaoPreenchido[] = { "Registos em falta.\n" };
const char invalidOption[] = {"Opcao invalida, escolha outra vez\n"};
const char invalidMonth[] = {"Mes invalido!\n"};
const char invalidOperationAdd[] = {"Ja' existe um registo para este mes\n"};
const char invalidOperationMod[] = {"Ainda nao existe um registo para este mes\n"};
const char exitProgram[] = {"Simulador encerrado\n"};
//endregion

//region Funções
void menu();

void escolha(char c, int* arrayRegistos, char nome[], char regiao[], int ano);

void opcaoA(int* arrayResgisto);

void opcaoM(int* arrayResgisto);

void opcaoR(int* arrayResgisto);

void opcaoG(int* arrayRegistos, int ano);

void opcaoV(int* arrayResgistoS);

void opcaoP(int* arrayResgisto, char distrito[], char nome[]);

void opcaoS(int* arrayResgisto, char distrito[]);

void opcaoT(int* arrayResgisto, char distrito[]);

int radiacaoPorDistrito(char distrito[]);

int validaDistrito(char distritoInserido[]);

int entreAB(int x, int inf, int sup);

void inicializaArray(int* arrint, int fim, int defaultValue);

void MostraArray(int v[], int fim);

int estaPreenchido(int* arrayResgisto, int fim);

int calcMedia(int vals[], int qtd);

int calcNumPaineis(int* arrayResgisto, char distrito[]);
//endregion

int main(void) {
    char opcao;
    char distritoInserido[17], nome[10];
    int ano;
    int arrayRegistos[YEAR];

    scanf(" %9s %16s %d", nome, distritoInserido, &ano);

    if (validaDistrito(distritoInserido) == 1) {
        puts(distritoInvalido);
        return 0;
    }

    inicializaArray(arrayRegistos, YEAR, -1);
    menu();

    do {
        if (scanf(" %c", &opcao) == 0) {
            printf("erro");
        }
        escolha(opcao, arrayRegistos, nome, distritoInserido, ano);
    } while (opcao != 'q');

    return 0;
}

//region Menu itself
void menu() {
    puts(" =====SIMULADOR DE PRODUCAO FOTOVOLTAICA===== ");
    puts(" |                                          | ");
    puts(" |_Registos_________________________________| ");
    puts(" |  a Adicionar consumo                     | ");
    puts(" |  m Modificar consumo                     | ");
    puts(" |  r Remover consumo                       | ");
    puts(" |                                          | ");
    puts(" |_Calculos_________________________________| ");
    puts(" |  g Media de consumo anual                | ");
    puts(" |  v Variancia de consumo verao vs inverno | ");
    puts(" |                                          | ");
    puts(" |_Simulacao________________________________| ");
    puts(" |  p Numero de paineis a instalar          | ");
    puts(" |  s Poupanca anual estimada               | ");
    puts(" |  t Tempo de retorno do investimento      | ");
    puts(" |                                          | ");
    puts(" |_Diversos_________________________________| ");
    puts(" |  f Imprimir o consumo por mes            | ");
    puts(" |  d Imprimir este menu                    | ");
    puts(" |  h Solicitar assistencia                 | ");
    puts(" |  q Sair                                  | ");
    puts(" |                                          | ");
    puts(" ============================================ ");
}

void assistencia() {
    puts("A nossa linha telefónica de assistência funciona nos dias úteis entre as 8 e as 18 horas.");
    puts("Se desejar desloque-se ás nossas instalações.");
    puts("Contacto telefónico: 212345667");
    puts("Endereço eletrónico: mundo.melhor@gmail.com");
    puts("Loja física perto de si: Rua poluída, lote 3");
}

void escolha(char c, int* arrayRegistos, char nome[], char regiao[], int ano) {
    switch (c) {
        case 'a':
            opcaoA(arrayRegistos);
            break;
        case 'm':
            opcaoM(arrayRegistos);
            break;
        case 'r':
            opcaoR(arrayRegistos);
            break;
        case 'g':
            opcaoG(arrayRegistos, ano);
            break;
        case 'v':
            opcaoV(arrayRegistos);
            break;
        case 'p':
            opcaoP(arrayRegistos, regiao, nome);
            break;
        case 's':
            opcaoS(arrayRegistos, regiao);
            break;
        case 't':
            opcaoT(arrayRegistos, regiao);
            break;
        case 'd':
            menu();
            break;
        case 'h':
            assistencia();
            break;
        case 'f':
            MostraArray(arrayRegistos, YEAR);
            break;
        case 'q':
            printf(exitProgram);
            return;
        default:
            puts(invalidOption);
            menu();
            break;
    }
}
//endregion

//region Registos
void opcaoA(int *arrayResgisto) {
    int mes;
    int consumo;
    scanf(" %d %d", &mes, &consumo);

    if (entreAB(mes, 0, YEAR + 1) == 0) {
        puts(invalidMonth);
        return;
    }

    if (arrayResgisto[mes - 1] != -1) {
        puts(invalidOperationAdd);
        return;
    }

    for (int i = 0; i < YEAR; i++) {
        if (mes - 1 == i) {
            arrayResgisto[i] = consumo;
        }
    }
}

void opcaoM(int* arrayResgisto) {
    int mes;
    int consumo;

    scanf(" %d %d", &mes, &consumo);

    if (arrayResgisto[mes - 1] == -1) {
        puts(invalidOperationMod);
        return;
    }

    if (entreAB(mes, 0, YEAR + 1)) {
        for (int i = 0; i < YEAR; i++) {
            if (mes - 1 == i) {
                arrayResgisto[i] = consumo;
            }
        }
    }
}

void opcaoR(int* arrayResgisto) {
    int mes;

    scanf(" %d", &mes);
    if (entreAB(mes, 0, YEAR + 1)) {
        for (int i = 0; i < YEAR; i++) {
            if (mes - 1 == i) {
                arrayResgisto[i] = DEFAULT_VALUE;
            }
        }
    }

}
//endregion

//region Calculos
void opcaoG(int* arrayRegistos, int ano) {
    int media = calcMedia(arrayRegistos, YEAR);
    printf("Durante o ano de %d foram consumidos em média %d kWh por mês\n", ano, media);
}

void opcaoV(int* arrayResgisto) {
    int media = 0;
    int media1 = 0;
    int media2 = 0;
    int delta = 0;
    int delta1 = 0;

    if (estaPreenchido(arrayResgisto, YEAR) == 0) {
        puts(arrayNaoPreenchido);
        return;
    }

    for (int i = 0; i < YEAR; i++) {
        if(arrayResgisto[i]>=0) {
            if (i >= 10 || i <= 1) {
                media = media + arrayResgisto[i];
            } else if (i >= 4 && i <= 7) {
                media1 = media1 + arrayResgisto[i];
            } else {
                media2 = media2 + arrayResgisto[i];
            }
        }
    }

    media = media / 4;
    media1 = media1 / 4;
    media2 = media2 / 4;
    delta = media - media2;
    delta1 = media1 - media2;
    printf("Consumo tipico: %d \nConsumo em época de frio: %d (delta= %d ) \nConsumo em época de calor: %d (delta= %d )\n", media2, media, delta, media1, delta1);
}
//endregion

void opcaoP(int* arrayResgisto, char regiao[], char nome[]) {
    int roofArea, numSolarPanels;

    if (estaPreenchido(arrayResgisto, YEAR) == 0) {
        puts(arrayNaoPreenchido);
        return;
    }

    scanf(" %d", &roofArea);

    //calcular o numero de paineis necessario para a producao anual
    numSolarPanels = calcNumPaineis(arrayResgisto, regiao);

    if (numSolarPanels * 2 > roofArea) {
        puts("Area do telhado inferior 'a area de paineis necessaria para a producao ideal face ao consumo indicado\n");
    }
    else {
        printf("É recomendado instalar %d paineis fotovoltaicos na propriedade de %s.\n", numSolarPanels, nome);
    }
}

void opcaoS(int* arrayResgisto, char regiao[]) {
    int anualProduction, numSolarPanels;
    float anualRadiation, kwhCost, anualSavings;

    if (estaPreenchido(arrayResgisto, YEAR) == 0) {
        puts(arrayNaoPreenchido);
        return;
    }

    scanf(" %f", &kwhCost);

    //calcular o num de kWh produzidos pelo numero de paineis solares
    anualRadiation = radiacaoPorDistrito(regiao) * 0.25;
    numSolarPanels = calcNumPaineis(arrayResgisto, regiao);
    anualProduction = anualRadiation * numSolarPanels;
    anualSavings = anualProduction * kwhCost;

    printf("Com a instalação de %d paineis e uma poupanca de %d kWh/ano, terá uma poupanca anual de %.2f euros.\n", numSolarPanels, anualProduction, anualSavings);
}

void opcaoT(int* arrayResgisto, char regiao[]) {
    int anualProduction, numSolarPanels;
    float anualRadiation, kwhCost, anualSavings;

    if (estaPreenchido(arrayResgisto, YEAR) == 0) {
        puts(arrayNaoPreenchido);
        return;
    }

    scanf(" %f", &kwhCost);

    //calcular o num de kWh produzidos pelo numero de paineis solares
    anualRadiation = radiacaoPorDistrito(regiao) * 0.25;
    numSolarPanels = calcNumPaineis(arrayResgisto, regiao);
    anualProduction = anualRadiation * numSolarPanels;
    anualSavings = anualProduction * kwhCost;

    printf("O investimento em paineis solares terá retorno apos %.1f anos de funcionamento.\n", (PANEL_COST*numSolarPanels) / anualSavings);
}

//region Funções auxiliares
int radiacaoPorDistrito(char regiao[]) {
    if (strcmp(distrito[0], regiao) == 1) { //Viana do Castelo
        return 1557;
    }
    else if (strcmp(distrito[1], regiao) == 1) { //Braga
        return 1574;
    }
    else if (strcmp(distrito[2], regiao) == 1) { //Vila Real
        return 1572;
    }
    else if (strcmp(distrito[3], regiao) == 1) { //Bragança
        return 1646;
    }
    else if (strcmp(distrito[4], regiao) == 1) { //Porto
        return 1628;
    }
    else if (strcmp(distrito[5], regiao) == 1) { //Aveiro
        return 1617;
    }
    else if (strcmp(distrito[6], regiao) == 1) { //Viseu
        return 1636;
    }
    else if (strcmp(distrito[7], regiao) == 1) { //Guarda
        return 1700;
    }
    else if (strcmp(distrito[8], regiao) == 1) { //Coimbra
        return 1642;
    }
    else if (strcmp(distrito[9], regiao) == 1) { //Castelo Branco
        return 1805;
    }
    else if (strcmp(distrito[10], regiao) == 1) { //Leiria
        return 1652;
    }
    else if (strcmp(distrito[11], regiao) == 1) { //Lisboa
        return 1772;
    }
    else if (strcmp(distrito[12], regiao) == 1) { //Santarém
        return 1735;
    }
    else if (strcmp(distrito[13], regiao) == 1) { //Portalegre
        return 1731;
    }
    else if (strcmp(distrito[14], regiao) == 1) { //Évora
        return 1827;
    }
    else if (strcmp(distrito[15], regiao) == 1) { //Setúbal
        return 1838;
    }
    else if (strcmp(distrito[16], regiao) == 1) { //Beja
        return 1884;
    }
    else if (strcmp(distrito[17], regiao) == 1) { //Faro
        return 1987;
    }

    return -1;
}

int entreAB(int x, int inf, int sup)
{
    if (x > inf && x < sup)
        return 1;
    else
        return 0;
}

int calcMedia(int vals[], int qtd) {
    int soma = 0;
    for (int idx = 0; idx < qtd; idx++) {
        if(vals[idx]>=0) {
            soma += vals[idx];
        }
    }

    return soma / qtd;
}

void inicializaArray(int arrint[], int fim, int defaultValue) {
    for (int idx = 0; idx < fim; idx++)
    {
        arrint[idx] = defaultValue;
    }
}

void MostraArray(int v[], int fim)
{
    for (int idx = 0; idx < fim; idx++)
    {
        printf("%d ", v[idx]);
    }
    puts("\n");
}

int validaDistrito(char distritoInserido[]) {
    for (int i = 0; i < 18; i++) {
        if (strcmp(distritoInserido, distrito[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

int estaPreenchido(int* arrayRegsisto, int fim) {
    for (int idx = 0; idx < fim; idx++)
    {
        if (arrayRegsisto[idx] == DEFAULT_VALUE) {
            return 0;
        }
    }
    return 1;
}

int calcNumPaineis(int* arrayResgisto, char regiao[]) {
    float anualConsumption, anualRadiation;

    //calcular o consumo a abater
    anualConsumption = calcMedia(arrayResgisto, YEAR) * 0.3;
    //calcular a produção em kWh por m2
    anualRadiation = radiacaoPorDistrito(regiao) * 0.25;
    //calcular o numero de paineis necessario para a producao anual
    return ceil(anualConsumption / anualRadiation);
}
//endregion
