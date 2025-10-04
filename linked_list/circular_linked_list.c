#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};


// Head Pointer

struct node* head = NULL;

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct node* list)
{
    if (head == NULL)
    {
        head = list;
        list->next = head;
    }
    else
    {

        struct node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = list;
        list->next = head;
        head = list;
    }
    
}

void insertAtPosition(struct node* list, int pos)
{
    struct node* temp = head;
    struct node* ptr = head;
    int i = 1;
    while(i<=pos-1)
    {
        printf("\n hi %d\t  %d",i,pos);
        ptr = temp;
        temp = temp->next;
        i++;
    }

        ptr->next = list;
        list->next = temp;   

    return;
}

void insertAtEnd(struct node* list)
{
        struct node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = list;
        list->next = head;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("\n The list is empty ");
        return;
    }
    else
    {
        struct node* temp = head;
        struct node* ptr = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        free(ptr);
    }
}

void deleteAtPos(int pos)
{

    int i = 1;
    struct node* temp = head;
    struct node* ptr = head;
    while (i <= pos-1)
    {
        ptr = temp;
        temp = temp->next;
        i++;
        printf("hi %d pos :: %d \n",pos,i);
    }
    ptr->next = temp->next;
    free(temp);
    return;
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("\n The list is empty ");
        return;
    }
    else
    {
        struct node* temp = head;
        struct node* ptr = head;
        while (temp->next != head)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = head;
        free(temp);
    }
    
}

void display()
{
    
        struct node* temp = head;
        do
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        } while (temp != head);
        
    return;
}


int main()
{
    int choice = 0;
    while (choice < 8)
    {
        printf("\n1  Insert at beginning : ");
        printf("\n2  Insert at end : ");
        printf("\n3 Insert at a position : ");
        printf("\n4 delete at beginning : ");
        printf("\n5 delete at end : ");
        printf("\n6 delete at a position : ");
        printf("\n7 Display\t:");
        scanf("%d", &choice);
        int data,pos;
        switch (choice)
        {
        case 1:
            printf("\n Enter the data to insert to the element : ");
            scanf("%d",&data);
            struct node* newNode = createNode(data);
            insertAtBeginning(newNode);
            break;
        case 2:
            printf("\n Enter the data to insert to the element : ");
            scanf("%d",&data);
            {

                struct node* newNode = createNode(data);
                insertAtEnd(newNode);
            }
            break;
        case 3:
            printf("\n Enter the data to insert to the element : ");
            scanf("%d",&data);
            printf("\n Enter the position to insert the element to : ");
            scanf("%d",&pos);
            {

                struct node* newNode = createNode(data);
                insertAtPosition(newNode,pos);
            }
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("\n Enter the position to delete the element from : ");
            scanf("%d",&pos);
            deleteAtPos(pos);
            break;
        case 7:
            display();
            break;
        default:
            break;
        }

    }
    

    return 0;
}