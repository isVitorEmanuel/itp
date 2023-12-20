#include <stdio.h>

int fib(int num) {
  if (num < 2) {
    return num;
  } else {
    return fib(num - 1) + fib(num - 2);
  }
}

int amountFib(int n1, int n2) {
  int amountFibs = 0;

  for (int i = 0; i < 15; i++) {
    if ((n1 < fib(i)) && (fib(i) < n2)) {
      amountFibs++;
    }
  }
  printf("Existem %d números de fibonacci entre %d e %d\n", amountFibs, n1, n2);
  return amountFibs;
}

int main(void) {

  int n1, n2, fibs;
  scanf("%d %d", &n1, &n2);
  fibs = amountFib(n1, n2);
}