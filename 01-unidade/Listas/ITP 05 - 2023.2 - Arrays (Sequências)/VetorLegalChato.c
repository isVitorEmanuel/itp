#include <stdio.h>

int verificaPar(int numero){
  if((numero % 2) == 0){
    return 1;
  } else{
    return 0;
  }
}

int verificaLegal(int *vet, int n){

  int leg = 1;
  int sub;
  
  for(int i = 0; i < n; i++){
    if(i > 0){
      sub = vet[i] - vet[i - 1];
      if(verificaPar(sub) == 0){
        leg = 0;
      } 
    }
  }
  return leg;
}

int main(void) {

  int n, sub;
  int leg;
  
  scanf("%d", &n);

  int valores[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &valores[i]);
  }

  leg = verificaLegal(valores, n);

  if(leg == 1){
    printf("Legal");
  } else {
    printf("Chato");
  }
}