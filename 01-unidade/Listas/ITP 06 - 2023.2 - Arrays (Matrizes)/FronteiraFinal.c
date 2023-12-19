#include <stdio.h>

int main(void) {
  int line, colu;
  int hostile, water, desert, vegetation, nothing;
  hostile = water = desert = vegetation = nothing = 0;
  char element;

  scanf("%d %d", &line, &colu);

  char scanner[line][colu];
  int superf = line * colu;

  for(int i = 0; i < line; i++){
    for(int j = 0; j < colu; j++){
      scanf(" %c", &scanner[i][j]);
    }
  }

  for(int i = 0; i < line; i++){
		for(int j = 0; j < colu; j++){
			element = scanner[i][j];
			switch(element){
				case '~': water++; break;
				case 'X': hostile++; break;
				case '^': desert++; break;
				case '*': vegetation++; break;
				case '.': nothing++; break;
			}
		}
	}

  if(hostile != 0){
    printf("Planeta Hostil");
  } else {
    if (water >= 0.85 * superf) {
      printf("Planeta Aquático");
    } else {
      if(vegetation >= 0.65 * superf){
         printf("Planeta Selvagem");
      } else {
        if(desert >= 0.6 * superf){
          printf("Planeta Desértico");
        } else {
          if(water >= 0.5 * superf && vegetation >= 0.2 * superf){
            printf("Planeta Classe M");
          } else {
            printf("Planeta Inóspito");
          }
        }
      }
    }
  }  
}