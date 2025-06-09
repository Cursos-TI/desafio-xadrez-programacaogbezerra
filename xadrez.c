#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int movimentoRei(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1;
}

int movimentoTorre(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2;
}

int movimentoBispo(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

int movimentoRainha(int x1, int y1, int x2, int y2) {
    return movimentoTorre(x1, y1, x2, y2) || movimentoBispo(x1, y1, x2, y2);
}

int coordenadaValida(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

int main() {
    char peca[10];
    int x1, y1, x2, y2;

    printf("=== DESAFIO DE PEÇAS DE XADREZ ===\n");
    printf("Escolha a peça (Rei, Torre, Bispo, Rainha): ");
    scanf("%s", peca);

    // Transforma para minúsculas
    for (int i = 0; peca[i]; i++) {
        peca[i] = tolower(peca[i]);
    }

    printf("Informe a posição atual (linha coluna, de 1 a 8): ");
    scanf("%d %d", &x1, &y1);

    printf("Informe a posição de destino (linha coluna, de 1 a 8): ");
    scanf("%d %d", &x2, &y2);

    if (!coordenadaValida(x1, y1) || !coordenadaValida(x2, y2)) {
        printf("Posições inválidas. Use valores de 1 a 8.\n");
        return 1;
    }

    int valido = 0;

    if (strcmp(peca, "rei") == 0) {
        valido = movimentoRei(x1, y1, x2, y2);
    } else if (strcmp(peca, "torre") == 0) {
        valido = movimentoTorre(x1, y1, x2, y2);
    } else if (strcmp(peca, "bispo") == 0) {
        valido = movimentoBispo(x1, y1, x2, y2);
    } else if (strcmp(peca, "rainha") == 0) {
        valido = movimentoRainha(x1, y1, x2, y2);
    } else {
        printf("Peça inválida.\n");
        return 1;
    }

    if (valido) {
        printf("Movimento VÁLIDO para a peça %s.\n", peca);
    } else {
        printf("Movimento INVÁLIDO para a peça %s.\n", peca);
    }

    return 0;
}
