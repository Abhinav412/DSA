#include <stdio.h>
#include <stdlib.h>

#define maxnodes 100

//function to initialize the adjacency matrix
void initadjmat(int adjmat[][maxnodes], int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            adjmat[i][j] = 0;
        }
    }
}

//function to add an edge to the graph
void addEdge(int adjmat[][maxnodes], int i, int j)
 {
    adjmat[i][j] = 1;
    adjmat[j][i] = 1;
}

//function to initialize the visited array
void initvisited(int *visited, int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        visited[i] = 0;
    }
}

//function to perform DFS traversal on the graph
void dfs(int adjmat[][maxnodes], int s, int *visited, int n) 
{
    visited[s] = 1;
    printf("%d ", s);
    for (int i = 1; i <= n; i++)
    {
        if (adjmat[s][i] == 1 && visited[i] != 1) 
        {
            dfs(adjmat, i, visited, n);
        }
    }
}

//function to perform BFS traversal on the graph
void bfs(int adjmat[][maxnodes], int s, int *visited, int n)
 {
    int queue[maxnodes], front = -1, rear = -1;
    visited[s] = 1;
    queue[++rear] = s;
    while (front != rear) 
    {
        int u = queue[++front];
        printf("%d ", u);
        for (int i = 1; i <= n; i++) 
        {
            if (adjmat[u][i] == 1 && visited[i] != 1) 
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

//main function
int main(void) 
{
    int n, e, i, j, s;
    int adjmat[maxnodes][maxnodes], visited[maxnodes];
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    initadjmat(adjmat, n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &e);
    for (int k = 1; k <= e; k++) 
    {
        printf("Enter the edge information for i and j: ");
        scanf("%d %d", &i, &j);
        addEdge(adjmat, i, j);
    }
    printf("Enter the starting node for traversal: ");
    scanf("%d", &s);
    printf("DFS traversal: ");
    initvisited(visited, n);
    dfs(adjmat, s, visited, n);
    printf("\nBFS traversal: ");
    initvisited(visited, n);
    bfs(adjmat, s, visited, n);
}