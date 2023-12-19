Espaço, a fronteira final...

Em sua constante jornada de exploração, a tripulação da nave Enterprise tem como importante missão mapear as áreas do espaço ainda desconhecidas pela Federação Galática. Encontrar novos planetas habitáveis, fazer contatos com novas civilizações, evitar conflitos contra Romulanos e Cardassianos... Não existe um dia lento para um oficial a serviço da Federação!

Como um novo recruta da divisão de ciências, você está responsável por atualizar os sistemas de sonda da nave. A partir dos scanners, é possível descobrir a composição da geografia do planeta, e classificá-lo de acordo com a taxonomia oficial da Federação. Existem seis tipos de planetas possíveis no atual quadro de classificação:

Planeta Classe M: única categoria considerada habitável, são planetas que possuem pelo menos 50% do território coberto por água, pelo menos 20% de florestas e áreas de vegetação e nenhuma espécie hostil considerada perigosa demais para o convívio no planeta.
```
Planeta Hostil: possui pelo menos uma espécie hostil considerada perigosa demais para o convívio no planeta.
Planeta Aquático: possui 85% da superfície coberta com água.
Planeta Desértico: possui 60% da superfície coberta de áreas de deserto.
Planeta Selvagem: possui 65% da superfície coberto por áreas de vegetação e florestas.
Planeta Inóspito: não possui uma quantidade mínima de recursos para tornar-se habitável, nem para ser classificado como um dos planetas anteriores.
```
A imagem do scanner mapeia a superfície do planeta como uma matriz de tamanho N por M, onde N indica o número de linhas, e M o número de colunas. A imagem gerada pelo scanner é formada por N x M símbolos, de acordo com a listagem abaixo.

"~" (acento til) :representa água
"X" (letra xis maiúscula) :representa espécies hostis
"^"(acento circunflexo):representa áreas de deserto
"*" (asterisco) : representa áreas de vegetação
"."(ponto final) :representa solo sem recursos naturais

Seu programa deve ler dois valores inteiros da entrada, as dimensões N e M do mapa, seguido de NxM símbolos representando a superfície do planeta. A saída do seu programa deverá ser a classificação desse planeta de acordo com os tipos descritos acima. Observe atentamente os exemplos de entrada e saída para ver a formatação esperada.

```
Entrada:
5 5
~~~~~
~..*~
~~**~
~****
~~**^

5 5
~~~~~
~..*~
~~**~
~****
~~**X
```

```
Saída:
Planeta Classe M

Planeta Hostil
```