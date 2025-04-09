// stack using LL(singly)
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *top = NULL;
void push(int data)
{
    stack *nnode = malloc(sizeof(stack));
    nnode->data = data;
    nnode->next = top;
    top = nnode;
}

void pop()
{
    if(top == NULL){
        printf("Underflow\n");
    }else{
        stack *temp = top;
        printf("\n");
        printf("popped element:\n");
        printf("%d",temp->data);
        printf("\n");
        top = temp->next;
        free(temp);
    }
}
void printstack(){
    if(top == NULL){
        printf("UNderflow - Stack is empty\n");
    }else{
        stack *temp = top;
        printf("stack:\n");
        while(temp != NULL){
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    printstack();
    pop();
    printstack();
    return 0;
}
