#include <stdio.h>
#include <time.h>

int a[20], n;

// Function to merge two sorted subarrays
void simple_sort(int[], int, int, int);

// Function to perform merge sort
void merge_sort(int[], int, int);

int main() {
    int i;
    clock_t start, end;
    double time_taken;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Measure the time taken for merge sort
    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    // Calculate the time taken for sorting
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Output the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Output the time taken for sorting
    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}

// Merge Sort function
void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively sort the two halves
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);

        // Merge the two sorted halves
        simple_sort(a, low, mid, high);
    }
}

// Simple sort (merge function) to merge two sorted subarrays
void simple_sort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[n];  // Temporary array to store merged result

    // Merge the two subarrays into the temporary array
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    // If there are remaining elements in the left subarray
    while (i <= mid) {
        c[k++] = a[i++];
    }

    // If there are remaining elements in the right subarray
    while (j <= high) {
        c[k++] = a[j++];
    }

    // Copy the sorted elements from temporary array back to the original array
    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}


####OUTPUT####
enter the number of elements:8
enter the array elements 9 8 3 1 5 6 7 4
sorted array:13456789
time taken to sort:0.000000 seconds

