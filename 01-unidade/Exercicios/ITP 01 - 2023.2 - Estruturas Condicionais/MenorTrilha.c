#include <stdio.h>

int main() {

  int T, S;

  scanf("%d", &T);

  if ((T >= 0) && (T < 5)) {
    
    printf("Iniciante\n");
    
  } else {

    scanf("%d", &S);

    if ((T >= 5) && (T < 20)) {
      
      if (S == 0) {
        printf("Iniciante\n");
      } else {
        printf("Intermediário\n");
      }
   
    } else {

      if (S == 0) {
        printf("Intermediário\n");
      } else {
        printf("Avançado\n");
      }
    }
  }
}