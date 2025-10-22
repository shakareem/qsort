#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stddef.h>
#include <stdbool.h>

// default quicksort with inssertion sort
// optimization for small arrays
// arr - an array for sorting
// n - array length
// size - size of each element in bytes
// less - comparison function: returns true if first argument is less than second
void quicksort(void *arr, size_t n, size_t size,
               bool (*less)(const void *, const void *));

// quicksort for integer arrays with inssertion sort
// optimization for small arrays
// arr - an array of integers for sorting
// n - array length
void quicksort_int(int *arr, size_t n);

#endif
