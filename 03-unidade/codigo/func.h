#include "definicoes.h"

Tabela criarTabela();
void *carregarTabelas(Tabela *tabelas, int *numTabs);
void listarTabelas(Tabela *tabelas, int numTab);
void adicionarLinha(Tabela *tabela);
void listarDadosTabela(Tabela tabela);
Tabela *apagarTabela(Tabela *tabelas, int *numTab, char *nomeTabela);