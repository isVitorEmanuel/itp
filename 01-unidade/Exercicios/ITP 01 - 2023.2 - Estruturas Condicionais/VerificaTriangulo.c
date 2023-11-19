#include <stdio.h>

int main() {

  int lado1, lado2, lado3;
  //informar lados
  scanf("%d", &lado1);
  scanf("%d", &lado2);
  scanf("%d", &lado3);
  //verificação do tamanho dos lados
  if (lado1 >= (lado2 + lado3)) {
    printf("impossivel");
  } else {
    if (lado2 >= (lado1 + lado3)) {
      printf("impossivel");
    } else {
      if (lado3 >= (lado1 + lado2)) {
        printf("impossivel");
      } else {
        printf("possivel");
      }
    }
  }
}