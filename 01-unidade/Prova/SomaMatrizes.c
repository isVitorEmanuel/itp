#include <stdio.h>

int main(void) {

  int n;
  int dia1 = 0;
  int dia2 = 0;
  int soma = 0;
  
  scanf("%d", &n);
  
  int matriz[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d ", &matriz[i][j]);
    }
    scanf("\n");
  }
  //soma diagonal principal
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(i == j){
        dia1 = dia1 + matriz[i][j];
      }
    }
  }
  //soma diagonal secunadaria
  for (int i = 0; i < n; i++) {
    dia2 = dia2 + matriz[i][n - 1 - i];
  }

  soma = dia1 + dia2;
  
  printf("%d", soma);
  return 0;
}