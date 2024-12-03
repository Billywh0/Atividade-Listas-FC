#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Escreva uma função que obtém o espelho de uma árvore, ou seja, troca a 
subárvore direita pela subárvore esquerda de todos os nós da árvore*/

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;  // NÓ

No* criarNo(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

void espelharArvore(No *raiz) {
    if (raiz == NULL) {
        return;
    }

    // Troca as subárvores esquerda e direita
    No *temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    espelharArvore(raiz->esquerda);
    espelharArvore(raiz->direita);
}

int alturaArvore(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int alturaEsquerda = alturaArvore(raiz->esquerda);
    int alturaDireita = alturaArvore(raiz->direita);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

void imprimirNivel(No *raiz, int nivelAtual, int nivelDesejado) {
    if (raiz == NULL) {
        if (nivelAtual == nivelDesejado) {
            printf("   ");
        }
        return;
    }
    if (nivelAtual == nivelDesejado) {
        printf(" %d ", raiz->valor);
    } else {
        imprimirNivel(raiz->esquerda, nivelAtual + 1, nivelDesejado);
        imprimirNivel(raiz->direita, nivelAtual + 1, nivelDesejado);
    }
}

void imprimirArvore(No *raiz) {
	int i;
    int h = alturaArvore(raiz);
    for (i = 1; i <= h; i++) {
        imprimirNivel(raiz, 1, i);
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "PORTUGUESE");
	
	// Árvore original
    No *raiz = criarNo(4);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(6);
    raiz->esquerda->esquerda = criarNo(1);
    raiz->esquerda->direita = criarNo(3);
    raiz->direita->esquerda = criarNo(5);
    raiz->direita->direita = criarNo(10);
    raiz->direita->direita->esquerda = criarNo(8);

    printf("Árvore original:\n");
    imprimirArvore(raiz);

    // Árvore espelhada
    espelharArvore(raiz);
    printf("\nÁrvore espelhada:\n");
    imprimirArvore(raiz);

    return 0;
}
