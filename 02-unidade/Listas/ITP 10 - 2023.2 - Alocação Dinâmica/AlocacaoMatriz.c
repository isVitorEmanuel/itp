#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix *createMatrix(int nlin, int ncol) { 

  Matrix *matriz = calloc(1, sizeof(Matrix));

  matriz->nlin = nlin;
  matriz->ncol = ncol;

  matriz->mat = calloc(nlin, sizeof(int *));

  for(int l = 0; l < matriz->nlin; l++){
    matriz->mat[l] = calloc(ncol, sizeof(int));
  }  
  return matriz; 
}

void readMatrix(Matrix *m) {

  int valor;

  for (int l = 0; l < m->nlin; l++) {
    for(int c = 0; c < m->ncol; c++){
      scanf("%d", &valor);
      m->mat[l][c] = valor;
    }
  }
}

void printMatrix(Matrix *m) {
  for(int i = 0; i < m->nlin; i++){
    for(int j = 0; j < m->ncol; j++){
      printf("%d ", m->mat[i][j]);
    }
    printf("\n");
  }
}

void destroyMatrix(Matrix **m) {
  for(int i = 0; i < (*m)->nlin; i++){
    free((*m)->mat[i]);
  }
  free(*m);
  *m = NULL;
}

int main(void) {
  int lin, col;
  Matrix* mat;

  scanf("%i %i", &lin, &col);
  
  mat = createMatrix(lin, col);
  
  readMatrix(mat);
  printMatrix(mat);
  destroyMatrix(&mat);
  
  if (mat == NULL) {
    printf("OK\n");
  }
}