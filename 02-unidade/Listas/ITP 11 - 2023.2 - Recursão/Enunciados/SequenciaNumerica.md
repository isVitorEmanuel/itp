Considere o seguinte processo para gerar uma sequência numérica:

Comece com um número inteiro n > 0;
    * Se n é par, divida por 2;
    * Se n é ímpar, multiplique por 3 e some 1;
    * Repita esse processo com o novo valor de n se n != 1;
    * Termine a sequência se n = 1.

Por exemplo, a sequência de números a seguir é gerada para n = 22:

22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

Escreva uma função recursiva que, dado um inteiro positivo, imprime a sequência de números acima.

```
Entrada:
22

23
```

```
Saída:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1
```