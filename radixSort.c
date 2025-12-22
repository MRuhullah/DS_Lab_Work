#include <stdio.h>

int getmax(int array[], int n)
{
    int max = array[0];

    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void countsort(int array[], int n, int exp)
{
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}
void radixsort(int array[], int n)
{
    int max = getmax(array, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countsort(array, n, exp);
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

    radixsort(array, n);
    printf("Sorted array is:\n");
    displayArray(array, n);

    return 0;
}