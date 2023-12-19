Para ajudar o estagiário Juca a compreender o conceito de funções, você sugeriu a seguinte atividade: determinar se dois números são amigos utilizando funções.

Definição: dois números naturais diferentes são amigos se cada um for igual à soma dos divisores do outro (sem incluir os próprios números nos divisores).

Assim, você forneceu o trecho de código abaixo e pediu para ele implementar as funções e depois criar um programa que recebe dois intervalos naturais L1 = [A,B] e L2 = [C,D] e apresenta todos os valores em L1 que possuem ao menos um amigo em L2.

```
#include

// retorna verdadeiro se numero é divisível por divisor e falso em caso contrário
int testa_divisor(int numero, int divisor){
  return 0;
}

// retorna a soma dos divisores de value no intervalo [1,value)
int soma_divisores(int value){
  return 0;
}

// retorna verdadeiro se a é amigo de b e falso em caso contrário
int testa_amigos(int a, int b){
  return 0;
}

// recebe dois intervalos naturais L1 = [A,B] e L2 = [C,D]
// apresenta todos os valores em L1 que possuem ao menos um amigo em L2.
int main(){
  return 0;
}
```

Para mais informações sobre números amigos, consulte o endereço: wikipedia.

​​A solução deve apresentar as funções descritas e não deve ter variáveis globais.

```
Entrada:
200 300
200 300

1 10
1 100
```

```
Saída:
O 220 possui um amigo!
O 284 possui um amigo!

Os intervalos nao apresentam amigos!
```