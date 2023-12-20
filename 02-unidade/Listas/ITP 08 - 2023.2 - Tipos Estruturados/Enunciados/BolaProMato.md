​Os professores de ITP começaram a se viciar em um dos jogos mais perigosos da face da terra...o Cartola FC. Todos os dias eles avidamente acompanham os resultados das partidas, em busca de descobrir quem são as melhores contratações e como foi o desempenho do seu time.

Um certo professor careca que não será nomeado está em último lugar com zero pontos, e resolveu fazer um programa que confere se a tabela de classificação exibida pelo google está correta, de forma que ele possa orientar suas próximas escolhas baseadas nela. O problema é que ele não sabe programar, e pediu que a turma fizesse o programa.

O seu programa deve ler um número inteiro T, indicando a quantidade de times, seguido por T linhas no seguinte formato:

nome; vitorias empates derrotas gols_feitos gols_sofridos

onde:

    Nome: nome do time. Uma string composta de no máximo 200 caracteres.

    Vitorias, empates e derrotas: resultados das partidas jogadas. Valores inteiros.

    Gols Feitos e Gols sofridos: valores inteiros representando a quantidade de gols que o time marcou e sofreu.

O seu programa imprimirá como saída a tabela de classificação final do campeonato contendo:

- Nome do time;
- Pontos obtidos pelo time. Cada vitória conta 3 pontos, e empates contam 1 ponto;
- Número total de partidas;
- Número de vitórias;
- Número de empates;
- Número de derrotas;
- Gols Feitos;
- Gols Sofridos;
- Saldo de Gols;
- Lista dos times que estão na zona da Libertadores (6 primeiros no campeonato);
- Lista dos times que estão na zona de rebaixamento (4 últimos. A impressão deve iniciar do último lugar até o primeiro na zona).

Atente aos exemplos de saída para verificar a formatação da impressão.

A impressão deve ocorrer na ordem de classificação do campeonato. A posição dos times é definido em função dos seguintes critérios:

- Pontos: o time com mais pontos fica a frente do time com menos pontos.
- Número de vitórias: em caso de empate no número de pontos, considera-se na frente o time com mais vitórias;
- Saldo de gols: em caso de empate nos critérios anteriores, considera-se na frente o time com maior saldo de gols.

Seu programa deve conter:

- Um tipo de dado Time, que armazena as informações necessárias de cada time do campeonato;
- Uma função para realizar a leitura dos times da entrada;
- Uma função para realizar a impressão da tabela;

DICA: a impressão será mais fácil se você ordenar os times de acordo com os critérios do enunciado. Para isso, dá uma olhada no exemplo do material com a função Bubblesort, que poderá ser utilizada aqui!

```
Entrada:
20
athletico paranaense; 17 8 10 49 31
atletico mineiro; 11 9 15 40 46
avai; 3 9 23 16 55
bahia; 11 12 12 40 39
botafogo; 13 3 19 30 41
ceara; 10 7 18 34 38
chapecoense; 6 10 19 27 49
corinthias; 13 14 8 39 30
cruzeiro; 7 15 13 27 41
csa; 8 8 19 22 51
flamengo; 26 6 3 77 31
fluminense; 11 8 16 35 44
fortaleza; 13 7 15 46 47
goias; 14 7 14 41 55
gremio; 17 8 10 57 36
internacional; 14 9 12 40 36
palmeiras; 19 11 5 53 28
santos; 20 8 7 54 32
sao paulo; 15 12 8 35 25
vasco da gama; 11 11 13 36 43

20
Atletico Goianiense; 12 14 12 40 45
Atletico Mineiro; 20 8 10 64 45
Atletico Paranaense; 15 8 15 38 36
Bahia; 12 8 18 48 59
Botafogo; 5 12 21 32 62
Bragantino; 13 14 11 50 40
Ceara; 14 10 14 54 51
Corinthias; 13 12 13 45 45
Coritiba; 7 10 21 31 54
Flamengo; 21 8 9 68 48
Fluminense; 18 10 10 55 42
Fortaleza; 10 11 17 34 44
Goias; 9 10 19 41 63
Gremio; 14 17 7 53 40
Internacional; 20 10 8 61 35
Palmeiras; 15 13 10 51 37
Santos; 14 12 12 52 51
Sao Paulo; 18 12 8 59 41
Sport Recife; 12 6 20 31 50
Vasco da Gama; 10 11 17 37 56
```

