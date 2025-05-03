#pragma warning(disable : 4996) // desabilita erros de compilação por uso do scanf 
#include <stdio.h>
#include <stdlib.h>


// define a matriz e sua dimensao
typedef struct {
	int dimensao;
	int** matriz;	
} Matriz;

// define as variaveis que armazenarao os resultados das operações na matriz
typedef struct {
	int somaDiagPrincipal;
	int somaDiagSecundaria;
	int somaImparLinha;
	int somaParColuna;
}OpcsMatriz;

// recebe a struct Matriz e aloca memoria para suas linhas e, para cada linha, aloca espaço para suas colunas
void inicializaMatriz(Matriz *m, int dimensao){
	// passa a dimensao informada no argumento para a struct
	m->dimensao = dimensao;
	// aloca memoria para as linhas
	m->matriz = (int**)malloc(dimensao * sizeof(int));
	// aloca memoria para cada coluna de cada linha
	for (int i = 0; i < dimensao; i++) {
		m->matriz[i] = (int*)malloc(dimensao * sizeof(int));
	}
}

void preencheMatriz(Matriz* m) {
	for (int i = 0; i < m->dimensao; i++) {
		for (int j = 0; j < m->dimensao; j++) {
			scanf("%d", &m->matriz[i][j]);
		}
	}
}

void OperacoesMatriz(Matriz* m1, OpcsMatriz* m2) {
	m2->somaDiagPrincipal = 0;
	m2->somaDiagSecundaria = 0;
	m2->somaImparLinha = 0;
	m2->somaParColuna = 0;
	int somaLinha = 0;
	int somaColuna = 0;

	for (int i = 0; i < m1->dimensao; i++) {
		for (int j = 0; j < m1->dimensao; j++) {
			if (i == j) {
				m2->somaDiagPrincipal += m1->matriz[i][j];
			}
			if (i + j + 2 == m1->dimensao + 1) { // soma 2 para corrigir o fato de que começamos a contagem pelo index 0 
				m2->somaDiagSecundaria += m1->matriz[i][j];
			}
			somaLinha += m1->matriz[i][j]; // linha fixa e variando seus itens na soma
			somaColuna += m1->matriz[j][i]; // inverte os indexes para fixar a coluna e varias seus itens na soma
		}
		if (somaLinha % 2 != 0) {
			m2->somaImparLinha += 1; // se a soma dos elementos da linha é impar, conta 1
		}
		if (somaColuna % 2 == 0) {
			m2->somaParColuna += 1; // se a soma dos elementos da coluna é par, conta 1
		}
		somaLinha = 0;
		somaColuna = 0;
	}
}


int main() {
	int dimensao;
	printf("Digite a dimensao da matriz: ");
	scanf("%d", &dimensao);

	Matriz matriz; // define uma matriz
	inicializaMatriz(&matriz, dimensao);

	printf("Digite agora as linhas da matriz com elementos separados por espaco:\n");
	preencheMatriz(&matriz);

	OpcsMatriz ops; // inicializa a struct das variaveis de operações da matriz
	OperacoesMatriz(&matriz, &ops);

	printf("A soma da diagonal principal eh: %d\n", ops.somaDiagPrincipal);
	printf("A soma da diagonal secundaria eh: %d\n", ops.somaDiagSecundaria);
	printf("O num. de colunas com soma par eh: %d\n", ops.somaParColuna);
	printf("O num. de linhas com soma impar eh: %d\n", ops.somaImparLinha);

	return 0;

}


