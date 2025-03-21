#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista duplamente ligada
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Função para criar uma lista duplamente ligada circular com N elementos
Node* createDoublyLinkedList(int N) {
    if (N <= 0) return NULL;

    Node* head = createNode(0);
    Node* temp = head;

    for (int i = 1; i < N; i++) {
        Node* newNode = createNode(i);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    // Tornar a lista circular
    temp->next = head;
    head->prev = temp;

    return head;
}

// Função para reorganizar a lista circular para que C seja a cabeça
Node* rearrangeList(Node* head, int C, int N) {
    Node* temp = head;
    while (temp->data != C) {
        temp = temp->next;
    }
    return temp; // Retorna o novo head
}

// Função para imprimir a lista circular uma única vez
void printList(Node* head, int N) {
    Node* temp = head;
    for (int i = 0; i < N; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função principal
int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    Node* head = createDoublyLinkedList(N);
    head = rearrangeList(head, C, N);

    printList(head, N);

    return 0;
}
