 #include "lista_circular.h"

// Criar lista vazia
p_no criar_lista() {
    p_no lista = malloc(sizeof(No));  // Cria o nó cabeça
    lista->prox = lista;  // A cabeça aponta para si mesma
    return lista;
}


/* Insercao esta "estranha", pois:
- a inserçao se da no 2o elemento
- mudamos quem é o primeiro elemento da lista
- nao lida com lista vazia (a remoção tb sofre com isso)

SOLUCAO: USAR LISTA CIRCULAR COM CABECA

p_no inserir_circ(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    if (lista == NULL){
        novo->prox = novo;
    }
    else {
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return novo;
}

p_no remover_circ(p_no lista, p_no no){
    p_no ant;
    if (no->prox == no){
        free(no);
        return NULL;
    }
    for (ant = no->prox; ant->prox != no; ant = ant->prox);
    ant->prox = no->prox;
    if(lista == no){
        lista = lista->prox;
    }
    free(no);
    return lista;
}

*/

/* SOLUCAO PARA O PROBLEMA ACIMA: LISTA CIRCULAR COM CABEÇA

IMPLEMENTACOES ABAIXO: */

p_no inserir_circ(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = lista->prox;
    lista->prox = novo;
    return lista;
}

p_no remover_circ(p_no lista, p_no no){
    p_no ant;
    for(ant = no->prox; ant->prox != no; ant = ant->prox);
    ant->prox = no->prox;
    free(no);
    return lista;
}

void imprimir_lista_circ(p_no lista){
    p_no p;
    p = lista;
    do {
        printf("%d\n", p->dado);
        p = p->prox;
    } while (p != lista);
}
