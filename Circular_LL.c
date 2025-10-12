#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void printlist(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

struct node *insertion_beg(struct node *head, int value)
{
    struct node *newnode = createnode(value);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return head;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
    return head;
}

struct node *insertion_end(struct node *head, int value)
{
    struct node *newnode = createnode(value);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return head;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
    return head;
}

struct node *insertion_any(struct node *head, int value, int position)
{
    if (position == 0 || head == NULL)
    {
        return insertion_beg(head, value);
    }

    struct node *newnode = createnode(value);
    struct node *temp = head;
    int i = 0;

    while (temp->next != head && i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

struct node *deletion_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    struct node *last = head;
    while (last->next != head)
        last = last->next;

    last->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

struct node *deletion_end(struct node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL)
        prev->next = head;

    free(temp);
    return head;
}

struct node *deletion_any(struct node *head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 0)
        return deletion_beg(head);

    struct node *temp = head;
    struct node *prev = NULL;
    int i = 0;

    while (temp->next != head && i < position)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i != position)
    {
        printf("Invalid position\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    int n, value;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &value);
        struct node *newnode = createnode(value);

        if (head == NULL)
        {
            head = tail = newnode;
            newnode->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    printlist(head);

    printf("Insert at beginning:\n");
    printf("Enter value: ");
    scanf("%d", &value);
    head = insertion_beg(head, value);
    printlist(head);

    printf("Insert at end:\n");
    printf("Enter value: ");
    scanf("%d", &value);
    head = insertion_end(head, value);
    printlist(head);

    int position;
    printf("Insert at any position:\n");
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter value: ");
    scanf("%d", &value);
    head = insertion_any(head, value, position);
    printlist(head);

    printf("Delete from beginning:\n");
    head = deletion_beg(head);
    printlist(head);

    printf("Delete from end:\n");
    head = deletion_end(head);
    printlist(head);
 
    printf("Enter position to delete: ");
    scanf("%d", &position);
    head = deletion_any(head, position);
    printlist(head);

    return 0;
}
