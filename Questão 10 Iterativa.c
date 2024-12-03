#include <stdio.h>
#include <stdlib.h>

// Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma iterativa e uma recursiva.

typedef struct No {
    int valor;
    struct No *proximo;
} No;

int listasIguaisIterativo(No *lista1, No *lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor != lista2->valor) {
            return 0;
        }
        lista1 = lista1->proximo;
        lista2 = lista2->proximo;
    }
    return lista1 == NULL && lista2 == NULL;
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

    if (listasIguaisIterativo(lista1, lista2)) {
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
