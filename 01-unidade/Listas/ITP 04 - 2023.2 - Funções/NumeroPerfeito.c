#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int verifyPerfect(int number) {

  bool isPerfect = true;
  int countDiv = 0;

  for (int div = 1; div < number; div++) {
    if ((number % div) == 0) {
      countDiv = countDiv + div;
    }
  }

  if (countDiv == number) {
    isPerfect = true;
  } else {
    isPerfect = false;
  }
  return isPerfect;
}

int main() {

  verifyPerfect(28);
  int allCases;

  scanf("%d", &allCases);

  for(int count = 1; count <= allCases; count++) {

    int actCase;

    scanf("%d", &actCase);

    if(verifyPerfect(actCase) == true) {
      printf("%d eh perfeito\n", actCase);
    } else {
      printf("%d nao eh perfeito\n", actCase);
    }
  }
}