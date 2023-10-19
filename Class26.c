#include<stdio.h>
#include<stdlib.h>
#define maxnodes 10 

void initgraph(int adjmat[][maxnodes],int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            adjmat[i][j] = 0;
        }
    }
}

void display(int adjmat[][maxnodes],int n)
{
    int i,j;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            printf("%5d",adjmat[i][j]);
        }
        printf("\n");
    }
}

void create_graph(int adjmat[][maxnodes],int n)
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
            adjmat[i][j] = 1;
            adjmat[j][i] = 1;
        }
    }
}

void initvisited(int *visited,int n)
{
    for(int i=0; i<=n; i++)
    {
        visited[i] = 0;
    }
}

void dfs(int adjmat[][maxnodes],int s,int *visited,int n)
{
    visited[s] = 1;
    printf("%d\n",s);
    for(int i=1; i<=n; i++)
    {
        if(adjmat[s][i]==1 && visited[i] != 1)
        {
            dfs(adjmat,i,visited,n);
        }
    }
}
int main(void)
{
    int adjmat[maxnodes][maxnodes],ch,n,visited[maxnodes],source,flag=0,s,d;
    do
    {
        printf("Enter a choice: 1.creategraph() 2. display() 3. dfs 4.exit()\n");
        scanf("%d\n",&ch);
        switch (ch)
        {
        case 1: printf("\nEnter the number of nodes in the graph:\n");
                scanf("%d",&n);
                initgraph(adjmat,n);
                create_graph(adjmat,n);
                break;
        case 2: display(adjmat,n);
                break;
        case 3: initvisited(visited,n);
                printf("Enter the source node:");
                for(int i=1;i<=n;i++)
                {
                    if(visited[i] == 0)
                    {
                        dfs(adjmat,s,visited,n);
                    }
                }
                dfs(adjmat,s,visited,n);
                break;
        case 4: exit(0);
        default:printf("Invalid choice");
        }
    } 
    while (ch<=4);
}