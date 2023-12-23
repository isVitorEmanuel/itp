#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"
#include "funcaux.h"
#include "definicoes.h"

int main() {

  char nomeTabela[MAX_NAME];
  int idTab = 0, numTab = 0;
  int opcao;
  bool tabelaExiste = false;

  Tabela *tabelas = NULL;

  carregarQuantidade(&numTab);
  printf("Numero de Tabelas disponiveis: %d\n", numTab);

   if (numTab > 0) {
    numTab = 0;
    tabelas = carregarTabelas(tabelas, &numTab);
  }

   do {

    tabelaExiste = false;

    printf("------------------- OPCOES -------------------\n");
    printf("0 - Sair do programa\n");
    printf("1 - Inserir nova tabela\n");
    printf("2 - Listar tabelas\n");
    printf("3 - Adicionar linha a uma tabela\n");
    printf("4 - Listar dados de uma tabela\n");
    printf("5 - Apagar uma tabela\n");
    printf("6 - Apagar uma linha\n");
    printf("7 - Pesquisar valores\n");
    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 0:
      printf("\nFinalizando o programa!\n\n");
      break;
    case 1:
      tabelas = inserirTabela(tabelas, &numTab, criarTabela());

      if ((tabelas->numColunas) > 1) {
        salvarTabela(tabelas[numTab - 1]);
        salvarNome(tabelas, numTab);
        salvarQuantidade(numTab);
      }
      break;
    case 2:
      listarTabelas(tabelas, numTab);
      break;
    case 3:
      printf("----------------------------------------------\n");
      printf("Digite o nome da tabela: ");
      scanf("%s", nomeTabela);

      for (idTab = 0; idTab < numTab; idTab++) {
        if (strcmp(tabelas[idTab].nomeTabela, nomeTabela) == 0) {
          tabelaExiste = true;
          break;
        }
      }

      if (tabelaExiste == false) {
        printf("Tabela nao encontrada!\n");
      } else {
        adicionarLinha(&tabelas[idTab]);
        salvarTabela(tabelas[idTab]);
      }
      break;
    case 4:
      printf("----------------------------------------------\n");
      printf("Digite o nome da tabela: ");
      scanf("%s", nomeTabela);

      for (idTab = 0; idTab < numTab; idTab++) {
        if (strcmp(tabelas[idTab].nomeTabela, nomeTabela) == 0) {
          tabelaExiste = true;
          break;
        }
      }

      if (tabelaExiste == false) {
        printf("Tabela nao encontrada!\n");
      } else {
        listarDadosTabela(tabelas[idTab]);
      }
      break;
    case 5:
      printf("----------------------------------------------\n");
      printf("Digite o nome da tabela a ser excluida: ");
      scanf("%s", nomeTabela);

      for (idTab = 0; idTab < numTab; idTab++) {
        if (strcmp(tabelas[idTab].nomeTabela, nomeTabela) == 0) {
          tabelaExiste = true;
          break;
        }
      }

      if (tabelaExiste == false) {
        printf("Tabela nao encontrada!\n");
      } else {
        tabelas = apagarTabela(tabelas, &numTab, nomeTabela);
        salvarNome(tabelas, numTab);
        salvarQuantidade(numTab);
      }
      break;
    case 6:
      printf("----------------------------------------------\n");
      printf("Digite o nome da tabela: ");
      scanf("%s", nomeTabela);
      for (idTab = 0; idTab < numTab; idTab++) {
        if (strcmp(tabelas[idTab].nomeTabela, nomeTabela) == 0) {
          tabelaExiste = true;
          break;
        }
      }

      if (tabelaExiste == false) {
        printf("Tabela nao encontrada!\n");
      } else {
        int chavePrimaria;
        printf("Digite o valor da chave primaria a ser apagada: ");
        scanf("%d", &chavePrimaria);
        deletarLinha(nomeTabela, tabelas, numTab, chavePrimaria);
      }
      break;
    }

  } while (opcao != 0);
}