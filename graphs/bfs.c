#include <stdio.h>

struct node{
    int x;
    int y;
};

int isEmpty(int q[])
{
    for (int i = 0; i < 7; i++)
    {
        if (q[i] == -1)
        {
            return -1;
        }
        
    }
    return 1;
    
}

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


void traversal(int init_vertex, int q[], int v[], int ad_m[7][7])
{

    int vertex = 0;
    int counter = 0;
    int visited_counter = 0;
    q[counter] = vertex;
    v[visited_counter] = vertex;

    counter++;
    visited_counter++;
    int temp_element = 0;
    while (counter >= 0)
    {
        temp_element = q[counter];
        counter--;
        // printf("hello");
        printf("%d \t ",temp_element);
        for (int i = 0; i < 7; i++)
        {
            if (ad_m[temp_element][i] == 1 && notVisited(v,ad_m[temp_element][i]) != -1)
            {
               q[counter] = i;
               v[visited_counter] = i;
               counter++;
               visited_counter++;
            }
        }
        
    }
    printf("gsg");
    print(v);
    
}


int main()
{
    // initializing the array with zeros
    int ad_matrix[7][7] = {};
    int queue[7] = {-1};
    int visited[7] = {-1};
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