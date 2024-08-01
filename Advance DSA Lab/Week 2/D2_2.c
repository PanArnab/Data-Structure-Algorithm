/*2.Write a C program to create a binary tree using non-recursive function and display that level wise.*/
#include <stdio.h>
#include <stdlib.h>

// Define structure for binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
void insertNode(struct Node **root, int data) {
    struct Node *newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    struct Node *current = *root;
    struct Node *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Function to display binary tree level-wise
void levelOrderTraversal(struct Node *root) {
    if (root == NULL)
        return;
    
    struct Node *queue[100]; // Assuming maximum 100 nodes
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        struct Node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    struct Node *root = NULL;
    int i,numNodes, data;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    
    printf("Enter the data for each node:\n");
    for (i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        insertNode(&root, data);
    }
    
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    
    return 0;
}

