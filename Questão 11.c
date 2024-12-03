#include <stdio.h>
#include <stdlib.h>

// (Ponto médio)  Escreva uma função que receba uma lista encadeada e devolva o endereço de uma célula que esteja 
// o mais próximo possível do meio da lista. Faça isso sem contar explicitamente o número de células da lista.

typedef struct No {
    int valor;
    struct No *proximo;
} No;

No *encontrarPontoMedio(No *inicio) {
    No *rapido = inicio;
    No *lento = inicio;
    
    while (rapido != NULL && rapido->proximo != NULL) {
        rapido = rapido->proximo->proximo;
        lento = lento->proximo;
    }
    
    return lento;
}

No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

int main() {
    No *lista = criarNo(1);
    lista->proximo = criarNo(2);
    lista->proximo->proximo = criarNo(3);
    lista->proximo->proximo->proximo = criarNo(4);
    lista->proximo->proximo->proximo->proximo = criarNo(5);

    No *meio = encontrarPontoMedio(lista);
    
    if (meio != NULL) {
        printf("O valor do ponto médio é: %d\n", meio->valor);
    }

    No *atual;
    while (lista != NULL) {
        atual = lista;
        lista = lista->proximo;
        free(atual);
    }

    return 0;
}
