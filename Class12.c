//Queues in C
/*Linear data structure where elements are inserted from rear end and removed from front end.
FIFO concept which means FIRST IN FIRST OUT.
Types are:
1.Linear 2.Circular 3.Priority 4.Double linked
When front is 0 and rear is -1 it is known as underflow condition also when front is greater than rear it is a underflow condition
For enqueue we have to increment rear=-1 by 1 and insert the value in that index
When rear value is equal to MAX-1 it is a overflow condition
To dequeue increment front=0 by 1 and point to the next element*/
//Queue in array notation.
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void enqueue(int *q,int *r,int ele)
{
    if(*r==MAX-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        *r=*r+1;
        q[*r] = ele;
    }
}

int dequeue(int *q,int *f, int*r)
{
    int x;
    if(*f>*r)
    return(999);
    else
    {
        x=q[*f];
        *f=*f+1;
        return x;
    }
}

void display(int *q,int f, int r)
{
    if(f>r)
    printf("Empty queue");
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
    int f=0, r=-1;
    int ele,ch,x;
    while(1)
    {
        printf("1.Enqueue\n 2.Dequeue\n 3.Display\n");
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&ele);
                    enqueue(q,&r,ele);
                    break;
            case 2: x=dequeue(q,&f,&r);
                    if(x==999)
                    printf("Queue is empty\n");
                    else
                    printf("Deleted element is:%d",x);
                    break;
            case 3: display(q,f,r);
        }
    }
}