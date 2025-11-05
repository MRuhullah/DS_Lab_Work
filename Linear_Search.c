#include <stdio.h>

int linearsearch(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key)
            return i;
    }
    return -1;
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
    printf("Array entered:\n");
    displayArray(array, n);

    int key;
    printf("Enter the number you want to find: ");
    scanf("%d", &key);

    int result = linearsearch(array, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
