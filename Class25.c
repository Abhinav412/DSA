//Create a Graph use depth first search traversal
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int visited[MAX];
int adj[MAX][MAX];
int n;
void create_graph()
{
    int i,j;
    while(1)
    {
        printf("Enter the edge information for i and j:");
        scanf("%d %d",&i,&j);
        if(i==-1 && j==-1)
        {
            break;
        }
        else
        {
            adj[i][j] = 1;
            adj[j][i] = 1;
        }
    }
}

//init function to initialise all elements of the adjacent matrix to zero
void init()
{
    int i,j;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            adj[i][j] = 0;
        }
    }
}

//dfs function to traverse the graph using depth first search
void dfs(int v,int n,int*visited)
{

}

void display()
{
    int i,j;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            printf("%5d",adj[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("Enter the number of nodes in the graph:");
    scanf("%d",&n);
    init();
    create_graph();
    display();
    //dfs(0,n,visited);

}