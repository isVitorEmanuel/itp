#include <stdio.h>
#include <string.h>

const char S[] =
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

int encontrarIndice(char c) {
    for (int i = 0; i < 40; i++)
        if (S[i] == c)
            return i;
    return -1;
}

char encontrarSimbolo(int i) {
    while (i < 0)
        i += 40;
    return S[i % 40];
}

int distanciaEntreSimbolos(char c, char d) {
    int indice_c = encontrarIndice(c);
    int indice_d = encontrarIndice(d);
    if (indice_c < 0 || indice_d < 0)
        return -1;

    int distancia = indice_c - indice_d;
    if (distancia < 0)
        distancia += 40;
    return distancia;
}

int descobrirChave(char CT[], char KP[], int chave[]) {
    int tamKP = strlen(KP);
    int tamCT = strlen(CT);
    int chaveDecifrada = 0;
    int indiceMaximo = tamCT - tamKP;

    for (int i = 0; i <= indiceMaximo && !chaveDecifrada; i++) {
        int match = 1;
        for (int j = 0; j < 4 && match; j++) {
            int posChave = (i + j) % 4;
            chave[posChave] = distanciaEntreSimbolos(CT[i + j], KP[j]);
            for (int k = j + 4; k < tamKP && match; k += 4)
                if (chave[posChave] != distanciaEntreSimbolos(CT[i + k], KP[k]))
                    match = 0;
        }
        chaveDecifrada = match;
    }
    return chaveDecifrada;
}

void decifrar(char CT[], int chave[]) {
    for (int i = 0; CT[i] != 0; i++)
        CT[i] = encontrarSimbolo(encontrarIndice(CT[i]) - chave[i % 4]);
}

int main() {
    int chave[4];
    char KP[] = "QUE A FORCA ESTEJA COM VOCE";
    char CT[200];

    fgets(CT, 200, stdin);
    CT[strlen(CT) - 1] = 0;

    int chaveDescoberta = descobrirChave(CT, KP, chave);

    if (chaveDescoberta) {
        for (int i = 0; i < 4; i++)
            printf("%d", chave[i]);
        printf("\n");

        decifrar(CT, chave);
        printf("%s\n", CT);
    } else {
        printf("Mensagem nao e da Resistencia!\n");
    }

    return 0;
}
