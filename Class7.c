// Circular singular linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}NODE;

struct list
{
    NODE *tail;
};
typedef struct list CLIST;

void init(CLIST *p_dlist)
{
    p_dlist->tail = NULL;
}

NODE* getnode(int ele)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->link=NULL;
    return temp;
}

void insert_front(CLIST *p_clist, int ele)
{
    NODE *newNode = getnode(ele);
    if(p_clist->tail == NULL)
    {
        newNode->link = newNode;
        p_clist->tail = newNode;
    }
    else
    {
        newNode->link = p_clist->tail->link;
        p_clist->tail->link = newNode;
    }
}

void display(CLIST *p_clist)
{
    NODE* cur = p_clist->tail->link;
    while(cur != p_clist->tail)
    {
        printf("%d\n",cur->data);
        cur = cur->link;
    }
    printf("%d\n",cur->data);
}

int main(void)
{
    int ch,ele,pos;
    CLIST clistv;
    init(&clistv);
    do
    {
    printf("Enter the choice 1: insert_front 2: delete_front 3: display() 4: insert_rear 5: delete_rear 6: delete_pos 7: Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_front(&clistv,ele);
                break;
        case 2: delete_front(&clistv);
                break;
        case 3: display(&clistv);
                break;
        case 4: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_rear(&clistv,ele);
                break;
        case 5: delete_rear(&clistv);
                break;
        case 6: delete_pos(&clistv,pos);
                break;        
        case 7: exit(0);
    }
    }while(ch!=4);
}