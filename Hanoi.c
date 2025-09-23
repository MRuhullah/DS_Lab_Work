#include <stdio.h>

void towerOfHanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }

    towerOfHanoi(n - 1, A, C, B);

    printf("Move disk %d from %c to %c\n", n, A, C);

    towerOfHanoi(n - 1, B, A, C);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
