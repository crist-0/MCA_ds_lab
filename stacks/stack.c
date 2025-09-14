#include <stdio.h>

#define TOP_SIZE 20

int top = 0;

void push(int stack[])
{
    if (top >= TOP_SIZE)
    {
        printf("Stack overflow");
    }
    else
    {
        int c;
        printf("\nEnter the no to enter: ");
        scanf("%d",&c);
        top++;
        stack[top] = c;
    }
    return;
}

void pop(int stack[])
{
    if (top <= -1)
    {
        printf("\nStack underflow");
    }
    else
    {
        int dlt = stack[top];
        top--;
        printf("\n deleted element : %d ",dlt);
    }
    return;
}

void peek(int stack[])
{
    printf("Top of the stack = %d ", stack[top]);
    return;
}

int main()
{
    int stack[TOP_SIZE];
    push(stack);
    push(stack);
    push(stack);
    push(stack);
    pop(stack);
    peek(stack);
    return 0;
}