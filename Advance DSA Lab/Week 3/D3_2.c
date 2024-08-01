/*Write a C program to create a binary search tree using non-recursive function and display that.*/
#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to insert a new node into BST
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    struct Node* current = *root;
    struct Node* parent = NULL;
    while (1) {
        parent = current;
        if (data < current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = newNode;
                return;
            }
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = newNode;
                return;
            }
        }
    }
}
// Function to display BST using inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("Binary Search Tree Creation\n");

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree (Inorder Traversal)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Binary Search Tree (Inorder Traversal): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);
    return 0;
}
