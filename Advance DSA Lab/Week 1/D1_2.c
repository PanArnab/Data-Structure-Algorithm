/*27,15,39,21,28,70*/
/*Write a C program to implement the concept of Selection sort on the above data set. Print the data set after every iteration.*/
#include <stdio.h>
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n) {
	int i,j,k;
    for (i = 0; i < n-1; i++) {
        int min_index = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_index])
        min_index = j;
        swap(&arr[min_index], &arr[i]);
        printf("Iteration %d: ", i + 1);
        for (k = 0; k < n; k++)
        printf("%d ", arr[k]);
        printf("\n");
    }
}
int main() {
	int i;
    int arr[] = {27, 15, 39, 21, 28, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original dataset: ");
    for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
    selectionSort(arr, n);
    printf("Sorted dataset: ");
    for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
return 0;
}
