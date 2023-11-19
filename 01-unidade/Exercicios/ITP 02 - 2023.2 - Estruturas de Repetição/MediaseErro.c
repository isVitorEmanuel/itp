#include <stdio.h>

int main() {

  double AriMed, AriHar, AriGeo, HarErro, GeoErro, MedErro;
  int Var;
  int SomaVar, MultVar = 0;

  for (int count = 1; count <= 10; count++) {

    scanf("%d", &Var);

    SomaVar = Var + SomaVar;
    
    MultVar = MultVar * Var;

    //continuar
  }
}