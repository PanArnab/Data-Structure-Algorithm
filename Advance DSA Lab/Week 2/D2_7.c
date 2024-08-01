/*Write a C program to count number of internal node present in a binary tree.*/
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

// Function to count the number of internal nodes in a binary tree
int countInternalNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL || root->right != NULL) {
        // If at least one child is present, it's an internal node
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
    // Otherwise, it's a leaf node
    return 0;
}

int main() {
    // Construct a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    // Count the number of internal nodes
    int internalNodes = countInternalNodes(root);
    printf("Number of internal nodes in the binary tree: %d\n", internalNodes);

    // Free memory allocated for the tree nodes
    // Note: In a real application, you may want to implement a function to free the entire tree
    //       by traversing it in postorder traversal and freeing each node.
    return 0;
}

