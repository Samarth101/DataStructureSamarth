#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

void createlinklist(struct node **listhead) {
    int nodedata, numofnodes;

    printf("Enter the number of nodes for the list: ");
    scanf("%d", &numofnodes);

    if (numofnodes <= 0) {
        printf("Invalid number of nodes!\n");
        return;
    }

    *listhead = (struct node *)malloc(sizeof(struct node));
    if (*listhead == NULL) {
        printf("Memory allocation failed for head node!\n");
        return;
    }

    printf("Enter value for node 1: ");
    scanf("%d", &nodedata);
    (*listhead)->data = nodedata;
    (*listhead)->next = NULL;

    struct node *currentnode = *listhead;  

    for (int i = 2; i <= numofnodes; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed at node %d!\n", i);
            return;
        }

        printf("Enter value for node %d: ", i);
        scanf("%d", &nodedata);

        newnode->data = nodedata;
        newnode->next = NULL;
        currentnode->next = newnode;
        currentnode = newnode;
    }
}

void displaylinkist(struct node * listhead)
{
    struct node *currentnode;
    int nodeindex = 1;
    if (listhead == NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        currentnode = listhead;
        while (currentnode != NULL)
        {
            printf("Data at node %d = %d\n", nodeindex, currentnode->data);
            currentnode = currentnode->next;
            nodeindex++;
        }
    }
}

int middlenodeofSLL(struct node * listhead)
{
    struct node * slow=listhead;
    struct node * fast=listhead;
    while (fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

int main(int argc, char const *argv[])
{
    struct node * listhead=NULL;
    createlinklist(&listhead);
    displaylinkist(listhead);
    printf("Middle node of link list is : %d\n",middlenodeofSLL(listhead));

    return 0;
}
