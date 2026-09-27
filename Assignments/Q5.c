#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;
void display();
// Create a new node
struct Node* createNode(int roll) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(int roll) {
    struct Node *newNode = createNode(roll);

    newNode->next = head;
    head = newNode;

    printf("After inserting %d at beginning: ", roll);
    display();
}

// Insert at end
void insertEnd(int roll) {
    struct Node *newNode = createNode(roll);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("After inserting %d at end: ", roll);
    display();
}

// Search for a roll number
void search(int roll) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d is found.\n", roll);
            return;
        }

        temp = temp->next;
    }

    printf("Roll number %d is not available.\n", roll);
}

// Delete a roll number
void deleteRoll(int roll) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number %d is not available.\n", roll);
        return;
    }

    // If deleting the first node
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);

    printf("After deleting %d: ", roll);
    display();
}

// Display the list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {
    int n, roll, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    printf("\nInitial list: ");
    display();

    printf("\nEnter roll number to insert at beginning: ");
    scanf("%d", &roll);
    insertBeginning(roll);

    printf("\nEnter roll number to insert at end: ");
    scanf("%d", &roll);
    insertEnd(roll);

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);
    search(roll);

    printf("\nEnter roll number to delete: ");
    scanf("%d", &roll);
    deleteRoll(roll);

    printf("\nFinal updated list: ");
    display();

    return 0;
}