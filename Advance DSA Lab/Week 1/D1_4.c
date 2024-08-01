/*27,15,39,21,28,70*/
/*Write a C program to implement the concept of Quick sort on the above data set. Print the data set after every iteration.*/
#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
	int j;
    int pivot = arr[high];
    int i = (low - 1);
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
	int i;
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        // Print dataset after every iteration
        printf("Iteration: ");
        for (i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
	int i;
    int arr[] = {27,15,39,21,28,70};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original dataset: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, n - 1);
    printf("Sorted dataset: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
