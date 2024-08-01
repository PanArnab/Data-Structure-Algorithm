/*5. Write a C program to identify degree of a given node.*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the degree of a given node in a binary tree
int findNodeDegree(struct Node* root, int target) {
    if (root == NULL) {
        return -1; // Node not found
    }

    if (root->data == target) {
        int degree = 0;
        if (root->left != NULL) degree++;
        if (root->right != NULL) degree++;
        return degree;
    }

    int leftDegree = findNodeDegree(root->left, target);
    if (leftDegree != -1) {
        return leftDegree;
    }

    int rightDegree = findNodeDegree(root->right, target);
    return rightDegree;
}

// Driver program to test the function
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int targetNode = 2;
    int degree = findNodeDegree(root, targetNode);

    if (degree != -1) {
        printf("The degree of node %d is: %d\n", targetNode, degree);
    } else {
        printf("Node not found in the binary tree.\n");
    }

    return 0;
}
