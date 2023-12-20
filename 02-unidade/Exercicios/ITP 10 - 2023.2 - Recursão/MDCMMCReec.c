#include <stdio.h>

int mdc(int x, int y) {
  if (x % y == 0) {
    return y;
  } else {
    return mdc(y, x % y);
  }
}

void calc_mdc_mmc(int x, int y, int *pmdc, int *pmmc) {
  *pmdc = mdc(x, y);
  *pmmc = (x * y) / *pmdc;
}

int main(void) {
  int x, y;
  int mdc, mmc;
  scanf("%d %d", &x, &y);

  calc_mdc_mmc(x, y, &mdc, &mmc);
  printf("MDC = %d, MMC = %d", mdc, mmc);
}