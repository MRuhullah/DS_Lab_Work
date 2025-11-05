#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = newnode->prev = NULL;
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
    printf("Doubly Circular Linked List: ");
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

struct node *insertion_beg(struct node *head, int value)
{
    struct node *newnode = createnode(value);

    if (head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }

    struct node *tail = head->prev;

    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;

    head = newnode;
    return head;
}

struct node *insertion_end(struct node *head, int value)
{
    struct node *newnode = createnode(value);

    if (head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }

    struct node *tail = head->prev;

    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;

    return head;
}

struct node *insertion_any(struct node *head, int value, int position)
{
    if (head == NULL || position == 0)
        return insertion_beg(head, value);

    struct node *newnode = createnode(value);
    struct node *temp = head;
    int i = 0;

    do
    {
        if (i == position - 1)
            break;
        temp = temp->next;
        i++;
    } while (temp != head);

    if (i != position - 1)
    {
        printf("Invalid position\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
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

    struct node *tail = head->prev;
    struct node *temp = head;

    head = head->next;
    tail->next = head;
    head->prev = tail;
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

    struct node *tail = head->prev;
    struct node *newtail = tail->prev;

    newtail->next = head;
    head->prev = newtail;
    free(tail);

    return head;
}

struct node *deletion_any(struct node *head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 0)
        return deletion_beg(head);

    struct node *temp = head;
    int i = 0;

    do
    {
        if (i == position)
            break;
        temp = temp->next;
        i++;
    } while (temp != head);

    if (i != position)
    {
        printf("Invalid position\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
        head = head->next;

    free(temp);
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int n, value, position;

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
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
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
