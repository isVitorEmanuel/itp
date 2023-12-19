Em várias situações, precisamos ordenar informações. Um dos algoritmos de ordenação mais simples (de implementar) realiza sucessivas trocas entre valores consecutivos levando, a cada iteração, o maior elemento para o fim da sequência. Assim, na primeira iteração, o maior elemento vai para sua posição ordenada (último). Na segunda iteração, o segundo maior vai para sua posição (penúltimo). Na terceira iteração, será a vez do antepenúltimo e assim por diante.

Esse algoritmo, também conhecido como bubble sort, é descrito em pseudocódigo da seguinte forma:

```
algoritmo bubble_sort(seja A um array de n valores)
   repita
   |  para i de 1 até n-1
   |  |  se A[i-1] > A[i] então
   |  |  |  troca os valores de A[i-1] e A[i]
   |  |  fim_se
   |  fim_para
   enquanto houver troca de valores no laço interno
fim_algoritmo
```
Implemente este algoritmo e imprima o estado de uma sequência de valores para compreender como ele funciona.

Entrada
    * O seu programa deve ler da entrada-padrão um valor inteiro N seguido de N valores inteiros.
Saída
    * A saída consiste em várias linhas, cada uma contendo os valores da sequência na iteração corrente, durante a execução do algoritmo. A primeira linha deve imprimir a sequência original (não ordenada) enquanto a última linha deve imprimir os valores da sequência em ordem crescente.

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
2 4 1 7
2 1 4 7
1 2 4 7

9 -4 2 7 -2 1 5 -7
-4 2 7 -2 1 5 -7 9
-4 2 -2 1 5 -7 7 9
-4 -2 1 2 -7 5 7 9
-4 -2 1 -7 2 5 7 9
-4 -2 -7 1 2 5 7 9
-4 -7 -2 1 2 5 7 9
-7 -4 -2 1 2 5 7 9
```