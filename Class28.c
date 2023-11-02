#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define visited 2
#define finished 3

int n;    //Number of vertices in the graph
int adj[MAX][MAX]; //Adjacency Matrix
int state[MAX]; //can be initial, visited or finished

void create_graph()
{
    int i,edges,origin,destination;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    edges = n*(n-1);
    for(i=1;i<=edges;i++)
    {
        printf("Enter the edge(-1 -1 to quit):\n");
        scanf("%d %d",&origin,&destination);
        if((origin == -1) && (destination == -1))
        {
            break;
        }
        if(origin >= n || destination >=n || origin < 0 || destination < 0)
        {
            printf("Invalid edge");
        }
        else
        {
            adj[origin][destination] = 1;
        
        }
    }
}

void dfs(int v)
{
    int i;
    state[v] = visited;
    for(int i=0; i<n; i++)
    {
        if(adj[v][i] == 1)
        {
            if(state[i] == initial)
            {
                dfs(i);
            }
            else if(state[i] == visited)
            {
                printf("Back edge (%d,%d) found\n",v,i);
                printf("Graph is cyclic\n");
                exit(1);
            }
            
        }
    }
    state[v] = finished;
}

void dfs_traversal()
{
    int v;
    for(int v=0; v<n; v++)
    {
        state[v] = initial;
    }
    dfs(0);
    for(v=0; v<n; v++)
    {
        if(state[v] == initial)
        {
            dfs(v);
        }
    }
    printf("Graph is acyclic\n");
}

int main(void)
{
    create_graph();
    dfs_traversal();
}