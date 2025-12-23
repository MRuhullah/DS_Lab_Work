/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include <stdio.h>

int insert(int nums[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)

            return mid;

        else if (nums[mid] < target)

            low = mid + 1;

        else

            high = mid - 1;
    }
    return low;
}

int main()
{
    int n;
    int target;

    printf("Enter the number of elements(MAX 49): ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements that will be in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter the target value for which you wnat find the index: ");
    scanf("%d", &target);

    int low = insert(nums, n, target);
    printf("The index of target value is: %d", low);

    return 0;
}