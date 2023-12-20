Considere o seguinte processo para gerar uma sequência numérica ni:

Imprima ni caso ela seja maior que 1;
    ni+1 = ni / primo, caso ni seja divisível pelo número primo = {2, 3, 5, 7};
    Termine a sequência se n = 1 ou n não é divisível por primo.

Por exemplo, a sequência de números a seguir é gerada para n = 98:

98 49 7 1

Escreva uma função recursiva que, dado um inteiro positivo, imprime a sequência de números acima

```
Entrada:
98

225
```

```
Saída:
98 49 7 1

225 75 25 5 1
```