#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};
struct Stack
{
    struct node * top;
}*stack;

void createstack()
{
    stack=(struct Stack *)malloc(sizeof(struct Stack));
    if (stack==NULL)
    {
        printf("Memory allocation failed!!!\n");
        return;
    }
    stack->top=NULL;
}

void pushdll(int data)
{
    if (stack==NULL)
    {
        printf("Stack is not initialized!!!\n");
        return;
    }

    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed!!!\n");
        return;
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=stack->top;

    if (stack->top!=NULL)
    {
        stack->top->prev=newnode;
    }
    stack->top=newnode;
}
int popdll()
{
    if (stack==NULL || stack->top==NULL)
    {
        printf("Stack is empty!!!\n");
        return -1;
    }

    int poppeddata=stack->top->data;
    struct node * freetop=stack->top;
    stack->top=stack->top->next;
    if (stack->top!=NULL)
    {
        stack->top->prev=NULL;
    }
    free(freetop);
    return poppeddata;
}

void displaystackdll()
{
    if (stack==NULL || stack->top==NULL)
    {
        printf("Stack is empty!!!\n");
        return;
    }
    
    struct node * currentnode=stack->top;
    printf("Top to Bottom : ");
    while (currentnode!=NULL)
    {
        printf("%d ",currentnode->data);
        currentnode=currentnode->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int n,data;
    printf("ENter how many data values you want to push : ");
    scanf("%d",&n);
    createstack();
    for (int i = 0; i < n; i++)
    {
        printf("Enter data value to be pushed : ");
        scanf("%d",&data);
        pushdll(data);
    }
    displaystackdll();
    printf("Popped element : %d\n",popdll());
    displaystackdll();
    return 0;
}
