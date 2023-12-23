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

Tabela *inserirTabela(Tabela *tabelas, int *numTab, Tabela novaTabela) {
  (*numTab)++;
  tabelas = realloc(tabelas, sizeof(Tabela) * (*numTab));

  tabelas[*numTab - 1] = novaTabela;

  return tabelas;
}

void salvarNome(Tabela *tabelas, int numTabs) {
  FILE *arqTab = fopen("nometabelas.txt", "w");

  if (arqTab == NULL) {
    printf("Arquivo nao encontrado!");
  } else {
    for (int i = 0; i < numTabs; i++) {
      fprintf(arqTab, "%s\n", tabelas[i].nomeTabela);
    }
  }
  fclose(arqTab);
}

void salvarQuantidade(int numTabs) {
  FILE *arqTab = fopen("qtdtabelas.txt", "w");

  if (arqTab == NULL) {
    printf("Arquivo nao encontrado!");
  } else {
    fprintf(arqTab, "%d", numTabs);
  }
  fclose(arqTab);
}

void salvarTabela(Tabela tabela) {

  char nomeArquivo[MAX_NAME];
  sprintf(nomeArquivo, "tabelas/%s.txt", tabela.nomeTabela);

  FILE *arquivo = fopen(nomeArquivo, "w");

  if (arquivo != NULL) {

    fprintf(arquivo, "%s\n", tabela.nomeTabela);
    fprintf(arquivo, "%d %d\n", tabela.numColunas, tabela.numLinhas);

    for (int i = 0; i < tabela.numColunas; i++) {

      fprintf(arquivo, "%s %d\n", tabela.colunas[i].nomeColuna,
              tabela.colunas[i].tipoColuna);
    }
    for (int i = 0; i < tabela.numLinhas; i++) {
      for (int j = 0; j < tabela.numColunas; j++) {
        switch (tabela.colunas[j].tipoColuna) {
        case CHAR:
          fprintf(arquivo, "%c ", tabela.dados[i][j].dataChar);
          break;
        case STRING:
          fprintf(arquivo, "%s ", tabela.dados[i][j].dataString);
          break;
        case INT:
          fprintf(arquivo, "%d ", tabela.dados[i][j].dataInt);
          break;
        case FLOAT:
          fprintf(arquivo, "%f ", tabela.dados[i][j].dataFloat);
          break;
        case DOUBLE:
          fprintf(arquivo, "%lf ", tabela.dados[i][j].dataDouble);
          break;
        default:
          break;
        }
      }

      fprintf(arquivo, "\n");
    }
    fclose(arquivo);
  } else {
    printf("Erro - Arquivo nao encontrado!\n");
  }
}