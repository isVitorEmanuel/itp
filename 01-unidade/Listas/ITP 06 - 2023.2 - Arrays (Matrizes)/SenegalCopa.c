#include <stdio.h>

int calcular_aposta(int width, int height, int flag[height][width], char color) {
  int sum = 0, colStart = 0, colEnd = 0;
  switch (color) {
    case 'G': colStart = 0; colEnd = colStart + (width/3); break; 
    case 'Y': colStart = width/3; colEnd = colStart + (width/3); break;
    case 'R': colStart = (width/3)*2; colEnd = colStart + (width/3);
  }
  for (int col = colStart; col < colEnd; col++) {
    for (int row = 0; row < height; row++)
      sum += flag[row][col];
  }
  return sum;
}

int main(void) {
  int width, height;
  scanf("%d", &width);
  height = (2 * width) / 3;
  int flag[height][width];
  int number;
  scanf("%d", &number);

  for (int col = 0; col < width; col++) {
    if (col % (width / 3) == 0)
      number++;
    for (int row = 0; row < height; row++)
      flag[row][col] = number;
  }
  char color;
  scanf(" %c", &color);
  int bet = 0;
  bet = calcular_aposta(width, height, flag, color);
  printf("%d", bet);
}
