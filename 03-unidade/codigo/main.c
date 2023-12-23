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
      /*
      tabelas = inserirTabela(tabelas, &numTab, criarTabela());

      if ((tabelas->numColunas) > 1) {
        salvarTabela(tabelas[numTab - 1]);
        salvarNome(tabelas, numTab);
        salvarQuantidade(numTab);
      }
      break;
      */
    case 2:
      printf("NUMERO DE TABELAS: %d\n", numTab);
      listarTabelas(tabelas, numTab);
      break;
    }
  } while (opcao != 0);
}