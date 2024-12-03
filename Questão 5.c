#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Usando listas dinâmicas, crie um programa que guarde strings. Re-implemente todas as funcionalidades para que seja 
// possível usar as funções básicas de inserção, remoção, busca e detecção de fim de lista;
// a. Implemente também a função que retorna o tamanho da lista (quantidade de elementos), e a perda de memória 
// (total da lista - quantidade de itens vazios) 

typedef struct Nodo {
    char string[100];
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
    int tamanho;
} Lista;

void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirNaLista(Lista *lista, const char *string) {
    Nodo *novo;
    novo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(novo->string, string);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void removerDaLista(Lista *lista, const char *string) {
    Nodo *anterior, *atual;
    anterior = NULL;
    atual = lista->inicio;
    while (atual != NULL && strcmp(atual->string, string) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            lista->inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
        lista->tamanho--;
    }
}

Nodo *buscarNaLista(Lista *lista, const char *string) {
    Nodo *atual;
    atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->string, string) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

int tamanhoDaLista(Lista *lista) {
    return lista->tamanho;
}

int perdaDeMemoria(Lista *lista) {
    int nodosAlocados;
    Nodo *atual;
    nodosAlocados = 0;
    atual = lista->inicio;
    while (atual != NULL) {
        nodosAlocados++;
        atual = atual->proximo;
    }
    return nodosAlocados - lista->tamanho;
}

int fimDaLista(Lista *lista, Nodo *nodo) {
    return nodo == NULL;
}

void liberarLista(Lista *lista) {
    Nodo *atual, *temp;
    atual = lista->inicio;
    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void imprimirLista(Lista *lista) {
    Nodo *atual;
    atual = lista->inicio;
    while (atual != NULL) {
        printf("%s\n", atual->string);
        atual = atual->proximo;
    }
}

int main() {
    Lista lista;
    inicializarLista(&lista);

    inserirNaLista(&lista, "primeira");
    inserirNaLista(&lista, "segunda");
    inserirNaLista(&lista, "terceira");

    imprimirLista(&lista);

    printf("Tamanho: %d\n", tamanhoDaLista(&lista));
    printf("Perda de memoria: %d\n", perdaDeMemoria(&lista));

    removerDaLista(&lista, "segunda");
    imprimirLista(&lista);

    liberarLista(&lista);
    return 0;
}
