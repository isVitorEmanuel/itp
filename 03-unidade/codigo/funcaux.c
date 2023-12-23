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

void printRow(Tabela tabela, int rowNum) {
  for (int j = 0; j < tabela.numColunas; j++) {
    switch (tabela.colunas[j].tipoColuna) {
    case CHAR:
      printf("| %c ", tabela.dados[rowNum][j].dataChar);
      break;
    case STRING:
      printf("| %s ", tabela.dados[rowNum][j].dataString);
      break;
    case INT:
      printf("| %d ", tabela.dados[rowNum][j].dataInt);
      break;
    case FLOAT:
      printf("| %f ", tabela.dados[rowNum][j].dataFloat);
      break;
    case DOUBLE:
      printf("| %lf ", tabela.dados[rowNum][j].dataDouble);
      break;
    default:
      break;
    }
  }
  printf("\n");
}

void buscarValoresMaiores(Tabela tabela, char *nomeColuna, int type,
                          Celula valor) {
  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      if (strcmp(tabela.colunas[j].nomeColuna, nomeColuna) == 0) {
        switch (type) {
        case CHAR:
          if (tabela.dados[i][j].dataChar > valor.dataChar) {
            printRow(tabela, i);
          }
          break;
        case STRING:
          if (strlen(tabela.dados[i][j].dataString) >
              strlen(valor.dataString)) {
            printRow(tabela, i);
          }
          break;
        case INT:
          if (tabela.dados[i][j].dataInt > valor.dataInt) {
            printRow(tabela, i);
          }
          break;
        case FLOAT:
          if (tabela.dados[i][j].dataFloat > valor.dataFloat) {
            printRow(tabela, i);
          }
          break;
        case DOUBLE:
          if (tabela.dados[i][j].dataDouble > valor.dataDouble) {
            printRow(tabela, i);
          }
          break;
        default:
          break;
        }
      }
    }
  }
}

void buscarValoresMaioresOuIguais(Tabela tabela, char *nomeColuna, int type,
                                  Celula valor) {
  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      if (strcmp(tabela.colunas[j].nomeColuna, nomeColuna) == 0) {
        switch (type) {
        case CHAR:
          if (tabela.dados[i][j].dataChar >= valor.dataChar) {
            printRow(tabela, i);
          }
          break;
        case STRING:
          if (strlen(tabela.dados[i][j].dataString) >=
              strlen(valor.dataString)) {
            printRow(tabela, i);
          }
          break;
        case INT:
          if (tabela.dados[i][j].dataInt >= valor.dataInt) {
            printRow(tabela, i);
          }
          break;
        case FLOAT:
          if (tabela.dados[i][j].dataFloat >= valor.dataFloat) {
            printRow(tabela, i);
          }
          break;
        case DOUBLE:
          if (tabela.dados[i][j].dataDouble >= valor.dataDouble) {
            printRow(tabela, i);
          }
          break;
        default:
          break;
        }
      }
    }
  }
}

void buscarValoresIguais(Tabela tabela, char *nomeColuna, int type,
                         Celula valor) {
  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      if (strcmp(tabela.colunas[j].nomeColuna, nomeColuna) == 0) {
        switch (type) {
        case CHAR:
          if (tabela.dados[i][j].dataChar == valor.dataChar) {
            printRow(tabela, i);
          }
          break;
        case STRING:
          if (strcmp(tabela.dados[i][j].dataString, valor.dataString) == 0) {
            printRow(tabela, i);
          }
          break;
        case INT:
          if (tabela.dados[i][j].dataInt == valor.dataInt) {
            printRow(tabela, i);
          }
          break;
        case FLOAT:
          if (tabela.dados[i][j].dataFloat == valor.dataFloat) {
            printRow(tabela, i);
          }
          break;
        case DOUBLE:
          if (tabela.dados[i][j].dataDouble == valor.dataDouble) {
            printRow(tabela, i);
          }
          break;
        default:
          break;
        }
      }
    }
  }
}

void buscarValoresMenores(Tabela tabela, char *nomeColuna, int type,
                          Celula valor) {
  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      if (strcmp(tabela.colunas[j].nomeColuna, nomeColuna) == 0) {
        switch (type) {
        case CHAR:
          if (tabela.dados[i][j].dataChar < valor.dataChar) {
            printRow(tabela, i);
          }
          break;
        case STRING:
          if (strlen(tabela.dados[i][j].dataString) <
              strlen(valor.dataString)) {
            printRow(tabela, i);
          }
          break;
        case INT:
          if (tabela.dados[i][j].dataInt < valor.dataInt) {
            printRow(tabela, i);
          }
          break;
        case FLOAT:
          if (tabela.dados[i][j].dataFloat < valor.dataFloat) {
            printRow(tabela, i);
          }
          break;
        case DOUBLE:
          if (tabela.dados[i][j].dataDouble < valor.dataDouble) {
            printRow(tabela, i);
          }
          break;
        default:
          break;
        }
      }
    }
  }
}

void buscarValoresMenoresOuIguais(Tabela tabela, char *nomeColuna, int type,
                                  Celula valor) {
  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      if (strcmp(tabela.colunas[j].nomeColuna, nomeColuna) == 0) {
        switch (type) {
        case CHAR:
          if (tabela.dados[i][j].dataChar <= valor.dataChar) {
            printRow(tabela, i);
          }
          break;
        case STRING:
          if (strlen(tabela.dados[i][j].dataString) <=
              strlen(valor.dataString)) {
            printRow(tabela, i);
          }
          break;
        case INT:
          if (tabela.dados[i][j].dataInt <= valor.dataInt) {
            printRow(tabela, i);
          }
          break;
        case FLOAT:
          if (tabela.dados[i][j].dataFloat <= valor.dataFloat) {
            printRow(tabela, i);
          }
          break;
        case DOUBLE:
          if (tabela.dados[i][j].dataDouble <= valor.dataDouble) {
            printRow(tabela, i);
          }
          break;
        default:
          break;
        }
      }
    }
  }
}

int minimum(int a, int b, int c) {
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  return min;
}

int levenshteinDistance(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int **dp = malloc((len1 + 1) * sizeof(int *));
  for (int i = 0; i <= len1; i++) {
    dp[i] = malloc((len2 + 1) * sizeof(int));
  }
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + minimum(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
      }
    }
  }
  int result = dp[len1][len2];
  for (int i = 0; i <= len1; i++) {
    free(dp[i]);
  }
  free(dp);

  return result;
}

bool testaparecida(char *str1, char *str2) {
  int dist = levenshteinDistance(str1, str2);
  return dist <= 2; 
}

int encontrarNumeroDaColuna(Tabela tabela, char *nomeColuna) {
  for (int i = 0; i < tabela.numColunas; i++) {
    if (strcmp(tabela.colunas[i].nomeColuna, nomeColuna) == 0) {
      return i;
    }
  }
  return -1; 
}

void buscarValoresParecidos(Tabela tabela, char *nomeColuna, char *string) {
  int coluna = encontrarNumeroDaColuna(tabela, nomeColuna);
  if (coluna != -1) {
    bool valorEncontrado = false;
    for (int i = 0; i < tabela.numLinhas; i++) {
      if (testaparecida(tabela.dados[i][coluna].dataString, string)) {
        valorEncontrado = true;
        printRow(tabela, i);
      }
    }
    if (!valorEncontrado) {
      printf("Nenhum valor foi encontrado\n");
    }
  } else {
    printf("Nome da coluna não encontrado\n");
  }
}
