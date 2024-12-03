#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100

typedef struct {
    int elemento;
    int contador;
} Info;

int esta_ordenada(int L1[], int tamanho) {
    int i = 0;
    while (i < tamanho - 1) {
        if (L1[i] > L1[i + 1]) return 0;
        i++;
    }
    return 1;
}

void copiar_lista(int L1[], int tamanho, int L2[]) {
    int i = 0;
    while (i < tamanho) {
        L2[i] = L1[i];
        i++;
    }
}

int copiar_unicos(int L1[], int tamanho, int L2[]) {
    int i = 0, k = 0;
    while (i < tamanho) {
        if (i == 0 || L1[i] != L1[i - 1]) {
            L2[k] = L1[i];
            k++;
        }
        i++;
    }
    return k;
}

void inverter_lista(int L1[], int tamanho, int L2[]) {
    int i = 0;
    while (i < tamanho) {
        L2[i] = L1[tamanho - 1 - i];
        i++;
    }
}

void inverter_na_propria(int L1[], int tamanho) {
    int i = 0, temp;
    while (i < tamanho / 2) {
        temp = L1[i];
        L1[i] = L1[tamanho - 1 - i];
        L1[tamanho - 1 - i] = temp;
        i++;
    }
}

int intercalar_listas(int L1[], int tam1, int L2[], int tam2, int L3[]) {
    int i = 0, j = 0, k = 0;
    while (i < tam1 && j < tam2) {
        if (L1[i] <= L2[j]) L3[k++] = L1[i++];
        else L3[k++] = L2[j++];
    }
    while (i < tam1) L3[k++] = L1[i++];
    while (j < tam2) L3[k++] = L2[j++];
    return k;
}

int gerar_lista_contagem(int L1[], int tamanho, Info L2[]) {
    int i = 1, k = 0, contador = 1;
    while (i <= tamanho) {
        if (i == tamanho || L1[i] != L1[i - 1]) {
            L2[k].elemento = L1[i - 1];
            L2[k].contador = contador;
            k++;
            contador = 1;
        } else contador++;
        i++;
    }
    return k;
}

int remover_elemento(int L1[], int tamanho, int elem) {
    int i = 0, k = 0;
    while (i < tamanho) {
        if (L1[i] != elem) L1[k++] = L1[i];
        i++;
    }
    return k;
}

void extremos(int L1[], int tamanho, int *minElem, int *minFreq, int *maxElem, int *maxFreq) {
    int i = 1, contador = 1;
    *minFreq = tamanho;
    *maxFreq = 0;
    while (i <= tamanho) {
        if (i == tamanho || L1[i] != L1[i - 1]) {
            if (contador > *maxFreq) {
                *maxFreq = contador;
                *maxElem = L1[i - 1];
            }
            if (contador < *minFreq) {
                *minFreq = contador;
                *minElem = L1[i - 1];
            }
            contador = 1;
        } else contador++;
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
	int i = 0, imprimir = 0;
    int L1[MAX] = {1, 2, 2, 3, 4, 4, 4, 5};
    int tamanho1 = 8, tamanho2, tamanho3;
    int L2[MAX], L3[MAX];
    Info listaContagem[MAX];
    int menorElem, menorFreq, maiorElem, maiorFreq;

   printf("L1 está ordenada: ");
   resultado = esta_ordenada(L1, tamanho1);
      while (imprimir < 1) {
        if (resultado == 1) {
            printf("Sim\n");
        } else {
            printf("Não\n");
        }
        imprimir++;
    }


    copiar_lista(L1, tamanho1, L2);
    printf("Cópia de L1 em L2: ");
    for (i = 0; i < tamanho1; i++) printf("%d ", L2[i]);
    printf("\n");

    tamanho2 = copiar_unicos(L1, tamanho1, L2);
    printf("Cópia única de L1 em L2: ");
    for (i = 0; i < tamanho2; i++) printf("%d ", L2[i]);
    printf("\n");

    inverter_lista(L1, tamanho1, L2);
    printf("L1 invertida em L2: ");
    for (i = 0; i < tamanho1; i++) printf("%d ", L2[i]);
    printf("\n");

    inverter_na_propria(L1, tamanho1);
    printf("L1 invertida na própria L1: ");
    for (i = 0; i < tamanho1; i++) printf("%d ", L1[i]);
    printf("\n");

    tamanho3 = intercalar_listas(L1, tamanho1, L2, tamanho2, L3);
    printf("L1 e L2 intercaladas em L3: ");
    for (i = 0; i < tamanho3; i++) printf("%d ", L3[i]);
    printf("\n");

    tamanho2 = gerar_lista_contagem(L1, tamanho1, listaContagem);
    printf("Lista de contagem:\n");
    for (i = 0; i < tamanho2; i++) {
        printf("Elemento: %d, Contagem: %d\n", listaContagem[i].elemento, listaContagem[i].contador);
    }

    tamanho1 = remover_elemento(L1, tamanho1, 4);
    printf("L1 após remover o elemento 4: ");
    for (i = 0; i < tamanho1; i++) printf("%d ", L1[i]);
    printf("\n");

    extremos(L1, tamanho1, &menorElem, &menorFreq, &maiorElem, &maiorFreq);
    printf("Elemento com menor frequência: %d (%d vezes)\n", menorElem, menorFreq);
    printf("Elemento com maior frequência: %d (%d vezes)\n", maiorElem, maiorFreq);

    return 0;
}
