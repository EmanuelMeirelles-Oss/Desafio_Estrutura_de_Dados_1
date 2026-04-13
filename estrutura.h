#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct estrutura Estrutura;

Estrutura *create(void);
void inserir(Estrutura *e, Requisicao *r);
Requisicao *remover(Estrutura *e);
int get_size(const Estrutura *e);
void libera_estrutura(Estrutura *e);

#endif
