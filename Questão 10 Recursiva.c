#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

int listasIguaisRecursivo(No *lista1, No *lista2) {
    if (lista1 == NULL && lista2 == NULL) {
        return 1;
    }
    if (lista1 == NULL || lista2 == NULL || lista1->valor != lista2->valor) {
        return 0;
    }
    return listasIguaisRecursivo(lista1->proximo, lista2->proximo);
}

No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

int main() {
    No *lista1 = criarNo(1);
    lista1->proximo = criarNo(2);
    lista1->proximo->proximo = criarNo(3);

    No *lista2 = criarNo(1);
    lista2->proximo = criarNo(2);
    lista2->proximo->proximo = criarNo(3);

    if (listasIguaisRecursivo(lista1, lista2)) {
        printf("As listas são iguais\n");
    } else {
        printf("As listas são diferentes\n");
    }

    No *atual;
    while (lista1 != NULL) {
        atual = lista1;
        lista1 = lista1->proximo;
        free(atual);
    }
    while (lista2 != NULL) {
        atual = lista2;
        lista2 = lista2->proximo;
        free(atual);
    }

    return 0;
}
