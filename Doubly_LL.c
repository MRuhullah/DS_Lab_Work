#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void printlist(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node *createll(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
struct node *insertion_beg(struct node *head, int data)
{
    struct node *newnode = createll(data);
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
    return head;
}
struct node *insertion_end(struct node *head, int data)
{
    struct node *newnode = createll(data);

    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
    return head;
}

struct node *insertion_any(struct node *head, int position, int data)
{
    struct node *newnode = createll(data);
    if (position < 0)
    {
        printf("Invalid position!\n");
        return head;
    }
    if (position == 0)
    {
        newnode->next = head;
        newnode->prev = NULL;
        if (head != NULL)
            head->prev = newnode;
        return newnode;
    }
    struct node *temp = head;
    int count = 0;
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
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

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}
struct node *deletion_end(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    struct node *temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        return NULL;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}
struct node *deletion_any(struct node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (position == 0)
    return deletion_beg(head);

    struct node *temp = head;
    int count = 0;
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

int main()
{
    int n, value;
    struct node *head = NULL, *tail = NULL;
    printf("Enter the number of nodes you wanna create:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);
        struct node *newnode = createll(value);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    printf("Linked List is:\n");
    printlist(head);

    printf("Enter the value you wanna insert at beginning: ");
    scanf("%d", &value);
    head = insertion_beg(head, value);
    printf("Updated Double Linked List:\n");
    printlist(head);

    printf("Enter the value you wanna insert at  ending: ");
    scanf("%d", &value);
    head = insertion_end(head, value);
    printf("Updated Double Linked List:\n");
    printlist(head);

    int position;
    printf("Enter at which position you wanna insert: ");
    scanf("%d", &position);
    printf("Enter the value you wanna insert: ");
    scanf("%d", &value);
    head = insertion_any(head, position, value);
    printf("Updated Double Linked List:\n");
    printlist(head);

    head = deletion_beg(head);
    printf("Updated Double Linked List:\n");
    printlist(head);

    head = deletion_end(head);
    printf("Updated Double Linked List:\n");
    printlist(head);

    printf("Enter at which position you wanna delete: ");
    scanf("%d", &position);
    head = deletion_any(head, position);
    printf("Updated Double Linked List:\n");
    printlist(head);

    return 0;
}