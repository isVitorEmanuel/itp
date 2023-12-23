#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definicoes.h"

void carregarQuantidade(int *numTabs) {
  FILE *arqTab = fopen("qtdtabelas.txt", "r");

  if (arqTab == NULL) {
    printf("Arquivo nao encontrado!");
  } else {
    fscanf(arqTab, "%i", numTabs);
  }
}