#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct queue
{
    struct node *data[100];
    int rear;
    int front;
};

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void enqueue(struct queue *q, struct node *node)
{
    q->rear++;

    q->data[q->rear] = node;
}
struct node *dequeue(struct queue *q)
{
    q->front++;
    return q->data[q->front];
}

struct node *createtree()
{
    int n, value;
    printf("Enter the total number of nodes that tree will contain: ");
    scanf("%d", &n);

    printf("Enter the value that will be in root node: ");
    scanf("%d", &value);

    struct node *root = createnode(value);
    struct queue q = {{0}, -1, -1};

    enqueue(&q, root);

    int count = 1;

    while (count < n)
    {
        struct node *parent = dequeue(&q);

        printf("Enter left child of %d (-1 for NULL): ", parent->data);
        scanf("%d", &value);

        if (value != -1)
        {
            parent->left = createnode(value);
            enqueue(&q, parent->left);
            count++;
        }
        if (count < n)
        {
            printf("Enter right child of %d (-1 for NULL): ", parent->data);
            scanf("%d", &value);
            if (value != -1)
            {
                parent->right = createnode(value);
                enqueue(&q, parent->right);
                count++;
            }
        }
    }

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void levelorder(struct node *root)
{
    if (root == NULL)
        return;

    struct queue q = {{0}, -1, -1};
    enqueue(&q, root);

    while (q.front != q.rear)
    {
        struct node *temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL)

            enqueue(&q, temp->left);

        if (temp->right != NULL)

            enqueue(&q, temp->right);
    }
}
int main()
{
    struct node *root = createtree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nLevel Order Traversal: ");
    levelorder(root);

    return 0;
}
