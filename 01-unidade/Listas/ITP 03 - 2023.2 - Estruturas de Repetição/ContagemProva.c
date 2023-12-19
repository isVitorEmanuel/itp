#include <stdio.h>

int main() {

  int numeroTimes, numCorrida, numSalto, numLanc, allAtle;
  char equipe;

  numeroTimes = 0;
  numLanc = 0;
  numSalto = 0;
  numCorrida = 0;
  
  scanf("%d", &numeroTimes);
  
  for (int count = 0; count < numeroTimes; count++) {
    
    do {
      scanf(" %c", &equipe);
  
      switch(equipe) {
        case 'S': numSalto++; break;
        case 'C': numCorrida++; break;
        case 'L': numLanc++; break;
       }
    } while(equipe != 'F');
  }

  allAtle = numLanc + numSalto + numCorrida;
  
  printf("%d %d %d %d", numCorrida, numSalto, numLanc, allAtle);
  
}