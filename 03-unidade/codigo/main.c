#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
/* Definição de um tipo enumerado para ser os possíveis tipos das células e
 colunas. - OK */
typedef enum { CHAR, STRING, INT, FLOAT } Types;

// Definição da estrutura da célula - OK
typedef struct {
  Types tipoCelula;
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

void adicionarLinha(Tabela *tabela) {
  tabela->numLinhas = tabela->numLinhas + 1;
}
void listarDadosTabela() {}

void pesquisarValores() {}

void apagarLinha() {}

void apagarTabela() {}

int main() {

  int numTab = 0;
  int opcao;
  // Cria um vetor que guardará todas as tabelas;
  Tabela *tabelas = NULL;

  do {
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      printf("\nFINALIZANDO PROGRAMA!\n\n");
      break;
    case 1:
      tabelas = inserirTabela(tabelas, &numTab, criarTabela());
      break;
    case 2:
      listarTabelas(tabelas, numTab);
      break;
    }

  } while (opcao != 0);

  printf("%s\n", tabelas[0].chavePrimaria.nomeColuna);
  printf("%d\n", tabelas[0].chavePrimaria.tipoColuna);

  // Tabela tabela_teste = criarTabela();

  // printf("Nome: \n%s", tabela_teste.nomeTabela);

  // adicionarLinha(&tabela_teste);
  // printf("Linhas: \n%d", tabela_teste.numLinhas);

  /*
  ----- TUDO AQUI É TESTE NADA DEFINITO, mas tá td funcionado
  */
  /*printf("Nome da Tabela: %s\n", tabela.nomeTabela);
  printf("Colunas e Linhas: %d %d\n", tabela.numColunas, tabela.numLinhas);

  for (int i = 0; i < tabela.numColunas; i++) {
    printf("Nome da %dª Coluna: %s\n", (i + 1), tabela.colunas[i].nomeColuna);
    printf("Tipo da %dª Coluna: %d\n", (i + 1), tabela.colunas[i].tipoColuna);
  }

  printf("Nome da ChavePrimária: %s\n", tabela.chavePrimaria.nomeColuna);
  printf("Tipo da ChavePrimária: %d\n", tabela.chavePrimaria.tipoColuna);

  printf("\nTABELA\n");

  for (int i = 0; i < tabela.numLinhas; i++) {
    for (int j = 0; j < tabela.numColunas; j++) {
      printf(" %d ", tabela.dados[i][j].dataInt);
    }
    printf("\n");
  }*/
}
