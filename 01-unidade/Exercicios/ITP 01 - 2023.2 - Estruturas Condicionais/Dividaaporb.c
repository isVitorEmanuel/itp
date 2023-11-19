#include <stdio.h>

int main() {

  int a, b;
  
  scanf("%d %d", &b, &a);
  
  if ((b % a) == 0) {
    int div = b / a;
    printf("Resultado: %d\n", div);
  }
}