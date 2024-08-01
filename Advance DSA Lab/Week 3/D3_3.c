/*Write a C program to insert (by using a function) a specific element into an existing binary search tree and then display that.*/
#include <stdio.h>
#include <stdlib.h>
// Structure of a node in BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};
// Function to create a new node
struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a new node into BST
struct node *insert(struct node *root, int value) {
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
// Function to display BST in inorder traversal
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main() {
    struct node *root = NULL; // Initializing an empty tree
    // Inserting some elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // Displaying the BST before insertion
    printf("Binary Search Tree before insertion: ");
    inorderTraversal(root);
    printf("\n");
    int elementToInsert;
    printf("Enter the element you want to insert: ");
    scanf("%d", &elementToInsert);
    // Inserting the specific element
    root = insert(root, elementToInsert);
    // Displaying the BST after insertion
    printf("Binary Search Tree after insertion: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
