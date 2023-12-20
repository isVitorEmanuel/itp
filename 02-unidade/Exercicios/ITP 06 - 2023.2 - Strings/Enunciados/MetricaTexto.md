Escreva um programa que leia do usuário um conjunto de textos (com espaços incluso) e depois imprima as seguintes métricas dos textos lidos:

O tamanho máximo entre os textos
O tamanho mínimo entre os textos
A média entre os tamanhos, com 2 casas decimais.
Os textos com tamanho mais próximos da média (podem ser mais de um)
A entrada é composta por um valor N, que define a quantidade de textos a serem fornecidos, seguida por N textos, um por linha. Cada texto não pode ter mais de 200 caracteres. Os textos podem ter espaços, como "Sao Paulo". Uma sugestão de implementação é usar o valor de N para declarar um vetor de strings que pode ser usado para armazenar os textos para processamento posterior.

Dica: Ler strings em C não é uma tarefa difícil, mas usualmente leva a vários erros desnecessários. Nesta questão e em outras, caso deseje, use a função abaixo para ler uma linha de texto:

void read_line(char linha[], int tam, FILE* f){
    fgets(linha, tam, f);
    while(linha[0] == '\n')
        fgets(linha, tam, f);
    if(linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1]='\0';
}
// para usar faça como a função fgets: read_line(string, 200, stdin);
// precisa incluir o stdio.h e string.h

```
Entrada: 
3
Teste
124
Teste_sem_espaco

4
Campos do Jordao
Montes Claros
Minar
Havaiano
```

```
Saída:
Tamanho máximo: 16
Tamanho mínimo: 3
Tamanho médio: 8.00
Tamanho mais próximo da média 5
Textos
Teste

Tamanho máximo: 16
Tamanho mínimo: 5
Tamanho médio: 10.50
Tamanho mais próximo da média 13
Textos
Montes Claros
```