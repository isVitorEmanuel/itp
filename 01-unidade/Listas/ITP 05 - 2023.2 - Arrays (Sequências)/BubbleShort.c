#include <stdio.h>

int main(){
  int n, aux, stop;

  scanf("%d", &n);
  int valores[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &valores[i]);
  }
  
  do{
    stop = 0;
    
    for(int i = 0; i < n; i++){
      printf("%d ", valores[i]);
    }
    
    printf("\n");

    for(int i = 0; i < (n - 1); i++){
      if(valores[i] > valores[i + 1]){
        aux = valores[i];
        valores[i] = valores[i + 1];
        valores[i + 1] = aux;
        stop = 1;
        }
      }    
  } while(stop == 1);
}