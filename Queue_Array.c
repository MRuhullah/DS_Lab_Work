#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void createQueue()
{
    int n, value;
    printf("Enter number of elements to create queue: ");
    scanf("%d", &n);

    front = 0;
    rear = -1;

    for (int i = 0; i < n; i++)
    {
        if (rear == MAX - 1)
        {
            printf("Queue overflow! Cannot add more elements.\n");
            break;
        }
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
    }
    printf("Queue created successfully.\n");
}

void enqueue()
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow! Cannot enqueue.\n");
        return;
    }
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued.\n", value);
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }
    int value = queue[front];
    front++;
    if (front > rear)
        front = rear = -1;
    return value;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("Queue Menu\n");
        printf("1. Create Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createQueue();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            value = dequeue();
            if (value != -1)
                printf("Dequeued value: %d\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
