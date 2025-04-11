#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó da lista duplamente ligada circular
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Criação de novo nó com valor 'data'
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

// Cria uma lista duplamente ligada circular com N elementos (0 a N-1)
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

// Move o ponteiro para que a cabeça da lista aponte para o cliente C
Node* rearrangeList(Node* head, int C) {
    Node* temp = head;
    while (temp->data != C) {
        temp = temp->next;
    }
    return temp;
}

// Imprime os N elementos a partir do head atual
void printList(Node* head, int N) {
    Node* temp = head;
    for (int i = 0; i < N; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Anda 'steps' passos no sentido horário a partir de 'start'
Node* moveClockwise(Node* start, int steps) {
    Node* temp = start;
    for (int i = 0; i < steps; i++) {
        temp = temp->next;
    }
    return temp;
}

// Anda 'steps' passos no sentido anti-horário a partir de 'start'
Node* moveCounterClockwise(Node* start, int steps) {
    Node* temp = start;
    for (int i = 0; i < steps; i++) {
        temp = temp->prev;
    }
    return temp;
}

// Remove um nó da lista e atualiza a cabeça, se necessário
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

    // Inicializa as posições de partida dos atendentes
    Node* current1 = head;
    Node* current2 = head;

    // --------- Primeira iteração ---------
    Node* kNode = moveClockwise(current1, K);
    Node* lNode = moveCounterClockwise(current2, L);

    printf("Removidos: %d %d\n", kNode->data, lNode->data);

    if (kNode == lNode) {
        head = removeNode(head, kNode, &N);
        current1 = current2 = kNode->next;
    } else {
        Node* next1 = kNode->next;
        Node* next2 = lNode->next;
        head = removeNode(head, kNode, &N);
        head = removeNode(head, lNode, &N);
        current1 = next1;
        current2 = next2;
    }

    if (N > 0)
        printList(head, N);
    else
        printf("Lista vazia.\n");


    // --------- Segunda iteração ---------
    if (N > 0) {
        kNode = moveClockwise(current1, K-1);
        lNode = moveCounterClockwise(current2, L);

        printf("Removidos: %d %d\n", kNode->data, lNode->data);

        if (kNode == lNode) {
            head = removeNode(head, kNode, &N);
        } else {
            head = removeNode(head, kNode, &N);
            head = removeNode(head, lNode, &N);
        }

        if (N > 0)
            printList(head, N);
        else
            printf("Lista vazia.\n");
    }

    return 0;
}
