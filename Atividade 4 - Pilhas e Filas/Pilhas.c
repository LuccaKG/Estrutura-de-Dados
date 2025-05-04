#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 24  // 22 d�gitos + '\0' + margem

int main() {
    char N[MAX_DIGITS];
    int k;

    // Leitura da entrada: n�mero como string e quantidade de d�gitos a remover
    scanf("%s %d", N, &k);
    int len = strlen(N);

    char stack[MAX_DIGITS];
    int top = -1;

    for (int i = 0; i < len; i++) {
        // Remove do topo da pilha enquanto for maior que o atual e ainda puder remover
        while (top >= 0 && stack[top] > N[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = N[i];
    }

    // Caso ainda falte remover d�gitos, remove do final
    top -= k;

    // Remove zeros � esquerda
    int start = 0;
    while (start <= top && stack[start] == '0') {
        start++;
    }

    // Imprime o resultado
    if (start > top) {
        printf("0");
    } else {
        for (int i = start; i <= top; i++) {
            putchar(stack[i]);
        }
    }

    return 0;
}
