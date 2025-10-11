#include <stdio.h>

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

int insertion_beg(int arr[], int n)
{
    int element;
    printf("Enter the element you wanna insert at the beginning: ");
    scanf("%d", &element);

    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
    return n + 1;
}

int insertion_end(int arr[], int n)
{
    int element;
    printf("Enter the element you wanna insert at the end: ");
    scanf("%d", &element);

    arr[n] = element;
    return n + 1;
}

int insertion_any(int arr[],int n)
{
    int element,position;
    printf("Enter at which position you wanna insert from 0 to %d: ",n);
    scanf("%d",&position);
    if(position < 0 || position > n)
    {
    printf("Invalid position!\n");
    return n;
    }

    printf("Enter the element you wanna insert: ");
    scanf("%d", &element);

    for(int i = n; i>position;i--)
    {
        arr[i] = arr[i-1];
    }

    arr[position] = element;
    return n+1;

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

    int arr[100];

    inputArray(arr, n);
    printf("Array elements are:\n");
    displayArray(arr, n);

    n = insertion_beg(arr, n);
    printf("Updated elements are:\n");
    displayArray(arr, n);

    n = insertion_end(arr,n);
    printf("Updated elements are:\n");
    displayArray(arr, n);

    n = insertion_any(arr,n);
    printf("Updated elements are:\n");
    displayArray(arr, n);

    return 0;
}
