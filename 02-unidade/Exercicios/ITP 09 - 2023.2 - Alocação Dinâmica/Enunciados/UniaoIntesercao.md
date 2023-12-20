Um conjunto pode ser modelado como vetor de elementos não repetidos. Usando essa ideia implemente um programa com as seguintes características:

Modele um novo tipo struct chamado Conjunto capaz de armazenar um vetor de números inteiros e o tamanho deste vetor. Usando essa struct faça:

    * Crie uma função uniao, que recebe como parâmetro dois conjuntos A e B e retorna a união de A e B. Lembre-se, a união entre dois conjuntos A e B é um novo conjunto que contém os elementos de A e de B sem repetições;
    * Crie uma função intersecao, que recebe como parâmetro dois conjuntos A e B e retorna a interseção entre A e B. Lembre-se que a interseção entre dois conjuntos A e B é um novo conjunto que contém os elementos que existem em A e em B;
    * Implemente o main do programa, considerando que a entrada é fornecida no seguinte formato: 6 1 2 3 4 5 6 significando que o conjunto tem tamanho 6, e que os seus elementos são {1, 2, 3, 4, 5, 6};
    * Seu programa deve ler os dois conjuntos A e B e usar as funções para computar os conjuntos U da união e I da interseção deles, imprimindo no main os conjuntos U e I, seguindo os formatos mostrados nos testes.

OBS: Todos os vetores dos conjuntos devem ser alocados dinamicamente e sem desperdícios de memória.​

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