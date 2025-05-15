#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

// Function to perform QuickSort
void quicksort(int[], int, int);

// Function to partition the array
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch;
    clock_t start, end;

    while (1) {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        // Generating random numbers between 0 and 199
        for (i = 0; i < n; i++)
            a[i] = rand() % 200;

        // Displaying the randomly generated array
        printf("The random generated array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        // Starting the clock for time measurement
        start = clock();

        // Sorting the array using QuickSort
        quicksort(a, 0, n - 1);

        // Ending the clock after sorting is complete
        end = clock();

        // Displaying the sorted array
        printf("\nThe sorted array is:\n");
        for (i = 0; i < n; i++)
            printf("%d\n", a[i]);

        // Calculating the time taken for sorting
        printf("Time taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Ask the user if they want to continue
        printf("\nDo you wish to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &ch);

        if (ch == 0)
            break;
    }

    return 0;
}

// QuickSort function
void quicksort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = partition(a, low, high);  // Get the pivot index
        quicksort(a, low, mid - 1);     // Recursively sort the left part
        quicksort(a, mid + 1, high);    // Recursively sort the right part
    }
}

// Partition function
int partition(int a[], int low, int high) {
    int key, i, j, temp, k;
    key = a[low];  // Taking the first element as the pivot
    i = low + 1;
    j = high;

    while (i <= j) {
        // Find an element greater than or equal to key
        while (i <= high && a[i] <= key)
            i++;

        // Find an element smaller than key
        while (a[j] > key)
            j--;

        // If i < j, swap elements at i and j
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            // Swap the pivot element with the element at index j
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            break;
        }
    }

    return j;  // Return the pivot index
}


#######OUTPUT########

Enter the number of elements: 4
The random generated array:
41
67
134
100

The sorted array elements are:
41
67
100
134
Time taken = 0.000000 seconds

Do you wish to continue (0/1)? 0

Process returned 0 (0x0)   execution time : 13.225 s
Press any key to continue.
