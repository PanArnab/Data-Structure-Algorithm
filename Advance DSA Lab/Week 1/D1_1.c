/*Data Set- : 27,15,39,21,28,70*/
/*Write a C program to implement the concept of Bubble sort on the above data set. Print the data set after every iteration.*/
#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
        printf("After iteration %d: ", i+1);
        printArray(arr, n);
    }
}
int main() {
    int dataSet[] = {27, 15, 39, 21, 28, 70};
    int dataSize = sizeof(dataSet) / sizeof(dataSet[0]);
    printf("Original Data Set: ");
    printArray(dataSet, dataSize);
    bubbleSort(dataSet, dataSize);
    printf("\nSorted Data Set: ");
    printArray(dataSet, dataSize);
	return 0;
}
