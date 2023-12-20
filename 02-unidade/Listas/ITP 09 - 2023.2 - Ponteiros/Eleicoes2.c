#include <stdio.h>

#define MAX_PARTIES 100
#define MAX_VOTES 1000

typedef struct {
    int idChapa;
    char nomeChapa[10];
    int votos;
} Party;

int compute_votes(int num_votes, int votes[num_votes], int num_parties, Party parties[num_parties], Party *most_voted, Party *second_most_voted) {
    int votosValidos = 0;
    float porcPrimeiro, porcSegundo;

    for (int i = 0; i < num_parties; i++) {
      parties[i].votos = 0;
      for (int j = 0; j < num_votes; j++) {
        if (votes[j] == parties[i].idChapa) {
          parties[i].votos++;
          votosValidos++;
        }
      }
    }

    *most_voted = parties[0];
    *second_most_voted = parties[0];

    for (int i = 1; i < num_parties; i++) {
      if (parties[i].votos > most_voted->votos) {
        *second_most_voted = *most_voted;
        *most_voted = parties[i];
      } else {
        if (parties[i].votos > second_most_voted->votos) {
          *second_most_voted = parties[i];
        }
      }
    }

    porcPrimeiro = (most_voted->votos * 100.0) / votosValidos;
    porcSegundo = (second_most_voted->votos * 100.0) / votosValidos;

    printf("VENCEDOR: %s (%d votos = %.2f%%)\n", most_voted->nomeChapa, most_voted->votos, porcPrimeiro);
    printf("VICE: %s (%d votos = %.2f%%)\n", second_most_voted->nomeChapa, second_most_voted->votos, porcSegundo);

  return votosValidos;
}

int main() {
    int numChapas, numVotos;
    Party chapas[MAX_PARTIES];
    int votos[MAX_VOTES];
    Party primeiro, segundo;

    scanf("%d", &numChapas);
    for (int i = 0; i < numChapas; i++) {
      scanf("%d %s", &chapas[i].idChapa, chapas[i].nomeChapa);
    }

    scanf("%d", &numVotos);
    for (int i = 0; i < numVotos; i++) {
      scanf("%d", &votos[i]);
    }

    compute_votes(numVotos, votos, numChapas, chapas, &primeiro, &segundo);

    return 0;
}
