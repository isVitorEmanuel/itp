#include <stdio.h>

void divide_primo(int numero) {

  if (numero == 1) {
    printf("1\n");
  } else {
    if (numero % 2 == 0) {
      printf("%d ", numero);
      divide_primo(numero / 2);
    } else if (numero % 3 == 0) {
      printf("%d ", numero);
      divide_primo(numero / 3);
    } else if (numero % 5 == 0) {
      printf("%d ", numero);
      divide_primo(numero / 5);
    } else if (numero % 7 == 0) {
      printf("%d ", numero);
      divide_primo(numero / 7);
    } else {
      printf("%d", numero);
    }
  }
}

int main() {

  int numero;
  scanf("%d", &numero);

  divide_primo(numero);
}
