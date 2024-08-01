/*Write a C program to search an element recursively in a binary search tree.*/
#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a new node
struct Node* insert(struct Node* root, int value) {
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
// Function to search for a value recursively
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}
int main() {
	int i;
    struct Node* root = NULL;
    int elements[] = { 5, 3, 7, 1, 4, 6, 8 };
    int n = sizeof(elements) / sizeof(elements[0]);
    // Inserting elements into the tree
    for (i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }
    int searchValue = 6;
    struct Node* result = search(root, searchValue);
    if (result != NULL) {
        printf("%d found in the tree.\n", searchValue);
    } else {
        printf("%d not found in the tree.\n", searchValue);
    }
    // Freeing dynamically allocated memory
    // (not essential in this simple program, but good practice)
    free(root);
    return 0;
}
