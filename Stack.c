#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push()
{
    int value;
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push.\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("STACK MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
