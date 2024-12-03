#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SLOTS 50

typedef struct {
    int itens[SLOTS];
    int tamanho;
} Lista;

void inicializar_lista(Lista *lista) {
    lista->tamanho = 0;
}

int inserir_crescente(Lista *lista, int x) {
    if (lista->tamanho >= SLOTS) {
        return 0; // Lista cheia
    }

    int i = 0;
    while (i < lista->tamanho && lista->itens[i] < x) {
        i++;
    }

    if (lista->tamanho > i) {
        memmove(&lista->itens[i + 1], &lista->itens[i], (lista->tamanho - i) * sizeof(int));
    }
    lista->itens[i] = x;
    lista->tamanho++;
    return 1; // Sucesso
}

int inserir_decrescente(Lista *lista, int x) {
    if (lista->tamanho >= SLOTS) {
        return 0; // Lista cheia
    }

    int i = 0;
    while (i < lista->tamanho && lista->itens[i] > x) {
        i++;
    }

    if (lista->tamanho > i) {
        memmove(&lista->itens[i + 1], &lista->itens[i], (lista->tamanho - i) * sizeof(int));
    }
    lista->itens[i] = x;
    lista->tamanho++;
    return 1; // Sucesso
}

void exibir_lista(const Lista *lista) {
	int i;
    for (i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->itens[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Lista lista;
    inicializar_lista(&lista);

    inserir_crescente(&lista, 5);
    inserir_crescente(&lista, 15);
    inserir_crescente(&lista, 25);
    inserir_crescente(&lista, 6);
    printf("Lista em ordem crescente:\n"); // Ordem crescente
    exibir_lista(&lista);

    // Reinicializar a lista
    inicializar_lista(&lista);

    inserir_decrescente(&lista, 5);
    inserir_decrescente(&lista, 15);
    inserir_decrescente(&lista, 25);
    inserir_decrescente(&lista, 6);
    printf("\nLista em ordem decrescente:\n"); // Ordem decrescente
    exibir_lista(&lista);

    return 0;
}
