#include<stdio.h>
#include<stdlib.h>
#define queuesize 5
int queue[queuesize];
int front=-1;
int back=-1;


void enqueue(int data)
{
    if (front==(back+1)%queuesize)
    {
        printf("Queue is full!!!\n");
        return;
    }
    if (front==-1)
    {
        front=0;
        queue[back]=data;
    }
    back=(back+1)%queuesize;
    queue[back]=data;
}

int dequeue()
{
    if (front==-1)
    {
        printf("Queue is empty!!!\n");
        return -1;
    }
    int dequeueddata=queue[front];
    if (front==back)
    {
        front=back=-1;
    }
    else
    {
        front=(front+1)%queuesize;
    }
    
}

void displayCqueue()
{
    printf("Queue(FIFO):\n");
    for (int i = front ; i <=back; i++)
    {
        printf("%d ",queue[i]);
    }
}
int main(int argc, char const *argv[])
{
    int data;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter data value to be enqueued:");
        scanf("%d",&data);
        enqueue(data);
    }
    displayCqueue();
    printf("\nDequeued data : %d\n",dequeue());
    displayCqueue();
    return 0;
}
