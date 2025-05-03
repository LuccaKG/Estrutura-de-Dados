#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacidade = 5;
    int *casos = (int *)calloc(capacidade, sizeof(int));
    if (casos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    int P;
    printf("Digite o numero de operacoes: ");
    scanf("%d", &P);

    for (int i = 0; i < P; i++) {
        int operacao, X, Y;
        scanf("%d %d %d", &operacao, &X, &Y);

        if (operacao == 0) {  // Adicionar
            // Se a idade Y for maior ou igual à capacidade, dobrar a capacidade do vetor
            while (Y >= capacidade) {
                capacidade *= 2;
                casos = realloc(casos, capacidade * sizeof(int));
                if (casos == NULL) {
                    printf("Erro ao alocar memoria.\n");
                    return 1;
                }
                // Inicializa a nova parte do vetor com zeros
                for (int j = capacidade / 2; j < capacidade; j++) {
                    casos[j] = 0;
                }
            }
            casos[Y] += X;
        } else if (operacao == 1) {  // Consultar
            int total = 0;
            for (int idade = X; idade <= Y; idade++) {
                if (idade < capacidade) {
                    total += casos[idade];
                }
            }
            printf("Total de casos entre %d e %d: %d\n", X, Y, total);
        } else {
            printf("Operacao invalida.\n");
        }
    }

    // Libera a memoria alocada
    free(casos);

    /* Note que cada posição do vetor corresponde a uma idade; por exemplo: casos[3] corresponde aos casos de covid para idade
    de 3 anos.*/

    return 0;
}
