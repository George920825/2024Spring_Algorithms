#include <stdio.h>

void swap(int* arr, int i, int j){
    if (i != j){
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }
}

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

int main(){
    int arr[] = {0,1,2,3};
    printArray(arr, 4);
    swap(arr, 1, 3);
    printArray(arr, 4);
}