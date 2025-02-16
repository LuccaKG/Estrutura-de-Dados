#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef No *p_no;

// Funções da lista circular com cabeça
p_no criar_lista();
p_no inserir_circ(p_no lista, int x);
p_no remover_circ(p_no lista, p_no no);
void imprimir_lista_circ(p_no lista);

#endif // LISTA_CIRCULAR_H
