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
    stack A, B;
    create(&A);
    create(&B);
    push(&A, 20);
    push(&A, 30);
    push(&A, 40);
    push(&A, 50);
    display(&A);

    return 0;
}
