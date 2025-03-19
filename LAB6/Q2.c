#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct Stack
{
    struct node *top;
} *stack;

void createstack()
{
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL)
    {
        printf("Memory allocation failed!!!\n");
        return;
    }
    stack->top = NULL;
}

void pushll(int data)
{
    if (stack == NULL) // check if stack is initialized
    {
        printf("Stack not initialized!\n");
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!!!\n");
        return;
    }

    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
}

int pop()
{
    if (stack == NULL || stack->top == NULL)
    {
        printf("Stack is empty!!!\n");
        return -1;
    }

    struct node *freetop = stack->top;
    int poppeddata = stack->top->data;
    stack->top = stack->top->next;
    free(freetop);
    return poppeddata;
}

void displaystackll()
{
    if (stack == NULL || stack->top == NULL)
    {
        printf("Stack is empty!!!\n");
        return;
    }

    struct node *currentnode = stack->top;
    printf("Top to Bottom: ");
    while (currentnode != NULL)
    {
        printf("%d ", currentnode->data);
        currentnode = currentnode->next;
    }
    printf("\n");
}

int main()
{
    int n, data;
    
    createstack();
    
    printf("Enter how many numbers you want to push in stack: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter data value to be pushed: ");
        scanf("%d", &data);
        pushll(data);
    }

    displaystackll();
    printf("Popped element: %d\n", pop());
    displaystackll();

    return 0;
}
