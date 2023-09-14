//Priority queue
#include<stdio.h>
#define MAX 5

void enqueue(int*q,int*f,int*r,int ele)
{
    if(*r==MAX-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int j =*r;
        while(j>=0 && ele<q[j])
        {
            q[j+1] = q[j];
            j--;
        }
        q[j+1] = ele;
        *r = *r+1;
    }
}

int dequeue(int*q,int*f,int*r)
{
    int x;
    if(*f>*r)
    {
        return(999);
    }
    else
    {
        x=q[*f];
        *f=*f+1;
        return(x);
    }
}

void display(int*q,int f,int r)
{
    if(f>r)
    {
        printf("Empty queue\n");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("%d\t\n",q[i]);
        }
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