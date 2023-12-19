Um vetor é legal caso a diferença entre qualquer elemento e seu antecessor seja par. Escreva uma função que recebe um vetor de inteiros e retorne se ele é legal ou não. Na função principal leia um número inteiro positivo nnn​ e em seguida os nnn valores do vetor. Então, exibe a mensagem "Legal" quando o vetor for legal, e "Chato" caso contrário. Considere 0 como um número par. 

```
Exemplos:

​[-2, -4, 10, 3, 5]​​
​Não é Legal, pois:
* 3 - 10 = -7;​

​[5, 7, 9, 13, 27]​
É Legal, pois:
* 7 - 5  == 2
* 9 - 7 == 2
* 13 - 9 == 4
* 27 - 13 == 14
```

```
Entrada:
5
-2
-4
10
3
5

5
5
7
9
13
27
```

```
Saída:
Chato

Legal
```