#include <stdio.h>
#include <stdbool.h>

void aprovados(int n, int *alunos, double *notas){
  bool pos = false;
  for(int i = 0; i < n; i++){
    if(notas[i] >= 7){
      if(pos == false){
        pos = true;
      } else {
        printf(",");
      }
      printf(" %d (%.1lf)", alunos[i], notas[i]);
    }
  }
}

void reprovados(int n, int *alunos, double *notas){
  bool pos = false;
  for(int i = 0; i < n; i++){
    if(notas[i] < 5){
      if(pos == false){
        pos = true;
      } else {
        printf(",");
      }
      printf(" %d (%.1lf)", alunos[i], notas[i]);
    }
  }
}

void recuperacao(int n, int *alunos, double *notas){
  bool pos = false;
  for(int i = 0; i < n; i++){
    if(notas[i] >= 5 && notas[i] < 7){
      if(pos == false){
        pos = true;
      } else {
        printf(",");
      }
      printf(" %d (%.1lf)", alunos[i], notas[i]);
    }
  }
}

int main() {

  int qtdAlunos;
  scanf("%d", &qtdAlunos);
  int chamada[qtdAlunos];
  double notas[qtdAlunos];

  for(int i = 0; i < qtdAlunos; i++){
    scanf("%d - %lf", &chamada[i], &notas[i]);
  }
  
  printf("Aprovados:");
  aprovados(qtdAlunos, chamada, notas);
  printf("\nRecuperação:");
  recuperacao(qtdAlunos, chamada, notas);
  printf("\nReprovados:");
  reprovados(qtdAlunos, chamada, notas);
}