#include <stdio.h>

void geraSequencia(int n) {
  if (n == 1) {
    printf("%d", n);
  } else {
    if ((n % 2) == 0) {
      printf("%d ", n);
      geraSequencia(n / 2);
    } else {
      printf("%d ", n);
      geraSequencia((n * 3) + 1);
    }
  }
}

int main(void) {
  int numero;
  scanf("%d", &numero);

  geraSequencia(numero);
}