/*Data Set- : 27,15,39,21,28,70. Write a C program to implement the concept of Insertion sort on the above data set. Print the
data set after every iteration.*/
#include <stdio.h>
void insertionSort(int arr[], int n) {
    int i, key, j,k;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        // Print the array after each iteration
        printf("Iteration %d: ", i);
        for (k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
int main() {
	int i;
    int arr[] = {27,15,39,21,28,70};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
return 0;
}
