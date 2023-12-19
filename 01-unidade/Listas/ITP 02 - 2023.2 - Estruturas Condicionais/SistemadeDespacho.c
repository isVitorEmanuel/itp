#include <stdio.h>

int main() {

  int amount, heroesType, mobsType;

  scanf("%d %d %d", &amount, &heroesType, &mobsType);

  if (mobsType == 1) {

    if (heroesType > 1) {
      
      if (amount >= 1) {
        printf("Heróis vencerão!");
      } else {
       printf("Melhor chamar Saitama!"); 
      }
    
    } else {
      if (heroesType == 1) {
        if (amount >= 3) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!");
        }
      } else {
        printf("Melhor chamar Saitama!");
      }
    }
    
  } else {

    if (mobsType == 2) {
      
      if (heroesType > 2) {
        
        if (amount >= 1) {
          printf("Heróis vencerão!");
        } else {
          printf("Melhor chamar Saitama!"); 
        }
        
      } else {
        if (heroesType == 2) {
          if (amount >= 3) {
            printf("Heróis vencerão!");
          } else {
            printf("Melhor chamar Saitama!");
          }
        } else {
          printf("Melhor chamar Saitama!");
        }
      }
    } else {

      if (mobsType == 3) {
        
        if (heroesType > 3) {
          
          if (amount >= 1) {
            printf("Heróis vencerão!");
          } else {
            printf("Melhor chamar Saitama!"); 
          }
          
        } else {
          if (heroesType == 3) {
            if (amount >= 3) {
              printf("Heróis vencerão!");
            } else {
              printf("Melhor chamar Saitama!");
            }
          } else {
            printf("Melhor chamar Saitama!");
          }
        }
        
      } else {

        if (mobsType == 4) {

          if (heroesType > 4) {
            if (amount >= 1) {
              printf("Heróis vencerão!");
            } else {
              printf("Melhor chamar Saitama!"); 
            }
          } else {
            if (heroesType == 4) {
              if (amount >= 3) {
                printf("Heróis vencerão!");
              } else {
                printf("Melhor chamar Saitama!");
              }
            } else {
              printf("Melhor chamar Saitama!");
            }  
          }      
        } else { 

          if (heroesType == 5) {
            if (amount >= 1) {
              printf("Heróis vencerão!");
            } else {
             printf("Melhor chamar Saitama!"); 
            }
          } else {
              printf("Melhor chamar Saitama!");
          }  
        }
      }  
    }
  }
}