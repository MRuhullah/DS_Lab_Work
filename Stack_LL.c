#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    struct Node *temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

void display(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void createStack(struct Node **top)
{
    int n, value;
    printf("Enter the number of elements to create stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(top, value);
    }
    printf("Stack created successfully.\n");
}

int main()
{
    struct Node *stack = NULL;
    int choice, value;

    while (1)
    {
        printf("Stack Menu\n");
        printf("1. Create Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createStack(&stack);
            break;
        case 2:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 3:
            value = pop(&stack);
            if (value != -1)
                printf("Popped value: %d\n", value);
            break;
        case 4:
            display(stack);
            break;
        case 5:
            while (stack != NULL)
                pop(&stack);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
