#include <stdio.h>
#include <string.h>

// Fazer um programa em C que lê uma lista de 20 produtos e de preços e armazena-os em um array do tipo da estrutura abaixo. 
// O programa deve, em seguida, ordenar o vetor em ordem alfabética de nome de produto e inflacionar os produtos cujo valor for menor que 100 em 5%. 
// Por fim, a lista de produtos/preços deve ser impressa. 

int i, j;

typedef struct {
    char nome[80];
    float preco;
} Produto;

void lerProdutos(Produto produtos[], int n) {
    for (i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %[^\n]", produtos[i].nome);
        printf("Digite o preco do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }
}

void ordenarProdutos(Produto produtos[], int n) {
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

void inflacionarPrecos(Produto produtos[], int n) {
    for (i = 0; i < n; i++) {
        if (produtos[i].preco < 100) {
            produtos[i].preco *= 1.05;
        }
    }
}

void imprimirProdutos(Produto produtos[], int n) {
    for (i = 0; i < n; i++) {
        printf("Produto: %s, Preco: %.2f\n", produtos[i].nome, produtos[i].preco);
    }
}

int main() {
    Produto produtos[20];
    int n = 20;

    lerProdutos(produtos, n);
    ordenarProdutos(produtos, n);
    inflacionarPrecos(produtos, n);
    imprimirProdutos(produtos, n);

    return 0;
}
