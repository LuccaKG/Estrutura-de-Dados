#include "lista_ligada.h"

int main() {
    p_no lista = criar_lista();

    // Adicionando elementos
    lista = add_elemento(lista, 10);
    lista = add_elemento(lista, 20);
    lista = add_elemento(lista, 30);

    // Imprimindo a lista
    printf("Elementos da lista:\n");
    imprime_lista(lista);

    // Liberando memória
    destruir_lista(lista);

    return 0;
}
