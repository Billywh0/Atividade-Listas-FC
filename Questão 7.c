#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.*/

typedef struct No {
    int valor;
    struct No* proximo;
} No;  // NÓ


int listaCrescente(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL && atual->proximo != NULL) {
        if (atual->valor > atual->proximo->valor) {
            return 0; // Não está em ordem crescente
        }
        atual = atual->proximo;
    }
    return 1; // Está em ordem crescente
}

void exibirLista(No* cabeca) {
    No* atual = cabeca;
    printf("Números na lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = valor;
        novo->proximo = NULL;
    }
    return novo;
}

void liberarLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
	setlocale(LC_ALL, "PORTUGUESE");

    No* lista = criarNo(5);
    lista->proximo = criarNo(15);
    lista->proximo->proximo = criarNo(25);

    exibirLista(lista);

    if (listaCrescente(lista) == 1) {
        printf("A lista está em ordem crescente\n");
    } else {
        printf("A lista não está em ordem crescente\n");
    }

    liberarLista(lista);
	
	lista = criarNo(25);
    lista->proximo = criarNo(15);
    lista->proximo->proximo = criarNo(5);

    exibirLista(lista);

    if (listaCrescente(lista) == 1) {
        printf("A lista está em ordem crescente\n");
    } else {
        printf("A lista não está em ordem crescente\n");
    }
    
    return 0;
}
