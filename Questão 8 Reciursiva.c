#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

int buscaRecursiva(No *inicio, int chave) {
    if (inicio == NULL) {
        return 0;
    }
    if (inicio->valor == chave) {
        return 1;
    }
    return buscaRecursiva(inicio->proximo, chave);
}

No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

int main() {
    No *inicio = criarNo(1);
    inicio->proximo = criarNo(3);
    inicio->proximo->proximo = criarNo(5);

    if (buscaRecursiva(inicio, 4)) {
        printf("Elemento encontrado\n");
    } else {
        printf("Elemento não encontrado\n");
    }

    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
