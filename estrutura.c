#include "estrutura.h"
#include <stdlib.h>

/* Nó interno da fila encadeada - ocultado do usuário */
typedef struct no {
    Requisicao *requisicao;
    struct no *proximo;
} No;

/* Estrutura interna ocultada: fila com ponteiros para início e fim */
struct estrutura {
    No *inicio;
    No *fim;
    int tamanho;
};

Estrutura *create(void) {
    Estrutura *e = (Estrutura *)malloc(sizeof(Estrutura));
    if (!e) return NULL;
    e->inicio = NULL;
    e->fim = NULL;
    e->tamanho = 0;
    return e;
}

/* Inserção no fim: O(1) */
void inserir(Estrutura *e, Requisicao *r) {
    No *no = (No *)malloc(sizeof(No));
    if (!no) return;
    no->requisicao = r;
    no->proximo = NULL;
    if (e->fim)
        e->fim->proximo = no;
    else
        e->inicio = no;
    e->fim = no;
    e->tamanho++;
}

/* Remoção do início: O(1) */
Requisicao *remover(Estrutura *e) {
    if (!e->inicio) return NULL;
    No *no = e->inicio;
    Requisicao *r = no->requisicao;
    e->inicio = no->proximo;
    if (!e->inicio)
        e->fim = NULL;
    free(no);
    e->tamanho--;
    return r;
}

int get_size(const Estrutura *e) {
    return e->tamanho;
}

void libera_estrutura(Estrutura *e) {
    No *atual = e->inicio;
    while (atual) {
        No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(e);
}
