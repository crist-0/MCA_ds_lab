#include <stdio.h>

#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createNode(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertion(int value)
{
    // printf("%d \t",value);
    struct node* newNode = createNode(value);
    // printf("%d \t",newNode->data);
    if (root == NULL)
    {
        root = newNode;
    }
    else{

        struct node* ptr = root;
        struct node* ptr1 = root;
        while (ptr != NULL)
        {
            if (newNode->data > ptr->data)
            {
                ptr1 = ptr;
                ptr = ptr->right;
            }
            else if (newNode->data < ptr->data)
            {
                ptr1 = ptr;
                ptr = ptr->left;
            }
        }
        // now ptr1 is at the leaf node
        if (newNode->data > ptr1->data)
        {
            ptr1->right = newNode;
        }
        else if (newNode->data < ptr1->data)
        {
            ptr1->left = newNode;
        }
    }
    return;   
}

struct node* smallestElement(struct node* top)
{
    struct node* temp = top->right;
    struct node* ptr = top->right;
    while (temp->left != NULL)
    {
        ptr = temp;
        temp = temp->left;
    }
    printf("\n Smallest element in right sub-tree %d \n",temp->data);
    ptr->left = NULL;
    return temp;
}

void removal(int value)
{
    struct node* ptr = root;
    struct node* ptr1 = root;
    while (ptr -> data != value )
    {
        if (value > ptr->data)
        {
            ptr1 = ptr;
            ptr = ptr->right;
        }
        else if (value < ptr->data)
        {
            ptr1 = ptr;
            ptr = ptr->left;
        }
    }

    if (ptr->left == NULL && ptr->right == NULL)
    {
        if (ptr->data > ptr1->data)
        {
            ptr1->right = NULL;
        }
        else{
            ptr1->left = NULL;
        }
        
    }
    else if (ptr->left == NULL && ptr->right != NULL || ptr->left != NULL && ptr->right == NULL)
    {
        if (ptr->left == NULL)
        {
            // if (ptr->data > ptr1->data)
            // {
            //     ptr1->right = ptr->right;
            //     free(ptr);
            // }
            // else if (ptr->data < ptr->data)
            // {
            //     ptr1->left = ptr->left;
            //     free(ptr);
            // }

            if (ptr->data > ptr1->data)
            {
                ptr1->right = ptr->right;
            }
            else if (ptr->data < ptr1->data)
            {
                ptr1->left = ptr->right;
            }
            
            
        
        }
        else if (ptr->right == NULL)
        {
            // if (ptr->data > ptr1->data)
            // {
            //     ptr1->left = ptr->left;
            //     free(ptr);
            // }
            // else if (ptr->data < ptr->data)
            // {
            //     ptr1->right = ptr->right;
            //     free(ptr);
            // }
            if (ptr->data > ptr1->data)
            {
                ptr1->right = ptr->left;
            }
            else if (ptr->data < ptr1->data)
            {
                ptr1->left = ptr->left;
            }
            
        }
       
    }
    else if (ptr->left != NULL && ptr->right != NULL)
    {   
        printf("\n sg \n");
        struct node* smallestNode = smallestElement(ptr);
        // if (ptr->data > ptr1->data)
        // {
        //     ptr1->right = smallestNode;
        // }
        // else{
        //     ptr1->left = smallestNode;
        // }
        
        ptr->data = smallestNode->data;

        // smallestNode->left = ptr->left;
        // smallestNode->right = ptr->left;
        // smallestNode->data = ptr->data;
        printf("\n element of right sub tree %d \n",ptr->right->data);
        free(smallestNode);
    }
    
    
}


void inOrder(struct node* tNode)
{
    // printf("hi\n");
    if (tNode == NULL)
        return;
    inOrder(tNode->left);
    printf("%d \t",tNode->data);
    inOrder(tNode->right);
}

void preOrder(struct node* tNode)
{
    if(tNode == NULL)
        return;
    printf("%d \t",tNode->data);
    preOrder(tNode->left);
    preOrder(tNode->right);
}

void postOrder(struct node* tNode)
{
    if(tNode == NULL)
        return;
    postOrder(tNode->left);
    postOrder(tNode->right);
    printf("%d \t",tNode->data);
}

int main()
{
    
    insertion(60);
    insertion(4);
    insertion(44);
    insertion(10);
    insertion(1);
    insertion(70);
    insertion(65);
    inOrder(root);
    removal(60);
    printf("\n");
    inOrder(root);
    return 0;
}