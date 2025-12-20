#include <stdio.h>

void selectionsort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j, k;

        for (j = k = i; j < n; j++)
        {
            if (array[j] < array[k])
                k = j;
        }

        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
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

    selectionsort(array, n);
    printf("Sorted array is:\n");
    displayArray(array, n);

    return 0;
}