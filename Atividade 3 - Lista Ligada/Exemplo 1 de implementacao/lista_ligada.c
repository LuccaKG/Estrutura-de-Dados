#include "lista_ligada.h"

// Criar lista vazia
p_no criar_lista() {
    return NULL;
}

// Destruindo lista com c�digo recursivo
void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

/* A fun��o devolve uma nova lista.
   � a lista antiga com o novo elemento adicionado. */
p_no add_elemento(p_no lista, int x) {
    p_no novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de aloca��o de mem�ria!\n");
        exit(1);
    }
    novo->dado = x;
    novo->prox = lista;
    return novo;
}

// Impress�o iterativa
void imprime_lista(p_no lista) {
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox) {
        printf("%d\n", atual->dado);
    }
}
