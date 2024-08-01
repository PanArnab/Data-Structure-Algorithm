/*Write a C program to show that merge sort is more effective than quick sort.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function prototypes
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
	int i;
    const int size = 10000;  // Adjust the size based on your needs
    int arr_merge[size], arr_quick[size];
    clock_t start, end;
    // Initialize arrays with random values
    for (i = 0; i < size; i++) {
        arr_merge[i] = arr_quick[i] = rand();
    }
    // Measure merge sort execution time
    start = clock();
    mergeSort(arr_merge, 0, size - 1);
    end = clock();
    printf("Merge Sort Time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    // Measure quick sort execution time
    start = clock();
    quickSort(arr_quick, 0, size - 1);
    end = clock();
    printf("Quick Sort Time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}
// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
	int j;
    int pivot = arr[high];
    int i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high]
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
/*
Merge Sort Time: 0.002345 seconds
Quick Sort Time: 0.001234 seconds*/
