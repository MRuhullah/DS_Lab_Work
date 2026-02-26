#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    struct Node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

void display()
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

void createStack()
{
    int n, value;
    printf("Enter the number of elements to create stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }
    printf("Stack created successfully.\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nStack Menu\n");
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
            createStack();
            break;
        case 2:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 3:
            value = pop();
            if (value != -1)
                printf("Popped value: %d\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            while (top != NULL)
                pop();
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
