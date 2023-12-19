Um dos principais algoritmos na área de computação gráfica é o algoritmo de recorte utilizado para determinar quais partes de um objeto devem ser exibidos na tela. Você deve desenvolver uma versão simplificada utilizada num programa de processamento de retângulos indicando se um retângulo está dentro de outro. Neste programa, os retângulos são representados por dois pontos: <esquerdo, inferior> e o <direito, superior>.

O programa deve iniciar recebendo as informações do retângulo da tela representando a área visível e para cada retângulo subsequente ele deve determinar se ele está contido, contém ou possui uma interseção com a área visível, ou seja, necessita de um tratamento para exibição. A entrada encerra com os valores 0,0,0,0. Você deve implementar uma função para efetuar essa verificação, ou seja, dados dois retângulos, determinar se o primeiro contém o segundo, ou se o segundo contém o primeiro, ou se nada pode ser afirmado. Desse modo, você deve identificar quais são os parâmetros, o retorno e como ela será aplicada no programa principal.

Por exemplo, na figura abaixo, a tela (retângulo A) é especificada pelos pontos <5,5> e <10,10> e o retângulo B pelos pontos <7,7> e <8,8>, neste caso, o retângulo B se encontra dentro do A.

Já na imagem abaixo, não podemos afirmar se A contém B ou se B contém A.

Observe o formato de entrada e saída nos casos de teste para indicar quando um retângulo contém ou está contido em relação ao retângulo da área visível.

A solução deve apresentar uma função e não deve ter variáveis globais.

```
Entrada:
10 10 20 20
0 0 30 30
0 0 0 0

0 0 1 1
0 0 1 1
0 0 0 0
```

```
Saída:
(<0.00,0.00>,<30.00,30.00>) contem (<10.00,10.00>,<20.00,20.00>).

Nao posso afirmar!
```