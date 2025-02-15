#include "lista_ligada.h"

// Criar lista vazia
p_no criar_lista() {
    return NULL;
}

// Destruindo lista com código recursivo
void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

/* A função devolve uma nova lista.
   É a lista antiga com o novo elemento adicionado. */
p_no add_elemento(p_no lista, int x) {
    p_no novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novo->dado = x;
    novo->prox = lista;
    return novo;
}

// Impressão iterativa
void imprime_lista(p_no lista) {
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox) {
        printf("%d\n", atual->dado);
    }
}
