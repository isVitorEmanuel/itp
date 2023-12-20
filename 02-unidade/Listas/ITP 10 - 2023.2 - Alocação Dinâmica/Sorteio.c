#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 80

int main() {
  char **PARTICIPANTES = NULL;
  char nome[MAX_NOMES];
  int N = 0, semente = 0;

  while (true) {
    fgets(nome, MAX_NOMES, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // adiciona o terminador de string

    if ((strcmp(nome, "acabou") == false)) {
      break;
    }

    N++;

    PARTICIPANTES = realloc(PARTICIPANTES, N * sizeof(char *));
    PARTICIPANTES[N - 1] = strdup(nome);
  }

  scanf("%d", &semente);
  srand(semente);

  int contSort = 0, indice_participante;
  int *indicSorteados = calloc(N, sizeof(int));

  while (contSort < N) {
    indice_participante = rand() % N;
    if (!indicSorteados[indice_participante]) {
      indicSorteados[indice_participante] = 1;
      printf("%s\n", PARTICIPANTES[indice_participante]);
      contSort++;
    }
  }

  for (int i = 0; i < contSort; i++) {
    free(PARTICIPANTES[i]);
  }
  free(PARTICIPANTES);
  free(indicSorteados);
}