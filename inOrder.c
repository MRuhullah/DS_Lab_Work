#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *stack[100];
int top = -1;

struct Node *newnode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void push(struct Node *node)
{
    stack[++top] = node;
}

struct Node *pop()
{
    return stack[top--];
}

int isEmpty()
{
    return top == -1;
}

void inorder(struct Node *root)
{
    struct Node *current = root;
    while (current != NULL || !isEmpty())
    {
        while (current != NULL)
        {
            push(current);
            current = current->left;
        }

        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
}
int main()
{
    struct Node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
