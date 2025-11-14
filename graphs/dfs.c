#include <stdio.h>

#define SIZE 5

void push(int s[], int *top, int data)
{
    if ((*top) < 2 * (SIZE-1))
    {
        (*top)++;
        s[*top] = data;
    }
    else
    {
        return;
    }

}

int pop(int s[], int *top)
{
    if ((*top >= 0))
    {
        int data = s[*top];
        (*top)--;
        return data;
    }
    else
    {
        return -1;
    }
}

int peek(int s[], int *top)
{
    return s[*top];
}

int doesExist(int vertex,int v[])
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        if (v[i] == vertex)
        {
            return 1;
            break;
        }
        
    }
    return -1;    
}

void display(int v[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d \n",v[i]);
    }
    
}

int isVisited(int v[], int vertex)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (v[i] == vertex)
        {
            return 1;
        }
    }
    return -1;
    
}

int hasUnvisited(int vertex, int v[], int adj_matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (adj_matrix[vertex][i] == 1)
        {
            if (isVisited(v, i) == -1)
            {
                return i;
            }
            
        }
        
    }
    return -1;
}

void dfs(int init_vertex,int v[], int s[], int adj_matrix[SIZE][SIZE])
{
    int top = -1;
    int visited_counter = 0;
    push(s,&top,init_vertex);
    v[visited_counter] = init_vertex;
    printf("hi");
    while (top >= 0)
    {
        int node = peek(s,&top);
        printf("%d \t",node);
        if (hasUnvisited(node, v, adj_matrix) != -1)
        {
            int data = hasUnvisited(node, v, adj_matrix);
            push(s,&top,data);
            v[visited_counter++] = data;
        }
        else
        {
            // for (int i = 0; i < SIZE; i++)
            // {
            //     if (hasUnvisited(node, v, adj_matrix) == -1)
            //     {
                    pop(s,&top);
            //     }
            // }
            
        }
        
    }

    printf("\n");

    display(v);
}

int main()
{
    int adj_matrix[SIZE][SIZE];
    int visited[SIZE];
    int stack[2*SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            adj_matrix[i][j] = 0;
        }
        visited[i] = -1;
    }
    

    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 1;
    
    adj_matrix[1][2] = 1;

    adj_matrix[2][0] = 1;
    adj_matrix[2][1] = 1;
    adj_matrix[2][3] = 1;
    adj_matrix[2][4] = 1;

    adj_matrix[3][2] = 1;

    adj_matrix[4][2] = 1;

    dfs(0,visited,stack,adj_matrix);

    return 0;
}