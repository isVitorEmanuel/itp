#include <stdio.h>

// Não lembro qual era o enunciado da questão, mas apenas pedia pra imprimir o que está abaixo.

int main() {

  int N, ANOS, MESES, DIAS;

  scanf("%d", &N);

  ANOS = N / 365;
  N = N % 365;

  MESES = N / 30;
  DIAS = N = N % 30;

  printf("%d ano(s)\n", ANOS);
  printf("%d mes(es)\n", MESES);
  printf("%d dia(s)\n", DIAS);
}