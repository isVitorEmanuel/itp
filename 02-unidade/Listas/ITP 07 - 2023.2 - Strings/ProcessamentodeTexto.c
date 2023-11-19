#include <stdio.h>
#include <string.h>

void removeSubstring(char *str, char *sub) {
  int i, j, k;
  int len = strlen(sub);
  int found;

  for (i = 0; str[i] != '\0';) {
    found = 0;
    // Verifica se a substring está presente a partir da posição atual
    for (j = i, k = 0; sub[k] != '\0'; j++, k++) {
      if (str[j] != sub[k]) {
        found = 0;
        break;
      }
      found = 1;
    }
    // Se a substring foi encontrada, remove-a
    if (found) {
      for (j = i; str[j + len] != '\0'; j++) {
        str[j] = str[j + len];
      }
      str[j] = '\0';
    } else {
      i++;
    }
  }
}

int main() {
  int tampref, tamsuf, tamanho;
  char palavra[100];

  scanf("%d\n", &tampref);
  char prefixos[tampref][11];
  for (int i = 0; i < tampref; i++) {
    scanf("%s", prefixos[i]);
  }

  scanf("%d\n", &tamsuf);
  char sufixos[tamsuf][11];
  for (int i = 0; i < tamsuf; i++) {
    scanf("%s", sufixos[i]);
  }

  do {
    scanf("%s", palavra);
    if (strcmp(palavra, "-1") != 0) {
      // verificar os prefixos
      for (int i = 0; i < tampref; i++) {
        removeSubstring(palavra, prefixos[i]);
      }
      // verificar os sufixos
      for (int i = 0; i < tamsuf; i++) {
        removeSubstring(palavra, sufixos[i]);
      }
      printf("%s\n", palavra);
    }
  } while (strcmp(palavra, "-1") != 0);
}
