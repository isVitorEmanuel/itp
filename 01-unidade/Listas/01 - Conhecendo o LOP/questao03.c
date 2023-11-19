#include <stdio.h>

// Não lembro qual era o enunciado da questão, mas apenas pedia pra imprimir o que está abaixo.

int main() {

  int QNTD;
  double INDICES, POP;
  char LETRA;

  scanf("%c %d %lf", &LETRA, &QNTD, &INDICES);

  POP = QNTD * INDICES;

  printf("A popularidade de %c é %.1lf\n", LETRA, POP);
}