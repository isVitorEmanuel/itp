Implemente um caça-palavras utilizando alocação dinâmica. Você deverá incluir o código abaixo em seu trabalho, o qual contém a definição dos tipos Grade e PalavraAchada, e as assinaturas das funções de localização e impressão das palavras encontradas:

// Guarda a matriz de caracteres do caça-palavras
typedef struct {
    char **m;
    int linhas;
    int colunas;
} Grade;

// Guarda a posição do primeiro caractere, o tamanho
// e a direção da palavra encontrada
typedef struct {
    int linha;
    int coluna;
    int tamanho;   
    char direcao;
} PalavraAchada;

PalavraAchada achaPalavra(Grade *g, char *p);
void imprimePalavra(Grade *g, PalavraAchada pa);
​Seu código principal será responsável por receber as entradas e deverá chamar as funções para localização de palavras e impressão.

A função de localização de palavras deverá receber como parâmetros uma Grade e a palavra a localizar. Deverá fornecer como resultado uma PalavraAchada, contendo a posição (linha e coluna) do primeiro caractere da palavra encontrada na Grade, o tamanho e a direção da palavra, conforme quadro abaixo:

'0' - palavra não encontrada
'c' - ↑ (para cima)
'b' - ↓ (para baixo)
'e' - ← (para a esquerda)
'd' - → (para a direita)
'1' - ↖ (diagonal cima/esquerda)
'2' - ↙ (diagonal baixo/esquerda)
'3' - ↗ (diagonal cima/direita)
'4' - ↘ (diagonal baixo/direita)

Obs1.: a função de localizar palavras deverá ignorar diferenças entre letras maiúsculas e minúsculas.
Obs2.: em caso de uma palavra em mais de um localização, considerar apenas aquela de menor índice.

A função de impressão de palavras deverá receber como parâmetros a Grade e a PalavraAchada.

Entrada do programa:
    * a quantidade N de palavras a procurar, a quantidade de linhas L da grade, a quantidade de colunas C da grade;
    * as N palavras a procurar, uma por linha;
    * uma matriz de caracteres de tamanho LxC, que deverá ser alocada dinamicamente num registro do tipo Grade.
```
casa
RATO
ave
LRFKqYUqfJ
kxYqvnrtYs
fRZRMZLygf
VeULqFPdbh
LQdQRRcrWd
NxEUoqrEKL
aitgasACsp
iJThBSTYFV
LadZpboUDK
kLRWQaoZmI
```
3 10 10

Saída do programa:

A saída do programa deverá conter, a cada linha:

    * a palavra encontrada;
    * a linha;
    * a coluna;
    * a direção. 
    * Caso a palavra não seja encontrada, a saída deverá conter a palavra que não foi localizada seguida de ",0,0,0".

```
CAsa,6,7,e
rATo,5,6,b
ave,0,0,0
```

Dicas:

    * Desenvolva e teste seu código gradualmente. Comece pela leitura e armazenamento das entradas. Para facilitar, você pode, inicialmente, guardar a grade de caracteres em uma matriz estática m[L][C].
    * Após a leitura dos dados de entrada, imprima a verifique se as palavras e o quadro foram armazenados corretamente.
    * Implemente a busca e a impressão das palavras utilizando a matriz de caracteres. Esta implementação pode ser tanto iterativa como recursiva.
    * Faça os ajustes do código para completar a tarefa, com a utilização do tipo Grade e da alocação dinâmica. 

Observação: Não serão aceitos códigos que não utilizem alocação dinâmica ou que não usem o tipo Grade.​

```
Entrada: 
5 7 11
venca
Torre
Derrota
ITP
desistir
hzVHzUIcvhV
hUaWlqffxcT
SFAFqAaXVvk
RsIhcPcpjYm
hIpCczNfOMl
taToRReDSkJ
gbIPpwvgiTP

3 9 8
casa
rato
ave
WinUJwoJ
UXZgqDLm
KLbLBbWZ
TlOWJKHj
WJjTLihL
DCIoAggl
daPMjROE
tSmrfknw
aVetHfnR
```

```
Saída:
veNca,6,6,c
ToRRe,5,2,d
DeRRoTa,5,7,e
ITP,4,1,4
desistir,0,0,0

casa,0,0,0
RATO,6,5,1
aVe,8,0,d
```