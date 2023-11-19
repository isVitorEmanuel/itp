#include <stdio.h>

float calculaMedia(char tipo, float n1, float n2, float n3){
  
  float media = 0;

  if(tipo == 'A'){
    media = (n1 + n2 + n3)/3;
  } else {
    media = ((n1 * 4) + (n2 * 5) + (n3 * 6))/15;
  }
  
  return media;
}

int main() {

  float n1, n2, n3, aux, media;
  char type;

  scanf("%c", &type);
  
  for (int i = 0; i < 3; i++){

    scanf("%f\n", &aux);
    switch(i){
      case 0: n1 = aux; break;
      case 1: n2 = aux; break;
      case 2: n3 = aux; break;
    }
  }
  
  media = calculaMedia(type, n1, n2, n3);

  printf("Média %.2f\n", media);
}