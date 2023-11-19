Em várias situações, precisamos ordenar informações. Um dos algoritmos de ordenação mais simples (de implementar) realiza sucessivas trocas levando, a cada iteração, o menor elemento para o início da sequência. Assim, na primeira iteração, o menor elemento vai para sua posição ordenada (o início da sequência). Na segunda iteração, o segundo menor vai para a segunda posição. Na terceira iteração, será a vez do terceiro e assim por diante.

Esse algoritmo, também conhecido como exchange sort (uma variante do bubble sort), é descrito em pseudocódigo da seguinte forma:

algoritmo exchange_sort(seja A um array de n valores)
   para i de 0 até n-2
   |  para j de i+1 até n-1
   |  |  se A[i] > A[j] então
   |  |  |  troca os valores de A[i] e A[j]
   |  |  fim_se
   |  fim_para
   fim_para
fim_algoritmo

Implemente este algoritmo e imprima o estado de uma sequência de valores para compreender como ele funciona.

Entrada

O seu programa deve ler da entrada-padrão um valor inteiro N seguido de N valores inteiros.

Saída

A saída consiste em várias linhas, cada uma contendo os valores da sequência na iteração corrente, durante a execução do algoritmo. A primeira linha deve imprimir a sequência original (não ordenada) enquanto a última linha deve imprimir os valores da sequência em ordem crescente.

```
Entrada:
4
2 7 4 1

8
9 -4 2 7 -2 1 5 -7
```

```
Saída:
2 7 4 1
1 7 4 2
1 2 7 4
1 2 4 7

9 -4 2 7 -2 1 5 -7
-7 9 2 7 -2 1 5 -4
-7 -4 9 7 2 1 5 -2
-7 -4 -2 9 7 2 5 1
-7 -4 -2 1 9 7 5 2
-7 -4 -2 1 2 9 7 5
-7 -4 -2 1 2 5 9 7
-7 -4 -2 1 2 5 7 9
```