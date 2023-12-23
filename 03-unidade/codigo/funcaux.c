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

void *carregarTabelas(Tabela *tabelas, int *numTabs) {
  FILE *arquivo = fopen("nometabelas.txt", "r");

  char nomeTabela[MAX_NAME];
  char nomeArquivoTabela[MAX_NAME + 11];

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de lista de tabelas!\n");
  }

  while (fgets(nomeTabela, MAX_NAME, arquivo) != NULL) {

    nomeTabela[strcspn(nomeTabela, "\n")] = '\0';
    sprintf(nomeArquivoTabela, "tabelas/%s.txt", nomeTabela);
    FILE *arquivoTabela = fopen(nomeArquivoTabela, "r");

    if (arquivoTabela == NULL) {
      continue;
    }

    Tabela novaTabela;

    fscanf(arquivoTabela, "%s", novaTabela.nomeTabela);
    fscanf(arquivoTabela, "%d %d", &novaTabela.numColunas,
           &novaTabela.numLinhas);

    novaTabela.colunas = calloc(novaTabela.numColunas, sizeof(Coluna));
    for (int i = 0; i < novaTabela.numColunas; i++) {
      fscanf(arquivoTabela, "%s %d", novaTabela.colunas[i].nomeColuna,
             &novaTabela.colunas[i].tipoColuna);
    }
  
    novaTabela.dados = malloc(novaTabela.numLinhas * sizeof(Celula *));
    for (int i = 0; i < novaTabela.numLinhas; i++) {
      novaTabela.dados[i] = malloc(novaTabela.numColunas * sizeof(Celula));
    }

    for (int i = 0; i < novaTabela.numLinhas; i++) {
      for (int j = 0; j < novaTabela.numColunas; j++) {
        switch (novaTabela.colunas[j].tipoColuna) {
        case CHAR:
          fscanf(arquivoTabela, "%c", &novaTabela.dados[i][j].dataChar);
          break;
        case STRING:
          novaTabela.dados[i][j].dataString = malloc(MAX_NAME * sizeof(char));
          fscanf(arquivoTabela, "%s ", novaTabela.dados[i][j].dataString);
          break;
        case INT:
          fscanf(arquivoTabela, "%d", &novaTabela.dados[i][j].dataInt);
          break;
        case FLOAT:
          fscanf(arquivoTabela, "%f", &novaTabela.dados[i][j].dataFloat);
          break;
        case DOUBLE:
          fscanf(arquivoTabela, "%lf", &novaTabela.dados[i][j].dataDouble);
          break;
        default:
          break;
        }
      }
    }

    (*numTabs)++;
    tabelas = realloc(tabelas, sizeof(Tabela) * (*numTabs));
    tabelas[*numTabs - 1] = novaTabela;
    fclose(arquivoTabela);
  }

  fclose(arquivo);

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


// Função que apaga uma linha de uma tabela OK
void apagarLinha(char *nomeTabela, Tabela *tabelas, int numTabs,
                 int chavePrimaria) {

  for (int i = 0; i < numTabs; i++) {
    if (strcmp(tabelas[i].nomeTabela, nomeTabela) == 0) {
      for (int j = 0; j < tabelas[i].numLinhas; j++) {
        if (tabelas[i].dados[j][0].dataInt == chavePrimaria) {
          free(tabelas[i].dados[j]); // Liberar memória alocada para a linha
          for (int k = j; k < tabelas[i].numLinhas - 1;
               k++) { // Deslocar as outras linhas
            tabelas[i].dados[k] = tabelas[i].dados[k + 1];
          }
          tabelas[i].numLinhas--; // Atualizar o número de linhas
          tabelas[i].dados = realloc(tabelas[i].dados, tabelas[i].numLinhas * sizeof(Celula *));
        }
      }
      salvarTabela(tabelas[i]); 
      break;
    }
  }
  printf("Linha deletada!");
}