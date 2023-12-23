#include "definicoes.h"

void carregarQuantidade(int *numTabs);
Tabela *inserirTabela(Tabela *tabelas, int *numTab, Tabela novaTabela);
void *carregarTabelas(Tabela *tabelas, int *numTabs);
void salvarNome(Tabela *tabelas, int numTabs);
void salvarQuantidade(int numTabs);
void salvarTabela(Tabela tabela);
int encontrarNumeroDaColuna(Tabela tabela, char *nomeColuna);
int levenshteinDistance(char *str1, char *str2);
int minimum(int a, int b, int c);
void sValues(Tabela tabela, char *nomeColuna, Celula valor, int type);
void buscarValoresMaiores(Tabela tabela, char *nomeColuna, int type,
                          Celula valor);
void buscarValoresMaioresOuIguais(Tabela tabela, char *nomeColuna, int type,
                                  Celula valor);
void buscarValoresIguais(Tabela tabela, char *nomeColuna, int type,
                         Celula valor);
void buscarValoresMenores(Tabela tabela, char *nomeColuna, int type,
                          Celula valor);
void buscarValoresMenoresOuIguais(Tabela tabela, char *nomeColuna, int type,
                                  Celula valor);
void buscarValoresParecidos(Tabela tabela, char *nomeColuna, char *string);
void printRow(Tabela tabela, int rowNum);