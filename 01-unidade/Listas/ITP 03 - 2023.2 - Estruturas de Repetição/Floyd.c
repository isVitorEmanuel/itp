#include <stdio.h>

int main() {

  int num;
  int som = 0;
  scanf("%d", &num);

  if (num > 0) {
    for (int lin = 1; lin <= num; lin++) {
      for (int colu = 1; colu <= lin; colu++) {
        som++;
        printf("%2d ", som);
     } 
      printf("\n");
  }
  } else {
    printf("Você entrou com %d, tente de novo na próxima", num); 
  }
}