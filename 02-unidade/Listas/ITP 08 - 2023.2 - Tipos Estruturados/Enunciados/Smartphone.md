Um site de avaliação de dispositivos móveis deseja fazer uma aplicação para permitir que seus visitantes encontrem os smartphones que desejam com mais facilidade. A aplicação deve permitir cadastrar smartphones e pesquisar aqueles que atendem aos requisitos mínimos de hardware. Faça um programa em C para auxiliar nesta tarefa. Para isso defina uma estrutura Smartphone com os campos:

char modelo[40];
int memoria;
float processador;
float camera;
float bateria;
Implemente a função int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]), a qual deverá acrescentar um smartphone ao cadastro no final da lista, solicitar do usuário os dados para preenchimento da estrutura e retornar a quantidade de smartphones na lista. 

Implementar a função int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin), a qual deverá exibir na tela os dados de todos os smartphones que atendem aos requisitos mínimos (reqMin) e retornar a quantidade de smartphones encontrados utilizando esse critério.

Na função main(), em um laço, o programa receberá do usuário a resposta relacionada ao cadastro de um smartphone, enquanto for ‘s’ (para sim), a função cadastraSmartphone deve ser chamada. Caso contrário, o programa deverá parar de cadastrar novos smartphones.  Após o final do laço de cadastro, o programa deverá solicitar uma estrutura Smartphone com os requisitos mínimos (reqMin) a serem passados para a função pesquisaSmartphones, para que esta procure na lista de cadastro os smartphones compatíveis. Por fim, o programa deverá imprimir a quantidade de smartphones encontrados pela função pesquisaSmartphones.Observe que, para a estrutura Smartphone com os requisitos mínimos, o campo modelo (nome do aparelho) não deverá ser preenchido, já que não é um critério avaliativo.

Dica: Utilize scanf(" %[^\n]s", modelo) para ler o modelo e scanf(" %d %f %f %f", memoria, ...) para ler os demais dados do smartphone.

```
Entrada:
s
Galaxy A51
4
2
48
4000
s
Galaxy S20 Ultra
12
2.44
108
5000
s
Redmi 9
3
1.9
13
5020
s
Asus Zenfone Shot Plus
4
1.8
12
4000
n
4
2
48
4500                

s
Galaxy A71 5G
6
2.2
64
4500
s
Galaxy S20 Ultra
12
2.44
108
5000
s
Galaxy A51
4
2
48
4000
n
4
2
48
4500
```

```
Saída:
Modelo: Galaxy S20 Ultra
Memoria: 12GB
Processador: 2.44Ghz
Camera: 108.00MPixels
Bateria: 5000.00mA

1 smartphones encontrados.

Modelo: Galaxy A71 5G
Memoria: 6GB
Processador: 2.20Ghz
Camera: 64.00MPixels
Bateria: 4500.00mA

Modelo: Galaxy S20 Ultra
Memoria: 12GB
Processador: 2.44Ghz
Camera: 108.00MPixels
Bateria: 5000.00mA

2 smartphones encontrados.
```