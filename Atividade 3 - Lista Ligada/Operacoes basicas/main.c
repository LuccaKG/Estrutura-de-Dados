#include "lista_ligada.h"

int main() {
    // Criando uma lista vazia
    p_no lista = criar_lista();

    // Adicionando elementos à lista
    lista = add_elemento(lista, 10);
    lista = add_elemento(lista, 20);
    lista = add_elemento(lista, 30);

    // Imprimindo a lista original
    printf("Lista original:\n");
    imprime_lista(lista);

    // Copiando a lista
    p_no lista_copia = copiar_lista(lista);
    printf("\nLista copiada:\n");
    imprime_lista(lista_copia);

    // Invertendo a lista
    p_no lista_invertida = inverter_lista(lista);
    printf("\nLista invertida:\n");
    imprime_lista(lista_invertida);

    // Criando outra lista para concatenar
    p_no outra_lista = criar_lista();
    outra_lista = add_elemento(outra_lista, 40);
    outra_lista = add_elemento(outra_lista, 50);

    printf("\nOutra lista:\n");
    imprime_lista(outra_lista);

    // Concatenando as listas
    p_no lista_concatenada = concat_lista(lista_invertida, outra_lista);
    printf("\nLista concatenada:\n");
    imprime_lista(lista_concatenada);

    // Liberando memória
    destruir_lista(lista_copia);
    destruir_lista(lista_concatenada);

    return 0;
}
