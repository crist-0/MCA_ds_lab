#include <stdio.h>

#define MAX_SIZE 7

int front = -1;
int rear = -1;

void enqueue(int queue[], int data)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = data;
    }
    else if (!(front == 0))
    {
        if (rear == MAX_SIZE-1)
        {
            rear = 0;
            queue[rear] = data;
        }
        else
        {
            rear++;
            queue[rear] = data;
        }
        
    }
    else
    {
        printf("Queue is full");
    }
}

void dequeue(int queue[])
{
    int data;
    if (front == rear)
    {
        printf("Queue is empty");
    }
    else
    {
        if (front == MAX_SIZE-1)
        {
            data = queue[front];
            queue[front] = 0;
            front = 0;
        }
        else
        {
            data = queue[front];
            queue[front] = 0;
            front++;
        }
        
    }
    
}

int main()
{

    return 0;
}