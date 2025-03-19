#include<stdio.h>
#include<stdlib.h>
#define stacksize 100
int stack[stacksize];
int top=-1;
void push(int data)
{
    if (top==stacksize-1)
    {
        printf("Stack overflow!!!\n");
        return;
    }
    stack[++top]=data;
}
int pop()
{
    if (top==-1)
    {
        printf("Stack is empty!!!\n");
        return -1;
    }
    return stack[top--];
}
void printstack()
{
    if (top==-1)
    {
        printf("STack is empty!!!\n");
        return;
    }
    printf("Top to Bottom : ");
    for (int i = top; i >=0; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
    
    
}
int main(int argc, char const *argv[])
{
    int n,data;
    printf("Enter how many numbers you want to push in stack : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data value to be pushed : ");
        scanf("%d",&data);
        push(data);
    }
    printstack();
    printf("Popped data : %d\n",pop());
    printstack();
    return 0;
}
