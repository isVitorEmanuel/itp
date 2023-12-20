#include <stdio.h>
int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {

  int numCell = 0;
  *left_index = user - distance;
  *right_index = user + distance;

  for(int i = 0; i < n; i++){
    if((cells[i] >= *left_index) && (cells[i] <= *right_index)){
      printf("%d ", cells[i]);
      numCell++;
    }
  }
  return numCell;
}

int main(void) {
  
  int N, D, U;
  scanf("%d %d %d", &N, &D, &U);

  int indexL = 0, indexR = 0;

  int celulas[N];
  for(int i = 0; i < N; i++){
    scanf("%d", &celulas[i]);
  }
  
  if(get_range(N, celulas, D, U, &indexL, &indexR) == 0){
    printf("USUARIO DESCONECTADO");
  } 
}