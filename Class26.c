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

void bfs(int adjmat[][maxnodes],int s,int *visited, int n)
{
    int q[20],f=0,r=-1,x;
    q[++r]=s;
    visited[s] = 1;
    printf("\n%d",s);
    while(f<=r)
    {
        x=q[f++];
        for(int i=0; i<=n; i++)
        {
            if(adjmat[x][i]==1 && visited[i]!=1)
            {
                q[++r] = i;
                visited[i]=1;
                printf("\n%d",i);
            }
        }
    }
}

int strong_conn(int adjmat[][maxnodes],int n,int *visited)
{
    for(int i=1;i<=n;i++)
    {
        initvisited(visited,n);
        dfs(adjmat,i,n,visited);
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int weak_conn(int adjmat[][maxnodes],int n,int *visited)
{
    int b[maxnodes][maxnodes];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(adjmat[i][j]==1)
           {
            b[i][j] = 1;
            b[j][i] = 1; 
           }
        }
    }
    initvisited(visited,n);
    dfs(b,1,visited,n);
    for(int i=0;i<=n;i++)
    {
        if(visited[i]==0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int adjmat[maxnodes][maxnodes],ch,n,visited[maxnodes],source,flag=0,s,d;
    do
    {
        printf("Enter a choice: 1.creategraph() 2. display() 3. dfs 4. bfs 5. exit()\n");
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
                        dfs(adjmat,i,visited,n);
                    }
                }
                dfs(adjmat,s,visited,n);
                break;
        case 4: initvisited(visited,n);
                printf("Enter the source node:");
                scanf("%d",&s);
                bfs(adjmat,s,visited,n);
                break;
        case 5: if(strong_conn(adjmat,n,visited))
                {
                    printf("\nThe graph is strongly connected.\n");
                }
                else
                {
                    if(weak_conn(adjmat,n,visited))
                    {
                        printf("The graph is weakly connected.\n");
                    }
                    else
                    {
                        printf("The graph is neither strongly nor weakly connected.\n");
                    }
                }
                break;
        }
    } 
    while (ch<=5);
}