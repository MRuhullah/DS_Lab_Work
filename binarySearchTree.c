#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
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
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createnode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
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
        {
            enqueue(&q, temp->left);
        }

        if (temp->right != NULL)
        {
            enqueue(&q, temp->right);
        }
    }
}

struct node *minval(struct node *root)
{
    struct node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)

        root->left = delete(root->left, key);

    else if (key > root->data)

        root->right = delete(root->right, key);

    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp = minval(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    struct node *root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nLevel Order Traversal: ");
    levelorder(root);

    int key;
    printf("\nEnter the value to delete: ");
    scanf("%d", &key);
    root = delete(root, key);
    printf("After deletion the tree is: ");
    inorder(root);

    int element;
    printf("\nEnter value to search: ");
    scanf("%d", &element);

    struct node *result = search(root, element);

    if (result != NULL)
        printf("Element %d found in BST\n", element);
    else
        printf("Element %d not found in BST\n", element);

    return 0;
}