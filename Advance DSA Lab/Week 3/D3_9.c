/*Write a C program to prove that binary search tree is better than binary tree.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Binary Tree Node Structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Function to create a new Binary Tree Node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to insert a node into Binary Tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
// Function to search a node in Binary Tree
struct TreeNode* searchNode(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    // Traverse left subtree if key is smaller
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    // Traverse right subtree if key is greater
    return searchNode(root->right, key);
}
// Function to create Binary Search Tree from an array
struct TreeNode* createBST(int arr[], int n) {
    struct TreeNode* root = NULL;
    int i;
    for (i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    return root;
}
// Function to calculate time taken for search operation
double searchTime(struct TreeNode* root, int key) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    struct TreeNode* result = searchNode(root, key);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
// Main function
int main() {
    // Creating an array and defining key to search
    int arr[] = { 5, 3, 7, 2, 4, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    // Creating a Binary Tree
    struct TreeNode* btRoot = createBST(arr, n);
    // Creating a Binary Search Tree
    struct TreeNode* bstRoot = createBST(arr, n);
    // Measuring search time for Binary Tree
    double btSearchTime = searchTime(btRoot, key);
    // Measuring search time for Binary Search Tree
    double bstSearchTime = searchTime(bstRoot, key);
    printf("Search time in Binary Tree: %f seconds\n", btSearchTime);
    printf("Search time in Binary Search Tree: %f seconds\n", bstSearchTime);
    // Freeing allocated memory
    // Assuming there are no memory leaks in the searchNode function
    free(btRoot);
    free(bstRoot);
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in a binary tree
struct Node* binaryTreeSearch(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    struct Node* left = binaryTreeSearch(root->left, data);
    struct Node* right = binaryTreeSearch(root->right, data);
    return (left != NULL) ? left : right;
}

// Function to search for a node in a binary search tree
struct Node* binarySearchTreeSearch(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return binarySearchTreeSearch(root->left, data);
    } else {
        return binarySearchTreeSearch(root->right, data);
    }
}

// Function to count the number of function calls
int functionCallCount = 0;
int countFunctionCalls(struct Node* root) {
    functionCallCount++;
    return functionCallCount;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    int searchData = 6;

    printf("Binary Tree Search Function Calls: %d\n", countFunctionCalls(binaryTreeSearch(root, searchData)));
    
    functionCallCount = 0; // Reset the function call count
    
    printf("Binary Search Tree Search Function Calls: %d\n", countFunctionCalls(binarySearchTreeSearch(root, searchData)));
    
    return 0;
}*/
