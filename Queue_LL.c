#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }
    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

void display(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    struct Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void createQueue(struct Queue *q)
{
    int n, value;
    printf("Enter number of elements to create queue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(q, value);
    }
    printf("Queue created successfully.\n");
}

int main()
{
    struct Queue q = {NULL, NULL};
    int choice, value;

    while (1)
    {
        printf(" Queue Menu\n");
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

            while (q.front != NULL)
            {
                dequeue(&q);
            }
            createQueue(&q);
            break;
        case 2:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 3:
            value = dequeue(&q);
            if (value != -1)
                printf("Dequeued value: %d\n", value);
            break;
        case 4:
            display(&q);
            break;
        case 5:

            while (q.front != NULL)
            {
                dequeue(&q);
            }
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
