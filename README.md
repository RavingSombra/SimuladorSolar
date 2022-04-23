# SimuladorSolar

Este exercício serve os seguintes objectivos:
- Utilização de operadores
- Utilização de variáveis
- Utilização de decisores
- Utilização de ciclos
- Utilização de Vetores e Strings
- Praticar pensamento algoritmico

Na resolução destes exercícios deve ser utilizada a Linguagem de Programação C. Para além da correta implementação dos requisitos, tenha em conta os seguintes aspetos:
- O código apresentado deve ser bem indentado.
- O código deve compilar sem erros ou *warnings* utilizando o *gcc* com as seguintes flags:
- `gcc -g -Wvla -Wall -Wpedantic -Wextra -Wdeclaration-after-statement main.c -o main -lm`
- O nome das variávies devem ser indicadores daquilo que as mesmas vão conter.
- O trabalho deve seguir as práticas da boa programação.

## Descrição do problema
O Daniel pretende instalar painéis fotovoltaicos na sua casa e para isso decidiu desenvolver uma aplicação para simualar a solução mais adequada aos seus consumos de eletricidade. Como base a este problema deverá usar um array para guardar os valores referentes a cada mês.
Ao iniciar o programa deve ser solicitado o seu primeiro nome, o distrito onde se pretende fazer a simulação e o ano a que se referem os consumos. Caso o distrito seja inválido, deverá ser imprimida a mensagem `O distrito indicado nao existe. A fechar...` e terminar o programa.

O programa deverá mostrar o seguinte menu:

```
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
```

Ao ler uma opção inválida é impressa a mensagem `Opcao invalida, escolha outra vez` seguido do menu.

### Registos
* opção `a`
  - Deverão ser lidos dois inteiros do tipo `int` referentes ao mês e ao consumo em kWh referente ao mesmo.
  Caso já exista dados para um determinado mês o programa deve imprimir `Já existe um registo para este mes`.
* opção `m` Idêntico à opção `a`, mas apenas é permitido alterar um registo caso já tenha sido inserido.

* opção `r`
  Remove o consumo para o mês lido como input. Nesse mês, a leitura voltará ao valor de quando o array foi inicializado.

### Cálculos
As opções desta categoria só poderão ser executadas caso existam consumos registados para todos os meses de um ano.

* opção `g`
  Calcular a média de consumo do ano indicado no mesmo formato do exemplo:
```
Durante o ano de 2021 foram consumidos em media 361 kWh por mes
```

* opção `v`
  Esta opção serve para dar uma estimativa ao utilizador do consumo médio a mais ou a menos nos períodos de inverno e de verão. Para tal consideram-se os seguintes intervalos:
  * Inverno (época de frio): novembro a fevereiro
  * Controlo: março e abril; setembro e outubro
  * Verão (época de calor): maio a agosto
<br> O texto a imprimir deverá estar no formato do exemplo:
```
Consumo tipico: 300 kWh
Consumo medio em epoca de frio: 450kWh (delta= 150 )
Consumo medio em epoca de calor: 270kWh (delta= -30 )
```

**NOTA**: Entende-se como delta a diferença entre dois valores, tipicamente em fenómenos físicos.

### Simulação
As opções desta categoria só poderão ser executadas caso existam consumos registados para todos os meses de um ano. Se tal não se verificar, deve imprimir a mensagem `Registos em falta.`

* opção `p`
  Deverá ser lido um inteiro do tipo `int` referente à área do telhado da casa. Para o cálculo do número de painéis recomendado a instalar deve ter em consideração a área de um painel fotovoltaico (2m<sup>2</sup>) e a sua eficiência típica (25%), o consumo anual que a produção fotovoltaica deve reduzir (30%) e o valor anual da irradiação, determinado em função do distrito[(1)](#ref1):

| Distrito         | Irradiação média anual(kWh/m<sup>2</sup>) |  
|------------------|-------------------------------------------|
| Viana do Castelo | 1557                                      |
| Braga            | 1574                                      |
| Vila Real        | 1572                                      |
| Bragança         | 1646                                      |
| Porto            | 1628                                      |
| Aveiro           | 1617                                      |
| Viseu            | 1636                                      |
| Guarda           | 1700                                      |
| Coimbra          | 1642                                      |
| Castelo Branco   | 1805                                      |
| Leiria           | 1652                                      |
| Lisboa           | 1772                                      |
| Santarém         | 1735                                      |
| Portalegre       | 1731                                      |
| Évora            | 1827                                      |
| Setúbal          | 1838                                      |
| Beja             | 1884                                      |
| Faro             | 1987                                      |

O output deverá estar no formato do exemplo:
```
  E' recomendado instalar 5 paineis fotovoltaicos na propriedade de Manuel 
```

Quando a área do telhado é inferior à área a ocupar pelos painéis fotovoltaicos, deve imprimir a mensagem `Area do telhado inferior 'a area de paineis necessaria para a producao ideal face ao consumo indicado.`.

**NOTA**: O nome dos distritos não deve conter espaços nem caracteres usados na língua portuguesa (acentos ou ç)

* opção `s` Deverá receber um `float` correspondente ao custo por kWh e calcular a poupança anual com o número de painéis instalados. O output deverá estar no formato do exemplo:
```
Com a instalacao de 3 paineis e uma poupanca de 500 kWh/ano, tera' uma poupanca anual de 85.00 euros.
```

* opção `t` Semelhante à opção `s`, mas calculando o tempo, em anos, de retorno do investimento, considerando que cada painel custa 400€. O output deverá estar no formato do exemplo:
```
O investimento em paineis solares tera' retorno apos 7.2 anos de funcionamento.
```

### Diversos
* opção `d` Esta opção mostra o menu novamente
* opção `f` Esta opção mostra os registos presentes no array

* opção `h` São mostrados os contactos em caso de dúvidas relativamente às operações realizadas como indicado
```
A nossa linha telefonica de assistencia funciona nos dias uteis entre as 8 e as 18 horas.
Se desejar desloque-se 'as nossas instalacoes.
Contacto telefonico: 212345667
Endereco eletronico: mundo.melhor@gmail.com
Loja fisica perto de si: Rua poluida, lote 3
```

* opção `q` O programa executa por tempo indeterminado até ser selecionada esta opção, que termina o programa e imprime a mensagem `Simulador encerrado`

### Notas adicionais

É estritamente proibida a utilização da instrução `goto`.
A utilização de variáveis globais é também proibida (excepto constantes).

## Referências

<a name="ref1"></a>
<a name="ref2"></a>

* (1) IPMA - Radiação Solar Global em Portugal e a sua variabilidade
https://www.researchgate.net/publication/312490545_Radiacao_Solar_Global_em_Portugal_e_a_sua_variabilidade
* (2) Enunciado inspirado nos
https://github.com/LP1ULHT/EX4_2022
https://github.com/LP1ULHT/EX3
https://github.com/LP1ULHT/EX2_2022
https://github.com/LP1ULHT/EX1_2022
https://github.com/LP1ULHT/EX0_2022