//Graph representation using adjacency list
#include<stdio.h>
#include<stdlib.h>
#define maxnodes 10
typedef struct node
{
    int data;
    struct node *link;
}graph;

void initgraph(graph **nodep,int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        nodep[i] = NULL;
    }
}

void insertfront(graph **nodep,int i,int j)
{
    graph *cur,*temp;
    temp=(graph*)malloc(sizeof(graph));
    temp->data = j;
    temp->link = NULL;
    cur = nodep[i];
    if(cur == NULL)
    {
        nodep[i] = temp;
    }
    else
    {
        while(cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
    }
}

void creategraph(graph **nodep, int n)
{
    int i, j, value;
    graph *temp;
    for(i=1;i<=n;i++)
    {
        temp = (graph*)malloc(sizeof(graph));
        temp->data = i;
        temp->link = NULL;
        nodep[i] = temp;
        printf("Enter the adjacent vertices of %d (-1 to exit): ",i);
        scanf("%d",&value);
        while(value != -1)
        {
            if(value > n || value < 1)
            {
                printf("Invalid node entered. Please enter a node between 1 and %d.\n", n);
            }
            else
            {
                graph *adj = (graph*)malloc(sizeof(graph));
                adj->data = value;
                adj->link = NULL;
                temp->link = adj;
                temp = adj;
            }
            scanf("%d",&value);
        }
    }
}

void display(graph **nodep,int n)
{
    graph *cur;
    for(int i=1;i<=n;i++)
    {
        cur=nodep[i];
        printf("%d: ",i);
        while(cur!=NULL)
        {
            printf("%d-> ",cur->data);
            cur=cur->link;
        }
        printf("\n");
    }
}

void initvisited(int *visited,int n)
{
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
}

void dfs(graph **nodep,int s,int n,int *visited)
{
    int adj;
    visited[s] = 1;
    printf("\n%d",s);
    for(graph *cur = nodep[s]; cur!= NULL; cur=cur->link)
    {
        adj = cur->data;
        if(visited[adj]==0)
        {
            dfs(nodep,adj,n,visited);
        }
    }
}

void bfs(graph **nodep,int s,int *visited)
{
    int q[maxnodes],f=0,r=-1,x,adj;
    visited[s] = 1;
    printf("\n%d",s);
    q[++r] = s;
    while(f<=r)
    {
        x = q[f++];
        for(graph *cur = nodep[x]; cur!= NULL; cur=cur->link)
        {
            adj = cur->data;
            if(visited[adj]==0)
            {
                visited[adj] = 1;
                printf("\n%d",adj);
                q[++r] = adj;
            }
        }
    }
}

int strong_conn(graph **nodep,int n,int *visited)
{
    for(int i=1;i<=n;i++)
    {
        initvisited(visited,n);
        dfs(nodep,i,n,visited);
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

int main(void)
{
    graph *listnode[maxnodes];
    int ch,n,source;
    int visited[maxnodes];
    do
    {
        printf("\nEnter 1:create_graph 2:display() 3:dfs() 4:bfs() 5:strong_conn() 6:exit()\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of nodes in the graph:");
                    scanf("%d",&n);
                    initgraph(listnode,n);
                    creategraph(listnode,n);
                    break;
            case 2: display(listnode,n);
                    break;
            case 3: initvisited(visited,n);
                    printf("Enter the source node:\n");
                    scanf("%d",&source);
                    dfs(listnode,source,n,visited);
                    break;
            case 4: initvisited(visited,n);
                    printf("Enter the source node:\n");
                    scanf("%d",&source);
                    bfs(listnode,source,visited);
                    break;
            case 5: if(strong_conn(listnode,n,visited))
                    {
                        printf("\nThe graph is strongly connected.\n");
                    }
                    else
                    {
                        printf("The graph is not strongly connected.\n");
                    }
                    break;
            case 6: exit(0);
        }
    }
    while(ch!=5);
}