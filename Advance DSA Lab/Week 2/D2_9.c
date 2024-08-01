/*Write a C program to count number of node present in a given binary tree using array.*/
#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to initialize a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count nodes in the binary tree
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        count++;

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    return count;
}

// Driver program to test the countNodes function
int main() {
    // Example binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int nodeCount = countNodes(root);
    printf("Number of nodes in the binary tree: %d\n", nodeCount);

    return 0;
}
