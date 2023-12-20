Crie um programa que receba uma sequência de endereços de e-mails de até 50 caracteres no formato nome@parte1.parte2 terminada pela palavra FIM. O programa deve exibir na saída padrão a parte parte1 de cada e-mail entrado em ordem alfabética. Assuma que na parte nome do e-mail não pode conter o caractere '@' e a parte parte1 não pode conter o caractere '.'.

O programa não deve utilizar variáveis globais e nem vetores com tamanhos fixos, isto é, deve fazer alocação dinâmica dos e-mails informados.

```
Entrada: 
nome@parte1.parte2
nome@parte3.parte4
FIM

fulano.beltrano@ufrn.br
nome.sobrenome@dominio.com
FIM
```

```
Saída:
parte1
parte3

dominio
ufrn
```