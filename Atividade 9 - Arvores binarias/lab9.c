#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária de busca
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Função para inserir um valor na BST
Node* insert(Node* root, int value) {
    if (root == NULL) return create_node(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Função para calcular a altura da árvore
int tree_height(Node* root) {
    if (root == NULL) return 0;
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

// Função para liberar a memória da árvore
void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int N;
    scanf("%d", &N);

    int i, value;

    // Construção da árvore de DN
    Node* dn_tree = NULL;
    for (i = 0; i < N; i++) {
        scanf("%d", &value);
        dn_tree = insert(dn_tree, value);
    }

    // Construção da árvore de Mentirinha
    Node* mentirinha_tree = NULL;
    for (i = 0; i < N; i++) {
        scanf("%d", &value);
        mentirinha_tree = insert(mentirinha_tree, value);
    }

    // Cálculo das alturas
    int height_dn = tree_height(dn_tree);
    int height_mentirinha = tree_height(mentirinha_tree);

    // Saída
    printf("%d %d\n", height_dn, height_mentirinha);

    // Liberação da memória
    free_tree(dn_tree);
    free_tree(mentirinha_tree);

    return 0;
}
