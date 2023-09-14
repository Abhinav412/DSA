//Queues using structures

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}NODE;

typedef struct queue
{
    NODE* front;
    NODE* rear;
}QUEUE;

void enqueue(QUEUE* ptr, int ele)
{
    NODE* temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->link = NULL;
    if(ptr->front == NULL && ptr->rear == NULL)
    {
        ptr->front = ptr->rear = temp;
    }
    else
    {
        ptr->rear->link = temp;
        ptr->rear = temp;
    }
}

int dequeue(QUEUE* ptr)
{
    int x;
    if(ptr->front == NULL)
    {
        return(999);
    }
    else
    {
        if(ptr->front == ptr->rear)
        {
            x=ptr->front->data;
            free(ptr->front);
            ptr->front = ptr->rear = NULL;
        }
        else
        {
            NODE* second = ptr->front->link;
            x=ptr->front->data;
            free(ptr->front);
            ptr->front = second;
        }
        return(x);
    }
}

void display(QUEUE* ptr)
{
    if(ptr->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        NODE* cur = ptr->front;
        while(cur!=NULL)
        {
            printf("%d\t\n",cur->data);
            cur = cur->link;
        }
    }
}

int main(void)
{
    QUEUE* ptr = malloc(sizeof(QUEUE));
    ptr->front = ptr->rear = NULL;
    int ele,ch,x;
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display");
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    enqueue(ptr,ele);
                    break;
            case 2: x=dequeue(ptr);
                    if(x==9999)
                    {
                        printf("Queue is empty\n");
                    }
                    else
                    {
                        printf("Deleted element is:%d\n",x);
                    }
                    break;
            case 3: display(ptr);
        }
    }
}