#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

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

    temp->next = head;
    head->prev = temp;

    return head;
}

Node* rearrangeList(Node* head, int C) {
    Node* temp = head;
    while (temp->data != C) {
        temp = temp->next;
    }
    return temp;
}

void printList(Node* head, int N) {
    Node* temp = head;
    for (int i = 0; i < N; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* moveClockwise(Node* start, int steps) {
    Node* temp = start;
    for (int i = 0; i < steps; i++) {
        temp = temp->next;
    }
    return temp;
}

Node* moveCounterClockwise(Node* start, int steps) {
    Node* temp = start;
    for (int i = 0; i < steps; i++) {
        temp = temp->prev;
    }
    return temp;
}

// Remove um nó da lista e retorna a nova cabeça (se o nó removido for a cabeça)
Node* removeNode(Node* head, Node* target, int* N) {
    if (*N == 1) {
        free(target);
        *N = 0;
        return NULL;
    }

    target->prev->next = target->next;
    target->next->prev = target->prev;

    Node* newHead = (head == target) ? target->next : head;

    free(target);
    (*N)--;

    return newHead;
}

int main() {
    int N, C, K, L;
    scanf("%d %d %d %d", &N, &C, &K, &L);

    Node* head = createDoublyLinkedList(N);
    head = rearrangeList(head, C);

    Node* kNode = moveClockwise(head, K);
    Node* lNode = moveCounterClockwise(head, L);

    printf("%d %d\n", kNode->data, lNode->data);

    if (kNode == lNode) {
        head = removeNode(head, kNode, &N);
    } else {
        head = removeNode(head, kNode, &N);
        head = removeNode(head, lNode, &N);
    }

    if (N > 0) {
        printList(head, N);
    } else {
        printf("Lista vazia.\n");
    }

    return 0;
}
