#include <stdio.h>

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int new = partition(array, low, high);

        quicksort(array, low, new - 1);
        quicksort(array, new + 1, high);
    }
}
void inputArray(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements (max 99): ");
    scanf("%d", &n);

    if (n > 99)
    {
        printf("Too many elements!\n");
        return 1;
    }

    int array[100];
    inputArray(array, n);
    printf("Original array:\n");
    displayArray(array, n);

    quicksort(array, 0, n - 1);
    printf("Sorted array is:\n");
    displayArray(array, n);

    return 0;
}