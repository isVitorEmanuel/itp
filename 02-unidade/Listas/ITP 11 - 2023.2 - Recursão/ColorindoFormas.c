#include <stdio.h>

void colorir(int m, int n, char matriz[m][n], int posL, int posC, char cor, char corAnt) {
  if (matriz[posL][posC] == corAnt) {
    matriz[posL][posC] = cor;
  }

  if (posL > 0 && matriz[posL - 1][posC] == corAnt) {
    colorir(m, n, matriz, posL - 1, posC, cor, corAnt);
  }

  if (posC < n - 1 && matriz[posL][posC + 1] == corAnt) {
    colorir(m, n, matriz, posL, posC + 1, cor, corAnt);
  }

  if (posL < m - 1 && matriz[posL + 1][posC] == corAnt) {
    colorir(m, n, matriz, posL + 1, posC, cor, corAnt);
  }

  if (posC > 0 && matriz[posL][posC - 1] == corAnt) {
    colorir(m, n, matriz, posL, posC - 1, cor, corAnt);
  }
}

int main(void) {
  int m, n, posL, posC;
  char enter, cor, corAnt;

  scanf("%d %d", &m, &n);
  scanf("%c", &enter);

  char matriz[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%c", &matriz[i][j]);
    }
    scanf("%c", &enter);
  }

  scanf("%d %d %c", &posL, &posC, &cor);
  corAnt = matriz[posL][posC];

  colorir(m, n, matriz, posL, posC, cor, corAnt);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }
}
