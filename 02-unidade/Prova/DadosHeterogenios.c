#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_LINHA 30

typedef struct {
  int codigo;
  char descricao[20];
  float preco;
} Produto;

void read_line(char linha[MAX_LINHA], int tam) {
  fgets(linha, tam, stdin);
  if (linha[strlen(linha) - 1] == '\n') {
    linha[strlen(linha) - 1] = '\0';
  }
}

void imprimeProdutos(Produto produtos[], int qtdProdutos) {
  printf("========================================\n");
  printf("| Código | Descrição       | Preço     |\n");
  printf("----------------------------------------\n");
  for (int i = 0; i < qtdProdutos; i++) {
    printf("| %6d ", produtos[i].codigo);
    printf("| %15s ", produtos[i].descricao);
    printf("| R$ %6.2f |\n", produtos[i].preco);
  }
  printf("----------------------------------------\n");
}

int main() {
  Produto listaProdutos[MAX_PRODUTOS];
  int numProdutos = 0;
  char linha[MAX_LINHA];

  while (1) {
    read_line(linha, sizeof(linha));
    if (linha[0] == '\0') {
      break;
    }

    Produto novoProduto;
    char descricaoTemp[20];

    char *endptr;
    novoProduto.codigo = strtol(linha, &endptr, 10);
    
    sscanf(endptr + 1, "%19[^,],%f", descricaoTemp, &novoProduto.preco);
    strncpy(novoProduto.descricao, descricaoTemp,
            sizeof(novoProduto.descricao));
    novoProduto.descricao[sizeof(novoProduto.descricao) - 1] = '\0';

    int produtoExistente = 0;
    for (int i = 0; i < numProdutos; i++) {
      if (listaProdutos[i].codigo == novoProduto.codigo) {
        produtoExistente = 1;
        break;
      }
    }

    if (!produtoExistente && numProdutos < MAX_PRODUTOS) {
      listaProdutos[numProdutos] = novoProduto;
      numProdutos++;
    }
  }

  imprimeProdutos(listaProdutos, numProdutos);

  return 0;
}
