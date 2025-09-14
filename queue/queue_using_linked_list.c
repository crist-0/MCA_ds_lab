#include <stdio.h>
#include <stdlib.h>


// Implementation of queues using linked list

struct queue
{
    int data;
    struct queue *next;
};

// Head and Tail pointers

struct queue *Head = NULL;

struct queue *Tail = NULL;

struct queue* createNode(int data)
{
    struct queue *Node = (struct queue *)(malloc(sizeof(struct queue)));
    Node->data = data;
    Node->next = NULL;
    return Node;
}

void enQueue(struct queue *node)
{
    if (Head == NULL && Tail == NULL)
    {
        Head = node;
        Tail = node;
    }
    else
    {
        Tail->next = node;
        Tail = node;
    }
}

void deQueue()
{
    if (Head == NULL && Tail == NULL)
    {
        printf("\n Queue is empty!!");
    }
    else
    {
        struct queue *node = Head;
        Head = node->next;
        free(node);
    }
}

void display()
{
    struct queue *temp = Head;
    while (temp != NULL)
    {
        printf("\t %d", temp->data);
        temp = temp->next;
    }

}

int main()
{
    int choice = 0;
    while (choice < 4)
    {
        printf("-------QUEUE -- LINKED LIST -------");
        printf("\n 1: ENQUEUE ");
        printf("\n 2: DEQUEUE ");
        printf("\n 3: DISPLAY ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int data;
            printf("\n Enter data ");
            scanf("%d",&data);
            struct queue *node = createNode(data);
            enQueue(node);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }
    
    return 0;
}