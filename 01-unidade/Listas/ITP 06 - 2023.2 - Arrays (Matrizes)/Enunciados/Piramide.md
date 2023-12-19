Você foi chamada para fazer parte da equipe de desenvolvimento do próximo Assassin's Creed, no qual o protagonista irá ao Egito. Sua tarefa é gerar pirâmides dinamicamente no cenário do jogo e, para isso, é necessário primeiro calcular a altura (em quantidade de blocos) em cada camada da pirâmide. As camadas são formadas por blocos sobre os blocos da camada abaixo, porém com uma quantidade menor de blocos.

Por exemplo, numa pirâmide que tem 5 blocos de largura, teremos 3 camadas. A primeira (a base da pirâmide) terá altura de um único bloco, a segunda camada terá altura de dois blocos e, por fim, a terceira de três blocos, como ilustrado a seguir:

1 1 1 1 1
1 2 2 2 1
1 2 3 2 1
1 2 2 2 1
1 1 1 1 1

Escreva então um programa que crie uma matriz quadrada com as alturas (número de blocos) da pirâmide, como no exemplo acima, dada a largura da pirâmide.

​Entrada

    * Seu programa deve ser um único valor inteiro N representando a quantidade de blocos da largura da pirâmide.

Saída

    * Considerando que a pirâmide possui uma base quadrada (largura  e profundidade são iguais), seu programa deve enviar para a saída-padrão uma matriz com a altura de cada posição da pirâmide.

```
Entrada:
3

4
```

```
Saída:
1 1 1
1 2 1
1 1 1

1 1 1 1
1 2 2 1
1 2 2 1
1 1 1 1
```