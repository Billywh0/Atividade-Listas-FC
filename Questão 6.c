#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vamos montar um programa de gestão de contatos;
// a. Crie um tipo novo, baseado em uma struct, que guardará os dados do contato (nome, telefone, email). 
// Use os tipos primitivos que você considerar adequados para os campos dessa struct;
// b. Instancie o container de dados usando esse seu novo tipo;
// c. Implemente as funcionalidades básicas, no estilo das listas, para inserir, remover, buscar e detectar o fim da lista de contatos
// d. Implemente as funcionalidades clássicas de uma agenda de contatos, em funções individuais:
//  1- Atualizar Nome do contato;
//  2- Atualizar Telefone do contato;
//  3- Atualizar email do contato;
// e. Construa um fluxo de interface em texto, para atuar como front-end para as funcionalidades já construídas;

typedef struct Contato {
    char nome[100];
    char telefone[20];
    char email[100];
    struct Contato *proximo;
} Contato;

typedef struct {
    Contato *inicio;
    int tamanho;
} ListaContatos;

void inicializarLista(ListaContatos *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirContato(ListaContatos *lista, const char *nome, const char *telefone, const char *email) {
    Contato *novo;
    novo = (Contato *)malloc(sizeof(Contato));
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    strcpy(novo->email, email);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

Contato *buscarContato(ListaContatos *lista, const char *nome) {
    Contato *atual;
    atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void removerContato(ListaContatos *lista, const char *nome) {
    Contato *anterior, *atual;
    anterior = NULL;
    atual = lista->inicio;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
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

void atualizarNome(Contato *contato, const char *novoNome) {
    strcpy(contato->nome, novoNome);
}

void atualizarTelefone(Contato *contato, const char *novoTelefone) {
    strcpy(contato->telefone, novoTelefone);
}

void atualizarEmail(Contato *contato, const char *novoEmail) {
    strcpy(contato->email, novoEmail);
}

int fimDaLista(Contato *contato) {
    return contato == NULL;
}

void imprimirContatos(ListaContatos *lista) {
    Contato *atual;
    atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Telefone: %s\n", atual->telefone);
        printf("Email: %s\n\n", atual->email);
        atual = atual->proximo;
    }
}

void liberarLista(ListaContatos *lista) {
    Contato *atual, *temp;
    atual = lista->inicio;
    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaContatos lista;
    inicializarLista(&lista);
    int opcao;
    char nome[100], telefone[20], email[100];
    do {
        printf("1. Inserir contato\n2. Buscar contato\n3. Remover contato\n4. Atualizar nome\n5. Atualizar telefone\n6. Atualizar email\n7. Mostrar contatos\n8. Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Telefone: ");
                scanf(" %[^\n]", telefone);
                printf("Email: ");
                scanf(" %[^\n]", email);
                inserirContato(&lista, nome, telefone, email);
                break;
            case 2:
                printf("Nome do contato a buscar: ");
                scanf(" %[^\n]", nome);
                Contato *encontrado;
                encontrado = buscarContato(&lista, nome);
                if (encontrado) {
                    printf("Nome: %s\nTelefone: %s\nEmail: %s\n", encontrado->nome, encontrado->telefone, encontrado->email);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 3:
                printf("Nome do contato a remover: ");
                scanf(" %[^\n]", nome);
                removerContato(&lista, nome);
                break;
            case 4:
                printf("Nome do contato a atualizar: ");
                scanf(" %[^\n]", nome);
                encontrado = buscarContato(&lista, nome);
                if (encontrado) {
                    printf("Novo nome: ");
                    scanf(" %[^\n]", nome);
                    atualizarNome(encontrado, nome);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 5:
                printf("Nome do contato a atualizar: ");
                scanf(" %[^\n]", nome);
                encontrado = buscarContato(&lista, nome);
                if (encontrado) {
                    printf("Novo telefone: ");
                    scanf(" %[^\n]", telefone);
                    atualizarTelefone(encontrado, telefone);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 6:
                printf("Nome do contato a atualizar: ");
                scanf(" %[^\n]", nome);
                encontrado = buscarContato(&lista, nome);
                if (encontrado) {
                    printf("Novo email: ");
                    scanf(" %[^\n]", email);
                    atualizarEmail(encontrado, email);
                } else {
                    printf("Contato nao encontrado\n");
                }
                break;
            case 7:
                imprimirContatos(&lista);
                break;
        }
    } while (opcao != 8);
    liberarLista(&lista);
    return 0;
}
