#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definicoes.h"
#include "funcaux.h"

Tabela criarTabela() {

  char nomeTabela[MAX_NAME];
  char nomeColuna[MAX_NAME];
  char nomeChave[MAX_NAME];

  Tabela tabela;

  printf("----------------------------------------------\n");
  printf("Digite o nome da tabela: ");
  scanf("%s", nomeTabela);
  strcpy(tabela.nomeTabela, nomeTabela);

  do {
    
    printf("Digite o numero de colunas: ");
    scanf("%d", &tabela.numColunas);

    if (tabela.numColunas <= 0) {
      printf("ERRO\n");
    } else {
 
      tabela.colunas = calloc(tabela.numColunas, sizeof(Coluna));

      printf("Digite o nome da primaria: ");
      scanf("%s", nomeChave);
      strcpy(tabela.chavePrimaria.nomeColuna, nomeChave);
      tabela.chavePrimaria.tipoColuna = INT;

      strcpy(tabela.colunas[0].nomeColuna, nomeChave);
      tabela.colunas->tipoColuna = INT;

      for (int i = 1; i < tabela.numColunas; i++) {
        printf("Digite o nome da coluna %i: ", i + 1);
        scanf("%s", nomeColuna);
        strcpy(tabela.colunas[i].nomeColuna, nomeColuna);

        printf("Digite o tipo da coluna %i: \n0 - CHAR\n1 - STRING\n2 - INT\n"
               "3 - FLOAT\n4 - DOUBLE\n: ",
               i + 1);

        scanf("%d", &tabela.colunas[i].tipoColuna);

        printf("Tabela criada com sucesso!\n");
      }
    }
  } while (tabela.numColunas <= 0);

  tabela.numLinhas = 0;

  return tabela;
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

void listarTabelas(Tabela *tabelas, int numTab) {

  printf("----------------------------------------------\n");
  printf("NUMERO DE TABELAS: %d\n", numTab);
  for (int i = 0; i < numTab; i++) {
    printf("%d - %s\n", (i + 1), tabelas[i].nomeTabela);
  }
}

void adicionarLinha(Tabela *tabela) {

  int chavePrimaria;
  bool chaveRepetida = false;

  printf("Digite o valor da chave primaria (inteiro): ");
  scanf("%d", &chavePrimaria);

  for (int i = 0; i < tabela->numLinhas; i++) {
    if (tabela->dados[i][0].dataInt == chavePrimaria) {
      chaveRepetida = true;
    }
  }

  if (chaveRepetida) {
    printf("Chave primaria repetida!\n");
  } else {
    tabela->numLinhas++;

    if (tabela->numLinhas == 1) {
      tabela->dados = malloc(tabela->numLinhas * sizeof(Celula *));
    } else {
      tabela->dados =
          realloc(tabela->dados, tabela->numLinhas * sizeof(Celula *));
    }

    for (int i = tabela->numLinhas - 1; i < tabela->numLinhas; ++i) {
      tabela->dados[i] = malloc(tabela->numColunas * sizeof(Celula));
    }

    tabela->dados[tabela->numLinhas - 1][0].dataInt = chavePrimaria;

    for (int i = 1; i < tabela->numColunas; i++) {
      printf("Digite o valor para a coluna '%s': ",
             tabela->colunas[i].nomeColuna);

      switch (tabela->colunas[i].tipoColuna) {
      case CHAR:
        scanf(" %c", &tabela->dados[tabela->numLinhas - 1][i].dataChar);
        break;
      case STRING:
        tabela->dados[tabela->numLinhas - 1][i].dataString =
            malloc(MAX_NAME * sizeof(char));
        scanf("%s", tabela->dados[tabela->numLinhas - 1][i].dataString);
        break;
      case INT:
        scanf("%d", &tabela->dados[tabela->numLinhas - 1][i].dataInt);
        break;
      case FLOAT:
        scanf("%f", &tabela->dados[tabela->numLinhas - 1][i].dataFloat);
        break;
      case DOUBLE:
        scanf("%lf", &tabela->dados[tabela->numLinhas - 1][i].dataDouble);
        break;
      default:
        break;
      }
    }
    printf("Linha adicionada com sucesso!\n");
  }
}

void listarDadosTabela(Tabela tabela) {

  printf("------ DADOS DA TABELA ------\n");

  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      switch (tabela.colunas[j].tipoColuna) {
      case CHAR:
        printf("| %c |", tabela.dados[i][j].dataChar);
        break;
      case STRING:
        printf("| %s |", tabela.dados[i][j].dataString);
        break;
      case INT:
        printf("| %i |", tabela.dados[i][j].dataInt);
        break;
      case FLOAT:
        printf("| %f |", tabela.dados[i][j].dataFloat);
        break;
      case DOUBLE:
        printf("| %lf |", tabela.dados[i][j].dataDouble);
        break;
      default:
        // Tratamento para tipos desconhecidos
        break;
      }
      printf(" ");
    }
    printf("\n");
  }
}

Tabela *apagarTabela(Tabela *tabelas, int *numTab, char *nomeTabela) {

  Tabela tabelaRetornada;
  int tabelaEncontrada = -1;
  char nomeArquivo[MAX_NAME];

  sprintf(nomeArquivo, "tabelas/%s.txt", nomeTabela);

  if (remove(nomeArquivo) == 0) {
    printf("Arquivo %s excluido com sucesso.\n", nomeArquivo);
    for (int i = 0; i < *numTab; i++) {
      if (strcmp(tabelas[i].nomeTabela, nomeTabela) == 0) {
        tabelaEncontrada = i;
        tabelaRetornada = tabelas[i];
        break;
      }
    }

    if (tabelaEncontrada != -1) {
      for (int i = tabelaEncontrada; i < *numTab - 1; i++) {
        tabelas[i] = tabelas[i + 1];
      }
      (*numTab)--;
      printf("Tabela excluida: %s\n", nomeTabela);
      Tabela *result = calloc(*numTab, sizeof(Tabela));
      for (int j = 0; j < *numTab; j++) {
        result[j] = tabelas[j];
      }
      return result;
    } else {
      printf("Erro ao excluir o arquivo %s\n", nomeArquivo);
      return tabelas;
    }
  }
}