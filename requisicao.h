#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct requisicao Requisicao;

Requisicao *cria_requisicao(const char *nome, int inscricao, const char *procedimento);
const char *get_nome(const Requisicao *r);
int get_inscricao(const Requisicao *r);
const char *get_procedimento(const Requisicao *r);
void libera(Requisicao *r);

#endif
