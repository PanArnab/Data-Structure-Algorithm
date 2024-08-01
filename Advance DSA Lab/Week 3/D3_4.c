/*Write a C program to search an element in a BST and show the result.*/
#include <stdio.h>
#include <stdlib.h>
// Define a structure for tree nodes
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct TreeNode* insert(struct TreeNode* root, int value) {
    // Base case: if the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(value);
    }

    // Recursive case: insert into the left subtree if the value is less than the current node
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Insert into the right subtree otherwise
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Ignore duplicate values
    return root;
}

// Function to search for a value in the BST
struct TreeNode* search(struct TreeNode* root, int value) {
    // Base cases: if the tree is empty or if the value is found
    if (root == NULL || root->data == value) {
        return root;
    }

    // If the value is less than the current node, search in the left subtree
    if (value < root->data) {
        return search(root->left, value);
    }
    // Otherwise, search in the right subtree
    else {
        return search(root->right, value);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int value, searchValue;
    char choice;

    do {
        printf("Enter a value to insert into the BST: ");
        scanf("%d", &value);
        root = insert(root, value);

        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Enter the value to search in the BST: ");
    scanf("%d", &searchValue);

    // Search for the value in the BST
    struct TreeNode* result = search(root, searchValue);

    if (result != NULL) {
        printf("%d is found in the BST.\n", searchValue);
    } else {
        printf("%d is not found in the BST.\n", searchValue);
    }

    // Free memory allocated for the BST nodes
    // Note: In a real application, you may want to implement a function to free the entire tree
    //       by traversing it in postorder traversal and freeing each node.
    return 0;
}

