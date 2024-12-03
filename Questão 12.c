#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// (Estatística de Textos) Escreva um programa que receba um texto longo (uma redação) e que monte uma lista das palavras existentes no texto. Implemente as seguintes funções:
// a. Uma função que retorne quantas palavras tem no texto;
// b. Uma função que retorne quantas palavras distintas tem no texto;
// c. Uma função que retorne a quantidade média de letras das palavras;
// d. Uma função que retorne a maior palavra;
// e. Uma função que retorne a menor palavra;
// f. Uma função que retorne a palavra mais frequente
// g. Uma função que retorne a palavra mais rara

typedef struct No {
    char palavra[100];
    int frequencia;
    struct No *proximo;
} No;

No* criarNo(char* palavra) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->palavra, palavra);
    novo->frequencia = 1;
    novo->proximo = NULL;
    return novo;
}

void inserirPalavra(No **inicio, char* palavra) {
    No *atual = *inicio;
    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            atual->frequencia++;
            return;
        }
        atual = atual->proximo;
    }
    No *novo = criarNo(palavra);
    novo->proximo = *inicio;
    *inicio = novo;
}

int contarPalavras(No *inicio) {
    int count = 0;
    No *atual = inicio;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

int contarPalavrasDistintas(No *inicio) {
    return contarPalavras(inicio);
}

double mediaLetras(No *inicio) {
    int totalLetras = 0;
    int totalPalavras = 0;
    No *atual = inicio;
    while (atual != NULL) {
        totalLetras += strlen(atual->palavra);
        totalPalavras++;
        atual = atual->proximo;
    }
    return totalPalavras == 0 ? 0 : (double)totalLetras / totalPalavras;
}

char* maiorPalavra(No *inicio) {
    char* maior = NULL;
    int maiorTamanho = 0;
    No *atual = inicio;
    while (atual != NULL) {
        if (strlen(atual->palavra) > maiorTamanho) {
            maior = atual->palavra;
            maiorTamanho = strlen(atual->palavra);
        }
        atual = atual->proximo;
    }
    return maior;
}

char* menorPalavra(No *inicio) {
    char* menor = NULL;
    int menorTamanho = 100;
    No *atual = inicio;
    while (atual != NULL) {
        if (strlen(atual->palavra) < menorTamanho) {
            menor = atual->palavra;
            menorTamanho = strlen(atual->palavra);
        }
        atual = atual->proximo;
    }
    return menor;
}

char* palavraMaisFrequente(No *inicio) {
    int maiorFrequencia = 0;
    char* maisFrequente = NULL;
    No *atual = inicio;
    while (atual != NULL) {
        if (atual->frequencia > maiorFrequencia) {
            maiorFrequencia = atual->frequencia;
            maisFrequente = atual->palavra;
        }
        atual = atual->proximo;
    }
    return maisFrequente;
}

char* palavraMaisRara(No *inicio) {
    int menorFrequencia = 1000;
    char* maisRara = NULL;
    No *atual = inicio;
    while (atual != NULL) {
        if (atual->frequencia < menorFrequencia) {
            menorFrequencia = atual->frequencia;
            maisRara = atual->palavra;
        }
        atual = atual->proximo;
    }
    return maisRara;
}

void processarTexto(char *texto, No **inicio) {
    char palavra[100];
    int i, j = 0;
    for (i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            palavra[j++] = tolower(texto[i]);
        } else if (j > 0) {
            palavra[j] = '\0';
            inserirPalavra(inicio, palavra);
            j = 0;
        }
    }
    if (j > 0) {
        palavra[j] = '\0';
        inserirPalavra(inicio, palavra);
    }
}

int main() {
    char texto[] = "Este é um exemplo de texto. Este texto serve para exemplo.";
    No *lista = NULL;
    
    processarTexto(texto, &lista);
    
    printf("Total de palavras: %d\n", contarPalavras(lista));
    printf("Total de palavras distintas: %d\n", contarPalavrasDistintas(lista));
    printf("Média de letras: %.2f\n", mediaLetras(lista));
    printf("Maior palavra: %s\n", maiorPalavra(lista));
    printf("Menor palavra: %s\n", menorPalavra(lista));
    printf("Palavra mais frequente: %s\n", palavraMaisFrequente(lista));
    printf("Palavra mais rara: %s\n", palavraMaisRara(lista));
    
    return 0;
}
