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

// Copiar lista -- modo recursivo
p_no copiar_lista(p_no lista){
    p_no novo;
    if (lista == NULL) {
        return NULL;
    }
    novo = malloc(sizeof(No));
    novo->dado = lista->dado;
    novo->prox = copiar_lista(lista->prox);
    return novo;
}

// Inverter lista ligada
p_no inverter_lista(p_no lista) {
    p_no atual = lista, invertida = NULL, prox;

    while (atual != NULL) {
        prox = atual->prox;   // Guarda refer�ncia do pr�ximo n�
        atual->prox = invertida; // Inverte o ponteiro
        invertida = atual;    // Move a cabe�a da lista invertida
        atual = prox;         // Avan�a na lista original
    }

    return invertida;
}

// Concatenar lista
p_no concat_lista(p_no primeira, p_no segunda){
    if (primeira == NULL){
        return segunda;
    }
    primeira->prox = concat_lista(primeira->prox, segunda);
    return primeira;
}

