#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct smartphoneSpecs {
  char modelo[40];
  int memoria;
  float processador;
  float camera;
  float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
  scanf(" %[^\n]s", phones[qnt_cadastrada].modelo);
  scanf(" %d %f %f %f", 
    &phones[qnt_cadastrada].memoria,
    &phones[qnt_cadastrada].processador,         
    &phones[qnt_cadastrada].camera,
    &phones[qnt_cadastrada].bateria);
  return ++qnt_cadastrada;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[],
                        Smartphone reqMin) {
  int quantidade = 0;

  for (int i = 0; i < qnt_cadastrada; i++) {
    if ((reqMin.memoria <= phones[i].memoria) &&
        (reqMin.processador <= phones[i].processador) &&
        (reqMin.camera <= phones[i].camera) &&
        (reqMin.bateria <= phones[i].bateria)) 
    {
      printf("Modelo: %s\n", phones[i].modelo);
      printf("Memoria: %dGB\n", phones[i].memoria);
      printf("Processador: %.2fGhz\n", phones[i].processador);
      printf("Camera: %.2fMPixels\n", phones[i].camera);
      printf("Bateria: %.2fmA\n\n", phones[i].bateria);
      
      quantidade++;
    }
  }
  return  quantidade;
}

int main() {

  char opcao;
  int quantSmartphones, results = 0;
  Smartphone smarphones[100];

  while (true) {
    scanf(" %c", &opcao);

    if (opcao == 'n') {
      break;
    }

    quantSmartphones = cadastraSmartphone(
        quantSmartphones, 
        smarphones
      );
  }

  Smartphone reqMin;
  
  scanf(" %d %f %f %f", 
    &reqMin.memoria,
    &reqMin.processador, 
    &reqMin.camera,
    &reqMin.bateria
  );

  results = pesquisaSmartphones(quantSmartphones, smarphones, reqMin);
  printf("%d smartphones encontrados.\n", results);
}
