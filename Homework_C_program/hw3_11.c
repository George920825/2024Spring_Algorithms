#include <stdio.h>

void findMinAndMax(const int* arr, int k, int* max, int* min) {
    int i;

    // Initialize min and max variables
    if (k % 2 == 0) {
        if (arr[0] < arr[1]) {
            *min = arr[0];
            *max = arr[1];
        } else {
            *min = arr[1];
            *max = arr[0];
        }
        i = 2; // Start comparison from 3rd element
    } else {
        *min = arr[0];
        *max = arr[0];
        i = 1; // Start comparison from 2nd element
    }

    // Compare elements pairwise
    while (i < k - 1) {
        if (arr[i] < arr[i + 1]) {
            if (arr[i] < *min) {
                *min = arr[i];
            }
            if (arr[i + 1] > *max) {
                *max = arr[i + 1];
            }
        } else {
            if (arr[i + 1] < *min) {
                *min = arr[i + 1];
            }
            if (arr[i] > *max) {
                *max = arr[i];
            }
        } i += 2;
    }
}

int main() {
    int a[] = {3, 6, 1, 8, 4, 10, 5, 2};
    int max, min;
    findMinAndMax(a, sizeof(a)/sizeof(a[0]), &max, &min);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
