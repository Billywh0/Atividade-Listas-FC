#include <stdio.h>
#include <stdlib.h>

// Escreva uma função que encontre uma célula com conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.

typedef struct No {
    int valor;
    struct No *proximo;
} No;

No *encontrarMinimoRecursivo(No *inicio, No *minimo) {
    if (inicio == NULL) {
        return minimo;
    }
    if (minimo == NULL || inicio->valor < minimo->valor) {
        minimo = inicio;
    }
    return encontrarMinimoRecursivo(inicio->proximo, minimo);
}

No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

int main() {
    No *inicio = criarNo(7);
    inicio->proximo = criarNo(3);
    inicio->proximo->proximo = criarNo(5);

    No *minimo = encontrarMinimoRecursivo(inicio, NULL);
    if (minimo != NULL) {
        printf("O valor mínimo é: %d\n", minimo->valor);
    }

    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
