#include "include/quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// usage example
int main()
{
    int n = 100;
    int arr[n];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("\nunsorted array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort_int(arr, n);

    printf("sorted array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
