#include <stdio.h>
#include <stdlib.h>

// Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa.

typedef struct No {
    int valor;
    struct No *proximo;
} No;

int buscaIterativa(No *inicio, int chave) {
    No *atual = inicio;
    while (atual != NULL) {
        if (atual->valor == chave) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
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

    if (buscaIterativa(inicio, 3)) {
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
