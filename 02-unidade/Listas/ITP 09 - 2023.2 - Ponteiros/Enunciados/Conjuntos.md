Um conjunto pode ser modelado como vetor de elementos não repetidos. Usando essa ideia implemente um programa com as seguintes características:

Modele uma struct, chamada conjunto, capaz de armazenar um conjunto de números inteiros, a struct deve armazenar tanto os números quanto a quantidade de números do conjunto. Usando essa struct faça:

Crie uma função uniao, que recebe como parâmetro duas referências para a struct conjunto, A e B. A função deve computar e retornar a união entre A e B. Lembre-se, a união entre dois conjuntos A e B é um novo conjunto que contém os elementos de A e de B.
Essa função pode ser implementada valendo 60% do valor sem a utilização de referencias.
Crie uma função interseção, que recebe como parâmetro duas referências para a struct conjunto, A e B. A função deve computar a interseção entre A e B. Lembre-se que a interseção entre dois conjuntos A e B é um novo conjunto que contém os elementos que existem em A e que existem em B ao mesmo tempo.
​Essa função pode ser implementada valendo 60% do valor sem a utilização de referencias.​
Implemente o main do programa, considerando que a entrada é fornecida no seguinte formato: 6 1 2 3 4 5 6; Significa que o conjunto tem tamanho 6, e que seus elementos são {1, 2, 3, 4, 5, 6}. Seu programa deve ler os conjuntos, criar as structs e usar as funções para computar a interseção e união dos conjuntos passados, imprimindo no main os resultados obtidos, seguindo os formatos mostrados.
​Você pode implementar de forma que a impressão do resultado seja feita dentro das funções, fazendo a parte relacionada à implementação do main valer 60% do valor total da questão.

```
Entrada:
6 1 2 3 4 5 6
5 2 3 4 5 6

12 3 4 5 7 8 12 13 14 16 18 19 20
12 13 11 4 1 7 3 6 10 12 5 20 18
```

```
Saída:
A união B == {1 2 3 4 5 6}
A interseção B == {2 3 4 5 6}

A união B == {3 4 5 7 8 12 13 14 16 18 19 20 11 1 6 10}
A interseção B == {13 4 7 3 12 5 20 18}
```