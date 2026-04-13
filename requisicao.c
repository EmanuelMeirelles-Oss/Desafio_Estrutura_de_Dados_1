#include "requisicao.h"
#include <stdlib.h>
#include <string.h>

struct requisicao {
    char nome[40];
    int inscricao;
    char procedimento[10];
};

Requisicao *cria_requisicao(const char *nome, int inscricao, const char *procedimento) {
    Requisicao *r = (Requisicao *)malloc(sizeof(Requisicao));
    if (!r) return NULL;
    strncpy(r->nome, nome, 39);
    r->nome[39] = '\0';
    r->inscricao = inscricao;
    strncpy(r->procedimento, procedimento, 9);
    r->procedimento[9] = '\0';
    return r;
}

const char *get_nome(const Requisicao *r) {
    return r->nome;
}

int get_inscricao(const Requisicao *r) {
    return r->inscricao;
}

const char *get_procedimento(const Requisicao *r) {
    return r->procedimento;
}

void libera(Requisicao *r) {
    free(r);
}
