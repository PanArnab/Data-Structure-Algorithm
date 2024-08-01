/*Write a C program to show that Quick sort is better than Bubble sort.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function declarations
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
int main() {
	int i;
    // Seed for random number generation
    srand(time(NULL));
    // Size of the array
    int n = 10000;  // You can adjust the size of the array
    // Generate a random array
    int arr1[n], arr2[n];
    for (i = 0; i < n; i++) {
        arr1[i] = arr2[i] = rand() % 1000;  // You can adjust the range of random numbers
    }
    // Measure time taken by Quick Sort
    clock_t start_quick = clock();
    quickSort(arr1, 0, n - 1);
    clock_t end_quick = clock();
    double time_quick = ((double) (end_quick - start_quick)) / CLOCKS_PER_SEC;
    // Measure time taken by Bubble Sort
    clock_t start_bubble = clock();
    bubbleSort(arr2, n);
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    // Output the results
    printf("Quick Sort took %f seconds\n", time_quick);
    printf("Bubble Sort took %f seconds\n", time_bubble);
    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
	int j;
    int pivot = arr[high];
    int i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void bubbleSort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
