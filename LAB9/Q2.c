#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int waiting = 0;

struct waitingqueue {
    char name[50];
    int waitingnum;
    struct waitingqueue *next;
} *front = NULL, *back = NULL;



void addpatient() {
    struct waitingqueue *newpatient = (struct waitingqueue *)malloc(sizeof(struct waitingqueue));
    if (newpatient == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter your name: ");
    fgets(newpatient->name, sizeof(newpatient->name), stdin);
    newpatient->name[strcspn(newpatient->name, "\n")] = '\0'; 

    newpatient->waitingnum = waiting++;
    newpatient->next = NULL;

    if (front == NULL) {
        front = back = newpatient;
    } else {
        back->next = newpatient;
        back = newpatient;
    }
}

struct waitingqueue* waitinglistupdate() {
    if (front == NULL) {
        printf("There is no patient in hospital\n");
        return NULL;
    }

    struct waitingqueue *checkingpatient = front;
    struct waitingqueue *freenode = front;

    if (front == back) {
        front = back = NULL;
    } else {
        front = front->next;

        // Update waiting numbers
        struct waitingqueue *temp = front;
        while (temp != NULL) {
            temp->waitingnum -= 1;
            temp = temp->next;
        }
    }

    waiting--;
    free(freenode);
    return checkingpatient;
}

int getwaitingnumber(char *patientname) {
    if (front == NULL) {
        printf("Currently no patients are in waiting, you can go to check up.\n");
        return 0;
    }

    struct waitingqueue *temp = front;
    while (temp != NULL) {
        if (strcmp(temp->name, patientname) == 0) {
            return temp->waitingnum;
        }
        temp = temp->next;
    }

    printf("You have not added yourself to the waiting list.\nDo you want to add? (1 for yes, 0 for no): ");
    int choice;
    scanf("%d", &choice);
    getchar();
    // clearBuffer();
    if (choice == 1) {
        addpatient();
    }

    return -1;
}

void displaywaitinglist() {
    if (front == NULL) {
        printf("Waiting list is empty!\n");
        return;
    }

    printf("\nNAME\tWAITING NO.\n");
    struct waitingqueue *temp = front;
    while (temp != NULL) {
        printf("%s\t%d\n", temp->name, temp->waitingnum);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- HOSPITAL WAITING LIST ---\n");
        printf("1. Add Patient\n2. Display Waiting List\n3. Remove First Patient (Update Waiting List)\n4. Get Waiting Number\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 1) {
            addpatient();
        } else if (choice == 2) {
            displaywaitinglist();
        } else if (choice == 3) {
            waitinglistupdate();
        } else if (choice == 4) {
            char name[50];
            printf("Enter patient name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            int pos = getwaitingnumber(name);
            if (pos >= 0)
                printf("Waiting number: %d\n", pos);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
