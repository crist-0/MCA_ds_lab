#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack* next;
    struct Stack* prev;
};

struct Stack* head = NULL;
struct Stack* TOP = NULL;

struct Stack* createNode(int data)
{
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void Push(int data){
    struct Stack* newNode = createNode(data);
    if (TOP == NULL)
    {
        TOP = newNode;
        head = newNode;
    }
    else
    {
        TOP->next = newNode;
        newNode->prev = TOP;
        TOP = newNode;
    }
    return;
}

void Pop()
{
    if (TOP == NULL)
    {
        printf("Stack UnderFlow");
    }
    else
    {
        struct Stack* temp = head;
        struct Stack* ptr = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        int deleted_data = temp->data;
        ptr->next = NULL;
        TOP = ptr;
        free(temp);
        printf("\nDeleted Data : %d",deleted_data);
    }
    return;
}

void display()
{
    struct Stack* temp = TOP;
    while (temp != NULL)
    {
        printf("\n %d ",temp->data);
        temp = temp->prev;
    }
    
}

void main()
{
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Push(6);
    display();
    Pop();
    Pop();
    Pop();
    Pop();
    display();
    return;
}