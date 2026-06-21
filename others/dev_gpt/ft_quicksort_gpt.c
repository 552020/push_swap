// QuickSort created by ChatGPT
// The program generates an array of 500 numbers and extract the 50 smallest thank to a QuickSort algorithm from that array.  

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // size of the input array
#define NUM_SMALLEST 50 // number of smallest elements to extract

// swap two elements in an array
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partition the array for quicksort
int partition(int *arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i+1;
}

// sort the array in ascending order using quicksort
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main() {
    int arr[SIZE];
    // fill the array with random numbers between 1 and 1000
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000 + 1;
    }
		// print the whole array
    printf("The array is of size %d. The elements are are:\n", SIZE);
		for (int i = 0; i<SIZE; i++)
			printf("%d ", arr[i]);
    // sort the array in ascending order using quicksort
    quicksort(arr, 0, SIZE-1);
    // create a new array to hold the 50 smallest elements
    int smallest[NUM_SMALLEST];
    // copy the first 50 elements to the new array
    for (int i = 0; i < NUM_SMALLEST; i++) {
        smallest[i] = arr[i];
    }
    // print the 50 smallest elements
    printf("The %d smallest numbers are:\n", NUM_SMALLEST);
    for (int i = 0; i < NUM_SMALLEST; i++) {
        printf("%d ", smallest[i]);
    }
    printf("\n");
    return 0;
}

