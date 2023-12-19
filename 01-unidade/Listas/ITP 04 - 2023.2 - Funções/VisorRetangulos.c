#include <stdio.h>

void verificar() {
  double x1, x2, y1, y2, a1, a2, b1, b2;

  scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

  do {

    scanf("%lf %lf %lf %lf", &a1, &a2, &b1, &b2);

    if (((a1 != 0) || (a2 != 0)) || ((b1 != 0) || (b2 != 0))) {

      if((x1 < a1 && x2 < a2) && (y1 > b1 && y2 > b2)) {
        printf("(<%.2lf,%.2lf>,<%.2lf,%.2lf>) contem "
                 "(<%.2lf,%.2lf>,<%.2lf,%.2lf>).\n",
                 x1, x2, y1, y2, a1, a2, b1, b2);
      } else {
        if ((x1 > a1 && x2 > a2) && (y1 < b1 && y2 < b2)) {
          printf("(<%.2lf,%.2lf>,<%.2lf,%.2lf>) contem "
                 "(<%.2lf,%.2lf>,<%.2lf,%.2lf>).\n",
                 a1, a2, b1, b2, x1, x2, y1, y2);
        } else {
          printf("Nao posso afirmar!\n");
        }
      }
      
    } else {
      break;
    }
    
  } while (((a1 != 0) || (a2 != 0)) || ((b1 != 0) || (b2 != 0)));
  
}

int main() {
  verificar();
}