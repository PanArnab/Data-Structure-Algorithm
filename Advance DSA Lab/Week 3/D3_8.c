/*8. Write a C program to Count the number of nodes present in an existing BST and display the highest element present in the BST.*/
#include <stdio.h>
#include <stdlib.h>
// Define a structure for BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to count the number of nodes in BST
int countNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the maximum element in BST
int findMax(struct node* root) {
    if (root == NULL) {
        printf("BST is empty\n");
        return -1; // Assuming -1 represents an empty tree
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    struct node* root = NULL;
    int i,n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of nodes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Number of nodes in BST: %d\n", countNodes(root));

    int max = findMax(root);
    if (max != -1) {
        printf("Highest element in BST: %d\n", max);
    }

    return 0;
}
