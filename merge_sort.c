#include <stdio.h>

void merge(int array[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])

            temp[k++] = array[i++];
        else

            temp[k++] = array[j++];
    }

    while (i <= mid)

        temp[k++] = array[i++];

    while (j <= high)

        temp[k++] = array[j++];

    for (i = low; i <= high; i++)

        array[i] = temp[i];
}

void mergesort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, low, mid, high);
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

    mergesort(array, 0, n - 1);
    printf("Sorted array is:\n");
    displayArray(array, n);

    return 0;
}