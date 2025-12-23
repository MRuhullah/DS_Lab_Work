#include <stdio.h>

int positivenum(int nums[], int n)
{
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[k - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    int n;

    printf("Enter the number of elements(MAX 49): ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements that will be in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int k = positivenum(nums, n);
    printf("Number of unique elements: %d\n", k);

    return 0;
}