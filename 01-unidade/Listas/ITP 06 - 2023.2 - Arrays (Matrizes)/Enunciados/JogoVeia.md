O jogo da velha é um fenômeno Interplanetário entre crianças de ensino fundamental, dado ao alto grau estratégico necessário para vencer no jogo. Uma partida consiste em um tabuleiro 3x3, onde os jogadores alternam jogadas colocando símbolos de X e de O. O jogador que conseguir uma sequência de três símbolos adjacentes no tabuleiro primeiro ganha. Os símbolos podem estar adjacentes tanto em uma linha, em uma coluna ou nas diagonais do tabuleiro. O jogador vencedor normalmente ganha o título de campeão universal mundial da rua.
Jeremias Johnson sempre gostou de programação e Inteligência Artificial, mas nunca foi o campeão do universo da rua dele. Logo ele teve a ideia de criar uma IA que poderia sempre vencer no jogo d Velha. Porém criar uma IA é difícil...então ele pensou em começar com pequenos passos. A ideia dele é criar um programa que, dado um tabuleiro parcialmente preenchido, e uma jogada, o programa consiga testar se aquela jogada vai vencer, não vai dar em nada ou se foi uma jogada inválida.
Como ele tem que fazer um quadro de macarrão essa semana, Jeremias pediu sua ajuda para fazer o programa. Se programa irá receber um tabuleiro de jogo da velha 3x3 parcialmente preenchido com os seguintes símbolos:

X - símbolo do jogador X
O (letra o maiúscula) - símbolo do jogador O

. (ponto final) - símbolo representando um espaço vazio

Um exemplo de tabuleiro é ilustrado abaixo:

X..
...
X.X

Após a leitura do tabuleiro, seu programa deverá ler um valor inteiro N indicando um número de jogadas para testar. A seguir, virão N linhas contendo dois valores inteiros e um símbolo, representando jogadas para testar no tabuleiro. ATENÇÃO: o seu programa não simulará uma partida, logo todas as jogadas devem ser testadas com o tabuleiro inicial.
A linha da jogada terá o formato X Y SIMB, onde X e Y são inteiros entre 1 e 3 representando respectivamente a linha e a coluna da jogada, e SIMB é o símbolo (X ou O) que foi jogado.
Para cada jogada testada, seu programa deverá imprimir uma mensagem informando o resultado de acordo com a lista abaixo:

- Jogada inválida! - quando a posição da jogada não estiver vazia.
- Boa jogada, vai vencer! - quando a jogada resultar em uma configuração vencedora.
- Continua o jogo. - quando a jogada não resultar em uma configuração vencedora

Atente para os exemplos de entrada e saída para verificar a formatação do seu programa.

```
Entrada:
X..
...
X.X
5
1 1 X
2 1 X
1 2 X
2 2 X
3 2 X

O.X
...
X.O
5
2 2 O
2 2 X
2 3 X
2 1 O
3 2 X
```

```
Saída:
Jogada inválida!
Boa jogada, vai vencer!
Continua o jogo.
Boa jogada, vai vencer!
Boa jogada, vai vencer!

Boa jogada, vai vencer!
Boa jogada, vai vencer!
Continua o jogo.
Continua o jogo.
Continua o jogo.
```