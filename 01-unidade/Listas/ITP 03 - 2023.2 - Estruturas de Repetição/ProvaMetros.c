#include <stdio.h>

int main(void) {

  double max, var;
  int count = 1;
  int atl = 0;
  int serie, resto;

  do {

    scanf("%lf", &var);

    if (count == 1) {
      max = var;
    } else {
      if (var <= max) {
        atl++;
      }
    }

    count++;

  } while (var != -1);

  atl--;

  resto = (atl % 8);

  if (resto == 0) {
    serie = atl / 8;
  } else {
    serie = (atl / 8) + 1;
  }

  printf("%d %d", atl, serie);
}
