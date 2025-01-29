#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createlinklist(struct node **listhead, int numofnodes) {
    struct node *currentnode, *newnode;
    (*listhead) = (struct node *)malloc(sizeof(struct node));
    if ((*listhead) == NULL) {
        printf("Memory allocation failed!!!\n");
        return;
    }
    int nodedata;
    printf("Enter data value for node 1: ");
    scanf("%d", &nodedata);
    (*listhead)->data = nodedata;
    (*listhead)->next = NULL;
    currentnode = (*listhead);
    
    for (int i = 2; i <= numofnodes; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!!!\n");
            return;
        }
        printf("Enter data value for node %d: ", i);
        scanf("%d", &nodedata);
        newnode->data = nodedata;
        newnode->next = NULL;
        currentnode->next = newnode;
        currentnode = newnode;
    }
}

void displaylist(struct node *listhead) {
    int i = 1;
    while (listhead != NULL) {
        printf("Data at node %d: %d\n", i, listhead->data);
        listhead = listhead->next;
        i++;
    }
}

struct node *listconcatenation(struct node *listhead1, struct node *listhead2) {
    if (listhead1 == NULL) return listhead2;
    if (listhead2 == NULL) return listhead1;
    
    struct node *currentnode = listhead1;
    while (currentnode->next != NULL) {
        currentnode = currentnode->next;
    }
    currentnode->next = listhead2;
    return listhead1;
}

void insertatbegin(struct node **listhead) {
    int nodedata;
    struct node *insertingnode = (struct node *)malloc(sizeof(struct node));
    if (insertingnode == NULL) {
        printf("Memory allocation failed!!!\n");
        return;
    }
    printf("Enter data value to be inserted: ");
    scanf("%d", &nodedata);
    insertingnode->data = nodedata;
    insertingnode->next = (*listhead);
    (*listhead) = insertingnode;
}

void insertatend(struct node *listhead) {
    if (listhead == NULL) return;
    
    int nodedata;
    struct node *currentnode = listhead;
    struct node *insertingnode = (struct node *)malloc(sizeof(struct node));
    if (insertingnode == NULL) {
        printf("Memory allocation failed!!!\n");
        return;
    }
    printf("Enter data value to be inserted: ");
    scanf("%d", &nodedata);
    insertingnode->data = nodedata;
    insertingnode->next = NULL;
    
    while (currentnode->next != NULL) {
        currentnode = currentnode->next;
    }
    currentnode->next = insertingnode;
}

void insertnode(struct node **listhead, int index, int nodedata) {
    struct node *currentnode = (*listhead), *insertingnode;
    insertingnode = (struct node *)malloc(sizeof(struct node));
    if (insertingnode == NULL) {
        printf("Memory allocation failed!!!\n");
        return;
    }
    insertingnode->data = nodedata;
    
    if (index == 1) {
        insertingnode->next = (*listhead);
        (*listhead) = insertingnode;
        return;
    }
    
    struct node *prevnode = NULL;
    int i = 1;
    while (i < index && currentnode != NULL) {
        prevnode = currentnode;
        currentnode = currentnode->next;
        i++;
    }
    if (prevnode != NULL) {
        prevnode->next = insertingnode;
        insertingnode->next = currentnode;
    } else {
        free(insertingnode);
        printf("Invalid index\n");
    }
}

int main() {
    struct node *listhead1 = NULL;
    int numofnodes;
    printf("Enter number of nodes for list 1: ");
    scanf("%d", &numofnodes);
    createlinklist(&listhead1, numofnodes);
    displaylist(listhead1);

    struct node *listhead2 = NULL;
    int nnodes;
    printf("Enter number of nodes for list 2: ");
    scanf("%d", &nnodes);
    createlinklist(&listhead2, nnodes);
    displaylist(listhead2);
    
    struct node *listhead3 = listconcatenation(listhead1, listhead2);
    printf("List after concatenation of List 1 and List 2:\n");
    displaylist(listhead3);
    
    insertatbegin(&listhead1);
    displaylist(listhead1);
    
    insertatend(listhead1);
    displaylist(listhead1);
    
    int insertdata, insertindex;
    printf("Enter data value to be inserted: ");
    scanf("%d", &insertdata);
    printf("Enter index at which the node to be inserted: ");
    scanf("%d", &insertindex);
    insertnode(&listhead1, insertindex, insertdata);
    displaylist(listhead1);
    
    return 0;
}
