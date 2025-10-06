#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct lifo
{
    int st[MAXSIZE];
    int top;
};
typedef struct lifo stack;
stack s;

void create(stack *s)
{
    s->top = -1;
}
void push(stack *s, int element)
{

    if (s->top == (MAXSIZE - 1))
    {
        printf("Stack overflow\n");
        exit(-1);
    }
    else
    {
        s->top++;
        s->st[s->top] = element;
    }
}
int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        exit(-1);
    }
    else
    {
        return (s->st[s->top--]);
    }
}
int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void display(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {

        printf("Stack elements are:\n");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d", s->st[i]);
            printf("\n");
        }
    }
}

int main()
{
    stack A;
    create(&A);
    printf("Elements before popping are:\n");
    push(&A, 20);
    push(&A, 30);
    push(&A, 40);
    push(&A, 50);
    if (isempty(&A))
    {
        printf("Stack A is empty\n");
        return 0;
    }
    display(&A);
    printf("Elements after popping are:\n");
    pop(&A);
    display(&A);
}
