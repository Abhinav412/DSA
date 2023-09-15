//Double-ended queue

#include<stdio.h>
#define MAX 5

void insert_front(int*q,int*f,int*r,int ele)
{
    if((*f==0 && *r==MAX-1)||(*f=*r+1))
    {
        printf("Queue is full\n");
    }
    else
    {
        if(*f=-1 && *r==-1)
        {
            *f=0;
            *r=0;
            q[*f]=ele;
        }
        else if(*f==0)
        {
            *f=MAX-1;
            q[*f] = ele;
        }
        else
        {
            q[*f] = ele;
            *f=*f-1;
        }
    }
}

void insert_rear(int*q,int*f,int*r,int ele)
{
    if((*f==0 && *r == MAX-1)||(*f==*r+1))
    {
        printf("Queue is full\n");
    }
    else
    {
        if(*f==-1 && *r==-1)
        {
            *r=0;
            *f=0;
            q[*r] = ele;
        }
        else if(*r==MAX-1)
        {
            *r=0;
            q[*r] = ele;
        }
        else
        {
            q[*r] = ele;
            *r=*r+1;
        }
    }
}

void display(int *q,int f,int r)
{
    if(f==-1)
    {
        printf("Empty queue\n");
    }
    else
    {
        for(int i=f;i!=r;i=(i+1)%MAX)
        {
            printf("%d\t",q[i]);
        }
        printf("%d\n",q[r]);
    }
}

int main(void)
{
    int q[MAX];
    int f=-1,r=-1;
    int ele,x,ch;
    while(1)
    {
        printf("1.Insert front 2.Insert rear 3.Display\n");
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element:\n");
                    scanf("%d",&ele);
                    insert_front(q,&f,&r,ele);
                    break;
            case 2: printf("Enter the element:\n");
                    scanf("&d",&ele);
                    insert_rear(q,&f,&r,ele);
                    break;
            case 3: display(q,f,r);
        }
    }
}