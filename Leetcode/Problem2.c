/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.*/

#include <stdio.h>

int removeval(int nums[], int n, int val)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
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
    int val;

    printf("Enter the number of elements(MAX 49): ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements that will be in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter the value that you wanna remove: ");
    scanf("%d", &val);

    int k = removeval(nums, n, val);

    printf("Number of elements after removing the occurrence of %d are %d\n", val, k);
    printf("The array after removing the element is:\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}