#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef No *p_no;

// Funções da lista ligada
p_no criar_lista();
void destruir_lista(p_no lista);
p_no add_elemento(p_no lista, int x);
void imprime_lista(p_no lista);

#endif // LISTA_LIGADA_H
