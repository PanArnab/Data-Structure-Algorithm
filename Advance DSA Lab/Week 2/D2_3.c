/*Write a C program to create a binary tree using array only and display the tree level wise.*/
#include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree using array representation
void insertNode(struct Node** treeArray, int index, int data, int n) {
    if (index < n) {
        treeArray[index] = createNode(data);
        insertNode(treeArray, 2 * index + 1, data, n); // Insert into left child
        insertNode(treeArray, 2 * index + 2, data, n); // Insert into right child
    }
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node** treeArray, int n) {
	int i;
    for (i = 0; i < n; i++) {
        if (treeArray[i] != NULL)
            printf("%d ", treeArray[i]->data);
    }
}

int main() {
    int i,n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node** treeArray = (struct Node*)malloc(n * sizeof(struct Node));
    for ( i = 0; i < n; i++)
        treeArray[i] = NULL;

    printf("Enter the values of the nodes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(treeArray, i, data, n);
    }

    printf("Level-wise display of the binary tree:\n");
    displayLevelOrder(treeArray, n);

    free(treeArray); // Free allocated memory

    return 0;
}
