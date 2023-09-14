//Circular Queues
#include<stdio.h>
#define MAX 5

void enqueue(int *q,int*f,int*r,int ele)
{
    if((*f==0 && *r==MAX-1)||(*f==*r+1))
    {
        printf("Queue is full\n");
    }
    else
    {
        if(*f==-1)
        {
            *f=0;
        }
        *r = (*r+1)%MAX;
        q[*r] = ele;
    }
}

int dequeue(int*q,int*f,int*r)
{
    int x;
    if(*f==-1)
    return(9999);
    else
    {
        if(*f == *r)
        {
            x=q[*f];
            *r=*f=-1;
            return(x);
        }
        x = q[*f];
        *f=(*f+1)%MAX;
    }
    return(x);
}

void display(int*q,int f,int r)
{
    if(f==-1)
    {
        printf("Empty queue\n");
    }
    else
    {
        for(int i=f; i!=r;i=(i+1)%MAX)
        {
            printf("%d\t",q[i]);
        }
        printf("%d\t\n",q[r]);
    }
}

int main(void)
{
    int q[MAX];
    int f=-1,r=-1;
    int ele,x,ch;
    while(1)
    {
        printf("1.Enqueue 2.Dequeue 3.Display\n");
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element:\n");
                    scanf("%d",&ele);
                    enqueue(q,&f,&r,ele);
                    break;
            case 2: x=dequeue(q,&f,&r);
                    if(x==9999)
                    {
                        printf("Queue is empty\n");
                    }
                    else
                    {
                        printf("Deleted element is:%d\t\n",x);
                    }
                    break;
            case 3: display(q,f,r);
        }
    }
}