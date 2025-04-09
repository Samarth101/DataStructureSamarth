#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* top = NULL;

void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    newNode->prev = NULL;
    if (top != NULL) {
        top->prev = newNode;
    }
    top = newNode;
}

int pop() {
    if (top == NULL) {
        return -1;
    }
    Node* temp = top;
    int data = temp->data;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    free(temp);
    return data;
}

void printStack() {
    Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    printStack();
    printf("Popped: %d\n", pop());
    printStack();
    return 0;
}
