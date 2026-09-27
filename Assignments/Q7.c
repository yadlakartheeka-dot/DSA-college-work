#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a value into BST
struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder: Left -> Root -> Right
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder: Root -> Left -> Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left -> Right -> Root
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search for a value
int search(struct Node *root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == value) {
        return 1;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

int main() {
    struct Node *root = NULL;
    int n, value, searchValue;
    int i;

    printf("Enter number of values: ");
    scanf("%d", &n);

    printf("Enter %d unique values:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue)) {
        printf("%d exists in the BST.\n", searchValue);
    } else {
        printf("%d does not exist in the BST.\n", searchValue);
    }

    return 0;
}