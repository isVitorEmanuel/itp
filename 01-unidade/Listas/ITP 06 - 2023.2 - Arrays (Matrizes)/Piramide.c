#include <stdio.h>

void preencherMatriz(int linIni, int linFin, int colIni, int colFin,
                     int matriz[10][10], int ponto) {
  for (int l = linIni; l <= linFin; l++)
    for (int c = colIni; c <= colFin; c++)
      matriz[l][c] = ponto;
}

int main(void) {
  int alt = 0, maxPoint = 0;
  scanf("%d", &alt);
  int piramide[10][10] = {0};
  maxPoint = (alt + 1) / 2;
  for (int i = 1; i <= maxPoint; i++) {
    preencherMatriz(i - 1, alt - i, i - 1, alt - i, piramide, i);
  }
  for (int l = 0; l < alt; l++) {
    for (int c = 0; c < alt; c++) {
      printf("%d ", piramide[l][c]);
    }
    printf("\n");
  }
}