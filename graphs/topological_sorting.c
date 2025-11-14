#include <stdio.h>

#define SIZE 6

void enqueue(int q[], int *front, int *rear, int value) {
    if (*rear == SIZE - 1) {
        printf("Queue full\n");
        return;
    }
    if (*front == -1) 
    {
        *front = 0;
    }
    q[++(*rear)] = value;
}

int dequeue(int q[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        return -1; 
    }
    return q[(*front)++];
}

int isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}


void topoSort(int adj[SIZE][SIZE]) {
    int indeg[SIZE] = {0};

    int count = 0;
 
    for (int col = 0; col < SIZE; col++) {
        for (int row = 0; row < SIZE; row++) {
            if (adj[row][col] == 1)
            {
                indeg[col]++;
            }
        }
    }

    int q[SIZE], front = -1, rear = -1;

    for (int i = 0; i < SIZE; i++) {
        if (indeg[i] == 0)
        {
            enqueue(q, &front, &rear, i);
        }
    }

    printf("Topological Order: ");

    while (!isEmpty(front, rear)) {
        int u = dequeue(q, &front, &rear);
        count++;
        printf("%d ", u);

       
        for (int v = 0; v < SIZE; v++) {
            if (adj[u][v] == 1) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    enqueue(q, &front, &rear, v);
                }
            }
        }
    }

    printf("\n");

    if (count != SIZE) {
    printf("Graph contains a cycle \n");
    }

}


int main() {

    int adj_matrix[SIZE][SIZE] = {
        {0,0,0,0,0,1},
        {0,0,0,0,1,1},
        {1,1,0,0,1,0},
        {1,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    topoSort(adj_matrix);

    return 0;
}
