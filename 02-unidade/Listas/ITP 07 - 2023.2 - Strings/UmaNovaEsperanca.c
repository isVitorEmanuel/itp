#include <stdio.h>
#include <string.h>

const char S[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

char procurarindice(char carac) {
  for (int i = 0; i < 40; i++) {
    if (S[i] == carac) {
      return i;
    }
  }
  return -1;
}

int cripto(char mensagem[], int key[]) {
  int posChave;
  char indice;

  for (int i = 0; i < strlen(mensagem); i++) {
    posChave = i % 4;
    indice = procurarindice(mensagem[i]);
    if (indice == -1) {
      return -1;
    }
    mensagem[i] = S[(indice + key[posChave]) % 40];
  }
  return 0;
}

int main(void) {

  int chaveValor;
  int chave[4] = {0};
  char mensagem[200];

  scanf("%d ", &chaveValor);
  fgets(mensagem, 200, stdin);
  mensagem[strlen(mensagem) - 1] = '\0';

  if (chaveValor > 0 && chaveValor < 9999) {
    for (int i = 3; i >= 0 && chaveValor > 0; i--) {
      chave[i] = chaveValor % 10;
      chaveValor = chaveValor / 10;
    }

    int Cript = cripto(mensagem, chave);

    if (Cript == -1) {
      printf("Caractere invalido na entrada!");
    } else {
      printf("%s\n", mensagem);
    }

  } else {
    printf("Chave invalida!");
  }
}