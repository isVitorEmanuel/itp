#ifndef DEF
#define DEF
#define MAX_NAME 50

typedef enum { CHAR, STRING, INT, FLOAT, DOUBLE } Types;

typedef struct {
  char dataChar;
  int dataInt;
  float dataFloat;
  double dataDouble;
  char *dataString;
} Celula;

typedef struct {
  char nomeColuna[MAX_NAME];
  Types tipoColuna;
} Coluna;

typedef struct {
  char nomeTabela[MAX_NAME];
  int numLinhas;
  int numColunas;
  Coluna *colunas; // Guardará os nomes das colunas e os tipos
  Coluna chavePrimaria;
  Celula **dados; // Matriz de células
} Tabela;
#endif