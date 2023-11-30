#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
/* Definição de um tipo enumerado para ser os possíveis tipos das células e
 colunas. - OK */
typedef enum { CHAR, STRING, INT, FLOAT, DOUBLE } Types;

// Definição da estrutura da célula - OK
typedef struct {
  char dataChar;
  int dataInt;
  float dataFloat;
  double dataDouble;
  char *dataString;
} Celula;

// Implementar o tipo estruturado da coluna - OK
typedef struct {
  char nomeColuna[MAX_NAME];
  Types tipoColuna;
} Coluna;

// Implementar o tipo estruturo da tabela - OK
typedef struct {
  char nomeTabela[MAX_NAME];
  int numLinhas;
  int numColunas;
  Coluna *colunas; // Guardará os nomes das colunas e os tipos
  Coluna chavePrimaria;
  Celula **dados; // Matriz de células
} Tabela;

// -- Funções
// Função que inicializa uma tabela - OK
Tabela criarTabela() {

  char nomeTabela[MAX_NAME];
  char nomeColuna[MAX_NAME];
  char nomeChave[MAX_NAME];

  Tabela tabela; // Aloca espaço para uma tabela

  printf("Digite o nome da tabela: ");
  scanf("%s", nomeTabela);
  strcpy(tabela.nomeTabela, nomeTabela);

  printf("Digite o número de colunas: ");
  scanf("%d", &tabela.numColunas);

  if (tabela.numColunas <= 0) {
    printf("ERRO\n");
  } else {
    // Aloca espaço para o vetor colunas
    tabela.colunas = calloc(tabela.numColunas, sizeof(Coluna));

    printf("Digite o nome da coluna primária: ");
    scanf("%s", nomeChave);
    strcpy(tabela.chavePrimaria.nomeColuna, nomeChave);
    tabela.chavePrimaria.tipoColuna = INT;

    strcpy(tabela.colunas[0].nomeColuna, nomeChave);
    tabela.colunas->tipoColuna = INT;

    for (int i = 1; i < tabela.numColunas; i++) {
      printf("Digite o nome da coluna %i: ", i + 1);
      scanf("%s", nomeColuna);
      strcpy(tabela.colunas[i].nomeColuna, nomeColuna);

      printf("Digite o tipo da coluna %i \n(0 - CHAR / 1 - STRING / 2 - INT / "
             "3 - FLOAT / 4 - DOUBLE): ",
             i + 1);

      scanf("%d", &tabela.colunas[i].tipoColuna);
    }
  }

  tabela.numLinhas = 0;

  return tabela;
}
// Funcão que adiciona tabelas em um vetor - OK
Tabela *inserirTabela(Tabela *tabelas, int *numTab, Tabela novaTabela) {
  (*numTab)++;
  tabelas = realloc(tabelas, sizeof(Tabela) * (*numTab));

  tabelas[*numTab - 1] = novaTabela;

  return tabelas;
}
// Função que lista as tabelas disponíveis - OK
void listarTabelas(Tabela *tabelas, int numTab) {
  printf("TABELAS: \n");
  for (int i = 0; i < numTab; i++) {
    printf("Nome da tabela: %s\n", tabelas[i].nomeTabela);
  }
}
// Função que adiciona linha - OK
void adicionarLinha(Tabela *tabela) {

  int chavePrimaria;
  bool chaveRepetida = false;

  printf("Digite o valor da chave primária (inteiro): ");
  scanf("%d", &chavePrimaria);

  for (int i = 0; i < tabela->numLinhas; i++) {
    if (tabela->dados[i][0].dataInt == chavePrimaria) {
      chaveRepetida = true;
    }
  }

  if (chaveRepetida) {
    printf("Chave primária repetida!\n");
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
      printf("Digite o valor para a coluna %s: ",
             tabela->colunas[i].nomeColuna);

      switch (tabela->colunas[i].tipoColuna) {
      case CHAR:
        scanf(" %c", &tabela->dados[tabela->numLinhas - 1][i].dataChar);
        break;
      case STRING:
        tabela->dados[tabela->numLinhas - 1][i].dataString =
            malloc(MAX_NAME * sizeof(char));
        printf("(max %d caracteres) ", MAX_NAME - 1);
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
        // Tratamento para tipos desconhecidos
        break;
      }
    }
  }
}

void salvarTabela(Tabela tabela) {

  char nomeArquivo[MAX_NAME];
  sprintf(nomeArquivo, "%s.txt", tabela.nomeTabela);

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
    printf("Error opening file!\n");
  }
}

