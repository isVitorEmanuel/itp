#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
  char sexo;
} Pessoa;

int adicionarPessoa(Pessoa pessoas[], int tamanho, Pessoa novaPessoa) {
  pessoas[tamanho] = novaPessoa;
  return ++tamanho;
}

int removerPessoa(Pessoa pessoas[], int tamanho, Pessoa pessoaRemover) {
  int i;
  for (i = 0; i < tamanho; i++)
    if (strcmp(pessoas[i].nome, pessoaRemover.nome) == 0 &&
        pessoas[i].idade == pessoaRemover.idade &&
        pessoas[i].sexo == pessoaRemover.sexo)
      break;
  if (tamanho > 0 && i < (tamanho)-1) {
    for (int j = i; j < tamanho; j++)
      pessoas[j] = pessoas[j + 1];
    tamanho--;
  }
  if (tamanho == 1 && i == 0)
    tamanho--;
  return tamanho;
}

void imprimirPessoa(Pessoa *pessoas, int tamanho) {
  for (int i = 0; i < tamanho; i++)
    printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
}

Pessoa lerDados() {
  Pessoa pessoa;
  char lixo;
  pessoa.nome[0] = '\0';
  fflush(stdin);
  fgets(pessoa.nome, 50, stdin);
  if (pessoa.nome[strlen(pessoa.nome) - 1] == '\n')
    pessoa.nome[strlen(pessoa.nome) - 1] = '\0';
  scanf("%d", &pessoa.idade);
  scanf(" %[^\n]c", &pessoa.sexo);
  scanf("%c", &lixo);
  return pessoa;
}

int main(void) {
  int tamanhoLista = 0;
  Pessoa listaPessoas[20];
  char comando = 0, lixo;
  
  while (comando != 'p') {
    fflush(stdin);
    scanf("%[^\n]c", &comando);
    scanf("%c", &lixo);
    if (comando == 'p')
      break;
    Pessoa novaPessoa = lerDados();
    if (comando == 'i')
      tamanhoLista = adicionarPessoa(listaPessoas, tamanhoLista, novaPessoa);
    if (comando == 'd')
      tamanhoLista = removerPessoa(listaPessoas, tamanhoLista, novaPessoa);
  }
  imprimirPessoa(listaPessoas, tamanhoLista);
  return 0;
}
