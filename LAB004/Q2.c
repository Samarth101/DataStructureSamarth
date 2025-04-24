// Question 2

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
void createlinklist(struct node **listhead) {
    int nodedata, numofnodes;

    printf("Enter the number of nodes for the list: ");
    scanf("%d", &numofnodes);

    if (numofnodes <= 0) {
        printf("Invalid number of nodes!\n");
        return;
    }
    *listhead = NULL;  
    struct node *currentnode = NULL; 

    for (int i = 1; i <= numofnodes; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed at node %d!\n", i);
            return;
        }
        printf("Enter value for node %d: ", i);
        scanf("%d", &nodedata);
        newnode->data = nodedata;
        newnode->next = NULL;
        if (*listhead == NULL) {
            *listhead = newnode; 
        } else {
            currentnode->next = newnode;
        }
        currentnode = newnode;
    }
}
int nodecount(struct node *listhead) {
    int count = 0;
    while (listhead != NULL) {
        count++;
        listhead = listhead->next;
    }
    return count;
}
void oddindexreverse(struct node **listhead) {
    if (*listhead == NULL || (*listhead)->next == NULL) {
        return;
    }
    int totalnodes = nodecount(*listhead), index = 0, count = 0;
    int *a = (int *)malloc((totalnodes / 2 + 1) * sizeof(int)); 
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    struct node *currentnode = *listhead;
    // Store values at odd indices
    while (currentnode != NULL) {
        if (index % 2 == 0) {
            a[count] = currentnode->data;
            count++;
        }
        currentnode = currentnode->next;
        index++;
    }
    // Reverse the stored odd index values into the linked list
    currentnode = *listhead;
    index = 0;
    count--;
    while (currentnode != NULL) {
        if (index % 2 == 0) {
            currentnode->data = a[count];
            count--;
        }
        currentnode = currentnode->next;
        index++;
    }
    free(a); 
}
void displaylist(struct node *listhead) {
    while (listhead != NULL) {
        printf("%d -> ", listhead->data);
        listhead = listhead->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *listhead1 = NULL;

    createlinklist(&listhead1);
    printf("Original List: ");
    displaylist(listhead1);

    oddindexreverse(&listhead1);
    printf("Modified List (Odd indices reversed): ");
    displaylist(listhead1);
    return 0;
}
