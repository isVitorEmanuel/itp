#include <stdio.h>

int main() {

  int a, b, c, d;

  scanf("%d %d %d %d", &a, &b, &c, &d);

  if (a >= b) {
    if(a >= c) {
      if(a >= d) {
        printf("Maior: %d", a);
      } else {
        printf("Maior: %d", d);
      }
    } else {
      if(c >= d) {
        printf("Maior: %d", c);
      } else {
        printf("Maior: %d", d);
      }
    }
    
  } else {
    if(b >= c) {
      if(b >= d) {
        printf("Maior: %d", b);
      } else {
        printf("Maior: %d", d);
      }
    } else {
      if(c >= d) {
        printf("Maior: %d", c);
      } else {
        printf("Maior: %d", d);
      }
    }
  }
}