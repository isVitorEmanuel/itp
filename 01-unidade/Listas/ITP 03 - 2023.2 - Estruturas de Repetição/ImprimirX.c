#include <stdio.h>

int main() {

  int n;
  char letra;

  scanf("%d %c", &n, &letra);

  for (int lin = 1; lin < n; lin++) {
    for (int colum = 1; colum < n; colum++) {
      if((lin == colum) || (colum == n - lin)) {
        printf("%c", letra);
      } else {
        printf(" ");
      }
    }
    printf(" \n");
  }
}