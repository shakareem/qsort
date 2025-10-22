#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

#define THRESHOLD 10

static void insertion_sort(void *arr, size_t n, size_t size,
                           bool (*less)(const void *, const void *))
{
    char *a = arr;
    char *tmp = malloc(size);

    for (size_t i = 1; i < n; i++)
    {
        memcpy(tmp, a + i * size, size);
        ssize_t j = i - 1;
        while (j >= 0 && less(tmp, a + j * size))
        {
            memcpy(a + (j + 1) * size, a + j * size, size);
            j--;
        }
        memcpy(a + (j + 1) * size, tmp, size);
    }

    free(tmp);
}

static size_t partition(void *arr, size_t n, size_t size,
                        bool (*less)(const void *, const void *))
{
    char *a = arr;
    char *pivot = malloc(size);
    memcpy(pivot, a + (n - 1) * size, size);
    ssize_t i = -1;

    for (size_t j = 0; j < n - 1; j++)
    {
        if (less(a + j * size, pivot) || !less(pivot, a + j * size))
        {
            i++;
            char temp[size];
            memcpy(temp, a + i * size, size);
            memcpy(a + i * size, a + j * size, size);
            memcpy(a + j * size, temp, size);
        }
    }

    char temp[size];
    memcpy(temp, a + (i + 1) * size, size);
    memcpy(a + (i + 1) * size, a + (n - 1) * size, size);
    memcpy(a + (n - 1) * size, temp, size);

    free(pivot);
    return i + 1;
}

void quicksort(void *arr, size_t n, size_t size,
               bool (*less)(const void *, const void *))
{
    if (n < THRESHOLD)
    {
        insertion_sort(arr, n, size, less);
        return;
    }

    size_t pivotIndex = partition(arr, n, size, less);

    if (pivotIndex > 0)
        quicksort(arr, pivotIndex, size, less);
    quicksort((char *)arr + (pivotIndex + 1) * size, n - pivotIndex - 1, size, less);
}

static bool int_less(const void *a, const void *b)
{
    return (*(int *)a) < (*(int *)b);
}

void quicksort_int(int *arr, size_t n)
{
    quicksort((void *)arr, n, sizeof(int), int_less);
}
