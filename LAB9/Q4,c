//IMPLEMENT QUEUE USING ARRAY
#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 100
int front = -1, rear = -1;
int queue[QUEUESIZE];

void enqueue(int data, int max_size)
{
    if (rear == max_size - 1)
    {
        printf("Queue is full!!!\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        queue[++rear] = data;
    }
    else
    {
        queue[++rear] = data;
    }
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!!\n");
        return -1;
    }
    int rdata = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return rdata;
}

void displayqueue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!!\n");
        return;
    }
    printf("FIFO: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int n, data;
    printf("Enter the maximum queue size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data value to be enqueued: ");
        scanf("%d", &data);
        enqueue(data, n);
    }
    displayqueue();
    dequeue();
    displayqueue();
    return 0;
}
