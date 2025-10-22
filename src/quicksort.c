#define THRESHOLD 10

void insertion_sort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void quicksort(int arr[], int left, int right)
{
    while (left < right)
    {
        if (right - left + 1 < THRESHOLD)
        {
            insertion_sort(arr, left, right);
            break;
        }
        else
        {
            int pivotIndex = partition(arr, left, right);

            if (pivotIndex - left < right - pivotIndex)
            {
                quicksort(arr, left, pivotIndex - 1);
                left = pivotIndex + 1;
            }
            else
            {
                quicksort(arr, pivotIndex + 1, right);
                right = pivotIndex - 1;
            }
        }
    }
}
