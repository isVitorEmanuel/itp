Preocupados com o desempenho dos alunos nas disciplinas do BTI, os coordenadores do curso, Profª. Rafaela e Prof. Girão, resolveram criar o IMD Cap, o "título de capitalização de conhecimentos" do Instituto Metrópole Digital. Os 5 melhores alunos de cada turma terão direito a uma cartela para concorrer em sorteios (bingo) de valiosos prêmios.

Premiação:

1) 🤚 um high-five com o Prof. Ivonildo Rêgo (Diretor do IMD);
2) 🅿️ uma vaga no estacionamento do IMD em dias de evento;
3) 🚚 uma carona em cima da carroceria da picape do Prof. Daniel;
4) 🥊 não ser "blipado" por Thanos (professor) em FMC II.

Como a coordenação do BTI dá bastante trabalho, eles pediram a ajuda dos alunos de ITP para implementar o programa que irá gerenciar os sorteios do IMD Cap.

O jogo:

O bingo consiste num globo contendo um conjunto de bolas numeradas, sorteadas uma a uma. No início da partida, cada jogador recebe uma cartela contendo um subconjunto aleatório dos números existentes no globo. A cada rodada, o jogador deve verificar se possui em sua cartela o número da bola sorteada, marcando-o em caso afirmativo. Vence o primeiro jogador que marcar corretamente todos os números em sua cartela e gritar "Bingo!". Exemplo.

Atividade:

Implemente o sorteio do IMD Cap (bingo). Considere as seguintes regras:

O globo terá M bolas, numeradas de 1 a M (M<=100).
As cartelas terão N números aleatórios entre os presentes no globo (N<=M).
O jogo poderá ter até 30 jogadores. 
Cada jogador irá escolher uma cartela com base em um valor inteiro T.
Um cartela não pode ter números repetidos.​​
​Para a geração dos números das cartela deverá ser utilizada a função rand(), com semente igual à identificação da cartela: Cartela 'T', semente 'T'.
O sorteio começa quando a expressão "Começou o jogo!" for digitada.
No sorteio não poderá haver repetição de números.
Para a geração dos números do sorteio deverá ser utilizada a função rand(), inicializada com a semente S.​
Em caso de repetição (sorteio e inicialização de cartelas), outro número deverá ser gerado pela função rand().
As seguintes funções deverão ser chamadas a partir do código principal:
uma função void para inicialização de uma cartela; recebe como parâmetro:
o índice da cartela no vetor de cartelas;
o vetor de cartelas;
o identificador da cartela T
o tamanho da cartela N
a quantidade de bolas do globo M; 
uma função int para marcar um número sorteado em uma cartela - deve retornar 1 quando a cartela marcar todos os números ou 0, caso contrário; recebe como parâmetros:
o índice da cartela no vetor de cartelas;
o vetor de cartelas;
o número sorteado.
Variáveis globais não deverão ser utilizadas.
O tipo de dados "Cartela", definido abaixo, deverá ser importado no código:
typedef struct {
    int id_cartela;
    int tam_cartela;
    int numeros[100];
    int marcacao[100];
} Cartela;​


Exemplos:​

Entrada: 
<tamanho da cartela N> <tamanho do globo M> <semente do sorteio S>
<id da primeira cartela - T_1>
<id da segunda cartela  - T_2>
<id da terceira cartela - T_3>
...
<id da n-ésima cartela  - T_n>
Comecou o jogo!

Exemplo:
10 25 10
1
2
3
4
5
6
7
8
9
10
Comecou o jogo!

Saída:   
<numeros_sorteados>
Bingo! Cartela <x>: <numeros_cartela_x>

Exemplo:
21 9 4 1 19 3 22 23 8 24
Bingo! Cartela 10: 21 9 4 1 19 3 22 23 8 24

Origem: 

O bingo (conhecido também por loto ou víspora) é um jogo de azar bem popular no mundo todo. Muito comum em festas municipais, eventos beneficentes e quermesses de igrejas, sua origem não é certa. Alguns relatos apontam à época do Império Romano, outros aos Bávaros. Uma versão bem difundida é a de que o jogo teria surgido na cidade italiana de Gênova, na Idade Média, como mecanismo para escolha aleatória dos representantes para os conselhos políticos locais, evitando acusações de favorecimentos ou de preferências.

```
Entrada: 
10 25 10
1
2
3
4
5
6
7
8
9
10
Comecou o jogo!

10 25 11
1
2
3
4
5
6
7
8
9
10
Comecou o jogo!
```

```
Saída:
21 9 4 1 19 3 22 23 8 24
Bingo! Cartela 10: 21 9 4 1 19 3 22 23 8 24

24 20 23 21 4 7 15 1 17 19 10 12 14 5 18 22 6 11 13 2 8 9 25
Bingo! Cartela 4: 2 9 25 14 13 1 4 11 20 5
```