#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createnode(int value)
{
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void printlist(struct node *head)
{
    struct node* tail = head;
    printf("Linked List: ");
    while (tail != NULL)
    {
        printf("%d -> ", tail->data);
        tail = tail->next;
    }
    printf("NULL\n");
}
struct node* insertion_beg(struct node *head, int value)
{
    struct node* newnode = createnode(value);
    newnode->next = head;
    head = newnode;
    return head;
}
struct node* insertion_end(struct node *head, int value)
{
    struct node* newnode = createnode(value);
    if (head == NULL)
        return newnode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
       temp->next = newnode;
    return head;
}
struct node* insertion_any(struct node *head, int value, int position)
{
    struct node* newnode = createnode(value);
    if (position == 0)
    {
        newnode->next = head;
        return newnode;
    }
    struct node* temp = head;
    int count = 0;
    while (temp != 0 && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid position!");
        return head;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node *delete_beg(struct node *head)
{

    if (head == NULL)
    {
        printf("List is already empty\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct node* delete_end(struct node* head)
{
    if (head == NULL)
    {
        printf("List is already empty\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    struct node *prev;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}
struct node* delete_position(struct node* head, int position)
{
     if (head == NULL)
    {
        printf("List is already empty.\n");
        return NULL;
    }
     struct node* temp = head;
     struct node* prev;
     int count = 0;
      while (temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid position: No node at index %d.\n", position);
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}
    int main()
{
    int n, value;
    struct node *head = NULL, *tail = NULL;
    printf("Enter the number of node you wanna create: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);
        struct node *newnode = createnode(value);
        if (head == NULL)
            head = newnode;
        else
            tail->next = newnode;
        tail = newnode;
    }

    printf("Enter the value you wanna insert");
    scanf("%d", &value);
    head = insertion_beg(head, value);
    printf("Updated Linked List: ");
    printlist(head);

    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    head = insertion_end(head, value);
    printf("Updated Linked List: ");
    printlist(head);

    int position;
    printf("Enter the position at which you wanna insert node: \n");
    scanf("%d", &position);
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    head = insertion_any(head, value, position);
    printf("Updated Linked List: ");
    printlist(head);

    head = delete_beg(head);
    printlist(head);

    head = delete_end(head);
    printlist(head);

    printf("Enter position to delete (0-based index): ");
    scanf("%d", &position);
    head = delete_position(head, position);
    printlist(head);


    return 0;
}