#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

// Create a new node
struct Node* createNode(char page[]) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert a new page at the end
void insertPage(char page[]) {
    struct Node *newNode = createNode(page);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        current = head;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted: %s\n", page);
}

// Move forward
void moveForward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->next == NULL) {
        printf("Already at the last page: %s\n", current->page);
    }
    else {
        current = current->next;
        printf("Moved forward to: %s\n", current->page);
    }
}

// Move backward
void moveBackward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->prev == NULL) {
        printf("Already at the first page: %s\n", current->page);
    }
    else {
        current = current->prev;
        printf("Moved backward to: %s\n", current->page);
    }
}

// Delete a specified page
void deletePage(char page[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Page not found: %s\n", page);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If the deleted page is the current page
    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted: %s\n", page);
}

// Display first to last
void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    printf("First to Last:\n");

    while (temp != NULL) {
        printf("%s", temp->page);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

// Display last to first
void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Last to First:\n");

    while (temp != NULL) {
        printf("%s", temp->page);

        if (temp->prev != NULL)
            printf(" -> ");

        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    int choice;
    char page[100];

    while (1) {
        printf("\n--- Web Page History ---\n");
        printf("1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter page name: ");
                scanf("%s", page);
                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}