/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <stdio.h>

void find(int num[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (num[i] + num[j] == target)
            {
                printf("The target number is found!");
                printf("The indexes are: %d %d\n", i, j);
                return;
            }
        }
    }
}

int main()
{
    int n;
    int target;

    printf("Enter the number of elements(MAX 49): ");
    scanf("%d", &n);

    int num[n];

    printf("Enter the elements that will be in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    printf("Enter the target number: ");
    scanf("%d", &target);

    find(num, n, target);

    return 0;
}