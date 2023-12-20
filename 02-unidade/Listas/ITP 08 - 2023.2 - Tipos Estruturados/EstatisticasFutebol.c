#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
  char nome[MAX_NOME];
  int golsMarcados;
  int golsSofridos;
} Time;

void ordenarTimes(Time time[], int qtdTimes) {
  Time aux;
  for (int i = 0; i < qtdTimes - 1; i++)
    for (int j = i + 1; j < qtdTimes; j++)
      if (time[i].golsMarcados < time[j].golsMarcados) {
        aux = time[i];
        time[i] = time[j];
        time[j] = aux;
      }
}

int main() {
  int qtdTimes;

  scanf("%d", &qtdTimes);
  Time *times = malloc(qtdTimes * sizeof(Time));

  // Leitura dos times
  for (int i = 0; i < qtdTimes; i++) {
    scanf(" %[^\n]s", times[i].nome); 
    scanf("%d", &times[i].golsMarcados);
    scanf("%d", &times[i].golsSofridos);
  }
  
  ordenarTimes(times, qtdTimes);

  // Exibe times
  for (int i = 0; i < qtdTimes; i++) {
    printf("%d - %s\n", i + 1, times[i].nome);
    printf("Gols marcados: %d\n", times[i].golsMarcados);
    printf("Gols sofridos: %d\n", times[i].golsSofridos);
  }

  free(times); 
  return 0;
}
