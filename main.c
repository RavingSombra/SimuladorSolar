#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YEAR 12

const char distrito[][17]={"VianaDoCastelo", "Braga", "VilaReal", "Braganca", "Porto", "Aveiro", "Viseu", "Guarda", "Coimbra", "CasteloBranco", "Leiria", "Lisboa", "Santarem", "Portalegre", "Evora", "Setubal", "Beja", "Faro"};

//region Funções
void menu();

void escolha(char c,int *arrayResgisto);

void opcaoA(int *arrayResgisto);

void opcaoM(int *arrayResgisto);

void opcaoR(int *arrayResgisto);

void opcaoG(int *arrayResgisto);

void opcaoV(int *arrayResgistoS);

void opcaoP();

void opcaoS();

void opcaoT();

int radiacaoPorDistrito (char distrito[]);

void MostraArray(int v[], int fim);
//endregion

int main(void) {
    char opcao;
    char distritoInserido[17];
    char nome[10];
    int ano;
    int passou = 1;
    int arrayRegistos[YEAR]={0,0,0,0,0,0,0,0,0,0,0,0};
    scanf(" %s %s %d", &nome, &distritoInserido, &ano);
    for (int i = 0; i < 18; i++) {
        if (strcmp(distritoInserido, distrito[i]) == 0) {
            passou = 0;
        }
    }
    if(passou==1){
        printf("O distrito indicado nao existe. A fechar...\n");
        return 0;
    }
    do {
        if (scanf(" %c", &opcao) == 0) {
            printf("erro");
        }
        escolha(opcao,arrayRegistos);
    }
    while (opcao != 'q');
    //Variáveis
    //Imprimir o menu
    menu();

    return 0;
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
    puts(" |  g Media de consumo anual                | ");
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

void escolha(char c,int *arrayRegistos){
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
            opcaoG(arrayRegistos);
            break;
        case 'v':
            opcaoV(arrayRegistos);
            break;
        case 'p':
            opcaoP();
            break;
        case 's':
            opcaoS();
            break;
        case 't':
            opcaoT();
            break;
        case 'd':
            menu();
            break;
        case 'h':
            assistencia();
            break;
        case 'f': //Apenas para debug
            MostraArray(arrayRegistos,12);
            break;
        case 'q':
            printf("Simulador encerrado");
            break;
        default:
            printf("Opcao invalida, escolha outra vez\n");
            break;
    }
}

//Registos
void opcaoA(int *arrayResgisto){
    int mes;
    int consumo;
    scanf(" %d %d", &mes,&consumo);
    if(mes>0&&mes<13){
        for (int i=0;i<YEAR;i++){
            if(mes==i){
                arrayResgisto[i] = consumo;
            }
        }
    }
}

void opcaoM(int *arrayResgisto){
    int mes;
    int consumo;
    scanf(" %d %d", &mes,&consumo);
    if(mes>0&&mes<13){
        for (int i=0;i<YEAR;i++){
            if(mes-1==i){
                arrayResgisto[i] = consumo;
            }
        }
    }

}

void opcaoR(int *arrayResgisto){
    int mes;

    scanf(" %d", &mes);
    if(mes>0&&mes<13){
        for (int i=0;i<YEAR;i++){
            if(mes-1==i){
                arrayResgisto[i] = -1;
            }
        }
    }

}
//
void opcaoG(int *arrayResgisto){
    int media=0;
    for (int i=0;i<YEAR;i++){
        media+=arrayResgisto[i];
    }
    media=media/12;
    printf("A media: %d",media);
}

void opcaoV(int *arrayResgisto){
    int media=0;
    int media1=0;
    int media2=0;
    int delta=0;
    int delta1=0;
    for (int i=0;i<YEAR;i++){
        if(arrayResgisto[i]!=0){
            if(i>=11||i<=2){
                media=media+arrayResgisto[i];
            }else if(i>=5&&i<=8){
                media1=media1+arrayResgisto[i];
            }else{
                media2=media1+arrayResgisto[i];
            }
        }
    }
    delta=(media/4)-media2;
    delta1=(media1/4)-media2;
    printf("Consumo típico: %d \nConsumo em época de frio: %d (delta= %d ) \nConsumo em época de calor: %d (delta= %d )\n",media2/4,media/4,delta,media1/4,delta1);

}

void opcaoP() {

}

void opcaoS() {

}

void opcaoT() {

}

//region Funções auxiliares
int radiacaoPorDistrito (char regiao[]){
    if(strcmp(distrito[0],regiao)==1){ //Viana do Castelo
        return 1557;
    }
    else if(strcmp(distrito[1],regiao)==1){ //Braga
        return 1574;
    }
    else if(strcmp(distrito[2],regiao)==1){ //Vila Real
        return 1572;
    }
    else if(strcmp(distrito[3],regiao)==1){ //Bragança
        return 1646;
    }
    else if(strcmp(distrito[4],regiao)==1){ //Porto
        return 1628;
    }
    else if(strcmp(distrito[5],regiao)==1){ //Aveiro
        return 1617;
    }
    else if(strcmp(distrito[6],regiao)==1){ //Viseu
        return 1636;
    }
    else if(strcmp(distrito[7],regiao)==1){ //Guarda
        return 1700;
    }
    else if(strcmp(distrito[8],regiao)==1){ //Coimbra
        return 1642;
    }
    else if(strcmp(distrito[9],regiao)==1){ //Castelo Branco
        return 1805;
    }
    else if(strcmp(distrito[10],regiao)==1){ //Leiria
        return 1652;
    }
    else if(strcmp(distrito[11],regiao)==1){ //Lisboa
        return 1772;
    }
    else if(strcmp(distrito[12],regiao)==1){ //Santarém
        return 1735;
    }
    else if(strcmp(distrito[13],regiao)==1){ //Portalegre
        return 1731;
    }
    else if(strcmp(distrito[14],regiao)==1){ //Évora
        return 1827;
    }
    else if(strcmp(distrito[15],regiao)==1){ //Setúbal
        return 1838;
    }
    else if(strcmp(distrito[16],regiao)==1){ //Beja
        return 1884;
    }
    else if(strcmp(distrito[17],regiao)==1){ //Faro
        return 1987;
    }

    return -1;
}

void calculaMedia(){

}

void inicializaArray(int arrint[]){

}

void MostraArray(int v[], int fim)
{
    for(int idx=0;idx<fim;idx++)
    {
        printf("%d ", v[idx]);
    }
    puts("\n");
}
//endregion
