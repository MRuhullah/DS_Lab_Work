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

int insertion_any(int arr[], int n)
{
    int element, position;
    printf("Enter at which position you wanna insert from 0 to %d: ", n);
    scanf("%d", &position);
    if (position < 0 || position > n)
    {
        printf("Invalid position!\n");
        return n;
    }

    printf("Enter the element you wanna insert: ");
    scanf("%d", &element);

    for (int i = n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    return n + 1;
}

int delete_beg(int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is already empty\n");
        return n;
    }

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}
int delete_end(int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is already empty\n");
        return n;
    }

    return n - 1;
}
int delete_any(int arr[], int n)
{
    int position;
    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &position);

    if (position < 0 || position >= n)
    {
        printf("Invalid position!\n");
        return n;
    }
    printf("Deleting element: %d\n", arr[position]);
    for (int i = position; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = 0;
    return n - 1;
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
    int choice;


    do
    {
        printf("ARRAY OPERATIONS:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Any Position\n");
        printf("7. Display Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            n = insertion_beg(arr, n);
            printf("Updated array:\n");
            displayArray(arr, n);
            break;
        case 2:
            n = insertion_end(arr, n);
            printf("Updated array:\n");
            displayArray(arr, n);
            break;
        case 3:
            n = insertion_any(arr, n);
            printf("Updated array:\n");
            displayArray(arr, n);
            break;
        case 4:
            n = delete_beg(arr, n);
            printf("Updated array:\n");
            displayArray(arr, n);
            break;
        case 5:
            n = delete_end(arr, n);
            printf("Updated array:\n");
            displayArray(arr, n);
            break;
        case 6:
            n = delete_any(arr, n);
            printf("Updated array:\n");
            displayArray(arr, n);
            break;
        case 7:
            printf("Array elements are:\n");
            displayArray(arr, n);
            break;
        case 8:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}
