#include <stdio.h>

int main() {

  int combo, price, troco, falta;

  scanf("%d %d", &combo, &price);

  if (combo == 1) {

    if (price == 12) {
      printf("Deu certim!");
    } else {
      if (price < 12) {
        
        falta = 12 - price;
        printf("Saldo insuficiente! Falta %d reais", falta);
        
      } else {

        troco = price - 12;
        printf("Troco = %d reais", troco);

      }
    }
    
  } else {

    if (combo == 2) {
      
      if (price == 23) {
        printf("Deu certim!");
      } else {
        if (price < 23) {
          
          falta = 23 - price;
          printf("Saldo insuficiente! Falta %d reais", falta);
          
        } else {
  
          troco = price - 23;
          printf("Troco = %d reais", troco);
  
        }
      }    
    } else {

      if (combo == 3) {
        
        if (price == 31) {
          printf("Deu certim!");
        } else {
          if (price < 31) {
            
            falta = 31 - price;
            printf("Saldo insuficiente! Falta %d reais", falta);
            
          } else {
    
            troco = price - 31;
            printf("Troco = %d reais", troco);
    
          }
        }    
      } else {

        if (combo == 4) {

          if (price == 28) {
            printf("Deu certim!");
          } else {
            if (price < 28) {
              
              falta = 28 - price;
              printf("Saldo insuficiente! Falta %d reais", falta);
              
            } else {
      
              troco = price - 28;
              printf("Troco = %d reais", troco);
      
            }
          }   
        } else {
          
          if (price == 15) {
            printf("Deu certim!");
          } else {
            if (price < 15) {
              
              falta = 15 - price;
              printf("Saldo insuficiente! Falta %d reais", falta);
              
            } else {
      
              troco = price - 15;
              printf("Troco = %d reais", troco);
      
            }
          }           
        }
      } 
    } 
  }  
}