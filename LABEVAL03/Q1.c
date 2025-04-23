#include<stdio.h>
#include<stdlib.h>
#define queuesize 100
int queue[queuesize];
int front = -1;
int rear = -1;

void getbinary(int n)
{
    if (rear == queuesize - 1)
    {
        printf("Queue is full\n");
        return;
    }
    while (n!=0)
    {
        queue[++rear]=n%2;
        if(front==-1) front++;
        n=n/2;   
    }
    for (int i = rear; i >=front; i--)
    {
        printf("%d",queue[i]);
    }
    front=rear=-1;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number upto which you want to print binary numbers : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Please enter a positive number.\n");
        return 1;
    }
    for (int i = 1; i <=n; i++)
    {
        printf("Binary of %d : ",i);
        getbinary(i);
        printf("\n");
    }
    return 0;
}
