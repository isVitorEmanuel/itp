#include <stdio.h>
#include <string.h>

int buscarPadrao(char texto[], char padrao[]) {
  int tamanhoTexto = strlen(texto);
  int tamanhoPadrao = strlen(padrao);
  
  int ocorrencias[tamanhoTexto];
  for(int i = 0; i < tamanhoTexto; i++) {
    ocorrencias[i] = 0;
    for(int j = tamanhoPadrao - 1; j >= 0; j--) {
      if (texto[i] ==  padrao[j]) {
        ocorrencias[i] = 1;
        break;
      }
    }
  }
  
  for(int i = 0; i <= tamanhoTexto - tamanhoPadrao; i++) {
    for(int j = 0; j < tamanhoPadrao; j++) {
      printf("%c ", texto[i + j]);
      if (texto[i + j] != padrao[j]) {
        printf("não\n");
        if (!ocorrencias[i + j]) {
          i += j;
        }
        break;
      }
      else if (j == tamanhoPadrao - 1) {
        printf("sim\n");
        return i;
      }
    }
  }
  return -1;
}

int main() {
  char texto[50];
  char padrao[50];
  scanf("%s %s", texto, padrao);
  
  int posicao = buscarPadrao(texto, padrao);
  if (posicao < 0) {
    printf("Não achei o padrão\n");
  }
  else {
    printf("Achei o padrão no índice %i\n", posicao);
  }

  return 0;
}
