/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

#include <stdio.h>

int plusone(int digits[], int n)
{
    if (digits[n - 1] != 9)
    {
        digits[n - 1]++;
        return n;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return n;
        }
    }

    for (int j = n; j > 0; j--)
    {
        digits[j] = digits[j - 1];
    }

    digits[0] = 1;
    return n + 1;
}

int main()
{
    int n;

    printf("Enter the number of elements (MAX 49): ");
    scanf("%d", &n);

    int digits[49];

    printf("Enter the elements that will be in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &digits[i]);
    }

    n = plusone(digits, n);

    printf("The new array is:\n");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", digits[k]);
    }

    return 0;
}
