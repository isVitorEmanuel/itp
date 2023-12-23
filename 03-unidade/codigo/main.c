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
    case 7: {
      int tipo;
      char nomeTabela[MAX_NAME];

      printf("Digite o nome da tabela: ");
      scanf("%s", nomeTabela);
      bool tabelaEncontrada = false;
      int tabelaIndex = -1;

      for (int i = 0; i < numTab; i++) {
        if (strcmp(tabelas[i].nomeTabela, nomeTabela) == 0) {
          tabelaEncontrada = true;
          tabelaIndex = i;
          break;
        }
      }

      if (!tabelaEncontrada) {
        printf("Tabela nao encontrada!\n");
        break;
      }

      printf("Colunas disponiveis na tabela %s:\n", nomeTabela);
      for (int i = 0; i < tabelas[tabelaIndex].numColunas; i++) {
        printf(".%s\n", tabelas[tabelaIndex].colunas[i].nomeColuna);
      }

      char nomeColuna[MAX_NAME];
      printf("Digite o nome da coluna: ");
      scanf("%s", nomeColuna);
      int colunaIndex = -1;

      for (int i = 0; i < tabelas[tabelaIndex].numColunas; i++) {
        if (strcmp(tabelas[tabelaIndex].colunas[i].nomeColuna, nomeColuna) == 0) {
          colunaIndex = i;
          break;
        }
      }
      if (colunaIndex == -1) {
        printf("Coluna nao encontrada!\n");
        break;
      }

      Types tipoColunaSelecionada =
          tabelas[tabelaIndex].colunas[colunaIndex].tipoColuna;
      Celula novoValor;

      switch (tipoColunaSelecionada) {
        case CHAR:
          tipo = 0;
          printf("Digite o valor desejado (char): ");
          scanf(" %c", &novoValor.dataChar);
          break;
        case STRING:
          tipo = 1;
          printf("Digite o valor desejado (string): ");
          novoValor.dataString = malloc(MAX_NAME * sizeof(char));
          scanf("%s", novoValor.dataString);
          break;
        case INT:
          tipo = 2;
          printf("Digite o valor desejado (int): ");
          scanf("%d", &novoValor.dataInt);
          break;
        case FLOAT:
          tipo = 3;
          printf("Digite o valor desejado (float): ");
          scanf("%f", &novoValor.dataFloat);
          break;
        case DOUBLE:
          tipo = 4;
          printf("Digite o valor desejado (double): ");
          scanf("%lf", &novoValor.dataDouble);
          break;
        default:
          printf("Tipo de coluna nao suportado!\n");
          break;
      }
      sValues(tabelas[tabelaIndex], nomeColuna, novoValor, tipo);
      break;
    }
    default:
    printf("ERRO - Opcão Inválida!\n");
   }
  } while (opcao != 0);
}