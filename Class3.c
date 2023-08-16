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

NODE* getnode(int ele)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->link=NULL;
    return temp;
}

void insert_rear(NODE* ptr,int ele)
{
    NODE* newNODE;
    newNODE = getnode(ele);
    while(ptr->link!=NULL)
    ptr = ptr->link;
    ptr->link = newNODE;
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
    printf("Enter the choice 1: insert_front 2: insert_rear 3: Display 4: Exit() \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                first = insert_front(first,ele);
                break;
        case 2: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_rear(first,ele);
                break;
        case 3: display(first);
                break;
        case 4: exit(0);
        
    }
    }while(ch!=4);


}