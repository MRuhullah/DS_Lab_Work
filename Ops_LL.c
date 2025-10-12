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
    struct node *tail = head;
    printf("Linked List: ");
    while (tail != NULL)
    {
        printf("%d -> ", tail->data);
        tail = tail->next;
    }
    printf("NULL\n");
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
    printlist(head);
    return 0;
}