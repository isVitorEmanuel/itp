O paint brush é um programa famoso do windows através dos quais as pessoas podem desenhar formas usando várias ferramentas. O paint também oferece a função de colorir as formas através da ferramenta "preencher com cor". O processo de colorir é simples: o usuário seleciona uma cor e clica na ferramenta de preenchimento. Em seguida clica com o botão esquerdo no ponto a partir do qual deseja colorir. O programa então muda a cor de todos os pixels vizinhos que possuem a mesma cor do ponto clicado.

Seu objetivo é criar um software de preenchimento semelhante ao do paint, mas que usará apenas matrizes de caracteres comuns para definir as formas e as cores. Por exemplo, a matriz 8x14 abaixo possui duas cores, representadas pelos caracteres - e *. Além disso, a cor * está definindo uma forma de retângulo na matriz.

--------------
----******----
----*----*----
----*----*----
----******----
--------------

Seu programa deverá ler as dimensões da matriz m e n e uma matriz de tamanho m x n. Em seguida seu programa deve ler as coordenadas de um ponto inicial que corresponde a uma posição da matriz, linha i e coluna j (começando ambos de zero), e por fim ler um caractere c que define uma cor de preenchimento.

Por exemplo, para a entrada abaixo

6 14
--------------
----******----
----*----*----
----*----*----
----******----
--------------

2 5

#

O resultado esperado é:

--------------
----******----
----*####*----
----*####*----
----******----
--------------

Dicas: 

Use recursividade para visitar os pontos vizinhos que possuem a mesma cor que o ponto inicial e que ainda não foram visitados;
Use uma matriz auxiliar que diz se um determinado ponto da matriz já foi visitado ou não como caso base.

```
Entrada:
6 14
--------------
----******----
----*----*----
----*----*----
----******----
--------------
2 5
#

6 14
--------------
----******----
----*----*----
----*----*----
----******----
--------------
0 0
#
```

```
Saída:
--------------
----******----
----*####*----
----*####*----
----******----
--------------

##############
####******####
####*----*####
####*----*####
####******####
##############
```