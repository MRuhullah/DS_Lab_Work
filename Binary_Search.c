#include <stdio.h>

int binarysearch(int array[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == key)

            return mid;

        else if (array[mid] < key)

            low = mid + 1;

        else

            high = mid - 1;
        }
    return -1;
}

int main()
{
    int array[] = {1, 3, 4, 6, 7, 34, 56, 78, 86};
    int n = sizeof(array) / sizeof(array[0]);
    int key;
    printf("Enter the number you want to find out: ");
    scanf("%d",&key);

    int result = binarysearch(array, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
