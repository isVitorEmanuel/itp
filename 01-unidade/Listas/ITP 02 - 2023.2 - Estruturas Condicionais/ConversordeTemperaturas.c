#include <stdio.h>

int main() {
  
  double tem, c, f, k;
  char scale;

  scanf("%lf %c", &tem, &scale);

  if (scale == 'C') {
    c = tem;
    f = c * 1.8 + 32;
    k = c + 273.15;

    printf("Celsius: %.2lf\nFarenheit: %.2lf\nKelvin: %.2lf", c, f, k);
    
  } else {
    if (scale == 'F') {
      f = tem;
      c = (f - 32.0)/1.8;
      k = c + 273.15;

      printf("Celsius: %.2lf\nFarenheit: %.2lf\nKelvin: %.2lf", c, f, k);
      
    } else {
      k = tem;
      c = k - 273.15;
      f = c * 1.8 + 32;

      printf("Celsius: %.2lf\nFarenheit: %.2lf\nKelvin: %.2lf", c, f, k);
      
    }
  }
}