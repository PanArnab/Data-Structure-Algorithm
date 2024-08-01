/*5. Write a C program to take user name as input and display the sorted sequence of characters using BST.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Define a structure for tree nodes
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Function to create a new node
struct TreeNode* createNode(char value) {
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
// Function to insert a character into the BST
struct TreeNode* insert(struct TreeNode* root, char value) {
    // Base case: if the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(value);
    }
    // Convert the character to lowercase for case-insensitive comparison
    char lowerValue = tolower(value);
    // Recursive case: insert into the left subtree if the value is less than the current node
    if (lowerValue < tolower(root->data)) {
        root->left = insert(root->left, value);
    }
    // Insert into the right subtree otherwise
    else if (lowerValue > tolower(root->data)) {
        root->right = insert(root->right, value);
    }
    // Ignore duplicate values
    return root;
}
// Function to display the BST in inorder traversal
void displayInOrder(struct TreeNode* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%c ", root->data);
        displayInOrder(root->right);
    }
}
int main() {
    struct TreeNode* root = NULL;
    char name[100];
    int i;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    // Insert each character of the name into the BST
    for (i = 0; i < strlen(name); i++) {
        if (isalpha(name[i])) {  // Only insert alphabetic characters
            root = insert(root, name[i]);
        }
    }
    printf("Sorted sequence of characters in your name: ");
    displayInOrder(root);
    printf("\n");
    // Free memory allocated for the BST nodes
    // Note: In a real application, you may want to implement a function to free the entire tree
    //       by traversing it in postorder traversal and freeing each node.
    return 0;
}
