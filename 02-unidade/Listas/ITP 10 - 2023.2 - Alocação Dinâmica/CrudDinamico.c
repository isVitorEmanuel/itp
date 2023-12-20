#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
  char sexo;
} Pessoa;

Pessoa criarPessoa() {
  Pessoa nova;
  getchar();
  scanf("%[^\n]", nova.nome);
  scanf("%d", &nova.idade);
  scanf(" %c", &nova.sexo);
  return nova;
}

Pessoa *inserir(Pessoa *pessoasArray, int *numPessoas, Pessoa nova) {
  (*numPessoas)++;
  pessoasArray = realloc(pessoasArray, sizeof(Pessoa) * (*numPessoas));

  pessoasArray[*numPessoas - 1] = nova;
  return pessoasArray;
}

Pessoa *deletar(Pessoa *pessoasArray, int *numPessoas, Pessoa alvo) {
  int posDel = -1;

  for (int i = 0; i < *numPessoas; i++) {
    if (pessoasArray[i].idade == alvo.idade &&
        pessoasArray[i].sexo == alvo.sexo &&
        strcmp(pessoasArray[i].nome, alvo.nome) == 0) {
      posDel = i;
      break;
    }
  }

  if (posDel != -1) {
    for (int i = posDel; i < *numPessoas - 1; i++) {
      pessoasArray[i] = pessoasArray[i + 1];
    }

    (*numPessoas)--;
    pessoasArray = realloc(pessoasArray, sizeof(Pessoa) * (*numPessoas));
  }

  return pessoasArray;
}

void imprimir(const Pessoa *pessoasArray, int numPessoas) {
  for (int i = 0; i < numPessoas; i++) {
    printf("%s,%d,%c\n", pessoasArray[i].nome, pessoasArray[i].idade,
           pessoasArray[i].sexo);
  }
}

int main() {
  int numPessoas = 0;
  Pessoa *pessoasArray = NULL;
  char acao = 'x';

  while (acao != 'p') {
    scanf(" %c", &acao);

    switch (acao) {
    case 'i':
      pessoasArray = inserir(pessoasArray, &numPessoas, criarPessoa());
      break;
    case 'd':
      pessoasArray = deletar(pessoasArray, &numPessoas, criarPessoa());
      break;
    case 'p':
      break;
    default:
      printf("Comando inválido.\n");
    }
  }

  imprimir(pessoasArray, numPessoas);

  free(pessoasArray);
  return 0;
}
