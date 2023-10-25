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

void creategraph(graph **nodep)
{
    int i,j;
    while(1)
    {
        printf("Enter the edge information:");
        scanf("%d %d",&i,&j);
        if(i==-1 && j==-1)
        {
            break;
        }
        else
        {
            insertfront(nodep,i,j);
        }
    }
}

void display(graph **nodep,int n)
{
    for(int i=1;i<=n;i++)
    {
        graph *cur = nodep[1];
        printf("%3d->",i);
        while(cur!=NULL)
        {
            printf("%3d->",cur->data);
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

int main(void)
{
    graph *listnode[maxnodes];
    int ch,n,source;
    int visited[maxnodes];
    do
    {
        printf("Enter 1:create_graph 2:display() 3:exit()\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of nodes in the graph:");
                    scanf("%d",&n);
                    initgraph(listnode,n);
                    creategraph(listnode);
            case 2: display(listnode,n);
                    break;
            case 3: initvisited(visited,n);
                    printf("Enter the source node:\n");
                    scanf("%d",&source);
                    dfs(listnode,source,n,visited);
            default:printf("Invalid choice");
        }
    }
    while(ch<=3);
}