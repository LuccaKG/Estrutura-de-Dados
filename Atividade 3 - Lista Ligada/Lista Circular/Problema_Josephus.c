#include "lista_circular.h"

int main() {
    p_no lista, temp;
    int i, N = 5, M = 2;
    lista = criar_lista();

    // Inserir de 0 a N-1
    for (i = 0; i < N; i++) {
        lista = inserir_circ(lista, i);
    }

    // Enquanto houver mais de um no na lista
    while (lista != lista->prox) {
        // Avanca M-1 posicoes para encontrar a pessoa a ser eliminada
        printf("Contagem para eliminar:\n");
        for (i = 0; i < M; i++) {
            lista = lista->prox;  // Avanca M-1 posicoes
            printf("  Avancando para o no %d: %d\n", i + 1, lista->dado);  // Imprime o no atual
        }

        // O no a ser removido
        temp = lista->prox;
        printf("  Removendo o no com valor %d\n", temp->dado);  // Imprime quem esta sendo removido

        // Atualiza o ponteiro para remover o no
        lista->prox = temp->prox;
        free(temp);  // Libera a memoria do no removido

        // Imprime a lista apos a remocao
        printf("Lista apos remocao: ");
        imprimir_lista_circ(lista);
    }

    // Imprime o ultimo sobrevivente
    printf("Ultimo sobrevivente: %d\n", lista->dado);
    return 0;
}