void listarDadosTabela(Tabela tabela) {
  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      switch (tabela.colunas[j].tipoColuna) {
      case CHAR:
        printf("%c", tabela.dados[i][j].dataChar);
        break;
      case STRING:
        printf("%s", tabela.dados[i][j].dataString);
        break;
      case INT:
        printf("%i", tabela.dados[i][j].dataInt);
        break;
      case FLOAT:
        printf("%f", tabela.dados[i][j].dataFloat);
        break;
      case DOUBLE:
        printf("%lf", tabela.dados[i][j].dataDouble);
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

void pesquisarValores() {}

void apagarLinha() {}

void apagarTabela() {}

void *carregarTabelas(Tabela *tabelas, int *numTabs) {
  FILE *arquivo = fopen("tabelas.txt", "r");

  char nomeTabela[MAX_NAME];
  char nomeArquivoTabela[MAX_NAME + 11];

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de lista de tabelas!\n");
  }

  while (fgets(nomeTabela, MAX_NAME, arquivo) != NULL) {
    // Remove o caractere de nova linha, se presente
    nomeTabela[strcspn(nomeTabela, "\n")] = '\0';

    printf("%s\n", nomeTabela);

    sprintf(nomeArquivoTabela, "%s.txt", nomeTabela);
    printf("Arquivo da Tabela: %s\n", nomeArquivoTabela);

    FILE *arquivoTabela = fopen(nomeArquivoTabela, "r");

    if (arquivoTabela == NULL) {
      continue;
    } else {
      printf("abriu\n");
    }
    // Cria uma nova tabela no vetor
    Tabela novaTabela;
    // Nome
    fscanf(arquivoTabela, "%s", novaTabela.nomeTabela);

    printf("Nome: %s\n", novaTabela.nomeTabela);
    // Colunas
    fscanf(arquivoTabela, "%d %d", &novaTabela.numColunas,
           &novaTabela.numLinhas);

    printf("Colunas: %d\n", novaTabela.numColunas);
    printf("Linhas: %d\n", novaTabela.numLinhas);

    // Aloca espaço para o vetor colunas

    novaTabela.colunas = calloc(novaTabela.numColunas, sizeof(Coluna));

    // Lê o nome e tipo de cada coluna
    for (int i = 0; i < novaTabela.numColunas; i++) {
      fscanf(arquivoTabela, "%s %d", novaTabela.colunas[i].nomeColuna,
             &novaTabela.colunas[i].tipoColuna);
    }

    for (int i = 0; i < novaTabela.numColunas; i++) {
      printf("Nome Coluna: %s - Tipo Coluna: %d\n",
             novaTabela.colunas[i].nomeColuna,
             novaTabela.colunas[i].tipoColuna);
    }
    // // Aloca espaço para a matriz de células
    novaTabela.dados = malloc(novaTabela.numLinhas * sizeof(Celula *));

    for (int i = 0; i < novaTabela.numLinhas; i++) {
      novaTabela.dados[i] = malloc(novaTabela.numColunas * sizeof(Celula));
    }

    // Lê os dados de cada célula
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
          // Tratamento para tipos desconhecidos
          break;
        }
      }
    }

    (*numTabs)++;
    tabelas = realloc(tabelas, sizeof(Tabela) * (*numTabs));
    tabelas[*numTabs - 1] = novaTabela;
    printf("NUM TABS: %d\n", *numTabs);
    printf("SO: %s\n", novaTabela.nomeTabela);
    fclose(arquivoTabela);
  }

  printf("NCOISOO: %s", tabelas[*numTabs - 1].nomeTabela);

  fclose(arquivo);

  return tabelas;
}

void salvarNome(Tabela *tabelas, int numTabs) {
  FILE *arqTab = fopen("tabelas.txt", "w");

  if (arqTab == NULL) {
    printf("Arquivo não encontrado!");
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
    printf("Arquivo não encontrado!");
  } else {
    fprintf(arqTab, "%d", numTabs);
  }
  fclose(arqTab);
}

void carregarQuantidade(int *numTabs) {
  FILE *arqTab = fopen("qtdtabelas.txt", "r");
  if (arqTab == NULL) {
    printf("Arquivo não encontrado!");
  } else {
    fscanf(arqTab, "%i", numTabs);
  }
}

int main() {

  char nomeTabela[MAX_NAME];
  int idTab = 0;
  bool tabelaExiste = false;
  int numTab = 0;
  int opcao;
  // Cria um vetor que guardará todas as tabelas;
  Tabela *tabelas = NULL;

  carregarQuantidade(&numTab);
  printf("num tabs: %d\n", numTab);

  if (numTab > 0) {
    numTab = 0;
    tabelas = carregarTabelas(tabelas, &numTab);
  }

  do {
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      printf("\nFINALIZANDO PROGRAMA!\n\n");
      break;
    case 1:
      tabelas = inserirTabela(tabelas, &numTab, criarTabela());
      salvarTabela(tabelas[numTab - 1]);
      salvarNome(tabelas, numTab);
      salvarQuantidade(numTab);
      break;
    case 2:
      printf("%d", numTab);
      listarTabelas(tabelas, numTab);
      break;
    case 3:

      printf("Digite o nome da tabela: ");
      scanf("%s", nomeTabela);

      for (idTab = 0; idTab < numTab; idTab++) {
        if (strcmp(tabelas[idTab].nomeTabela, nomeTabela) == 0) {
          tabelaExiste = true;
          break;
        }
      }

      if (tabelaExiste == false) {
        printf("TABELA NÃO ENCONTRADA\n");
      } else {
        adicionarLinha(&tabelas[idTab]);
        salvarTabela(tabelas[idTab]);
      }
      break;
    case 4:
      printf("Digite o nome da tabela: ");
      scanf("%s", nomeTabela);

      for (idTab = 0; idTab < numTab; idTab++) {
        if (strcmp(tabelas[idTab].nomeTabela, nomeTabela) == 0) {
          tabelaExiste = true;
          break;
        }
      }

      if (tabelaExiste == false) {
        printf("TABELA NÃO ENCONTRADA\n");
      } else {
        listarDadosTabela(tabelas[idTab]);
      }
      break;
    }
  } while (opcao != 0);
}