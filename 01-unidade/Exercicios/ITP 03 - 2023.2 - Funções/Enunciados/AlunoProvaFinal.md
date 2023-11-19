Um aluno ficou em recuperação e quer saber quanto precisa tirar na prova final para passar. Escreva um programa que recebe as três notas e chama uma função calcNota. A função possui três parâmetros de entrada e um de retorno. Os parâmetros de entrada indicam as 3 notas do aluno. calcNota deve retornar a nota mínima necessária para passar se o aluno precisar fazer a prova de reposição (caso as 3 notas sejam maiores ou iguais a 3 e a média < 5) e -1 caso contrário.

Para passar na prova final, a média da nota da prova final com as duas maiores notas anteriores do aluno deve ser pelo menos 5.Por exemplo: se nota1 = 6.0, nota2 = 4.0 e nota3 = 3.0, então calcNota deve retornar 5.0. Se nota1 = 4.0, nota2 = 3.0 e nota3 = 3.0, então calcNota deve retornar 8.0.

Imprima na main o status do aluno. Se o aluno for fazer a prova final, imprima também a nota necessária com uma casa decimal.

```
Entrada:
6
4
3

4
3
3
```

```
Saída:
Final
5.0

Final
8.0
```