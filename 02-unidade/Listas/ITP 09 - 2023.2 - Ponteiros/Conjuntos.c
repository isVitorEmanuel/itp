#include <stdio.h>

typedef struct {
  int elementos[20];
  int tamanho;
} Conjunto;

void lerConjunto(Conjunto *c) {
  for (int i = 0; i < c->tamanho; i++)
    scanf("%d", &c->elementos[i]);
}

void exibirConjunto(Conjunto c) {
  printf("{");
  if (c.tamanho == 0)
    printf("vazio}\n");
  else
    for (int i = 0; i < c.tamanho; i++) {
      printf("%d", c.elementos[i]);
      if (i < c.tamanho - 1)
        printf(" ");
      else
        printf("}\n");
    }
}

int buscarElemento(int elemento, Conjunto c) {
  for (int i = 0; i < c.tamanho; i++)
    if (c.elementos[i] == elemento)
      return i;
  return -1;
}

void uniaoConjuntos(Conjunto A, Conjunto B, Conjunto *U) {
  U->tamanho = 0;

  for (int i = 0; i < A.tamanho; i++)
    U->elementos[U->tamanho++] = A.elementos[i];

  for (int i = 0; i < B.tamanho; i++)
    if (buscarElemento(B.elementos[i], A) == -1)
      U->elementos[U->tamanho++] = B.elementos[i];
}

void intersecaoConjuntos(Conjunto A, Conjunto B, Conjunto *I) {
  I->tamanho = 0;

  for (int i = 0; i < B.tamanho; i++)
    if (buscarElemento(B.elementos[i], A) != -1)
      I->elementos[I->tamanho++] = B.elementos[i];
}

int main(void) {
  Conjunto conjuntoA, conjuntoB;
  scanf("%d", &conjuntoA.tamanho);
  lerConjunto(&conjuntoA);
  scanf("%d", &conjuntoB.tamanho);
  lerConjunto(&conjuntoB);

  Conjunto uniao;
  uniaoConjuntos(conjuntoA, conjuntoB, &uniao);
  printf("A união B == ");
  exibirConjunto(uniao);

  Conjunto intersecao;
  intersecaoConjuntos(conjuntoA, conjuntoB, &intersecao);
  printf("A interseção B == ");
  exibirConjunto(intersecao);

  return 0;
}
