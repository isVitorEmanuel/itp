#include <stdbool.h>
#include <stdio.h>

bool verifyEnd(char tab_aux[3][3], char icon, int linha, int coluna) {
  bool end = false;
  tab_aux[linha - 1][coluna - 1] = icon;
  for (int i = 0; i < 3; i++) {
    if ((tab_aux[i][0] != '.') &&
        (tab_aux[i][0] == tab_aux[i][1] && tab_aux[i][1] == tab_aux[i][2])) {
      end = true;
    }
    if ((tab_aux[0][i] == tab_aux[1][i] && tab_aux[1][i] == tab_aux[2][i]) &&
        (tab_aux[0][i] != '.')) {
      end = true;
    }
  }
  if (tab_aux[0][0] == tab_aux[1][1] && tab_aux[1][1] == tab_aux[2][2] &&
      tab_aux[0][0] != '.') {
    end = true;
  }
  if (tab_aux[0][2] == tab_aux[1][1] && tab_aux[1][1] == tab_aux[2][0] &&
      tab_aux[0][2] != '.') {
    end = true;
    ;
  }
  return end;
}

int main(void) {
  char tabuleiro[3][3], tab_aux[3][3], icone;
  int jogadas, linha, coluna;
  bool endGame = false;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%c", &tabuleiro[i][j]);
    }
    scanf("\n");
  }

  scanf("%d", &jogadas);

  for (int i = 0; i < jogadas; i++) {
    scanf("%d %d %c", &linha, &coluna, &icone);

    if (tabuleiro[linha - 1][coluna - 1] == 'X' ||
        tabuleiro[linha - 1][coluna - 1] == 'O') {
      printf("Jogada inválida!\n");
    } else {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          tab_aux[i][j] = tabuleiro[i][j];
        }
      }

      endGame = verifyEnd(tab_aux, icone, linha, coluna);

      if (endGame == true) {
        printf("Boa jogada, vai vencer!\n");
      } else {
        printf("Continua o jogo.\n");
      }
    }
  }
}