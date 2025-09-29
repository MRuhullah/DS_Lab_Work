#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void InsertionFront(struct Node **headref, int val)
{
    struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = val;
    new_Node->next = *headref;
    *headref = new_Node;

   // void Insertion_End(struct Node * *tailref, int val)
   
}
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // head = (struct Node *)malloc(sizeof(struct Node ));
    // tail = (struct Node *)malloc(sizeof(struct Node));

    insertionAtFront(&head, 3);
    insertionAtFront(&head, 2);
    insertionAtFront(&head, 1);
    printLinkedList(head);
    return 0;
}