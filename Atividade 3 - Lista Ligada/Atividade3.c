#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da lista duplamente ligada
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para criar uma lista duplamente ligada circular com N elementos
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

// Fun��o para reorganizar a lista circular para que C seja a cabe�a
Node* rearrangeList(Node* head, int C, int N) {
    Node* temp = head;
    while (temp->data != C) {
        temp = temp->next;
    }
    return temp; // Retorna o novo head
}

// Fun��o para imprimir a lista circular uma �nica vez
void printList(Node* head, int N) {
    Node* temp = head;
    for (int i = 0; i < N; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Fun��o para encontrar o elemento ap�s K deslocamentos no sentido hor�rio
int findElementAfterK(Node* head, int K) {
    Node* temp = head;
    for (int i = 0; i < K; i++) {
        temp = temp->next;
    }
    return temp->data;
}

// Fun��o para encontrar o elemento ap�s L deslocamentos no sentido anti-hor�rio
int findElementAfterL(Node* head, int L) {
    Node* temp = head;
    for (int i = 0; i < L; i++) {
        temp = temp->prev;
    }
    return temp->data;
}

// Fun��o principal
int main() {
    int N, C, K, L;
    scanf("%d %d %d %d", &N, &C, &K, &L);

    Node* head = createDoublyLinkedList(N);
    head = rearrangeList(head, C, N);

    printList(head, N);
    printf("%d\n", findElementAfterK(head, K));
    printf("%d\n", findElementAfterL(head, L));

    return 0;
}
