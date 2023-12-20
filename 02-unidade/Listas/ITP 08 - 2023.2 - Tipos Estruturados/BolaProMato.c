#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_LINHA 60

typedef struct {
  char nome[MAX_NOME];
  int vitorias, empates, derrotas, gols_feitos, gols_sofridos, pontos, saldo;
} Time;

void lerTime(Time *time) {
  char linha[MAX_LINHA], *str = NULL;
  
  fgets(linha, MAX_LINHA, stdin);
  str = strtok(linha, ";");
  strcpy(time->nome, str);

  str = strtok(NULL, " ");
  if (str != NULL) time->vitorias = atoi(str);
  str = strtok(NULL, " ");
  if (str != NULL) time->empates = atoi(str);
  str = strtok(NULL, " ");
  if (str != NULL) time->derrotas = atoi(str);
  str = strtok(NULL, " ");
  if (str != NULL) time->gols_feitos = atoi(str);
  str = strtok(NULL, " ");
  if (str != NULL) time->gols_sofridos = atoi(str);

  time->pontos = time->vitorias * 3 + time->empates;
  time->saldo = time->gols_feitos - time->gols_sofridos;
}

void trocarTimes(Time *a, Time *b) {
  Time tmp = *a;
  *a = *b;
  *b = tmp;
}

void ordenarTimes(Time times[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (times[j].pontos < times[j + 1].pontos ||
          (times[j].pontos == times[j + 1].pontos &&
           times[j].vitorias < times[j + 1].vitorias) ||
          (times[j].pontos == times[j + 1].pontos &&
           times[j].vitorias == times[j + 1].vitorias &&
           times[j].saldo < times[j + 1].saldo)) {
        trocarTimes(&times[j], &times[j + 1]);
      }
    }
  }
}

void imprimirTabela(Time times[], int n) {
  printf("Tabela do campeonato:\n");
  printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");

  for (int i = 0; i < n; i++) {
    printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", times[i].nome, times[i].pontos,
           times[i].vitorias + times[i].empates + times[i].derrotas, times[i].vitorias,
           times[i].empates, times[i].derrotas, times[i].gols_feitos, times[i].gols_sofridos,
           times[i].saldo);
  }

  printf("\nTimes na zona da libertadores:\n");
  for (int i = 0; i < 6 && i < n; i++)
    printf("%s\n", times[i].nome);

  printf("\nTimes rebaixados:\n");
  for (int i = n - 1; i >= n - 4 && i >= 0; i--)
    printf("%s\n", times[i].nome);
}

int main(void) {
  int num_times = 0;
  scanf("%d\n", &num_times);
  Time times[num_times];

  for (int i = 0; i < num_times; i++) {
    lerTime(&times[i]);
  }

  ordenarTimes(times, num_times);
  imprimirTabela(times, num_times);

  return 0;
}
