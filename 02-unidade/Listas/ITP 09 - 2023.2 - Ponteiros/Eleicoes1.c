#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *secund_most_voted){

  int *pVetIni;
  int *pVetFim = votes + n;
  int contVotos, atual, aux = 0;
  int contPrimeiro = 0;
  int contSegundo = 0;

  for(pVetIni = votes; pVetIni < pVetFim; pVetIni++){
    atual = *pVetIni;
    contVotos = 0;
    for(int *prox = pVetIni; prox < pVetFim; prox++){
      if(*pVetIni == *prox){
        contVotos = contVotos + 1;
      }
    }
    if((contVotos > contPrimeiro) && (*pVetFim != *most_voted)){
      *secund_most_voted = *most_voted;
      *most_voted = atual;
      contSegundo = contPrimeiro;
      contPrimeiro = contVotos;
    } else {
      if((contVotos > contSegundo) && (*pVetFim !=       
      *secund_most_voted) && (*pVetFim != *most_voted)){
        *secund_most_voted = atual;
        contSegundo = contVotos;
      }
    }
  }
}

int main(void) {
  int n;
  int primeiro = 0;
  int segundo = 0;
  scanf("%d", &n);
  //ler votos
  int votos[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &votos[i]);
  }
  compute_votes(n, votos, &primeiro, &segundo);

  printf("%i %i", primeiro, segundo);
}