```
Saída:
Tabela do campeonato:
Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols
flamengo| 84| 35| 26| 6| 3| 77| 31| 46
santos| 68| 35| 20| 8| 7| 54| 32| 22
palmeiras| 68| 35| 19| 11| 5| 53| 28| 25
gremio| 59| 35| 17| 8| 10| 57| 36| 21
athletico paranaense| 59| 35| 17| 8| 10| 49| 31| 18
sao paulo| 57| 35| 15| 12| 8| 35| 25| 10
corinthias| 53| 35| 13| 14| 8| 39| 30| 9
internacional| 51| 35| 14| 9| 12| 40| 36| 4
goias| 49| 35| 14| 7| 14| 41| 55| -14
fortaleza| 46| 35| 13| 7| 15| 46| 47| -1
bahia| 45| 35| 11| 12| 12| 40| 39| 1
vasco da gama| 44| 35| 11| 11| 13| 36| 43| -7
botafogo| 42| 35| 13| 3| 19| 30| 41| -11
atletico mineiro| 42| 35| 11| 9| 15| 40| 46| -6
fluminense| 41| 35| 11| 8| 16| 35| 44| -9
ceara| 37| 35| 10| 7| 18| 34| 38| -4
cruzeiro| 36| 35| 7| 15| 13| 27| 41| -14
csa| 32| 35| 8| 8| 19| 22| 51| -29
chapecoense| 28| 35| 6| 10| 19| 27| 49| -22
avai| 18| 35| 3| 9| 23| 16| 55| -39

Times na zona da libertadores: 
flamengo
santos
palmeiras
gremio
athletico paranaense
sao paulo

Times rebaixados: 
avai
chapecoense
csa
cruzeiro

Tabela do campeonato:
Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols
Flamengo| 71| 38| 21| 8| 9| 68| 48| 20
Internacional| 70| 38| 20| 10| 8| 61| 35| 26
Atletico Mineiro| 68| 38| 20| 8| 10| 64| 45| 19
Sao Paulo| 66| 38| 18| 12| 8| 59| 41| 18
Fluminense| 64| 38| 18| 10| 10| 55| 42| 13
Gremio| 59| 38| 14| 17| 7| 53| 40| 13
Palmeiras| 58| 38| 15| 13| 10| 51| 37| 14
Santos| 54| 38| 14| 12| 12| 52| 51| 1
Atletico Paranaense| 53| 38| 15| 8| 15| 38| 36| 2
Bragantino| 53| 38| 13| 14| 11| 50| 40| 10
Ceara| 52| 38| 14| 10| 14| 54| 51| 3
Corinthias| 51| 38| 13| 12| 13| 45| 45| 0
Atletico Goianiense| 50| 38| 12| 14| 12| 40| 45| -5
Bahia| 44| 38| 12| 8| 18| 48| 59| -11
Sport Recife| 42| 38| 12| 6| 20| 31| 50| -19
Fortaleza| 41| 38| 10| 11| 17| 34| 44| -10
Vasco da Gama| 41| 38| 10| 11| 17| 37| 56| -19
Goias| 37| 38| 9| 10| 19| 41| 63| -22
Coritiba| 31| 38| 7| 10| 21| 31| 54| -23
Botafogo| 27| 38| 5| 12| 21| 32| 62| -30

Times na zona da libertadores: 
Flamengo
Internacional
Atletico Mineiro
Sao Paulo
Fluminense
Gremio

Times rebaixados: 
Botafogo
Coritiba
Goias
Vasco da Gama
```