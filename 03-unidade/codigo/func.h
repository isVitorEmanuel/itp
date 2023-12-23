#include "definicoes.h"

Tabela criarTabela();
void listarTabelas(Tabela *tabelas, int numTab);
void adicionarLinha(Tabela *tabela);
void listarDadosTabela(Tabela tabela);
Tabela *apagarTabela(Tabela *tabelas, int *numTab, char *nomeTabela);
void deletarLinha(char *nomeTabela, Tabela *tabelas, int numTabs, int chavePrimaria);
void sValues(Tabela tabela, char *nomeColuna, Celula valor, int type);