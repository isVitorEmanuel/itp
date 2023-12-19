#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ehPar(int number){

  bool ehPar = true;

  if((number % 2) == 0){
    ehPar = true;
  } else {
    ehPar = false;
  }

  return ehPar;
}

int main(void) {

  int numero;

  scanf("%d", &numero);

  if(ehPar(numero) == 1){
    printf("true");
  } else {
    printf("false");
  }
  
  return 0;
}