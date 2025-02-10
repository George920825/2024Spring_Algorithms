#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* arr, int i, int j){
    if (i != j){
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
}

// void swap(int* arr, int i, int j){
//     if (i != j){
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
// }

void printArray(int arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int randomizePartition(int* arr, int len){
    int index = rand() % len;
    swap(arr, index, len-1);
    // here to finish
    int pivot = arr[len-1];
    int i = -1; // Index of the smaller element
    for (int j = 0; j < len - 1; j++) {
        if (arr[j] <= pivot) {
            i=i+1;
            // Swap arr[i] and arr[j]
            swap(arr, i, j);
        }
    }
    // Swap arr[i+1] and arr[len-1] (putting the pivot in its correct place)
    swap(arr, i+1, len-1);
    // Return the index of the pivot element after partitioning
    return i+1;
}

void copyArray(int source[], int start, int finish, int destination[]){
    for (int i = start; i < finish; i++) {
        destination[i - start] = source[i];
    }
}

int randomizeSelection(int* arr, int len, int i){
    int p = randomizePartition(arr, len);
    // printf("%d ", p);
    // printf("after partition: ");
    // printArray(arr, len);
    if(p == i){
        return arr[p];
    }else if(p < i){
        int start = p+1;   // Start index of the slice
        int finish = len;  // Finish index of the slice
        int destination[finish - start]; // Destination array size
        copyArray(arr, start, finish, destination);
        // printf("after copy: ");
        // printArray(destination, len-(p+1));
        return randomizeSelection(destination, len-(p+1), i-(p+1));
    }
    int start = 0;   // Start index of the slice
    int finish = p;  // Finish index of the slice
    int destination[finish - start]; // Destination array size
    copyArray(arr, start, finish, destination);
    // printf("after copy: ");
    // printArray(destination, p);
    return randomizeSelection(destination, p, i);
}

int main(){
    srand(time(NULL));
    int a[] = {7,1,2,5,3,6,8,10};
    int len = sizeof(a)/sizeof(a[0]);
    printf("the smallest in a is: %d\n", randomizeSelection(a, len, 0));
    printf("the 1st smallest in a is: %d\n", randomizeSelection(a, len, 1));
    printf("the 2nd smallest in a is: %d\n", randomizeSelection(a, len, 2));
}