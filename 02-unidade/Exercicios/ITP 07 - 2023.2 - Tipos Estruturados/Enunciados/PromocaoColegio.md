A diretora de uma escola está fazendo uma promoção comemorativa pelos 15 anos de inauguração do colégio. Para isso ela lançou um concurso para cada um dos três anos do ensino médio. Serão calculadas as médias das turmas A e B de cada ano. Todas as turmas que tiverem a média acima de 8 ganharão uma viagem com passagens e hospedagem pagos pelo colégio! E ainda tem mais! O melhor aluno de cada ano (maior nota entre as turmas A e B de cada ano do ensino médio) ganhará passagens, hospedagem e também os ingressos para os parques que eles vão visitar. Detalhe importante!! Para o melhor aluno ganhar esse prêmio ele precisa ter nota acima de 8!

Como são muitos alunos por turma, a diretora precisa de sua ajuda para saber quem são os ganhadores. Para isso faça um programa que, dadas as informações das turmas A e B de um dos anos do ensino médio, ele escreve na tela qual das turmas foi contemplada com a viagem e qual o aluno ganhou o ingresso por ter tido a melhor nota entre as duas turmas.

Escreva uma função que leia os dados (nome e nota de cada aluno) de duas turmas (A e B), determine e informe qual turma (ou se as duas, ou se nenhuma) será contemplada com a viagem paga e determine e informe qual aluno foi contemplado com ingresso grátis. Para isso:

escreva uma função que leia os dados dos alunos de uma turma e armazene em um registro e 
escreva uma função que, dado o registro de uma turma, determine qual aluno foi o melhor. 
DEFINA e UTILIZE um tipo estruturado adequado para armazenar as informações de entrada.

Proibido uso de ponteiros.

entrada: 

Serão fornecidos os nomes e notas de cada aluno da turma. Quando não houver mais alunos na turma, o usuário deve digitar *. A partir daí serão digitados os dados (nomes e notas) da segunda turma. Assim como ocorreu com a primeira, não havendo mais alunos, o usuário digitará *. Observe o exemplo a seguir:

maria
8
joao
9.2
marcio
9.8
jose
9.1
ana
4.1
beatriz
4.2
josefa
4.3

Neste caso a turma A possui 4 alunos (maria, joao, marcio e jose) e a turma B possui 3 alunos (ana, beatriz e josefa). Observe o asterisco indicando o final da turma após a conclusão da digitação dos dados de cada turma. Obs.: Por motivos didáticos, não haverá casos de testes que tenham alunos empatados (notas iguais).

saída: O seu programa deverá imprimir uma das seguintes mensagens:

Viagem para todos!
Viagem para turma A
Viagem para turma B
Nenhuma das turmas viaja...

Após a mensagem que indica qual turma irá viajar, o programa deve imprimir o nome do melhor aluno e sua nota, ou uma mensagem avisando que não houve ganhador para esse prêmio. Veja o modelo:

Caso haja ganhador:
marcio ganhou viagem e ingresso no parque!
Nota: 9.80

Utilize arredondamento para 2 casas decimais no valor da nota.

Caso não haja ganhador:
Ninguem ganhou viagem e ingresso no parque...

Todas as mensagens são seguidas de um final de linha.

```
Entrada: 
maria
8
joao
9.2
marcio
9.8
jose
9.1
*
ana
4.1
beatriz
4.2
josefa
4.3
*

a1
4.0
a2
4.1
a3
4.2
a4
4.3
*
b1
5.0
b2
5.1
b3
5.2
*
```

```
Saída:
Viagem para turma A
marcio ganhou viagem e ingresso no parque!
Nota: 9.80

Nenhuma das turmas viaja...
Ninguem ganhou viagem e ingresso no parque...
```