#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *back = NULL;

void enqueue(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = back = newnode;
    }
    else
    {
        back->next = newnode;
        back = newnode;
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("QUeue is empty!!!\n");
        return -1;
    }
    int dequeueddata = front->data;
    struct node *freenode = front;
    if (front == back)
    {
        front = back = NULL;
    }
    front = front->next;
    free(freenode);
    return dequeueddata;
}

void displayqueue()
{
    if (front == NULL)
    {
        printf("queue is empty!!!\n");
        return;
    }
    struct node *temp = front;
    printf("FIFO : \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    int choice, data;
    do
    {
        printf("\n1. Enqueue Data : \n");
        printf("2.Dequeue Data :\n");
        printf("3.Display Queue :\n");
        printf("4.EXit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to be enqueued : ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            printf("dequeued data : %d\n", dequeue());
            break;

        case 3:
            displayqueue();
            break;

        default:
            printf("ENter valid choice !!!!\n");
            break;
        }

    } while (choice != 4);

    return 0;
}
