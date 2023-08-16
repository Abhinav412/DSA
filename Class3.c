//Inserting node at front end of a list:

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE* insert_front(NODE *head, int element)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = element;
    temp->link = NULL;
    if(head==NULL)
    head = temp;
    else
    {
        temp->link = head;
        head = temp;
    }
    return head;
}

void display(NODE *q)
{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q = q->link;
    }
}

int main(void)
{
    NODE *first  =NULL;
    int ch,ele;
    do
    {
    printf("Enter the choice 1: insert_front 2: display() 3: Exit() \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_front(first,ele);
                break;
        case 2: display(first);
                break;
        case 3: exit(0);
        
    }
    }while(ch!=3);


}