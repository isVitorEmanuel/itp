#include <stdio.h>

int main(void) {

  int an = -1;
  int n;
  scanf("%d", &n);
  int valores[n];

  for(int i = 0; i < n; i++){
    scanf("%d ", &valores[i]);
  }

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(valores[i] == valores[j]){
        
        printf("%d ", valores[i]);
      }
    }
   }
}