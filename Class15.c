//Circular queue using linked list

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

void enqueue(QUEUE *q, int ele)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = ele;
    newNode->link = NULL;

    if(q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->link = newNode;
        q->rear = newNode;
    }
}

int dequeue(QUEUE *q)
{
    if(q->front == NULL)
    {
        printf("Empty queue\n");
        return -1;
    }
    int data = q->front->data;
    NODE* temp = q->front;
    q->front = q->front->link;

    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void display(QUEUE*q)
{
    NODE* temp = q->front;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}

int main(void)
{
    
}