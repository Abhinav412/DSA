//Linked lists revision

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

NODE* delete_front(NODE*ptr)
{
    NODE*aux;
    if(ptr==NULL)
    printf("Empty list\n");
    else
    {
        aux = ptr;
        return ptr->link;
        free(aux);
    }
}

void delete_rear(NODE*ptr)
{
    NODE *prev = NULL,*next = ptr;
    if(ptr==NULL)
    printf("Empty list\n");
    else
    {
    while(next->link!=NULL)
    {
        prev = next;
        next = next->link;
    }
    prev->link = NULL;
    free(next);
    }
}

NODE* getnode(int ele)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->link=NULL;
    return temp;
}

NODE* insert_rear(NODE* ptr,int ele)
{
    NODE* newNODE,*cur;
    newNODE = getnode(ele);
    if(ptr==NULL)
    return newNODE;
    else
    {
    while(cur->link!=NULL)
    cur = cur->link;
    cur->link = newNODE;
    return ptr;
    }
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

void key_search(NODE*ptr,int key)
{
    NODE *cur = ptr;
    while(cur!=NULL && cur->data!=key)
    {
        cur = cur->link;
    }
    if(cur==NULL)
    {
        printf("Element does not exist");
    }
    else
    {
        printf("Element found");
    }
}

int main(void)
{
    NODE *first = NULL;
    int key,ch,ele;
    do
    {
    printf("Enter the choice 1: insert_front 2: insert_rear 3: delete_front 4: delete_rear 5: key_search 6: Display() 7: Exit() \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                first = insert_front(first,ele);
                break;
        case 2: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                first = insert_rear(first,ele);
                break;
        case 3: first = delete_front(first);
                break;
        case 4: delete_rear(first);
                break;
        case 5: printf("Element to be searched:\n");
                scanf("%d\n",&key);
                key_search(first,key);
                break;
        case 6: display(first);
                break;
        case 7: exit(1);
        
    }
    }while(ch!=8);
}