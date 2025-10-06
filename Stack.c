#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct lifo
{
    int st[MAXSIZE];
    int top;
};

void create(struct lifo *s)
{
    s->top = -1;
}

void push(struct lifo *s, int element)
{
    if (s->top == MAXSIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->st[s->top] = element;
}

int pop(struct lifo *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->st[s->top--];
}

void display(struct lifo *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d\n", s->st[i]);
    }
}

int main()
{
    struct lifo s;
    int choice, value;

    create(&s);

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;

        case 2:
            value = pop(&s);
            if (value != -1)
                printf("Popped element: %d\n", value);
            break;

        case 3:
            display(&s);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
