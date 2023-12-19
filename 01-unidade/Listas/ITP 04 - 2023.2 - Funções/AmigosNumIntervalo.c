#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int testa_divisor(int numero, int divisor) {
  
  bool divide = true;

  if ((numero % divisor) == 0) {
    divide = true;
  } else {
    divide = false;
  }
  return divide;
}

int soma_divisores(int value) {
  
  int soma = 0;
  
  for (int div = 1; div < value; div++) {
    
    if (testa_divisor(value, div) == true) {
      soma = soma + div;
    } 
  }
  return soma;
}

int testa_amigos(int a, int b) {

  bool amigo = true;

  int somaA = soma_divisores(a);
  int somaB = soma_divisores(b);

  if((somaA == b) && (somaB == a)) {
    amigo = true;
  } else {
    amigo = false;
  }
  return amigo;
}

int main(void) {

  int amigos = 0;
  
  int L1_1, L1_2, L2_1, L2_2;

  scanf("%d %d", &L1_1, &L1_2);
  scanf("%d %d", &L2_1, &L2_2);

  for (int firstNumber = L1_1; firstNumber < L1_2; firstNumber++) {
    for (int secundNumber = L2_1; secundNumber < L2_2; secundNumber++){
      if(firstNumber != secundNumber) {
        if(testa_amigos(firstNumber, secundNumber) == true) {
          printf("O %d possui um amigo!\n", firstNumber);
          amigos = amigos + 1;   
        }
      }
    }
  }
  if(amigos == 0) {
    printf("Os intervalos nao apresentam amigos!");
  }
}