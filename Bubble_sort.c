#include <stdio.h>

void bubblesort(int array[], int m)
{
    for (int i = 0; i < m - 1; i++)
    { int flag = 0;
        for (int j = 0; j < m - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {  
            printf("Exited with %d pass\n",i);
            break;
        }
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

    bubblesort(array, n);
    printf("Sorted array is:\n");
    displayArray(array, n);

    return 0;
}