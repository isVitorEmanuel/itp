#include <stdio.h>

void retornaVetor(int tam, int *vet) {

  int vetAux[tam];
  int j, i, menor, maior, menorPos, pos = 0;

  maior = vet[0];
  menorPos = 0;

  for (i = 0; i < tam; i++) {
    menor = maior;
    for (j = 0; j < tam; j++) {
      if (vet[j] < menor) {
        menor = vet[j];
        menorPos = j;
      } else if (vet[j] > maior) {
        maior = vet[j];
      }
    }

    vetAux[pos] = menor;
    pos++;
    vet[menorPos] = maior + 1;
  }

  for (i = 0; i < tam; i++) {
    vet[i] = vetAux[i];
  }
}

int main(void) {
  // inicializar variaveis e vetores
  int N, M, repe;
  int aux = 0;

  scanf("%d %d", &N, &M);

  int conj1[N], conj2[M];
  int vetoraux[100] = {0};

  for (int i = 0; i < N; i++) {
    scanf("%d", &conj1[i]);
  }

  for (int i = 0; i < M; i++) {
    scanf("%d", &conj2[i]);
  }
  // verificação
  for (int i = 0; i < N; i++) {
    repe = 0;
    for (int j = 0; j < M; j++) {
      if (conj1[i] == conj2[j]) {
        repe++;
      }
    }
    
    if (repe == 0) {
      for (int k = 0; k < 20; k++) {
        if (vetoraux[k] == 0) {
          vetoraux[k] = conj1[i];
          break;
        } 
      }
      aux++;
    }
  }

  for (int i = 0; i < M; i++) {
    repe = 0;
    for (int j = 0; j < N; j++) {
      if (conj2[i] == conj1[j]) {
        repe++;
      }
    }
    if (repe == 0) {
      for (int k = 0; k < 20; k++) {
        if (vetoraux[k] == 0) {
          vetoraux[k] = conj2[i];
          break;
        } 
      }
      aux++;
    }
  }
  //colocar valores no diff e configurálo
  int vetDiff[aux];

  for(int i = 0; i < aux; i++){
    vetDiff[i] = vetoraux[i];
  }
  
  retornaVetor(aux, vetDiff);
  //imprimir valor alterado
  for(int i = 0; i < aux; i++){
    printf("%d ", vetDiff[i]);
  }
}