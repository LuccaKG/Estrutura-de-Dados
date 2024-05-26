#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// dados � o vetor ordenado onde ser� feita a busca. L e R sao as posi��es inferior e superior, respectivamente. X � o dado buscado
int busca_binaria(int* dados, int l, int r, int x) {
	int m = (l + r) / 2;

	if (l > r) { // intervalo vazio
		return -1; 
	}

	if (dados[m] == x) {
		return m;
	}

	else if (dados[m] < x) {
		return busca_binaria(dados, m + 1, r, x); // se dados[m] < x, redefine o intervalo para a direita do chute inicial (utilizando recursao)
	}

	else {
		return busca_binaria(dados, l, m - 1, x); // caso dados[m] > x, redefine o intervalo para buscar � esquerda 
	}
}

int busca_linear(int* dados, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (dados[i] == x) {
			return i;
		}
	}
	return -1; // caso nao encontrar
}

int main() {
    int n = 1000000; // Tamanho do vetor
    int* vect = (int*)malloc(n * sizeof(int)); // Aloca mem�ria para o vetor

    if (vect == NULL) { // Verifica se a aloca��o foi bem-sucedida
        fprintf(stderr, "Erro ao alocar mem�ria\n");
        return 1;
    }

    // Preenche o vetor como uma PA de raz�o 2
    for (int i = 0; i < n; i++) {
        vect[i] = i * 2;
    }

    int x = 9998; // Valor a ser buscado

    // Medi��o do tempo de execu��o da busca bin�ria
    LARGE_INTEGER frequency, start_bin, end_bin;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_bin);

    int pos_bin = busca_binaria(vect, 0, n - 1, x);

    QueryPerformanceCounter(&end_bin);

    double time_taken_bin = (double)(end_bin.QuadPart - start_bin.QuadPart) / frequency.QuadPart;

    // Medi��o do tempo de execu��o da busca linear
    LARGE_INTEGER start_lin, end_lin;
    QueryPerformanceCounter(&start_lin);

    int pos_lin = busca_linear(vect, n, x);

    QueryPerformanceCounter(&end_lin);

    double time_taken_lin = (double)(end_lin.QuadPart - start_lin.QuadPart) / frequency.QuadPart;

    printf("Busca binaria:\n");
    printf("A posicao de %d eh: %d\n", x, pos_bin);
    printf("Tempo de execucao: %f segundos\n", time_taken_bin);

    printf("\nBusca linear:\n");
    printf("A posicao de %d eh: %d\n", x, pos_lin);
    printf("Tempo de execucao: %f segundos\n", time_taken_lin);

    free(vect); // Libera a mem�ria alocada

    return 0;
}