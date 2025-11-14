#include <stdio.h>
#define SIZE 14

struct node{
    int x;
    int y;
};



int notVisited(int v[], int element)
{
    for (int i = 0; i < 7; i++)
    {
        if (v[i] == element)
        {
            return -1;
        }
    }
    return 1;

}

void print(int v[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%d \n",v[i]);
    }
    
}

void enqueue(int q[], int *f, int *r, int data)
{
    if (*r == SIZE-1)
    {
        return;
    }
    else if (*r == -1 && *f == -1)
    {
        (*f)++;
        (*r)++;
        q[*r] = data;
    }
    else
    {
        (*r)++;
        q[*r] = data;
    }
    
}


int dequeue(int q[], int *f, int *r)
{
    if (*f == -1 || *f > *r)
    {
        return -1;
    }
    int data = q[*f];
    (*f)++;
    return data;
    
}

void traversal(int init_vertex, int q[], int v[], int ad_m[7][7])
{

    int front = 0;
    int rear = 0;

    int visited_counter = 0;
    enqueue(q,&front,&rear, init_vertex);
    v[visited_counter] = init_vertex;
    visited_counter++;
    int temp_element = 0;

    while (front <= rear)
    {
        temp_element = dequeue(q,&front,&rear);
        // printf("hello");
        printf("%d \t ",temp_element);
        for (int i = 0; i < 7; i++)
        {
            if (ad_m[temp_element][i] == 1 && notVisited(v,i) != -1)
            {
               enqueue(q,&front,&rear,i);
               v[visited_counter] = i;

               visited_counter++;
            }
        }
        
    }
    // printf("gsg");
    // print(v);
    
}


int main()
{
    // initializing the array with zeros
    int ad_matrix[7][7] = {};
    int queue[14] = {-1};
    int visited[14];
    for (int i = 0; i < 14; i++)
    {
        visited[i] = -1;
    }
    
    ad_matrix[0][2] = 1;
    ad_matrix[0][5] = 1;
    ad_matrix[1][3] = 1;
    ad_matrix[1][4] = 1;
    ad_matrix[2][4] = 1;
    ad_matrix[3][2] = 1;
    ad_matrix[3][5] = 1;
    ad_matrix[4][0] = 1;
    ad_matrix[5][4] = 1;

    traversal(0,queue,visited,ad_matrix);


    return 0;
}