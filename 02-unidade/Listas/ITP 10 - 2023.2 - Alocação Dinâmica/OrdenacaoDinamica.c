#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void ordVet(int *vetor, int tamanho) {

  bool stop;
  int aux = 0;

  do {
    stop = false;

    for (int i = 0; i < (tamanho - 1); i++) {
      if (vetor[i] > vetor[i + 1]) {
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
        stop = true;
      }
    }
  } while (stop == true);
}

int main() {
  int *numeros = NULL;
  int tam = 0;
  int num;
  while (scanf("%d", &num) == 1) {
    tam++;
    numeros = realloc(numeros, tam * sizeof(int));
    numeros[tam - 1] = num;
  }
  ordVet(numeros, tam);
  for (int i = 0; i < tam; i++) {
    printf("%d ", numeros[i]);
  }
  free(numeros);
  return 0;
}