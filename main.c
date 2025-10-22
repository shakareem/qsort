#include "include/quicksort.h"
#include <stdio.h>

// usage example
int main()
{
    int arr[] = {9, 4, 6, 2, 7, 1, 3, 8, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nunsorted array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("sorted array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
